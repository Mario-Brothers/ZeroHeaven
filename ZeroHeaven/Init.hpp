#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <SDL3/SDL_init.h>

SDL_AppResult InitEverything(SDL_Renderer* renderer, SDL_Window* window, SDL_GLContext glContext);