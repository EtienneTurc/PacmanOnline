#include <iostream>
#include "grid.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    unsigned int getScore();
    std::string getStatus();
    void updateScore(unsigned int new_score);
    void updateStatus(std::string new_status);
    Game();
    ~Game() {};

private:
    unsigned int _score;
    std::string _status;
};


#endif //GAME_H
