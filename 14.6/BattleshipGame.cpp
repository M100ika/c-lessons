#include "BattleshipGame.h"
#include <iostream>


using namespace std;

void initializeField(Field& field) {
    field = Field(FIELD_SIZE, vector<bool>(FIELD_SIZE, false));
}

void setupShips(Field& field) {
    for (int i = 0; i < 4; i++) {
        int x, y;
        cout << "Введите координаты для одноклеточного корабля (формат: x y): ";
        cin >> x >> y;
        Ship ship = {1, x, y, x, y};
        while (!placeShip(field, ship)) {
            cout << "Неверные координаты или клетка уже занята. Попробуйте снова: ";
            cin >> x >> y;
            ship = {1, x, y, x, y};
        }
    }
}

void printField(const Field& field) {
    cout << "  ";
    for (int i = 0; i < FIELD_SIZE; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < FIELD_SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < FIELD_SIZE; ++j) {
            cout << (field[i][j] ? 'o' : '.') << " ";
        }
        cout << endl;
    }
}

bool placeShip(Field& field, Ship& ship) {
    if (!isValidPosition(field, ship)) {
        return false;
    }
    setShip(field, ship, true);
    return true;
}

bool shoot(Field& field, int x, int y) {
    if (x < 0 || x >= FIELD_SIZE || y < 0 || y >= FIELD_SIZE) {
        cout << "Координаты выстрела вне поля." << endl;
        return false;
    }
    if (field[x][y]) {
        field[x][y] = false;  
        cout << "Попадание!" << endl;
        return true;
    } else {
        cout << "Мимо!" << endl;
        return false;
    }
}

bool areShipsRemaining(const Field& field) {
    for (int i = 0; i < FIELD_SIZE; ++i) {
        for (int j = 0; j < FIELD_SIZE; ++j) {
            if (field[i][j]) return true;
        }
    }
    return false;
}

bool isValidPosition(const Field& field, Ship& ship) {
    if (ship.x1 < 0 || ship.x2 >= FIELD_SIZE || ship.y1 < 0 || ship.y2 >= FIELD_SIZE) {
        return false; 
    }

    if (ship.x1 != ship.x2 && ship.y1 != ship.y2) {
        return false; 
    }

 
    for (int i = min(ship.x1, ship.x2); i <= max(ship.x1, ship.x2); ++i) {
        for (int j = min(ship.y1, ship.y2); j <= max(ship.y1, ship.y2); ++j) {
            if (field[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void setShip(Field& field, Ship& ship, bool status) {
    for (int i = min(ship.x1, ship.x2); i <= max(ship.x1, ship.x2); ++i) {
        for (int j = min(ship.y1, ship.y2); j <= max(ship.y1, ship.y2); ++j) {
            field[i][j] = status;
        }
    }
}
