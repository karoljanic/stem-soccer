#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
static sf::Vector2f cartesianToIsometric(sf::Vector2f cartesianCoord);
static sf::Vector2f isometricToCartesian(sf::Vector2f isometricCoord);
} // namespace simulation
