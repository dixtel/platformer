#include "include/parsers/tmxparser.h"

TMXParser::TMXParser() {

    width = 0;
    height = 0;
    tile_width = 0;
    tile_height = 0;
}

TMXParser::~TMXParser() {

    if (file) {

        delete file;
        file = nullptr;
    }
}

bool TMXParser::LoadTMX(std::string path) {

    if (file) {

        delete file;
        file = nullptr;
    }

    try {
        file = new rapidxml::file<>(path.c_str());
    } catch (std::runtime_error &e) {

        SDL_Log("(TMXPARSER) Error load .tmx file %s", e.what());
        return false;
    }

    document.parse<0>(file->data());

    rapidxml::xml_node<> *map_node = document.first_node("map");

    width = ConvertToInt(map_node->first_attribute("width")->value());
    height = ConvertToInt(map_node->first_attribute("height")->value());
    tile_width = ConvertToInt(map_node->first_attribute("tilewidth")->value());
    tile_height = ConvertToInt(map_node->first_attribute("tilewidth")->value());

    rapidxml::xml_node<> *tileset_node = map_node->first_node("tileset");

    path_tileset = tileset_node->first_attribute("source")->value();

    for (rapidxml::xml_node<> *layer = map_node->first_node("layer"); layer; layer = layer->next_sibling()) {

        std::string name_layer = layer->first_attribute("name")->value();
        std::string layer_data;

        rapidxml::xml_node<> *data_node = layer->first_node("data");
        layer_data = data_node->value();

        layers.insert(std::make_pair(name_layer, ConvertLayerToVector(layer_data)));
    }

    return true;
}

unsigned TMXParser::GetWidth() {

    return width;
}

unsigned TMXParser::GetHeight() {

    return height;
}

unsigned TMXParser::GetTileWidth() {

    return tile_width;
}

unsigned TMXParser::GetTileHeight() {

    return tile_height;
}

std::string TMXParser::GetPathTileset() {

    return path_tileset;
}

std::vector<int> TMXParser::GetLayer(std::string layer_name) {

    for (std::map<std::string, std::vector<int>>::iterator it = layers.begin(); it != layers.end(); ++it) {

        if (it->first == layer_name)
            return it->second;
    }

    return std::vector<int> {};
}

std::vector<int> TMXParser::ConvertLayerToVector(std::string data) {

    std::vector<int> layer;

    std::string value;
    for (int i = 0; i < data.size(); ++i) {

        if (int(data[i]) >= 48 && int(data[i]) <= 57) {

            value += data[i];
        }
        else if (data[i] == ',') {

            layer.push_back(ConvertToInt(value));
            value.clear();
        }
        else {

            continue;
        }
    }

    return layer;
}

template <typename T>
int TMXParser::ConvertToInt(T num) {

    int re_val;
    std::stringstream ss;
    ss << num;
    ss >> re_val;

    return re_val;
}
