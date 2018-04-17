#include "game.h"

void Game::run()
{
    for(int i = 0; i < 10; i++)
    {
        for(int p = 0; p < _pacmans.size(); p++)
        {
            _pacmans[p].move(1);
        }

        for (int p = 0; p < _ghosts.size(); p++)
        {
            _ghosts[p].move(1);
        }

        displayEntities();
        std::cout << "Loop number " << i << "\n";
    }
    
}