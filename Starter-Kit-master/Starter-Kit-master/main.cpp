// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT8L 
// Names: ARMAN HAZIQ BIN ZULKARNAIN | ADAM UZAIR BIN MOHD SORI
// IDs: 1201103668 | 1211101120  
// Emails: 1201103668@student.mmu.edu.my | 1211101120@student.mmu.edu.my  
// Phones: 0163256635 | 01158455813
// ********************************************************* 


#include "pf/helper.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Alien
{
private:
    int life_;
    int attack_;

public:
    Alien() : life_(100), attack_(0) {}

    int getLife() const
    {
        return life_;
    }

    void setLife(int life)
    {
        if (life > 100)
        {
            life_ = 100;
        }
        else
        {
            life_ = life;
        }
    }

    int getAttack() const
    {
        return attack_;
    }

    void setAttack(int attack)
    {
        attack_ = attack;
    }
};

class Board
{
private:
    vector<vector<char>> map_;
    int dimX_, dimY_;
    int numZ;
    int alienX_;
    int alienY_;
    int width_;
    int height_;
    Alien alien_;

public:
    Board(int dimX = 15, int dimY = 5, int numZ = 1);
    void init(int dimX, int dimY, int numZ);
    void display() const;
    void moveAlienUp();
    void moveAlienRight();
    void moveAlienLeft();
    void moveAlienDown();
    void findAlien(int &x, int &y) const;
    void displayStats() const;
    char getObject(int x, int y) const;
    char setObject(int x, int y, char ch);
    void location(int dimX, int dimY, int numZ);
};

void Board::displayStats() const
{
    cout << "                            " << endl;
    cout << "Alien   : "
         << "Life  " << alien_.getLife() << ", Attack  " << alien_.getAttack() << endl;
    cout << "                            " << endl;
}

Board::Board(int dimX, int dimY, int numZ)
{
    init(dimX, dimY, numZ);
    dimX_ = dimX;
    dimY_ = dimY;
}

char Board::getObject(int x, int y) const
{
    return map_[dimY_ - y][x - 1];
}
char Board::setObject(int x, int y, char ch)
{
    return map_[dimY_ - y][x - 1] = ch;
}

void Board::moveAlienUp()
{
    int width_ = map_[0].size();
    int height_ = map_.size();
    int alienX, alienY;
    findAlien(alienX, alienY);

    while (alienY > 0 && map_[alienY - 1][alienX] != 'Z')
    {
        char obj = map_[alienY - 1][alienX];
        map_[alienY][alienX] = '.';
        alienY--;
        map_[alienY][alienX] = 'A';
        if (obj == '^')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienUp();
            return;
        }
        else if (obj == '>')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienRight();
            return;
        }
        else if (obj == '<')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienLeft();
            return;
        }
        else if (obj == 'v')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienDown();
            return;
        }
        else if (obj == 'h')
        {
            alien_.setLife(alien_.getLife() + 20);
            cout << "Alien receive 20 Life" << endl;
        }
    }
}

void Board::moveAlienRight()
{
    int width_ = map_[0].size();
    int height_ = map_.size();
    int alienX, alienY;
    findAlien(alienX, alienY);

    while (alienX < width_ - 1 && map_[alienY][alienX + 1] != 'Z')
    {
        char obj = map_[alienY][alienX + 1];
        map_[alienY][alienX] = '.';
        alienX++;
        map_[alienY][alienX] = 'A';
        if (obj == '^')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienUp();
            return;
        }
        else if (obj == '>')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienRight();
            return;
        }
        else if (obj == '<')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienLeft();
            return;
        }
        else if (obj == 'v')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienDown();
            return;
        }
        else if (obj == 'h')
        {
            alien_.setLife(alien_.getLife() + 20);
            cout << "Alien receive 20 Life" << endl;
        }
        else if (obj == 'r')
        {
            srand(time(NULL));
            int buff = rand() % 5;

            switch (buff)
            {
            case 0:
                alien_.setAttack(alien_.getAttack() + 20);
                cout << "Alien received attack buff (^)" << endl;
                break;
            case 1:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienRight();
                cout << "Alien received attack buff (>)" << endl;
                break;
            case 2:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienLeft();
                cout << "Alien received attack buff (<)" << endl;
                break;
            case 3:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienDown();
                cout << "Alien received attack buff (v)" << endl;
                break;
            case 4:
                alien_.setLife(alien_.getLife() + 20);
                cout << "Alien received life buff (h)" << endl;
                break;
            }
        }
    }
}

