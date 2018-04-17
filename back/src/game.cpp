#include "game.h"

Game::Game()
{
    _ghosts_status = ATTACK;
    std::vector<Pacman> _pacmans;
    std::vector<Ghost> _ghosts;
    Grid* _grid; //Grid constructor fills the grid
}

int Game::getGhostsStatus() {
    return _ghosts_status;
}

void Game::updateGhostsStatus(int new_ghosts_status) {
    _ghosts_status = new_ghosts_status;
}

std::vector<Pacman> Game::getPacmans() 
{
    return _pacmans;    
}

std::vector<Ghost> Game::getGhosts()
{
    return _ghosts;
}

void Game::addGhost(Ghost new_ghost)
{
    _ghosts.push_back(new_ghost);
}

void Game::addPacman(Pacman new_pacman)
{
    _pacmans.push_back(new_pacman);
}

