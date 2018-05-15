#ifndef IA_GHOST_H
#define IA_GHOST_H

#include <cstdlib>
#include <algorithm>

#include "ghost.h"
#include "pacman.h"
#include "virtual_ghost.h"
#include "grid.h"

int lowestDirection(Pacman pacman, Ghost ghost, int ranking = 0);

int randomDirection(Entity entity);

int lowestDirectionToIntersection(Pacman pacman, Ghost ghost);

#endif
