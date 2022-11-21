#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
//См. комментарии к методам в файле MainMenu.cpp
class MainMenu {
private:
    char choice = '0';
    //Переменные для прерывания циклов работы экранов
    bool isMenu = true;
    bool isTheme = true;
    //Путь к файлу
    string path = " ";
    //Ключ для дешифровки слова из файла
    int key;
public:
    string GetPath();
    int GetKey();
    void ShowTitle();
    void ShowRules();
    void ShowThemeButtons();
    void ShowDifficultyButtons();
    void ChoiceDifficulty();
    void ChoiceTheme(string path1, string path2, string path3);
    void ShowMenu();
};

