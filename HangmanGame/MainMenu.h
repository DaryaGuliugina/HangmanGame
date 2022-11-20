#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
//��. ����������� � ������� � ����� MainMenu.cpp
class MainMenu {
private:
    char choice = '0';
    //���������� ��� ���������� ������ ������ �������
    bool isMenu = true;
    bool isTheme = true;
    //���� � �����
    string path = " ";
    //���� ��� ���������� ����� �� �����
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

