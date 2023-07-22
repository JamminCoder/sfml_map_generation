#include <SFML/Graphics.hpp>
#include "lib/Map.cpp"

int WIN_WIDTH = 16 * 32;
int WIN_HEIGHT = 16 * 32;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_WIDTH), "Map Drawing");
    Map map(WIN_HEIGHT, WIN_WIDTH);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        map.draw(window);

        window.display();
    }

}