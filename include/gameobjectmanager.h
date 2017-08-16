#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "SDL2/SDL_log.h"

#include "include/gameobject.h"
#include "include/gameobjects/player.h"
#include "include/gameobjects/ground.h"

#include "map"

class GameObjectManager
{
public:

    GameObjectManager();
    ~GameObjectManager();

    void CreateObject(std::string object_name, GameObject* object);
    void RemoveObject(std::string object_name);

    GameObject *GetGameObject(std::string object_name);
private:

    std::map<std::string, GameObject*> gameobjects;
};

#endif // GAMEOBJECTMANAGER_H