void Board::moveAlienLeft()
{
    int width_ = map_[0].size();
    int height_ = map_.size();
    int alienX, alienY;
    findAlien(alienX, alienY);

    while (alienX > 0 && map_[alienY][alienX - 1] != 'Z')
    {
        char obj = map_[alienY][alienX - 1];
        map_[alienY][alienX] = '.';
        alienX--;
        map_[alienY][alienX] = 'A';
        if (obj == '^')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienUp();
            return;
        }
        else if (obj == '>')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienRight();
            return;
        }
        else if (obj == '<')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienLeft();
            return;
        }
        else if (obj == 'v')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienDown();
            return;
        }
        else if (obj == 'h')
        {
            alien_.setLife(alien_.getLife() + 20);
            cout << "Alien receive 20 Life" << endl;
        }
        else if (obj == 'r')
        {
            srand(time(NULL));
            int buff = rand() % 5;

            switch (buff)
            {
            case 0:
                alien_.setAttack(alien_.getAttack() + 20);
                cout << "Alien received attack buff (^)" << endl;
                break;
            case 1:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienRight();
                cout << "Alien received attack buff (>)" << endl;
                break;
            case 2:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienLeft();
                cout << "Alien received attack buff (<)" << endl;
                break;
            case 3:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienDown();
                cout << "Alien received attack buff (v)" << endl;
                break;
            case 4:
                alien_.setLife(alien_.getLife() + 20);
                cout << "Alien received life buff (h)" << endl;
                break;
            }
        }
    }
}

void Board::moveAlienDown()
{
    int width_ = map_[0].size();
    int height_ = map_.size();
    int alienX, alienY;
    findAlien(alienX, alienY);

    while (alienY < height_ - 1 && map_[alienY + 1][alienX] != 'Z')
    {
        char obj = map_[alienY + 1][alienX];
        map_[alienY][alienX] = '.';
        alienY++;
        map_[alienY][alienX] = 'A';
        if (obj == '^')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienUp();
            return;
        }
        else if (obj == '>')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienRight();
            return;
        }
        else if (obj == '<')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienLeft();
            return;
        }
        else if (obj == 'v')
        {
            alien_.setAttack(alien_.getAttack() + 20);
            moveAlienDown();
            return;
        }
        else if (obj == 'h')
        {
            alien_.setLife(alien_.getLife() + 20);
            cout << "Alien receive 20 Life" << endl;
        }
        else if (obj == 'r')
        {
            srand(time(NULL));
            int buff = rand() % 5;

            switch (buff)
            {
            case 0:
                alien_.setAttack(alien_.getAttack() + 20);
                cout << "Alien received attack buff (^)" << endl;
                break;
            case 1:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienRight();
                cout << "Alien received attack buff (>)" << endl;
                break;
            case 2:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienLeft();
                cout << "Alien received attack buff (<)" << endl;
                break;
            case 3:
                alien_.setAttack(alien_.getAttack() + 20);
                moveAlienDown();
                cout << "Alien received attack buff (v)" << endl;
                break;
            case 4:
                alien_.setLife(alien_.getLife() + 20);
                cout << "Alien received life buff (h)" << endl;
                break;
            }
        }
    }
}

void Board::findAlien(int &x, int &y) const
{
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            if (map_[i][j] == 'A')
            {
                x = j;
                y = i;
                return;
            }
        }
    }
}

