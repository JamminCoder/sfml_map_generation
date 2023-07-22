#include "../headers/Tile.hpp"
#include <iostream>

Tile::Tile(sf::Vector2f pos, sf::Vector2f size, const char* textureFile) {
    this->position = pos;
    this->size = size;
    this->sprite.setPosition(position);
    this->texture = sf::Texture();
    this->texture.loadFromFile(textureFile);
    this->sprite.setTexture(texture);
}


void Tile::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

