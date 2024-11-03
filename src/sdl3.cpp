#include <SDL3/SDL.h> //includes SDL3 core functions
#include <SDL3/SDL_main.h> //include SDL3 core  
//manage the main entry point in SDL3. which my be required on some platforms
// we used to need to use the sdl2 main linking library
#include <iostream>

int main()
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    if (result < 0)
    {
        std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }
    window = SDL_CreateWindow("muteboi", 500, 500, 0);
    if (window == nullptr)
    {
        std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
        return -2;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr)
    {
        std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
        return -3;
    }

    std::cout << "msg: SDL3 initialized successfully" << std::endl;

    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    std::cout << "msg: SDL3 event quit" << std::endl;
                    quit = true;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_ESCAPE)
                    {
                        std::cout << "msg: SDL3 event quit" << std::endl;
                        quit = true;
                    }
                    break;  

            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0xff, 0xff);
        SDL_RenderClear(renderer); //clears the screen using the set color
        SDL_RenderPresent(renderer); //displays the frame
        SDL_Delay(1); //add a slight delay to reduce CPU usage
    }

    std::cout << "msg: SDL3 shutdown" << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit(); // clean up SDL
    return 0;
}