#include <iostream>
#include <windows.h> //Подключаем библиотеку Winmm.lib для доступа к функции PlaySound
#include "Game.h"

int main()
{    
    //Задаем консоли определенный размер
    //Не надо менять размер консоли, иначе может поплыть интерфейс
    system("mode con cols=120 lines=31");
    srand(time(0));
    //Подключаем возможность ввода и вывода русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Цикл игры
    //Прерывание см. в классе Game
    while (true) {
        Game game;
        //Вызываем функцию для проигрывания музыки и зацикливаем
        PlaySound(TEXT("449359103103a80.wav"), NULL, SND_ASYNC | SND_LOOP);
        game.ShowMainMenu();
        PlaySound(TEXT("f731b15834e3dd5.wav"), NULL, SND_ASYNC | SND_LOOP);
        game.GamePlay();
        PlaySound(TEXT("81cebf7e45fdef7.wav"), NULL, SND_ASYNC | SND_LOOP);
        game.GameResult();
    }
}


