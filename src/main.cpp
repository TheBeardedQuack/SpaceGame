#include <string>

#include <SFML/Graphics.hpp>


std::string g_ScreenTitle{"SpaceGame"};
long g_ScreenWidth = 800;
long g_ScreenHeight = 600;

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
    sf::CircleShape sun{100.0f};

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
        window.draw(sun);
        window.display();
    }
}
