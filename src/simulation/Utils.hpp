#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
sf::Vector2f cartesianToIsometric(sf::Vector3i cartesianCoord);
sf::Vector3i isometricToCartesian(sf::Vector2f isometricCoord);
} // namespace simulation
