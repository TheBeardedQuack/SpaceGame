#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>


std::string g_ScreenTitle{"SpaceGame"};
long g_ScreenWidth = 800;
long g_ScreenHeight = 600;
long g_texSunDiameter = 64;

int
main(
    int argc,
    char* argv[]
) {
    // Silence warnings re. unused variables
    (void)argc;
    (void)argv;

    //! TODO: Parse command line params

    sf::RenderWindow window{sf::VideoMode{g_ScreenWidth, g_ScreenHeight}, g_ScreenTitle};
    sf::Texture texSun;
    sf::Sprite spriteSun;

    if(!texSun.loadFromFile("rsc/images/sun.png", sf::IntRect{0, 0, 256, 256}))
    {
        std::cout << "Failed to load resource images/sun.png\n";
        return -1;
    }

    spriteSun.setTexture(texSun);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();

                default:
                    // Silence warnings re. unhandled cases
                    break;
            }
        }

        window.clear();
        window.draw(spriteSun);
        window.display();
    }
}
