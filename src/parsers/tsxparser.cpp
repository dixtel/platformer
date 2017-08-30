#include "include/parsers/tsxparser.h"

TSXParser::TSXParser() {

    image_width = 0;
    image_height = 0;
    tile_width = 0;
    tile_height = 0;
    tile_counts = 0;
    tile_columns = 0;
}

TSXParser::~TSXParser() {

    if (file) {

        delete file;
        file = nullptr;
    }
}


bool TSXParser::LoadTSX(std::string path) {

    if (file) {

        delete file;
        file = nullptr;
    }

    try {
        file = new rapidxml::file<>(path.c_str());
    } catch (std::runtime_error &e) {

        SDL_Log("(TSXPARSER) Error load .tsx file %s", e.what());
        return false;
    }

    document.parse<0>(file->data());

    rapidxml::xml_node<> *tileset_node = document.first_node("tileset");

    tile_width = ConvertToUnsigned(tileset_node->first_attribute("tilewidth")->value());
    tile_height = ConvertToUnsigned(tileset_node->first_attribute("tileheight")->value());
    tile_counts = ConvertToUnsigned(tileset_node->first_attribute("tilecount")->value());
    tile_columns = ConvertToUnsigned(tileset_node->first_attribute("columns")->value());

    rapidxml::xml_node<> *image_node = tileset_node->first_node("image");

    path_image = ConvertToUnsigned(image_node->first_attribute("source")->value());
    image_width = ConvertToUnsigned(image_node->first_attribute("width")->value());
    image_height = ConvertToUnsigned(image_node->first_attribute("height")->value());

    // TODO parse each properties object

    return true;
}

unsigned TSXParser::GetImageWidth() {

    return image_width;
}

unsigned TSXParser::GetImageHeight() {

    return image_height;
}

unsigned TSXParser::GetTileWidth() {

    return tile_width;
}

unsigned TSXParser::GetTileHeight() {

    return tile_height;
}

unsigned TSXParser::GetTileCount() {

    return tile_counts;
}

unsigned TSXParser::GetColumns() {

    return tile_columns;
}

std::string TSXParser::GetPathImage() {

    return path_image;
}

template <typename T>
unsigned TSXParser::ConvertToUnsigned(T num) {

    unsigned re_val;
    std::stringstream ss;
    ss << num;
    ss >> re_val;

    return re_val;
}
