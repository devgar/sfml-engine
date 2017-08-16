#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int main()
{
    //load resources
    sf::Music music;
    if (!music.openFromFile("assets/music/acdc.ogg"))
        return -1; // error

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    music.setVolume(50);
    music.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
