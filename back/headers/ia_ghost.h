#ifndef IA_GHOST_H
#define IA_GHOST_H

#include <cstdlib>
#include <algorithm>

#include "ghost.h"
#include "pacman.h"
#include "virtual_ghost.h"
#include "grid.h"

int lowestDirection(Pacman pacman, Ghost ghost);

int randomDirection(Entity entity);

#endif
