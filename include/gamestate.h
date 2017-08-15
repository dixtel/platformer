#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:

    virtual ~GameState() {}

    virtual void UpdateState(float dt) = 0;
    virtual void RenderState() = 0;
    virtual void HandleEvents() = 0;
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual bool IsGameExit() { return false; }
};

#endif // GAMESTATE_H
