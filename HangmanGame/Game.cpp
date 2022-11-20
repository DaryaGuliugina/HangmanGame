#include "Game.h"
//Вывод главной функции меню из класса MainMenu
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
//Чтение данных из файла и занесение в вектор words
//Проверка на открытие файла
void Game::ReadFile()
{
    fin.open(menu.GetPath());
    if (!fin.is_open()) {
        //Подобный вылет случился на открытии exe, так что проверка сработала
        cout << "\n\tОшибка открытия файла!\n";
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
//Расшифровка полученного слова
//Ключ получаем из класса MainMenu
void Game::Decryption()
{
    char ch;
    for (int i{}; strHiddenWord[i] != '\0'; ++i) {
        ch = strHiddenWord[i];
        if (ch >= 'а' && ch <= 'я') {
            ch = ch - menu.GetKey();
            if (ch < 'а') {
                ch = ch + 'я' - 'а' + 1;
            }
            strHiddenWord[i] = ch;
        }
    }
}
//Выбор слова и занесение его в геймплей
//См. более подробные комментарии в функции
void Game::ChoiceHiddenWord()
{
    //Программа читает файл 
    ReadFile();
    //Выбирает случайное слово из вектора words
    randWordNumber = rand() % words.size();
    strHiddenWord = words[randWordNumber];
    //Дешифрует его
    Decryption();
    //Заносит в вектор hiddenWord
    for (int i{}; i < strHiddenWord.size(); i++) {
        hiddenWord.push_back(strHiddenWord[i]);
    }
    //Заполняет вектор showHiddenWord символом '_'
    for (int i{}; i < hiddenWord.size(); i++) {
        showHiddenWord.push_back('_');
    }
    //Ставит итератор в начало вектора hiddenWord
    itErase = hiddenWord.begin();
}
//Вывод человечка поэтапно, в зависимости от количества ошибок
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
//Вывод интерфейса
void Game::ShowInterface()
{
    cout << endl;
    //Вывод человечка
    ShowHangman(counterUserErrors);
    for (int i{}; i < 120; i++) cout << "_";
    //Вывод угаданных букв
    cout << "\n\n\t";
    for (int i{}; i < showHiddenWord.size(); i++)
        cout << showHiddenWord[i] << ' ';
    cout << "\n";
    for (int i{}; i < 120; i++) cout << "_";
    //Вывод оставшихся попыток
    cout << "\n\n\n\tОставшиеся жизни: " << livesLeft;
    //Вывод ошибочных букв
    cout << "\n\n\tНеверно угаданные буквы: ";
    for (auto a : wrongLetters)
        cout << a << ' ';
    cout << "\n";
    for (int i{}; i < 120; i++) cout << "_";
}
//Функция основного геймплея
//См. более подробные комментарии в функции
void Game::GamePlay()
{
    //Компьютер задает слово
    ChoiceHiddenWord();
    //Начинаем счет времени игры
    auto start = sc.now();
    //Продолжаем игру пока не угадаем слово или не проиграем
    while (hiddenWord.size() != 0 && counterUserErrors != 6) {
        bool isRusLetters = false;
        bool isError = true;
        ShowInterface();
        cout << "\n\nВведите букву: ";
        cin >> userLetter;
        counterAttemps++;
        index = 0;
        //Проверка на соответствие буквам русского алфавита
        if (userLetter > -33 && userLetter < 0)
            isRusLetters = true;
        //Проверка на повторный ввод ошибочных букв
        if (!wrongLetters.empty()) {
            for (auto a : wrongLetters) {
                if (a == userLetter) {
                    cout << "\nВнимательней!\n";
                    Sleep(1000);
                    counterUserErrors--;
                    livesLeft++;
                }
            }
        }
        //Если угадали букву увеличивается счетчик counterOfGuessedLetters
        for (int i{}; i < hiddenWord.size(); i++)
            if (userLetter == hiddenWord[i]) 
                counterOfGuessedLetters++;
        //Если угадали букву, меняем '_' в векторе showHiddenWord на угаданный символ
        for (int i{}; i < strHiddenWord.size(); i++) {
            if (userLetter == strHiddenWord[i]) {
                showHiddenWord[i] = userLetter;
                isError = false;
            }
        }
        //Вводимый символ не относится к буквам русского алфавита
        if (counterOfGuessedLetters == 0 && isError == true && isRusLetters == false) {
            cout << "\nНеопознанный символ!\n";
            Sleep(1000);
        }
        //Вводимая буква уже угадана в слове
        else if (counterOfGuessedLetters == 0 && isError == false && isRusLetters == true) {
            cout << "\nБуква уже угадана!\n";
            Sleep(1000);
        }
        //В случае ошибки заносим букву в wrongLetters
        else if (counterOfGuessedLetters == 0 && isError == true && isRusLetters == true) {
            counterUserErrors++;
            livesLeft--;
            wrongLetters.insert(userLetter);
        }
        //В случае если буква угадана...
        while (counterOfGuessedLetters != 0) {
            //Ищем позицию угаданной буквы
            for (; index < hiddenWord.size(); index++)
                if (userLetter == hiddenWord[index]) break;
            //Перемещаем итератор на нужную позицию
            itErase += index;
            //Удаляем угаданную букву из вектора
            hiddenWord.erase(itErase);
            //Перемещаем итератор в начало вектора
            itErase = hiddenWord.begin();
            counterOfGuessedLetters--;
        }
        system("cls");
    }
    //Заканчиваем счет времени игры
    auto end = sc.now();
    //Вычислем сколько прошло времени в секундах
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    //Заносим в переменную timeGameSec и преобразуем к типу int
    timeGameSec = (int)time_span.count();
}
//Перевод секунд из переменной timeGameSec в формат часы:минуты:секунды
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
//Вывод полного изображения человечка в случае поражения
void Game::ShowDefeat(int  errors)
{
    cout << "\t   _________\n";
    cout << "\t  |/\t   |\n" << "\t  |\t   |\n" << "\t  |\t   O\n" << "\t  |\t  /|\\\n" << "\t  |\t   |\n" << "\t  |\t  / \\\n" << "\t  |\t\n";
    cout << "        _/|\\________\t\n";
    Sleep(1500);
    system("cls");
}
//Вывод кнопок "Новая игра" и "Выход"
//Определение дальнейших действий игрока
void Game::NewGameOrExit()
{
    char choice;
    cout << "\n\n\t\t\t\t     ";
    for (int i{}; i < 40; i++) cout << "_";
    cout << "\n\t\t\t\t    ||\t\t        ||\t\t    ||";
    cout << "\n\t\t\t\t    ||  [Н] Новая игра  ||    [В] Выход     ||";
    cout << "\n\t\t\t\t    ||__________________||__________________||";
    cout << "\n\n\t\t\t\t    >";
    cin >> choice;
    switch (choice)
    {
    case 'н':
        //Начать игру заново (выходим из цикла)
        isEnd = false;
        system("cls");
        break;
    case 'в':
        //Завершить программу
        cout << "\n\t\t\t\t    Выход\n";
        exit(0);
        break;
    default:
        //При ошибке ввода перезапускаем цикл
        cout << "\n\t\t\t\t    Ошибка ввода";
        Sleep(1000);
        system("cls");
        break;
    }
}
//Инициализируем статические переменные
int Game::victory = 0;
int Game::defeat = 0;
//Подведение итогов игры
//См. более подробные комментарии в функции
void Game::GameResult()
{
    //Поскольку при новой итерации цикла объект уничтожается и создается заново
    //нужно использовать статические переменные victory и defeat
    while (isEnd)
    {
        //Определяем победу или поражение через переменную counterUserErrors
        if (counterUserErrors >= 6) {
            ShowDefeat(counterUserErrors);
            cout << "\n\n\t\t\t\t\t\t  ПОРАЖЕНИЕ";
            defeat++;
        }
        else { cout << "\n\n\t\t\t\t\t\t  ПОБЕДА"; victory++; }
        cout << "\n\n";
        for (int i{}; i < 120; i++) cout << '_';
        //Выводим статистику
        cout << "\n\n\t\tПОБЕДЫ: " << victory << "\t\t\t СТАТИСТИКА" << "\t\t\t  ПОРАЖЕНИЯ: " << defeat << "\n";
        for (int i{}; i < 120; i++) cout << '_';
        cout << "\n\n\n\t\t\t\t\t    Искомое слово: " << strHiddenWord;
            cout << "\n\n\n\t\t\t\t\t    Количество попыток: " << counterAttemps;
        cout << "\n\n\n\t\t\t\t\t    Буквы игрока: ";
        //Выводим все буквы из wrongLetters
        for (char a : wrongLetters)
            cout << a << ' ';
        //Выводим угаданные буквы из вектора showHiddenWord
        for (int i{}; i < showHiddenWord.size(); i++)
            if (showHiddenWord[i] != '_') cout << showHiddenWord[i] << ' ';
        //Выводим время из функции Time
        cout << "\n\n\n\t\t\t\t\t    Время: ";
        Time();
        cout << "\n\n\n";
        for (int i{}; i < 120; i++) cout << '_';
        //Выбор игрока:
        //1. Начать новую итерацию цикла (Новая игра)
        //2. Завершить программу (Выход)
        NewGameOrExit();
    }
}
