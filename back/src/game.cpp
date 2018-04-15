#include "game.h"

unsigned int Game::getScore() {
    return _score;
}

std::string Game::getStatus() {
    return _status;
}

void Game::updateScore(unsigned int new_score) {
    _score = new_score;
}

void Game::updateStatus(std::string new_status) {
    _status = new_status;
}

Game::Game() {
    _score = 0;
    _status = "Initialization";
}