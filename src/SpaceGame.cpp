#include "SolarSystem.hpp"

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>


std::string g_ScreenTitle{"SpaceGame"};
long g_ScreenWidth = 1920;
long g_ScreenHeight = 1080;
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
    SolarSystem solarSystem;

    {
        auto view = window.getView();
        view.setCenter(
            view.getSize().x / 2,
            view.getSize().y / 2
        );
        window.setView(view);
    }

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyReleased:
                {
                    // No modifier keys
                    if(event.key.alt || event.key.control || event.key.shift || event.key.system)
                        break;
                 
                    auto view = window.getView();   
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Key::Up:
                            view.move({0.0f, 10.0f});
                            window.setView(view);
                            break;

                        case sf::Keyboard::Key::Down:
                            view.move({0.0f, -10.0f});
                            window.setView(view);
                            break;

                        case sf::Keyboard::Key::Left:
                            view.move({10.0f, 0.0f});
                            window.setView(view);
                            break;

                        case sf::Keyboard::Key::Right:
                            view.move({-10.0f, 0.0f});
                            window.setView(view);
                            break;

                        default:
                            break;
                    }
                    break;
                }

                case sf::Event::Resized:
                {
                    auto view = window.getView();
                    
                    float ratio = float(event.size.width) / float(event.size.height);

                    view.setSize(g_ScreenWidth, g_ScreenWidth / ratio);
                    window.setView(view);
                    break;
                }

                default:
                    // Silence warnings re. unhandled cases
                    break;
            }
        }

        solarSystem.TickAnimation();

        window.clear();
        window.draw(solarSystem);
        window.display();
    }
}
