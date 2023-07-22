#include <SFML/Graphics.hpp>
#include "../headers/Map.hpp"
#include "../lib/Tile.cpp"
#include <string>


Map::Map(int h, int w) {
    this->height_px = h;
    this->width_px = w;
    this->tiles_y = h / 16;
    this->tiles_x = w / 16;

    this->map_blocks.loadFromFile("resources/map.png");
    std::string textureFile;

    for (int y = 0; y < this->tiles_y; y++) {
        std::vector<Tile> row;
        for (int x = 0; x < this->tiles_x; x++) {

            sf::Color color = this->map_blocks.getPixel(x, y);
            if (color.b == 255) {
                textureFile = "resources/water.png";
            } else if (color.r == 255) {
                textureFile = "resources/house.png";
            } else {
                textureFile = "resources/grass.png";
            }

            Tile tile(sf::Vector2f(x * 16, y * 16), sf::Vector2f(16, 16), textureFile.c_str());
            row.push_back(tile);
        }
        this->map.push_back(row);
    }
}

Tile& Map::get_tile(int x, int y) {
    return this->map[y][x];
}

void Map::draw(sf::RenderWindow& window) {
    for (int y = 0; y < this->tiles_y; y++) {
        for (int x = 0; x < this->tiles_x; x++) {
            Tile tile = this->get_tile(x, y);
            tile.draw(window);
        }
    }
}