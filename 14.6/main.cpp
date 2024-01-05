#include "BattleshipGame.h"
#include <iostream>
#include <vector>
#include <locale>
#include "Texts.h"
#include <thread>
#include <chrono>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Field field_1, field_2;
    initializeField(field_1);
    initializeField(field_2);

    printWithDelay(Texts::welcome, 10);

    cout << "Игрок 1, расставляете свои корабли." << endl;
    setupShips(field_1);
    cout << "Игрок 2, расставляете свои корабли." << endl;
    setupShips(field_2);

    bool turn = true;
    while (areShipsRemaining(field_1) && areShipsRemaining(field_2)) {
        cout << "Игрок " << (turn ? "1" : "2") << ", ваш ход." << endl;
        int x, y;
        cout << "Введите координаты для выстрела (формат: x y): ";
        cin >> x >> y;
        
        if (turn) {
            if (shoot(field_2, x, y)) {
                printField(field_2);  // Показать обновленное поле после выстрела
                if (!areShipsRemaining(field_2)) {
                    cout << "Игрок 1 победил!" << endl;
                    break;
                }
            }
        } else {
            if (shoot(field_1, x, y)) {
                printField(field_1);  // Показать обновленное поле после выстрела
                if (!areShipsRemaining(field_1)) {
                    cout << "Игрок 2 победил!" << endl;
                    break;
                }
            }
        }
        turn = !turn;
    }

    return 0;
}
