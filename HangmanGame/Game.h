#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>
#include "MainMenu.h"
//См. комментарии к методам в файле Game.cpp
class Game
{
private:
    //Создаем объект класса MainMenu для вызова его функций
    MainMenu menu;
    //Создаем объект структуры steady_clock из библиотеки chrono 
    //(библиотека ctime считается устаревшей и не такой точной как chrono)
    chrono::steady_clock sc;
    //Создаем объект класса ifstream для считывания данных из файла
    ifstream fin;
    //Переменная для записи слова из вектора words
    string str;
    //Символ вводимый пользователем
    char userLetter{ '0' };
    //Индекс загаданного слова из вектора words
    int  randWordNumber{};
    //Счетчик угаданных букв
    int  counterOfGuessedLetters{};
    //Счетчик ошибок
    int  counterUserErrors{};
    //Счетчик попыток
    int  counterAttemps{};
    //Счетчик жизней
    int  livesLeft{ 6 };
    //Переменные времени
    int  timeGameSec{};
    int  timeGameMin{};
    int  timeGameHour{};
    //Индекс угаданной буквы
    int  index{};
    //Переменная для цикла конца игры
    bool isEnd{true};
    //Загаданное слово
    string strHiddenWord;
    //Вектор содержащий все слова из файла
    vector <string> words;
    //Вектор содержащий символы загаданного слова
    vector <char> hiddenWord;
    //Вектор для отображения загаданного слова в процессе игры
    vector <char> showHiddenWord;
    //Set для ошибочных букв
    set <char> wrongLetters;
    //итератор (умный указатель) для работы с вектором hiddenWord 
    //(конкретно для функции erase)
    vector <char>::iterator itErase;
    //Переменные для счета побед и поражений 
    static int defeat;
    static int victory;
public:
    void ShowMainMenu();
    void ReadFile();
    void Decryption();
    void ChoiceHiddenWord();
    void ShowHangman(int  counterUserErrors);
    void ShowInterface();
    void GamePlay();
    void Time();
    void ShowDefeat(int  errors);
    void NewGameOrExit();
    void GameResult();
};

