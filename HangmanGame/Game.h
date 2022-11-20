#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>
#include "MainMenu.h"
//��. ����������� � ������� � ����� Game.cpp
class Game
{
private:
    //������� ������ ������ MainMenu ��� ������ ��� �������
    MainMenu menu;
    //������� ������ ��������� steady_clock �� ���������� chrono 
    //(���������� ctime ��������� ���������� � �� ����� ������ ��� chrono)
    chrono::steady_clock sc;
    //������� ������ ������ ifstream ��� ���������� ������ �� �����
    ifstream fin;
    //���������� ��� ������ ����� �� ������� words
    string str;
    //������ �������� �������������
    char userLetter{ '0' };
    //������ ����������� ����� �� ������� words
    int  randWordNumber{};
    //������� ��������� ����
    int  counterOfGuessedLetters{};
    //������� ������
    int  counterUserErrors{};
    //������� �������
    int  counterAttemps{};
    //������� ������
    int  livesLeft{ 6 };
    //���������� �������
    int  timeGameSec{};
    int  timeGameMin{};
    int  timeGameHour{};
    //������ ��������� �����
    int  index{};
    //���������� ��� ����� ����� ����
    bool isEnd{true};
    //���������� �����
    string strHiddenWord;
    //������ ���������� ��� ����� �� �����
    vector <string> words;
    //������ ���������� ������� ����������� �����
    vector <char> hiddenWord;
    //������ ��� ����������� ����������� ����� � �������� ����
    vector <char> showHiddenWord;
    //Set ��� ��������� ����
    set <char> wrongLetters;
    //�������� (����� ���������) ��� ������ � �������� hiddenWord 
    //(��������� ��� ������� erase)
    vector <char>::iterator itErase;
    //���������� ��� ����� ����� � ��������� 
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

