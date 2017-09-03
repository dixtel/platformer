#include "include/gameobjectmanager.h"

GameObjectManager::GameObjectManager() {

}

GameObjectManager::~GameObjectManager() {

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        for (std::vector<GameObjectInfomation*>::iterator it_object_info = it_groups->second.begin(); it_object_info != it_groups->second.end(); ++it_object_info) {

            delete (*it_object_info);
        }
    }
}

void GameObjectManager::CreateObject(std::string group, GameObject* object) {

    std::string object_number = "1";

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group)
            continue;

        object_number = std::to_string(it_groups->second.size() + 1);

        it_groups->second.push_back(new GameObjectInfomation(object, group));

        return;
    }

    gameobjects.insert(std::make_pair(group, std::vector<GameObjectInfomation*>{}));
    gameobjects[group].push_back(new GameObjectInfomation(object, object_number));
}

void GameObjectManager::CreateObject(std::string group, std::string name_object, GameObject* object) {

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group)
            continue;

        for (std::vector<GameObjectInfomation*>::iterator it_object_info = it_groups->second.begin(); it_object_info != it_groups->second.end(); ++it_object_info) {

            if ((*it_object_info)->name_object == name_object) {

                delete (*it_object_info);
                *it_object_info = new GameObjectInfomation(object, name_object);

                return;
            }
        }

        it_groups->second.push_back(new GameObjectInfomation(object, name_object));

        return;
    }

    gameobjects.insert(std::make_pair(group, std::vector<GameObjectInfomation*>{}));
    gameobjects[group].push_back(new GameObjectInfomation(object, name_object));
}

void GameObjectManager::RemoveObject(std::string group, std::string name_object) {

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group)
            continue;

        for (std::vector<GameObjectInfomation*>::iterator it_object_info = it_groups->second.begin(); it_object_info != it_groups->second.end(); ++it_object_info) {

            if ((*it_object_info)->name_object == name_object) {

                delete (*it_object_info);

                return;
            }
        }
    }
}

GameObject *GameObjectManager::GetGameObject(std::string group, std::string name_object) {

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group)
            continue;

        for (std::vector<GameObjectInfomation*>::iterator it_object_info = it_groups->second.begin(); it_object_info != it_groups->second.end(); ++it_object_info) {

            if ((*it_object_info)->name_object == name_object) {

                return (*it_object_info)->object;
            }
        }
    }

    return nullptr;
}

GameObject *GameObjectManager::GetLastGameObject(std::string group) {

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group)
            continue;

        return it_groups->second.back()->object;
    }

    return nullptr;
}

std::vector<GameObject*> &GameObjectManager::GetGroupObjects(std::string group) {

    static std::vector<GameObject*> objects;
    objects.clear();

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group)
            continue;

        for (std::vector<GameObjectInfomation*>::iterator it_object_info = it_groups->second.begin(); it_object_info != it_groups->second.end(); ++it_object_info) {

            objects.push_back((*it_object_info)->object);
        }

        return objects;
    }

    return objects;
}

std::vector<GameObject*> &GameObjectManager::GetGameObjectsByLayer(std::string layer_name) {

    static std::vector<GameObject*> objects;
    objects.clear();

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        for (std::vector<GameObjectInfomation*>::iterator it_object_info = it_groups->second.begin(); it_object_info != it_groups->second.end(); ++it_object_info) {

            if ((*it_object_info)->object->GetLayerType() == layer_name)
                objects.push_back((*it_object_info)->object);
        }
    }

    return objects;
}

std::vector<RectangleCollision*> &GameObjectManager::GetGroupObjectsAsRectangleCollision(std::string group) {

    static std::vector<RectangleCollision*> objects;
    objects.clear();

    for (std::map<std::string, std::vector<GameObjectInfomation*>>::iterator it_groups = gameobjects.begin(); it_groups != gameobjects.end(); ++it_groups) {

        if (it_groups->first != group)
            continue;

        for (std::vector<GameObjectInfomation*>::iterator it_object_info = it_groups->second.begin(); it_object_info != it_groups->second.end(); ++it_object_info) {

            objects.push_back((*it_object_info)->object->GetRectangleCollision());
        }

        return objects;
    }

    return objects;
}
