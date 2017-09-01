#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <SDL2/SDL_log.h>

#include "include/parsers/mapparser.h"
#include "include/imageloader.h"
#include "include/gameobjectmanager.h"

#include <vector>

class WorldMap
{
public:

    WorldMap();

    void Init(std::string path_to_maps, ImageLoader *image_loader);
    void CreateObjectsMap(std::string map_name, GameObjectManager *game_object_manager);
    void AddMap(std::string map_name, std::string tileset_name);
private:

    std::string              path_to_maps;
    std::vector<std::string> name_maps;
    std::vector<std::string> name_tilesets;

    ImageLoader             *image_loader = nullptr;
    MapParser                map_parser;
};

#endif // WORLDMAP_H
