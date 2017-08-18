#include "include/gameobjectmanager.h"

GameObjectManager::GameObjectManager() {

    for (std::map<std::string, std::map<std::string, GameObject*>> it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->seccond.begin(); it_objects != it_groups->seccond.end(); ++it_objects) {

            delete it_objects->seccond;
        }

        it_groups->clear();
    }

    gameobjects.clear();
}

GameObjectManager::~GameObjectManager() {

}

void GameObjectManager::CreateObject(std::string group, std::string object_name, GameObject* object) {

    for (std::map<std::string, std::map<std::string, GameObject*>> it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->seccond.begin(); it_objects != it_groups->seccond.end(); ++it_objects) {

            if (it_objects->first != object_name) continue;

            delete it_objects->seccond;
            it_groups->seccond.clear(it_objects);
        }
    }

    gameobjects[group][object_name] = object;
}

void GameObjectManager::RemoveObject(std::string group, std::string object_name) {

    for (std::map<std::string, std::map<std::string, GameObject*>> it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->seccond.begin(); it_objects != it_groups->seccond.end(); ++it_objects) {

            if (it_objects->first != object_name) continue;

            delete it_objects->seccond;
            it_groups->seccond.clear(it_objects);
        }
    }
}

GameObject *GameObjectManager::GetGameObject(std::string group, std::string object_name) {

    for (std::map<std::string, std::map<std::string, GameObject*>> it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->seccond.begin(); it_objects != it_groups->seccond.end(); ++it_objects) {

            if (it_objects->first != object_name) continue;

            return it_objects->seccond;
        }
    }

    return nullptr;
}

std::vector<GameObject*> &GameObjectManager::GetGroupObjects(std::string group) {

    std::vector<GameObject*> objects;

    for (std::map<std::string, std::map<std::string, GameObject*>> it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->seccond.begin(); it_objects != it_groups->seccond.end(); ++it_objects) {

            if (it_objects->first != object_name) continue;

            objects.push_back(it_objects->seccond);
        }
    }

    return objects;
}

