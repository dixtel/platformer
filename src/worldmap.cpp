#include "include/worldmap.h"

WorldMap::WorldMap()
{

}

void WorldMap::Init(std::string path_to_maps, ImageLoader *image_loader) {

    this->path_to_maps = path_to_maps;
    this->image_loader = image_loader;
}

void WorldMap::CreateObjectsMap(std::string map_name, GameObjectManager *game_object_manager) {

    for (int i = 0; i < name_maps.size(); ++i) {

        if (name_maps[i] == map_name) {

            if(!map_parser.LoadMap(path_to_maps + map_name, path_to_maps + name_tilesets[i])) {

                SDL_Log("(WorldMap) Error load map: %s", &map_name);
                return;
            }

            std::string path_to_image = path_to_maps + map_parser.GetImagePath();

            SDL_Texture *check_path = image_loader->LoadTexture(path_to_image.c_str());

            if (!check_path) {

                SDL_Log("(WorldMap) cannot load path to tileset, path: %s", &path_to_image);
                return;
            }

            std::vector<TileType> layer_top    = map_parser.GetMapLayer(LayerType_TOP);
            std::vector<TileType> layer_middle = map_parser.GetMapLayer(LayerType_MIDDLE);
            std::vector<TileType> layer_down   = map_parser.GetMapLayer(LayerType_DOWN);
            std::vector<TileType> layer_other  = map_parser.GetMapLayer(LayerType_OTHER);

            std::vector<std::vector<TileType>> layers {layer_top, layer_middle, layer_down, layer_other};

            std::vector<LayerType> layer_name = {LayerType_TOP, LayerType_MIDDLE, LayerType_DOWN, LayerType_OTHER};

            unsigned tile_width = map_parser.GetTileWidth();
            unsigned tile_height = map_parser.GetTileHeight();

            unsigned map_width = map_parser.GetMapWidth();
            unsigned map_height = map_parser.GetMapHeight();

            for (int y = 0; y < map_height; ++y) {

                for (int x = 0; x < map_width; ++x) {

                    float x_pos = x * tile_width;
                    float y_pos = y * tile_height;

                    unsigned current_tile = y * map_width + x;

                    for (int j = 0; j < layers.size(); ++j) {

                        if (layers[j][current_tile] == TileType_GROUND) {

                            SDL_Texture *tile_image = image_loader->LoadTexture(path_to_image.c_str());
                            SDL_Rect destination = map_parser.GetImageDestination(TileType_GROUND);

                            game_object_manager->CreateObject(TileTypeToString(TileType_GROUND), new Ground());
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_GROUND))->SetLayerType(LayerTypeToString(layer_name[j]));
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_GROUND))->Init(Vector2f(x_pos, y_pos), Vector2u(tile_width, tile_height), tile_image, image_loader);
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_GROUND))->GetRectangle()->SetSourceTexture(destination);
                        }
                        else if (layers[j][current_tile] == TileType_DECORATION_BOX1) {

                            SDL_Texture *tile_image = image_loader->LoadTexture(path_to_image.c_str());
                            SDL_Rect destination = map_parser.GetImageDestination(TileType_DECORATION_BOX1);

                            game_object_manager->CreateObject(TileTypeToString(TileType_DECORATION_BOX1), new Decoration());
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_DECORATION_BOX1))->SetLayerType(LayerTypeToString(layer_name[j]));
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_DECORATION_BOX1))->Init(Vector2f(x_pos, y_pos), Vector2u(tile_width, tile_height), tile_image, image_loader);
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_DECORATION_BOX1))->GetRectangle()->SetSourceTexture(destination);
                        }
                        else if (layers[j][current_tile] == TileType_DECORATION_BOX2) {

                            SDL_Texture *tile_image = image_loader->LoadTexture(path_to_image.c_str());
                            SDL_Rect destination = map_parser.GetImageDestination(TileType_DECORATION_BOX2);

                            game_object_manager->CreateObject(TileTypeToString(TileType_DECORATION_BOX2), new Decoration());
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_DECORATION_BOX2))->SetLayerType(LayerTypeToString(layer_name[j]));
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_DECORATION_BOX2))->Init(Vector2f(x_pos, y_pos), Vector2u(tile_width, tile_height), tile_image, image_loader);
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_DECORATION_BOX2))->GetRectangle()->SetSourceTexture(destination);
                        }
                        else if (layers[j][current_tile] == TileType_PLAYER) {

                            SDL_Texture *tile_image = image_loader->LoadTexture(path_to_image.c_str());
                            SDL_Rect destination = map_parser.GetImageDestination(TileType_PLAYER);

                            game_object_manager->CreateObject(TileTypeToString(TileType_PLAYER), new Player());
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_PLAYER))->SetLayerType(LayerTypeToString(layer_name[j]));
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_PLAYER))->Init(Vector2f(x_pos, y_pos), Vector2u(tile_width, tile_height), tile_image, image_loader);
                            //game_object_manager->GetLastGameObject(TileTypeToString(TileType_PLAYER))->GetRectangle()->SetSourceTexture(destination);
                        }
                        else if (layers[j][current_tile] == TileType_ENDMAP) {

                            SDL_Texture *tile_image = image_loader->LoadTexture(path_to_image.c_str());
                            SDL_Rect destination = map_parser.GetImageDestination(TileType_ENDMAP);

                            game_object_manager->CreateObject(TileTypeToString(TileType_ENDMAP), new EndMap());
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_ENDMAP))->SetLayerType(LayerTypeToString(layer_name[j]));
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_ENDMAP))->Init(Vector2f(x_pos, y_pos), Vector2u(tile_width, tile_height), tile_image, image_loader);
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_ENDMAP))->GetRectangle()->SetSourceTexture(destination);
                        }
                        else if (layers[j][current_tile] == TileType_BOX1) {

                            SDL_Texture *tile_image = image_loader->LoadTexture(path_to_image.c_str());
                            SDL_Rect destination = map_parser.GetImageDestination(TileType_BOX1);

                            game_object_manager->CreateObject(TileTypeToString(TileType_BOX1), new Box1());
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_BOX1))->SetLayerType(LayerTypeToString(layer_name[j]));
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_BOX1))->Init(Vector2f(x_pos, y_pos), Vector2u(tile_width, tile_height), tile_image, image_loader);
                            game_object_manager->GetLastGameObject(TileTypeToString(TileType_BOX1))->GetRectangle()->SetSourceTexture(destination);
                        }
                    }
                }
            }
        }
    }
}

void WorldMap::AddMap(std::string map_name, std::string tileset_name) {

    name_maps.push_back(map_name);
    name_tilesets.push_back(tileset_name);
}
