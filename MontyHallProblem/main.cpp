#include <iostream>
#include <ctime>
#include "Doors.h"

//using namespace std;
#define dla for
int main()
{
    srand(time(NULL));

    Doors game0;
    dla(int i = 0; i < 1000; i++) {
        game0.newGame();
        game0.chose();
        //game0.show();
        game0.open();
        //game0.show();

        game0.change();

        //game0.show();
        game0.check();
        //game0.show();
        //game0.showScore();
        //std::cout << std::endl;
    }
    game0.showScore();
    return 0;
}
