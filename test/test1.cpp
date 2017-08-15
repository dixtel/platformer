//#include "include/rectangle.h"
//#include "include/render.h"
//#include "include/window.h"

//#include <SDL2/SDL.h>

//int main(int argc, char *argv[])
//{

//    Window window;
//    if (!window.Init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) {

//        return 1;
//    }

//    Render render(window.GetRenderer(), SDL_Color{0, 0, 0, 255});

//    Rectangle object;

//    object.SetSize({100, 50});
//    object.SetPosition({0, 0});
//    object.SetRectColor({0, 255, 0, 255});


//    object.SetPosition({200, 200});


//    render.Clear();
//    render.Draw(&object);
//    render.Display();

//    SDL_Delay(3 * 1000);

//    return 0;
//}
