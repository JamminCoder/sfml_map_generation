#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture texture;
    sf::Sprite sprite;
    

    Tile(sf::Vector2f pos, sf::Vector2f size, const char* textureFile);

    void draw(sf::RenderWindow& window);
};