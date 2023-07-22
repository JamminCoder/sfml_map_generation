#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include <vector>

class Map {
public:
    std::vector<std::vector<Tile>> map;
    sf::Image map_blocks;

    int width_px;
    int height_px;

    int tiles_x;
    int tiles_y;

    Map(int h, int w);

    Tile& get_tile(int x, int y);

    void draw(sf::RenderWindow& window);
};