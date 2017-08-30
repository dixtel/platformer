#ifndef TSXPARSER_H
#define TSXPARSER_H

#include <SDL2/SDL_log.h>

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <stdexcept>
#include <sstream>

class TSXParser
{
public:

    TSXParser();
    ~TSXParser();

    bool LoadTSX(std::string path);

    unsigned GetImageWidth();
    unsigned GetImageHeight();
    unsigned GetTileWidth();
    unsigned GetTileHeight();
    unsigned GetTileCount();
    unsigned GetColumns();
    std::string GetPathImage();
private:

    template <typename T>
    unsigned ConvertToUnsigned(T num);

    unsigned image_width;
    unsigned image_height;
    unsigned tile_width;
    unsigned tile_height;
    unsigned tile_counts;
    unsigned tile_columns;
    std::string path_image;

    rapidxml::file<> *file = nullptr;
    rapidxml::xml_document<> document;
};

#endif // TSXPARSER_H
