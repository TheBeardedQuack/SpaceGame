#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

class SolarSystem :
    public sf::Drawable,
    public sf::Transformable
{
public:
    SolarSystem();
    
    /*
    SolarSystem(
        uint8_t numPlanets
    );

    SolarSystem(
        uint8_t minPlanets,
        uint8_t maxPlanets
    );
    */

    SolarSystem(
        const SolarSystem& copy
    ) = default;

    SolarSystem(
        SolarSystem&& move
    ) = default;

    virtual
    ~SolarSystem() = default;

    SolarSystem&
    operator=(
        const SolarSystem& copy
    );

    SolarSystem&
    operator=(
        SolarSystem&& move
    );

    void
    TickAnimation();

    //! Implent sf::Drawable

    virtual
    void
    draw(
        sf::RenderTarget& renderer,
        sf::RenderStates states
    ) const;

private:
    struct StellarObject
    {
        enum EObjectType
        {
            _START = 0,

            Sun = _START,
            Planet,
            Moon,
            Asteroid,
            Satelite,

            _COUNT
        };

        EObjectType objectType;
        sf::Vector2f position{0.0f, 0.0f};
        float velocity{0.0f};
        sf::Texture texture;
        sf::Sprite sprite;

        StellarObject(
            const std::string& spriteImage
        ) {
            if(!texture.loadFromFile(spriteImage))
                throw std::runtime_error{"Failed to open resource `" + spriteImage + "`"};
            
            auto texSize = texture.getSize();
            sprite.setTexture(texture);
            sprite.setOrigin(texSize.x / 2, texSize.y / 2);
        }
    };

    std::vector<StellarObject> stellarObjects;
};
