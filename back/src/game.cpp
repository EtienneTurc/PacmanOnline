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

void Game::displayEntities()
{
    for(int p = 0; p < _pacmans.size(); p++)
    {
        _grid->setCell(_pacmans[p].getXPosition(), _pancmans[p].getYPosition(), 9);
    }

    std::vector<int> ghosts_cells;
    for(int g = 0; g < _ghosts[g]; g++)
    {
        ghosts_cells.push_back(_grid->getCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition()));
        _grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), 8);
    }
    
    _grid->displayGrid();

    for (int p = 0; p < _pacmans.size(); p++)
    {
        _grid->setCell(_pacmans[p].getXPosition(), _pancmans[p].getYPosition(), 1);
    }

    for (int g = 0; g < _ghosts[g]; g++)
    {
        _grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), ghosts_cells[g]);
    }
}

