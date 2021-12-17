#include "ResourceType.hpp"

void
to_json(
    nlohmann::json& json,
    const ResourceType& rsc
) {
    json = {
        {"name", rsc.name},
        {"image", rsc.image}
    };
}

ResourceType::ResourceType(
    const std::string& name,
    const std::filesystem::path& image
) :
    name(name),
    spSprite(Textures::LoadSprite(image))
{
    // Nothing to do
}

