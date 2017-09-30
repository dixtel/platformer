#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "SDL2/SDL_log.h"

#include "include/gameobject.h"
#include "include/gameobjects/player.h"
#include "include/gameobjects/ground.h"
#include "include/gameobjects/decoration.h"
#include "include/gameobjects/endmap.h"
#include "include/gameobjects/box1.h"


#include <map>
#include <vector>
#include <utility>

struct GameObjectInfomation {

    GameObjectInfomation() {

        object = nullptr;
        name_object = "";
    }

    GameObjectInfomation(GameObject *object, std::string name_object) {

        this->object = object;
        this->name_object = name_object;
    }

    ~GameObjectInfomation() {

        delete object;
        object = nullptr;
    }

    GameObject *object;
    std::string name_object;
};

class GameObjectManager
{
public:

    GameObjectManager();
    ~GameObjectManager();

    void CreateObject(std::string group, GameObject* object);
    void CreateObject(std::string group, std::string name_object, GameObject* object);
    void RemoveObject(std::string group, std::string name_object);  

    GameObject *GetGameObject(std::string group, std::string name_object);
    GameObject *GetLastGameObject(std::string group);
    std::vector<GameObject*> &GetGroupObjects(std::string group);
    std::vector<GameObject*> &GetGameObjectsByLayer(std::string layer_name);
    std::vector<RectangleCollision*> &GetGroupObjectsAsRectangleCollision(std::string group);
private:

    // [group object] -> [GameObjectInformation]
    std::map<std::string, std::vector<GameObjectInfomation*>> gameobjects;

};

#endif // GAMEOBJECTMANAGER_H
