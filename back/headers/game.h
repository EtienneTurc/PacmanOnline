#ifndef GAME_H
#define GAME_H

#include <vector>

#include "grid.h"
#include "parameters.h"
#include "entity.h"
#include "ghost.h"
#include "pacman.h"

class Game
{
public:
    unsigned int getScore();
    int getGhostsStatus();
    std::vector<Pacman> getPacmans();
    std::vector<Ghost> getGhosts();
    void updateScore(unsigned int new_score);
    void updateGhostsStatus(int new_ghosts_status);
    void addGhost(Ghost new_ghost);
    void addPacman(Pacman new_pacman);
    void init();
    void run();
    Game();
    ~Game() {};

private:
    unsigned int _score;
    int _ghosts_status;
    std::vector<Pacman> _pacmans;
    std::vector<Ghost> _ghosts;
    Grid* _grid;
};

#endif 
