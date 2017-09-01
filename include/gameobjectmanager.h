#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "SDL2/SDL_log.h"

#include "include/gameobject.h"
#include "include/gameobjects/player.h"
#include "include/gameobjects/ground.h"

#include <map>
#include <vector>
#include <utility>

class GameObjectManager
{
public:

    GameObjectManager();
    ~GameObjectManager();

    void CreateObject(std::string group, GameObject* object);
    void CreateObject(std::string group, std::string object_name, GameObject* object);
    void RemoveObject(std::string group, std::string object_name);

    GameObject *GetGameObject(std::string group, std::string object_name);
    GameObject *GetLastGameObject(std::string group);
    std::vector<GameObject*> &GetGroupObjects(std::string group);
    std::vector<GameObject*> &GetGameObjectsByLayer(std::string layer_name);
    std::vector<RectangleCollision*> &GetGroupObjectsAsRectangleCollision(std::string group);
private:

    // [group object] -> ([name object], [object pointer])
    std::map<std::string, std::map<std::string, GameObject*>> gameobjects;

};

#endif // GAMEOBJECTMANAGER_H
