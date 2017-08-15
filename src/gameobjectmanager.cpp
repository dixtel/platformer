#include "include/gameobjectmanager.h"

GameObjectManager::GameObjectManager() {

    for (std::map<std::string, GameObject*>::iterator it = gameobjects.begin(); it != gameobjects.end(); ++it) {

        delete it->second;
        it->second = nullptr;
    }

    gameobjects.clear();
}

GameObjectManager::~GameObjectManager() {

}

void GameObjectManager::CreateObject(std::string object_name, GameObject* object) {

    std::map<std::string, GameObject*>::iterator it;
    it = gameobjects.find(object_name);

    if (it != gameobjects.end()) {

        delete it->second;
        it->second = nullptr;
        gameobjects.erase(it);
    }

    gameobjects[object_name] = object;
}

void GameObjectManager::RemoveObject(std::string object_name) {

    std::map<std::string, GameObject*>::iterator it;
    it = gameobjects.find(object_name);

    if (it != gameobjects.end()) {

        delete it->second;
        it->second = nullptr;
        gameobjects.erase(it);
    }
}

GameObject *GameObjectManager::GetGameObject(std::string object_name) {

    std::map<std::string, GameObject*>::iterator it;
    it = gameobjects.find(object_name);

    if (it != gameobjects.end()) {

        return it->second;
    }

    SDL_Log("Error: cannot get GameObject with this name: %s (GameObjectManager)", object_name);

    return nullptr;
}
