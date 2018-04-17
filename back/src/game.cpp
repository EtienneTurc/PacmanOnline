#include "game.h"

Game::Game()
{
    _score = 0;
    _ghosts_status = ATTACK;
    std::vector<Pacman> _pacmans;
    std::vector<Ghost> _ghosts;
    Grid _grid;
}

unsigned int Game::getScore() {
    return _score;
}

int Game::getGhostsStatus() {
    return _ghosts_status;
}

void Game::updateScore(unsigned int new_score) {
    _score = new_score;
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

