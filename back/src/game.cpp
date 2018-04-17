#include "game.h"

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

Game::Game() {
    _score = 0;
    _ghosts_status = ATTACK;
}