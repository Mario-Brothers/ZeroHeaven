#include "Init.hpp"

SDL_AppResult InitEverything(SDL_Renderer* renderer, SDL_Window* window, SDL_GLContext glContext)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Tworzenie okna SDL
    window = SDL_CreateWindow("OpenGL in SDL", 800, 600, SDL_WINDOW_OPENGL);
    if (!window)
    {
        SDL_Log("Error creating window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Tworzenie kontekstu OpenGL
    glContext = SDL_GL_CreateContext(window);
    if (!glContext)
    {
        SDL_Log("Error creating OpenGL context: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Inicjalizacja GLEW
    if (glewInit() != GLEW_OK)
    {
        SDL_Log("Error initializing GLEW");
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}