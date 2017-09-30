#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <SDL2/SDL_rect.h>

#include "include/parsers/tmxparser.h"
#include "include/parsers/tsxparser.h"

#include <vector>

enum TileType {
    TileType_NONE = 0,
    TileType_GROUND = 1,
    TileType_DECORATION_BOX1 = 2,
    TileType_PLAYER = 3,
    TileType_DECORATION_BOX2 = 4,
    TileType_ENDMAP = 5,
    TileType_BOX1 = 6,
};

enum LayerType {
    LayerType_OTHER,
    LayerType_TOP,
    LayerType_MIDDLE,
    LayerType_DOWN,
};

static std::string TileTypeToString(TileType type) {

     if (type == TileType_GROUND)
         return "ground";
     else if (type == TileType_DECORATION_BOX1)
         return "decoration_box1";
     else if (type == TileType_PLAYER)
         return "player";
     else if (type == TileType_DECORATION_BOX2)
         return "decoration_box2";
     else if (type == TileType_ENDMAP)
         return "end_map";
     else if (type == TileType_BOX1)
         return "box1";
}

static std::string LayerTypeToString(LayerType type) {

     if (type == LayerType_OTHER)
         return "other";
     else if (type == LayerType_TOP)
         return "top";
     else if (type == LayerType_MIDDLE)
         return "middle";
     else if (type == LayerType_DOWN)
         return "down";
}

class MapParser
{
public:

    MapParser();

    bool LoadMap(std::string path_map, std::string path_tileset);

    unsigned GetTileWidth();
    unsigned GetTileHeight();
    unsigned GetMapWidth();
    unsigned GetMapHeight();
    std::string GetImagePath();
    std::vector<TileType> GetMapLayer(LayerType name_layer);
    SDL_Rect GetImageDestination(TileType tile);
private:

    TMXParser tmx_parser;
    TSXParser tsx_parser;
};

#endif // MAPPARSER_H
