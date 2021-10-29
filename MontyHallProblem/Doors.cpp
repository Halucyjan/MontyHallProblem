#include "Doors.h"
#include <cstdlib>
#include <iostream>

Doors::Doors()
{
    chosenOne = 0;
    winerNumber = 0;
    wins = 0;
    losers = 0;
    for (int i = 0; i < 3; i++)
    {
        tabOfDoors[i].open = false;
    }
}

void Doors::chose(int number)
{
    chosenOne = number;
}

void Doors::chose()
{
    chosenOne = (std::rand() % 3);
}
void Doors::choseRandom()
{
    chosenOne = (std::rand() % 3);
}
void Doors::change()
{
    for (int i = 0; i < 3; i++)
    {
        if (this->chosenOne != i)
        {
            if (!(this->tabOfDoors[i].open))
            {
                this->chosenOne = i;
                break;
            }
        }
    }
}
void Doors::open()
{
    int openDoor = 0;
    if (this->chosenOne == this->winerNumber)
    {
        while (openDoor == this->chosenOne)
        {
            openDoor = (std::rand() % 3);
        }
    }
    else
    {
        int sum = this->chosenOne + this->winerNumber;
        if (sum == 1)
        {
            openDoor = 2;
        }
        if (sum == 2)
        {
            openDoor = 1;
        }
        if (sum == 3)
        {
            openDoor = 0;
        }
    }
    this->tabOfDoors[openDoor].open = true;
}
void Doors::open(int n)
{
    tabOfDoors[n].open = 1;
}
void Doors::check()
{
    for (int i = 0; i < 3; i++)
    {
        tabOfDoors[i].open = 1;
    }
    if (chosenOne == winerNumber)
    {
        wins++;
        //std::cout << "wins ++: " << wins << ", losers: " << losers<< std::endl;
    }
    else
    {
        losers++;
        //std::cout << "wins: " << wins << ", losers ++: " << losers<< std::endl;
    }
}

void Doors::newGame()
{
    //std::cout << "wins: " << wins << ", losers: " << losers<< std::endl;
    chosenOne = 0;
    winerNumber = (std::rand() % 3);
    for (int i = 0; i < 3; i++)
    {
        tabOfDoors[i].open = false;

        if (winerNumber == i)
            tabOfDoors[i].prize = 1;
        else
            tabOfDoors[i].prize = 0;
    }
    // std::cout << "wins: " << wins << ", losers: " << losers<< std::endl;
}

void Doors::show()
{
    for (int i = 0; i < 3; i++)
    {
        if (tabOfDoors[i].open) //door is open
        {
            if (tabOfDoors[i].prize == 1)    //winer prize
                std::cout << "W ";
            else                            //losing prize
                std::cout << "L ";
        }
        else //door is close
        {
            if (i == chosenOne)
                std::cout << "X ";
            else
                std::cout << "H ";
        }
    }
    std::cout << std::endl;

}
void Doors::showScore()
{
    std::cout << "wins: " << wins << ", losers: " << losers << std::endl;
}
