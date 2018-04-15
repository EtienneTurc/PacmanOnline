#include <iostream>
#include "entity.h"

int main(int argc, char const *argv[])
{
    Entity entity(4, 5, 'L', 1, 3);
    std::cout << "Xposition " << int(entity.getXPosition()) << '\n';
    std::cout << "Yposition " << int(entity.getYPosition()) << '\n';
    std::cout << "Direction " << entity.getDirection() << '\n';
    std::cout << "Speed " << int(entity.getSpeed()) << '\n';
    std::cout << "Subsection " << int(entity.getSubsection()) << '\n';
    entity.updateDirection('R');
    std::cout << "New Direction " << entity.getDirection() << '\n';

    return 0;
}