void help()
{
    cout << "List of available commands:" << endl;
    cout << "u - move alien up" << endl;
    cout << "d - move alien down" << endl;
    cout << "l - move alien left" << endl;
    cout << "r - move alien right" << endl;
    cout << "h - display this help menu" << endl;
    cout << "q - quit game" << endl;
    cout << endl;
}

void Board::init(int dimX, int dimY, int numZ)
{
    char objects[] = {'^', '>', '<', 'v', 'h', 'p', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int noOfObjects = 14;

    dimX_ = dimX;
    dimY_ = dimY;

    map_.resize(dimY_);
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_);
    }

    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }

    srand(time(0));
    while (numZ > 0)
    {
        int x = rand() % dimX_;
        int y = rand() % dimY_;
        if (map_[y][x] == ' ')
        {
            map_[y][x] = 'Z';
            numZ--;
        }
    }
    int centerX = dimX_ / 2;
    int centerY = dimY_ / 2;
    map_[centerY][centerX] = 'A';
}

void Board::display() const
{
    cout << " --------------------------------" << endl;
    cout << " =       Alien VS Zombie        =" << endl;
    cout << " --------------------------------" << endl;

    for (int i = 0; i < dimY_; ++i)
    {
        for (int r = 0; r < 1; r++)
        {
            cout << " ";
        }
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY_ - i);
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    cout << " ";
    for (int r = 0; r < 1; r++)
    {
        cout << " ";
    }
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    for (int r = 0; r < 1; r++)
    {
        cout << " ";
    }
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int r = 0; r < 1; r++)
    {
        cout << " ";
    }
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << "             " << endl;
    displayStats();
    cout << "             " << endl;
    cout << endl
         << endl;
}

void Board::location(int dimX, int dimY, int numZ)
{

    Board game(dimX, dimY);
    game.display();

    cout << " " << endl;
    int x, y;
    char obj;
    cout << "Please input column: " << endl;
    cin >> x;
    cout << "Please input row : " << endl;
    cin >> y;
    obj = game.getObject(x, y);

    cout << "Object at column " << x << " and row " << y << " is [" << obj << "]" << endl;
    cout << "Enter a new command: " << endl;
    cin >> obj;

    game.setObject(x, y, obj);
    game.display();
}

int main()
{
    int dimX, dimY, numZ;
    cout << "             Default Game Settings                " << endl;
    cout << "Board Rows      : 15                              " << endl;
    cout << "Board Columns   : 5                               " << endl;
    cout << "                                                  " << endl;
    goto a;
a:
    cout << "Do you want to customise the game settings? (1=yes, 0=no)" << endl;
    cin >> dimX;
    if (dimX == 1)
    {
        cout << "             Board Settings   " << endl;
        cout << "Enter custom gameboard width: ";
        cin >> dimX;
        cout << "Enter custom gameboard height: ";
        cin >> dimY;
    }
    else if (dimX == 0)
    {
        dimX = 15;
        dimY = 5;
        numZ = 1;
    }
    else
    {
        cout << "Invalid Output" << endl;
        goto a;
    }

    Board game(dimX, dimY);
    game.init(dimX, dimY, numZ);
    game.display();
    char command;
    while (true)
    {
        cout << "Command: ";
        cin >> command;

        if (command == 'h')
        {
            help();
            continue;
        }
        else if (command == 'q')
        {
            cout << "                                   " << endl;
            cout << "Are you sure that you want to quit?" << endl;
            cout << "                                   " << endl;
            break; 
        }
        else if (command == 'u')
        {
            game.moveAlienUp();
            system("pause");
        }
        else if (command == 'd')
        {
            game.moveAlienDown();
            system("pause");
        }
        else if (command == 'l')
        {
            game.moveAlienLeft();
            system("pause");
        }
        else if (command == 'r')
        {
            game.moveAlienRight();
            system("pause");
        }
        else if (command == 'c')
        {
            game.location(dimX, dimY, numZ);
            system("pause");
        }

        else
        {
            cout << "Invalid command. Please try again." << endl;
            system("pause");
        }

        game.display();
    }

    return 0;
}
