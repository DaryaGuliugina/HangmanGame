#include "Game.h"
//����� ������� ������� ���� �� ������ MainMenu
void Game::ShowMainMenu()
{
	menu.ShowMenu();
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t   __      __" << "    __________" << "    __      __" << "    __________" << "    __________" << "    __      __" << "\n\n";
    cout << "\t\t  |  |    |  |" << "  |   ____   |" << "  |  |    |  |" << "  |   ____   |" << "  |   ____   |" << "  |  |   /   |" << "\n\n";
    cout << "\t\t  |  |____|  |" << "  |  |____|  |" << "  |  |____|  |" << "  |  |____|  |" << "  |  |    |  |" << "  |  |  //|  |" << "\n\n";
    cout << "\t\t  |   ____   |" << "  |   ____   |" << "  |_______   |" << "  |   ____   |" << "  |  |    |  |" << "  |  | // |  |" << "\n\n";
    cout << "\t\t  |  |    |  |" << "  |  |    |  |" << "          |  |" << "  |  |    |  |" << "  |  |    |  |" << "  |  |//  |  |" << "\n\n";
    cout << "\t\t  |__|    |__|" << "  |__|    |__|" << "          |__|" << "  |__|    |__|" << "  |__|    |__|" << "  |__ /   |__|" << "\n\n";
    Sleep(1000);
    system("cls");
}
//������ ������ �� ����� � ��������� � ������ words
//�������� �� �������� �����
void Game::ReadFile()
{
    fin.open(menu.GetPath());
    if (!fin.is_open()) {
        //�������� ����� �������� �� �������� exe, ��� ��� �������� ���������
        cout << "\n\t������ �������� �����!\n";
        system("pause");
        exit(0);
    }
    else {
        while (!fin.eof()) {
            str = "";
            getline(fin, str);
            words.push_back(str);
        }
    }
    fin.close();
}
//����������� ����������� �����
//���� �������� �� ������ MainMenu
void Game::Decryption()
{
    char ch;
    for (int i{}; strHiddenWord[i] != '\0'; ++i) {
        ch = strHiddenWord[i];
        if (ch >= '�' && ch <= '�') {
            ch = ch - menu.GetKey();
            if (ch < '�') {
                ch = ch + '�' - '�' + 1;
            }
            strHiddenWord[i] = ch;
        }
    }
}
//����� ����� � ��������� ��� � ��������
//��. ����� ��������� ����������� � �������
void Game::ChoiceHiddenWord()
{
    //��������� ������ ���� 
    ReadFile();
    //�������� ��������� ����� �� ������� words
    randWordNumber = rand() % words.size();
    strHiddenWord = words[randWordNumber];
    //��������� ���
    Decryption();
    //������� � ������ hiddenWord
    for (int i{}; i < strHiddenWord.size(); i++) {
        hiddenWord.push_back(strHiddenWord[i]);
    }
    //��������� ������ showHiddenWord �������� '_'
    for (int i{}; i < hiddenWord.size(); i++) {
        showHiddenWord.push_back('_');
    }
    //������ �������� � ������ ������� hiddenWord
    itErase = hiddenWord.begin();
}
//����� ��������� ��������, � ����������� �� ���������� ������
void Game::ShowHangman(int  counterUserErrors)
{
    cout << "\t   _________\n";
    switch (counterUserErrors)
    {
    case 0:
        cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t\n" << "\t  |\t\n" << "\t  |\t\n" << "\t  |\t\n" << "\t  |\t\n";
        break;
    case 1:
        cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t   O\n" << "\t  |\t\n" << "\t  |\t\n" << "\t  |\t\n" << "\t  |\t\n";
        break;
    case 2:
        cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t   O\n" << "\t  |\t   |\n" << "\t  |\t   |\n" << "\t  |\t\n" << "\t  |\t\n";
        break;
    case 3:
        cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t   O\n" << "\t  |\t  /|\n" << "\t  |\t   |\n" << "\t  |\t\n" << "\t  |\t\n";
        break;
    case 4:
        cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t   O\n" << "\t  |\t  /|\\\n" << "\t  |\t   |\n" << "\t  |\t\n" << "\t  |\t\n";
        break;
    case 5:
        cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t   O\n" << "\t  |\t  /|\\\n" << "\t  |\t   |\n" << "\t  |\t  / \n" << "\t  |\t\n";
        break;
    }
    cout << "        _/|\\________\t\n";
}
//����� ����������
void Game::ShowInterface()
{
    cout << endl;
    //����� ���������
    ShowHangman(counterUserErrors);
    for (int i{}; i < 120; i++) cout << "_";
    //����� ��������� ����
    cout << "\n\n\t";
    for (int i{}; i < showHiddenWord.size(); i++)
        cout << showHiddenWord[i] << ' ';
    cout << "\n";
    for (int i{}; i < 120; i++) cout << "_";
    //����� ���������� �������
    cout << "\n\n\n\t���������� �����: " << livesLeft;
    //����� ��������� ����
    cout << "\n\n\t������� ��������� �����: ";
    for (auto a : wrongLetters)
        cout << a << ' ';
    cout << "\n";
    for (int i{}; i < 120; i++) cout << "_";
}
//������� ��������� ��������
//��. ����� ��������� ����������� � �������
void Game::GamePlay()
{
    //��������� ������ �����
    ChoiceHiddenWord();
    //�������� ���� ������� ����
    auto start = sc.now();
    //���������� ���� ���� �� ������� ����� ��� �� ���������
    while (hiddenWord.size() != 0 && counterUserErrors != 6) {
        bool isRusLetters = false;
        bool isError = true;
        ShowInterface();
        cout << "\n\n������� �����: ";
        cin >> userLetter;
        counterAttemps++;
        index = 0;
        //�������� �� ������������ ������ �������� ��������
        if (userLetter > -33 && userLetter < 0)
            isRusLetters = true;
        //�������� �� ��������� ���� ��������� ����
        if (!wrongLetters.empty()) {
            for (auto a : wrongLetters) {
                if (a == userLetter) {
                    cout << "\n������������!\n";
                    Sleep(1000);
                    counterUserErrors--;
                    livesLeft++;
                }
            }
        }
        //���� ������� ����� ������������� ������� counterOfGuessedLetters
        for (int i{}; i < hiddenWord.size(); i++)
            if (userLetter == hiddenWord[i]) 
                counterOfGuessedLetters++;
        //���� ������� �����, ������ '_' � ������� showHiddenWord �� ��������� ������
        for (int i{}; i < strHiddenWord.size(); i++) {
            if (userLetter == strHiddenWord[i]) {
                showHiddenWord[i] = userLetter;
                isError = false;
            }
        }
        //�������� ������ �� ��������� � ������ �������� ��������
        if (counterOfGuessedLetters == 0 && isError == true && isRusLetters == false) {
            cout << "\n������������ ������!\n";
            Sleep(1000);
        }
        //�������� ����� ��� ������� � �����
        else if (counterOfGuessedLetters == 0 && isError == false && isRusLetters == true) {
            cout << "\n����� ��� �������!\n";
            Sleep(1000);
        }
        //� ������ ������ ������� ����� � wrongLetters
        else if (counterOfGuessedLetters == 0 && isError == true && isRusLetters == true) {
            counterUserErrors++;
            livesLeft--;
            wrongLetters.insert(userLetter);
        }
        //� ������ ���� ����� �������...
        while (counterOfGuessedLetters != 0) {
            //���� ������� ��������� �����
            for (; index < hiddenWord.size(); index++)
                if (userLetter == hiddenWord[index]) break;
            //���������� �������� �� ������ �������
            itErase += index;
            //������� ��������� ����� �� �������
            hiddenWord.erase(itErase);
            //���������� �������� � ������ �������
            itErase = hiddenWord.begin();
            counterOfGuessedLetters--;
        }
        system("cls");
    }
    //����������� ���� ������� ����
    auto end = sc.now();
    //�������� ������� ������ ������� � ��������
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    //������� � ���������� timeGameSec � ����������� � ���� int
    timeGameSec = (int)time_span.count();
}
//������� ������ �� ���������� timeGameSec � ������ ����:������:�������
void Game::Time()
{
    timeGameMin = timeGameSec / 60;
    timeGameHour = timeGameSec / 3600;
    if (timeGameSec >= 60) {
        timeGameSec -= (timeGameSec / 60) * 60;
    }
    if (timeGameMin >= 60) {
        timeGameMin -= (timeGameMin / 60) * 60;
    }
    timeGameHour < 10 ? cout << "0" << timeGameHour : cout << timeGameHour;
    cout << ":";
    timeGameMin < 10 ? cout << "0" << timeGameMin : cout << timeGameMin;
    cout << ":";
    timeGameSec < 10 ? cout << "0" << timeGameSec : cout << timeGameSec;
}
//����� ������� ����������� ��������� � ������ ���������
void Game::ShowDefeat(int  errors)
{
    cout << "\t   _________\n";
    cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t   O\n" << "\t  |\t  /|\\\n" << "\t  |\t   |\n" << "\t  |\t  / \\\n" << "\t  |\t\n";
    cout << "        _/|\\________\t\n";
    Sleep(1500);
    system("cls");
}
//����� ������ "����� ����" � "�����"
//����������� ���������� �������� ������
void Game::NewGameOrExit()
{
    char choice;
    cout << "\n\n\t\t\t\t     ";
    for (int i{}; i < 40; i++) cout << "_";
    cout << "\n\t\t\t\t    ||\t\t        ||\t\t    ||";
    cout << "\n\t\t\t\t    ||  [�] ����� ����  ||    [�] �����     ||";
    cout << "\n\t\t\t\t    ||__________________||__________________||";
    cout << "\n\n\t\t\t\t    >";
    cin >> choice;
    switch (choice)
    {
    case '�':
        //������ ���� ������ (������� �� �����)
        isEnd = false;
        system("cls");
        break;
    case '�':
        //��������� ���������
        cout << "\n\t\t\t\t    �����\n";
        exit(0);
        break;
    default:
        //��� ������ ����� ������������� ����
        cout << "\n\t\t\t\t    ������ �����";
        Sleep(1000);
        system("cls");
        break;
    }
}
//�������������� ����������� ����������
int Game::victory = 0;
int Game::defeat = 0;
//���������� ������ ����
//��. ����� ��������� ����������� � �������
void Game::GameResult()
{
    //��������� ��� ����� �������� ����� ������ ������������ � ��������� ������
    //����� ������������ ����������� ���������� victory � defeat
    while (isEnd)
    {
        //���������� ������ ��� ��������� ����� ���������� counterUserErrors
        if (counterUserErrors >= 6) {
            ShowDefeat(counterUserErrors);
            cout << "\n\n\t\t\t\t\t\t  ���������";
            defeat++;
        }
        else { cout << "\n\n\t\t\t\t\t\t  ������"; victory++; }
        cout << "\n\n";
        for (int i{}; i < 120; i++) cout << '_';
        //������� ����������
        cout << "\n\n\t\t������: " << victory << "\t\t\t ����������" << "\t\t\t  ���������: " << defeat << "\n";
        for (int i{}; i < 120; i++) cout << '_';
        cout << "\n\n\n\t\t\t\t\t    ������� �����: " << strHiddenWord;
            cout << "\n\n\n\t\t\t\t\t    ���������� �������: " << counterAttemps;
        cout << "\n\n\n\t\t\t\t\t    ����� ������: ";
        //������� ��� ����� �� wrongLetters
        for (char a : wrongLetters)
            cout << a << ' ';
        //������� ��������� ����� �� ������� showHiddenWord
        for (int i{}; i < showHiddenWord.size(); i++)
            if (showHiddenWord[i] != '_') cout << showHiddenWord[i] << ' ';
        //������� ����� �� ������� Time
        cout << "\n\n\n\t\t\t\t\t    �����: ";
        Time();
        cout << "\n\n\n";
        for (int i{}; i < 120; i++) cout << '_';
        //����� ������:
        //1. ������ ����� �������� ����� (����� ����)
        //2. ��������� ��������� (�����)
        NewGameOrExit();
    }
}
