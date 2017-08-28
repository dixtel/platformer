#include "include/gameobjectmanager.h"

GameObjectManager::GameObjectManager() {

}

GameObjectManager::~GameObjectManager() {

    for (std::map<std::string, std::map<std::string, GameObject*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->second.begin(); it_objects != it_groups->second.end(); ++it_objects) {

            delete it_objects->second;
        }

        it_groups->second.clear();
    }

    gameobjects.clear();
}

void GameObjectManager::CreateObject(std::string group, std::string object_name, GameObject* object) {

    for (std::map<std::string, std::map<std::string, GameObject*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->second.begin(); it_objects != it_groups->second.end(); ++it_objects) {

            if (it_objects->first != object_name) continue;

            delete it_objects->second;
            it_groups->second.erase(it_objects);
        }
    }

    gameobjects[group].insert(std::make_pair(object_name, object));
}

void GameObjectManager::RemoveObject(std::string group, std::string object_name) {

    for (std::map<std::string, std::map<std::string, GameObject*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->second.begin(); it_objects != it_groups->second.end(); ++it_objects) {

            if (it_objects->first != object_name) continue;

            delete it_objects->second;
            it_groups->second.erase(it_objects);
        }
    }
}

GameObject *GameObjectManager::GetGameObject(std::string group, std::string object_name) {

    for (std::map<std::string, std::map<std::string, GameObject*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->second.begin(); it_objects != it_groups->second.end(); ++it_objects) {

            if (it_objects->first != object_name) continue;

            return it_objects->second;
        }
    }

    return nullptr;
}

std::vector<GameObject*> &GameObjectManager::GetGroupObjects(std::string group) {

    std::vector<GameObject*> objects;

    for (std::map<std::string, std::map<std::string, GameObject*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->second.begin(); it_objects != it_groups->second.end(); ++it_objects) {

            objects.push_back(it_objects->second);
        }

        return objects;
    }

    return objects;
}

std::vector<RectangleCollision*> &GameObjectManager::GetGroupObjectsAsRectangleCollision(std::string group) {

    static std::vector<RectangleCollision*> objects;
    objects.clear();

    for (std::map<std::string, std::map<std::string, GameObject*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group) continue;

        for (std::map<std::string, GameObject*>::iterator it_objects = it_groups->second.begin(); it_objects != it_groups->second.end(); ++it_objects) {

            objects.push_back(it_objects->second->GetRectangleCollision());
        }

        return objects;
    }

    return objects;
}


