#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
sf::Vector2f cartesianToIsometric(sf::Vector3f cartesianCoord);
sf::Vector2f cartesianToIsometric(sf::Vector3i cartesianCoord);
sf::Vector3f isometricToCartesian(sf::Vector2f isometricCoord);
} // namespace simulation
