#include "MainMenu.h"
using namespace std;
//Возврат пути для получения доступа к файлу
string MainMenu::GetPath()
{
	return path;
}
//Возврат ключа для дешифровки слов из файла
int MainMenu::GetKey()
{
    return key;
}
//Вывод заставки главного меню
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
    cout << "\n\t\t\t    ||    [И] Игра      ||   [П] Правила    ||    [В] Выход     ||";
    cout << "\n\t\t\t    ||__________________||__________________||__________________||";
    cout << "\n\n\t\t\t\t\t\t\tВНИМАНИЕ!";
    cout << "\n    Ввод всех букв осуществляется в нижнем регистре.";
    cout << " Проверте, переключена ли ваша клавиатура на русскую раскладку.\n";
    cout << "\t\t\t\t\t\tПРОЧИТАЙТЕ ПРАВИЛА ЗАРАНЕЕ!\n";
}
//Вывод экрана с правилами и информацией об игровых режимах 
void MainMenu::ShowRules()
{
    system("cls");
    cout << "\n\t\t\t\t\t\t\tПРАВИЛА\n\n";
    cout << "\t\t\tЦель игры состоит в том, чтобы угадать случайно выбранное слово до того, \n\t\t\t\t\tкак человечек на виселице будет дорисован.";
    cout << "\n\n\t\t\tУгадайте букву, введя ее в консоль и нажав Enter. В случае ошибки количество";
    cout << "\n\t\t\t     жизней уменьшится, а на виселице появится часть тела человечка.";
    cout << "\n\n\t\t\tВ игре есть три уровня сложности - Простой, Средний и Трудный.\n";
    cout << "\n\n\t\t\tРежим сложности\t\tДлина слова";
    cout << "\n\n\t\t\tПростой\t\t\t4-6";
    cout << "\n\n\t\t\tСредний\t\t\t7-9";
    cout << "\n\n\t\t\tТрудный\t\t\t10-12";
    cout << "\n\n\t\t\tДоступные темы: Животные, Растения, Космос";
    cout << "\n\n\t\t\t\t\t\t __________________\n";
    cout << "\t\t\t\t\t\t||                ||\n";
    cout << "\t\t\t\t\t\t||   [Н] Назад    ||\n";
    cout << "\t\t\t\t\t\t||________________||\n";
}
//Вывод кнопок с информациях о тематических режимах
void MainMenu::ShowThemeButtons()
{
    cout << "\n\t\t     Выбор темы...";
    cout << "\n\t\t     ";
    for (int i{}; i < 80; i++) cout << "_";
    cout << "\n\t\t    ||\t\t        ||\t\t    ||\t\t        ||\t\t    ||";
    cout << "\n\t\t    ||   [Ж] Животные   ||   [Р] Растения   ||   [К] Космос     ||    [Н] Назад     ||";
    cout << "\n\t\t    ||__________________||__________________||__________________||__________________||";
    cout << "\n\n\t\t    >";
}
//Вывод кнопок с информацией о режимах сложности
void MainMenu::ShowDifficultyButtons()
{
    system("cls");
    cout << "\n\t\t     Выбор режима сложности...";
    cout << "\n\t\t     ";
    for (int i{}; i < 80; i++) cout << "_";
    cout << "\n\t\t    ||\t\t        ||\t\t    ||\t\t        ||\t\t    ||";
    cout << "\n\t\t    ||   [П] Простой    ||   [С] Средний    ||   [Т] Трудный    ||    [Н] Назад     ||";
    cout << "\n\t\t    ||__________________||__________________||__________________||__________________||";
    cout << "\n\n\t\t    >";
}
//Выбирая уровень сложности, игрок получает доступ к выбору темы
//Функция ChoiceTheme принимает выбор и, в зависимости от него, выбирает путь к нужному файлу
void MainMenu::ChoiceDifficulty()
{
    cin >> choice;
    switch (choice)
    {
    case 'п':
        ShowThemeButtons();
        ChoiceTheme("wordsFaunaEasy.txt", "wordsFloraEasy.txt", "wordsSpaceEasy.txt");
        break;
    case 'с':
        ShowThemeButtons();
        ChoiceTheme("wordsFaunaMedium.txt", "wordsFloraMedium.txt", "wordsSpaceMedium.txt");
        break;
    case 'т':
        ShowThemeButtons();
        ChoiceTheme("wordsFaunaHard.txt", "wordsFloraHard.txt", "wordsSpaceHard.txt");
        break;
    case 'н':
        //В случае выбора команды "НАЗАД" программа возвращается к главному меню
        isTheme = false;
        isMenu = true;
        system("cls");
        break;
    default:
        cout << "\n\t\t   Ошибка ввода";
        Sleep(1000);
        break;
    }
}
//Функция принимает три пути к файлам (слова из файлов относятся к одному режиму сложности) 
//При выборе темы программа переходит на игровой экран 
void MainMenu::ChoiceTheme(string path1, string path2, string path3)
{
    cin >> choice;
    switch (choice)
    {
    case 'ж':
        path = path1;
        key = 20;
        isMenu = false;
        isTheme = false;
        system("cls");
        break;
    case 'р':
        path = path2;
        key = 25;
        isMenu = false;
        isTheme = false;
        system("cls");
        break;
    case 'к':
        key = 10;
        path = path3;
        isMenu = false;
        isTheme = false;
        break;
    case 'н':
        //В случае выбора команды "НАЗАД" программа возвращается к выбору режима сложности
        system("cls");
        break;
    default:
        //В случае "ошибки ввода" программа возвращается к выбору режима сложности
        cout << "\n\t\t   Ошибка ввода";
        Sleep(1000);
        break;
    }
    system("cls");
}
//Главная функция меню (см. комментарии внутри функции)
void MainMenu::ShowMenu()
{
    while (isMenu)
    {
        choice = '0';
        //Вызываем главное меню
        ShowTitle();
        cout << "\n\t>";
        cin >> choice;
        switch (choice)
        {
        case 'и':
            //Переход к выбору режима сложности и тем 
            isMenu = false;
            isTheme = true;
            //Экран выбора режима перезагружается до тех пор пока:
            //1. Не будет выбрана тема
            //2. Пока игрок не вернется в главное меню
            //В случае выбора пункта 1 идет переход к игровому экрану из класса Game
            while (isTheme)
            {
                ShowDifficultyButtons();
                ChoiceDifficulty();
            }
            break;
        case 'п':
            //Переход на экран правил
            while (choice != 'н') {
                ShowRules();
                cout << "\n\t\t\t>";
                cin >> choice;
                //В случае ошибки экран перезагружается
                if (choice != 'н') {
                    cout << "\n\t\t\tОшибка ввода";
                    Sleep(1000);
                }
            }
            system("cls");
            break;
        case 'в':
            //Завершение программы
            cout << "\n\tВыход\n";
            Sleep(1000);
            exit(0);
            break;
        default:
            //В случае ошибки экран перезагружается
            cout << "\n\tОшибка ввода";
            Sleep(1000);
            system("cls");
            break;
        }
    }
}


