#ifndef TMXPARSER_H
#define TMXPARSER_H

#include <SDL2/SDL_log.h>

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>

class TMXParser
{
public:

    TMXParser();
    ~TMXParser();

    bool LoadTMX(std::string path);

    unsigned GetWidth();
    unsigned GetHeight();
    unsigned GetTileWidth();
    unsigned GetTileHeight();
    std::string GetPathTileset();
    std::vector<int> GetLayer(std::string layer_name);
private:

    std::vector<int> ConvertLayerToVector(std::string data);

    template <typename T>
    int ConvertToInt(T num);

    unsigned width;
    unsigned height;
    unsigned tile_width;
    unsigned tile_height;
    std::string path_tileset;

    // (layer_name, layer_data)
    std::map<std::string, std::vector<int>> layers;

    rapidxml::file<> *file = nullptr;
    rapidxml::xml_document<> document;
};

#endif // TMXPARSER_H
