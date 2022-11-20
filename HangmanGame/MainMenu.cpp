#include "MainMenu.h"
using namespace std;
//������� ���� ��� ��������� ������� � �����
string MainMenu::GetPath()
{
	return path;
}
//������� ����� ��� ���������� ���� �� �����
int MainMenu::GetKey()
{
    return key;
}
//����� �������� �������� ����
void MainMenu::ShowTitle()
{
    cout << "  ";
    for (int i{}; i < 57; i++) cout << "* ";
    cout << "\n\n";
    cout << "*  __________" << "    __      __" << "    __________" << "    __________" << "    __________" << "    __      __" << "    __      __" << "      __________   *\n\n";
    cout << "* |   ____   |" << "  |  |   /   |" << "  |   ____   |" << "  |   _______|" << "  |   ____   |" << "  |  |   /   |" << "  |  |    |  |" << "    |   ____   |  *\n\n";
    cout << "* |  |____|  |" << "  |  |  //|  |" << "  |  |    |__|" << "  |  |_______ " << "  |  |    |  |" << "  |  |  //|  |" << "  |  |    |  |" << "    |  |____|  |  *\n\n";
    cout << "* |   ____   |" << "  |  | // |  |" << "  |  |     __ " << "  |   _______|" << "  |  |    |  |" << "  |  | // |  |" << "  |  |    |  |" << "    |   ____   |  *\n\n";
    cout << "* |  |____|  |" << "  |  |//  |  |" << "  |  |____|  |" << "  |  |_______ " << "  |  |    |  |" << "  |  |//  |  |" << "  |  |____|  |_" << "   |  |    |  |  *\n\n";
    cout << "* |__________|" << "  |__ /   |__|" << "  |__________|" << "  |__________|" << "  |__|    |__|" << "  |__ /   |__|" << "  |_________   |" << "  |__|    |__|  *\n\n";
    cout << "*  \t\t\t\t\t\t\t\t\t\t\t        |__|\t\t    *\n\n";
    cout << "  ";
    for (int i{}; i < 57; i++) cout << "* ";
    cout << "\n\t\t\t     ";
    for (int i{}; i < 60; i++) cout << "_";
    cout << "\n\t\t\t    ||\t\t        ||\t\t    ||\t\t        ||";
    cout << "\n\t\t\t    ||    [�] ����      ||   [�] �������    ||    [�] �����     ||";
    cout << "\n\t\t\t    ||__________________||__________________||__________________||";
    cout << "\n\n\t\t\t\t\t\t\t��������!";
    cout << "\n    ���� ���� ���� �������������� � ������ ��������.";
    cout << " ��������, ����������� �� ���� ���������� �� ������� ���������.\n";
    cout << "\t\t\t\t\t\t���������� ������� �������!\n";
}
//����� ������ � ��������� � ����������� �� ������� ������� 
void MainMenu::ShowRules()
{
    system("cls");
    cout << "\n\t\t\t\t\t\t\t�������\n\n";
    cout << "\t\t\t���� ���� ������� � ���, ����� ������� �������� ��������� ����� �� ����, \n\t\t\t\t\t��� ��������� �� �������� ����� ���������.";
    cout << "\n\n\t\t\t�������� �����, ����� �� � ������� � ����� Enter. � ������ ������ ����������";
    cout << "\n\t\t\t     ������ ����������, � �� �������� �������� ����� ���� ���������.";
    cout << "\n\n\t\t\t� ���� ���� ��� ������ ��������� - �������, ������� � �������.\n";
    cout << "\n\n\t\t\t����� ���������\t\t����� �����";
    cout << "\n\n\t\t\t�������\t\t\t4-6";
    cout << "\n\n\t\t\t�������\t\t\t7-9";
    cout << "\n\n\t\t\t�������\t\t\t10-12";
    cout << "\n\n\t\t\t��������� ����: ��������, ��������, ������";
    cout << "\n\n\t\t\t\t\t\t __________________\n";
    cout << "\t\t\t\t\t\t||                ||\n";
    cout << "\t\t\t\t\t\t||   [�] �����    ||\n";
    cout << "\t\t\t\t\t\t||________________||\n";
}
//����� ������ � ����������� � ������������ �������
void MainMenu::ShowThemeButtons()
{
    cout << "\n\t\t     ����� ����...";
    cout << "\n\t\t     ";
    for (int i{}; i < 80; i++) cout << "_";
    cout << "\n\t\t    ||\t\t        ||\t\t    ||\t\t        ||\t\t    ||";
    cout << "\n\t\t    ||   [�] ��������   ||   [�] ��������   ||   [�] ������     ||    [�] �����     ||";
    cout << "\n\t\t    ||__________________||__________________||__________________||__________________||";
    cout << "\n\n\t\t    >";
}
//����� ������ � ����������� � ������� ���������
void MainMenu::ShowDifficultyButtons()
{
    system("cls");
    cout << "\n\t\t     ����� ������ ���������...";
    cout << "\n\t\t     ";
    for (int i{}; i < 80; i++) cout << "_";
    cout << "\n\t\t    ||\t\t        ||\t\t    ||\t\t        ||\t\t    ||";
    cout << "\n\t\t    ||   [�] �������    ||   [�] �������    ||   [�] �������    ||    [�] �����     ||";
    cout << "\n\t\t    ||__________________||__________________||__________________||__________________||";
    cout << "\n\n\t\t    >";
}
//������� ������� ���������, ����� �������� ������ � ������ ����
//������� ChoiceTheme ��������� ����� �, � ����������� �� ����, �������� ���� � ������� �����
void MainMenu::ChoiceDifficulty()
{
    cin >> choice;
    switch (choice)
    {
    case '�':
        ShowThemeButtons();
        ChoiceTheme("wordsFaunaEasy.txt", "wordsFloraEasy.txt", "wordsSpaceEasy.txt");
        break;
    case '�':
        ShowThemeButtons();
        ChoiceTheme("wordsFaunaMedium.txt", "wordsFloraMedium.txt", "wordsSpaceMedium.txt");
        break;
    case '�':
        ShowThemeButtons();
        ChoiceTheme("wordsFaunaHard.txt", "wordsFloraHard.txt", "wordsSpaceHard.txt");
        break;
    case '�':
        //� ������ ������ ������� "�����" ��������� ������������ � �������� ����
        isTheme = false;
        isMenu = true;
        system("cls");
        break;
    default:
        cout << "\n\t\t   ������ �����";
        Sleep(1000);
        break;
    }
}
//������� ��������� ��� ���� � ������ (����� �� ������ ��������� � ������ ������ ���������) 
//��� ������ ���� ��������� ��������� �� ������� ����� 
void MainMenu::ChoiceTheme(string path1, string path2, string path3)
{
    cin >> choice;
    switch (choice)
    {
    case '�':
        path = path1;
        key = 20;
        isMenu = false;
        isTheme = false;
        system("cls");
        break;
    case '�':
        path = path2;
        key = 25;
        isMenu = false;
        isTheme = false;
        system("cls");
        break;
    case '�':
        key = 10;
        path = path3;
        isMenu = false;
        isTheme = false;
        break;
    case '�':
        //� ������ ������ ������� "�����" ��������� ������������ � ������ ������ ���������
        system("cls");
        break;
    default:
        //� ������ "������ �����" ��������� ������������ � ������ ������ ���������
        cout << "\n\t\t   ������ �����";
        Sleep(1000);
        break;
    }
    system("cls");
}
//������� ������� ���� (��. ����������� ������ �������)
void MainMenu::ShowMenu()
{
    while (isMenu)
    {
        choice = '0';
        //�������� ������� ����
        ShowTitle();
        cout << "\n\t>";
        cin >> choice;
        switch (choice)
        {
        case '�':
            //������� � ������ ������ ��������� � ��� 
            isMenu = false;
            isTheme = true;
            //����� ������ ������ ��������������� �� ��� ��� ����:
            //1. �� ����� ������� ����
            //2. ���� ����� �� �������� � ������� ����
            //� ������ ������ ������ 1 ���� ������� � �������� ������ �� ������ Game
            while (isTheme)
            {
                ShowDifficultyButtons();
                ChoiceDifficulty();
            }
            break;
        case '�':
            //������� �� ����� ������
            while (choice != '�') {
                ShowRules();
                cout << "\n\t\t\t>";
                cin >> choice;
                //� ������ ������ ����� ���������������
                if (choice != '�') {
                    cout << "\n\t\t\t������ �����";
                    Sleep(1000);
                }
            }
            system("cls");
            break;
        case '�':
            //���������� ���������
            cout << "\n\t�����\n";
            Sleep(1000);
            exit(0);
            break;
        default:
            //� ������ ������ ����� ���������������
            cout << "\n\t������ �����";
            Sleep(1000);
            system("cls");
            break;
        }
    }
}


