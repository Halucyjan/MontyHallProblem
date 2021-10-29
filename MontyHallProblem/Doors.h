#pragma once

struct door
{
    bool open;
    int prize;
};

class Doors
{
public:
    Doors();
    void chose(int);
    void chose();
    void choseRandom();
    void change();
    void open();
    void open(int);
    void check();
    void newGame();
    void show();
    void showScore();


protected:

private:
    int chosenOne;
    int winerNumber;
    door tabOfDoors[3];
    int wins, losers;
};

