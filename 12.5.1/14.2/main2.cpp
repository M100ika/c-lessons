#include <chrono>
#include <iostream>
#include <locale>
#include <thread>
#include <vector>

using namespace std;

void printWithDelay(const string &text, unsigned int delay_ms) {
  for (char c : text) {
    cout << c << flush;
    this_thread::sleep_for(chrono::milliseconds(delay_ms));
  }
}

void language(const string &text) {
  int lang;
  while (true) {
    cin >> lang;
    if (lang == 1) {
      printWithDelay(text, 10);
      cout << endl;
      break;
    } else if (lang == 2) {
      cout << "У создателя пока не получилось разобраться с русским языком. "
              "Играй на английском))\n"
           << endl;
      printWithDelay("The creator has not yet managed to figure out the "
                     "Russian language. Play in English))",
                     10);
      printWithDelay(text, 10);
      break;
    } else
      cout << "Invalid language number. Try again.\nНеверный номер языка. "
              "Попробуй еще раз."
           << endl;
  }
}

void printBattleField(const char board[3][3]) {
  cout << "     1   2   3\n";
  for (int i = 0; i < 3; i++) {
    cout << "   -------------\n";
    cout << i + 1 << "  | ";
    for (int j = 0; j < 3; j++) {
      cout << board[i][j];
      if (j < 2)
        cout << " | ";
    }
    cout << " |\n";
  }
  cout << "   -------------\n";
}

int checkCin() {
  int number;
  while (true) {
    cin >> number;
    if (cin.fail()) {
      cin.clear();
      while (cin.get() != '\n') {
      }
      cout << "Invalid input. Please enter a fractrional number." << endl;
    } else {
      while (cin.get() != '\n') {
      }
      return number;
    }
  }
}

bool checkWin(const char game[3][3], char player) {
  for (int i = 0; i < 3; i++) {
    if (game[i][0] == player && game[i][1] == player && game[i][2] == player)
      return true;
    if (game[0][i] == player && game[1][i] == player && game[2][i] == player)
      return true;
  }
  return false;
}

int main() {
  setlocale(LC_ALL, "Russian");
  cout << "Task 14.2!\n";
  char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  int moveCount = 0;
  char currentPlayer = 'X';

  string text_ru =
      "### Правила Игры в Крестики-Нолики: Весёлая Версия \n\n"
      "Цель игры: Стать королём или королевой крестиков и ноликов, путём "
      "выстраивания трёх своих символов в ряд!\n\n"
      "#### Основы:\n"
      "1. Поле для битвы: Игра происходит на магическом поле 3x3, где каждая "
      "клетка - это волшебный портал в другую реальность. Но пока что это "
      "просто клетка.\n"
      "2. Игроки: Двое смельчаков (может быть ты и твой кот?).\n"
      "3. Оружие выбора: Один выбирает могущественные крестики (X), другой - "
      "загадочные нолики (O).\n\n"
      "#### Правила Хода:\n"
      "1. Координаты для магии: Каждый ход - это заклинание. Чтобы его "
      "сотворить, используй координаты от [0-2] для строк и [0-2] для "
      "столбцов. Например, \"1, 2\" - это как волшебное слово, перемещающее "
      "твой символ в центр правого столбца.\n"
      "2. По очереди кастуете заклинания: Сначала один игрок кричит свои "
      "магические координаты, затем другой. Никаких подсказок от волшебных "
      "существ!\n\n"
      "#### Как Выиграть:\n"
      "1. Три в ряд - и ты магистр: Выстроить три своих символа горизонтально "
      "или вертикально. Это как собрать три одинаковых кристалла мощи.\n"
      "2. Блокируй соперника: Если видишь, что соперник собирается создать ряд "
      "из трёх, используй своё заклинание, чтобы поместить свой символ на его "
      "пути. Это как \"Абракадабра, ты не пройдёшь!\"\n\n"
      "#### Если Ничья:\n"
      "1. Мирное сосуществование: Если все клетки заполнены, но никто не "
      "собрал трех в ряд, поздравляем, вы оба магистры компромиссов!\n\n"
      "#### И Наконец:\n"
      "- Веселье превыше всего: Помните, главное - не победа, а хорошо "
      "проведённое время и весёлые заклинания!";

  string text_en =
      "### Tic-Tac-Toe Rules: The Fun Version \n\n"
      "Objective: Become the king or queen of crosses and noughts by aligning "
      "three of your symbols in a row!\n\n"
      "#### Basics:\n"
      "1. Battlefield: The game takes place on a magical 3x3 grid where each "
      "square is a portal to another reality. But for now, it's just a "
      "square.\n"
      "2. Players: Two brave souls (maybe you and your cat?).\n"
      "3. Weapon of Choice: One chooses mighty crosses (X), the other "
      "enigmatic noughts (O).\n\n"
      "#### How to Play::\n"
      "1. Coordinates for Magic: Each move is a spell. To cast it, use "
      "coordinates from 1-3 for rows and 1-3 for columns. For example, \"1, "
      "2\" is like a magic word that teleports your symbol to the center of "
      "the right column.\n"
      "2. Taking Turns Casting Spells: First, one player shouts their magical "
      "coordinates, then the other. No hints from magical creatures!\n\n"
      "#### How to Win::\n"
      "1. Three in a Row - You're a Master: Line up three of your symbols "
      "horizontally or vertically. It's like gathering three identical power "
      "crystals.\n"
      "2. Block Your Opponent: If you see that your opponent is about to "
      "create a row of three, cast your spell to place your symbol in their "
      "path. It's like saying \"Abracadabra, you shall not pass!\"\"\n\n"
      "#### In Case of a Draw:\n"
      "1. Peaceful Coexistence: If all the squares are filled, but no one has "
      "formed a row of three, congratulations, you both are masters of "
      "compromise!\n\n"
      "#### And Finally:\n"
      "- Fun Above All: Remember, the main thing is not winning, but having a "
      "good time and casting fun spells!";

  cout << "Please choose language: \n1. English\n2. Русский\n";
  language(text_en);

  while (moveCount < 9) {
    cout << "\n\nBattlefield: " << endl;
    printBattleField(game);
    cout << "Player " << currentPlayer << "'s move. Enter coordinates: \n";
    int row, col;
    row = checkCin();
    col = checkCin();
    if (row < 1 || row > 3 || col < 1 || col > 3 ||
        game[row - 1][col - 1] != ' ') {
      cout << "Invalid coordinates. Try again." << endl;
      continue;
    }
    game[row - 1][col - 1] = currentPlayer;
    moveCount++;

    if (checkWin(game, currentPlayer)) {
      printBattleField(game);
      cout << "Player " << currentPlayer << " wins!" << endl;
      return 0;
    }
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }
  printBattleField(game);
  cout << "Draw!" << endl;
  return 0;
}