#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "parameters.h"

class Game
{
public:
    unsigned int getScore();
    int getGhostsStatus();
    void updateScore(unsigned int new_score);
    void updateGhostsStatus(int new_ghosts_status);
    Game();
    ~Game() {};

private:
    unsigned int _score;
    int _ghosts_status;
};

#endif 
