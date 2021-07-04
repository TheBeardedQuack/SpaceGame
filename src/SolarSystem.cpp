#include "SolarSystem.hpp"
#include <iostream>

SolarSystem::SolarSystem()
{
    stellarObjects.reserve(10);

    sf::Vector2f sunPosition{400, 300};
    sf::Vector2f earthPosition{200, 0};

    // Sun
    stellarObjects.emplace_back("rsc/images/suns/0.png");
    stellarObjects[0].sprite.move(sunPosition);

    // Earth
    stellarObjects.emplace_back("rsc/images/planets/0.png");
    {
        auto& earth = stellarObjects[1];
        earth.velocity = 0.01f;
        earth.sprite.setOrigin((earth.sprite.getOrigin() - earthPosition) * 20.0f);
        earth.sprite.setScale(0.1f, 0.1f);
        earth.sprite.move(sunPosition);
    }
}

void
SolarSystem::TickAnimation()
{
    for(auto& object : stellarObjects)
    {
        if(object.velocity != 0.0f)
            object.sprite.rotate(object.velocity);
    }
}

void
SolarSystem::draw(
    sf::RenderTarget& renderer,
    sf::RenderStates states
) const {
    for(size_t i = 0; i < stellarObjects.size(); ++i)
    {
        renderer.draw(stellarObjects[i].sprite);
    }
}
