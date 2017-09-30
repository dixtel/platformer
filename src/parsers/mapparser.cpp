#include "include/parsers/mapparser.h"

MapParser::MapParser()
{

}
bool MapParser::LoadMap(std::string path_map, std::string path_tilese) {

    if (!tmx_parser.LoadTMX(path_map) || !tsx_parser.LoadTSX(path_tilese))
        return false;

    return true;
}

unsigned MapParser::GetTileWidth() {

    return tsx_parser.GetTileWidth();
}

unsigned MapParser::GetTileHeight() {

    return tsx_parser.GetTileHeight();
}

unsigned MapParser::GetMapWidth() {

    return tmx_parser.GetWidth();
}

unsigned MapParser::GetMapHeight() {

    return tmx_parser.GetHeight();
}

std::string MapParser::GetImagePath() {

    return tsx_parser.GetPathImage();
}

std::vector<TileType> MapParser::GetMapLayer(LayerType layer_type) {

    std::vector<int> raw_layer = tmx_parser.GetLayer(LayerTypeToString(layer_type));
    std::vector<TileType> layer;

    for (int i = 0; i < raw_layer.size(); ++i) {

        if (raw_layer[i] == TileType_GROUND)
            layer.push_back(TileType_GROUND);
        else if (raw_layer[i] == TileType_DECORATION_BOX1)
            layer.push_back(TileType_DECORATION_BOX1);
        else if (raw_layer[i] == TileType_PLAYER)
            layer.push_back(TileType_PLAYER);
        else if (raw_layer[i] == TileType_DECORATION_BOX2)
            layer.push_back(TileType_DECORATION_BOX2);
        else if (raw_layer[i] == TileType_ENDMAP)
            layer.push_back(TileType_ENDMAP);
        else if (raw_layer[i] == TileType_BOX1)
            layer.push_back(TileType_BOX1);
        else
            layer.push_back(TileType_NONE);
    }

    return layer;
}

SDL_Rect MapParser::GetImageDestination(TileType tile) {

    unsigned x_pos = (tile - 1)  % tsx_parser.GetColumns();
    unsigned y_pos = (tile - 1) / tsx_parser.GetColumns();

    return SDL_Rect {x_pos * GetTileWidth(), y_pos * GetTileHeight(), GetTileWidth(), GetTileHeight()};
}
