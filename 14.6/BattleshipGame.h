#ifndef BATTLESHIPGAME_H
#define BATTLESHIPGAME_H

#include <vector>
#include <string>

const int FIELD_SIZE = 10;

typedef std::vector<std::vector<bool>> Field;
struct Ship {
    int size;
    int x1, y1, x2, y2;
};

void initializeField(Field& field);
void printField(const Field& field);
bool placeShip(Field& field, Ship& ship);
bool shoot(Field& field, int x, int y);
bool areShipsRemaining(const Field& field);
bool isValidPosition(const Field& field, Ship& ship);
void setShip(Field& field, Ship& ship, bool status);
void setupShips(Field& field);

#endif
