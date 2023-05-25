#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <math.h>
#include "storage/mathVector.h"
#include "storage/matrix.h"
#include "storage/test.h"
using namespace std;

const int WITH = 800, HEIGHT = 600;
vector<SDL_Point> koch(vector<SDL_Point> oldPoints)
{
    vector<SDL_Point> newPoints;

    for (int i = 0; i < oldPoints.size()-1; i++)
    {
        newPoints.push_back(oldPoints[i]);
        MathVector<double> vec{static_cast<double>(oldPoints[i + 1].x - oldPoints[i].x), static_cast<double>(oldPoints[i + 1].y - oldPoints[i].y)};
        vec = vec * (1.0 / 3.0);
        SDL_Point p = {static_cast<int>(oldPoints[i].x + vec.get(0)), static_cast<int>(oldPoints[i].y + vec.get(1))};
        SDL_Point q = {static_cast<int>(oldPoints[i + 1].x - vec.get(0)), static_cast<int>(oldPoints[i + 1].y - vec.get(1))};
        double norm = vec.normalise();
        Matrix<double> m{{cos(45), -sin(45)}, {sin(45), cos(45)}};
        MathVector<double> rotated = m * vec;
        rotated = rotated * (norm);
        newPoints.push_back(p);
        newPoints.push_back({static_cast<int>(p.x + rotated.get(0)), static_cast<int>(p.y + rotated.get(1))});
        newPoints.push_back(q);
        newPoints.push_back(oldPoints[i + 1]);
    }
    return newPoints;
}

int main(int argc, char *argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WITH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    vector<SDL_Point> x = {{200, 400}, {600, 400}};
    vector<SDL_Point> y;
    vector<SDL_Point> remover;

    if (NULL == window)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;
    bool quit = false;
    while(true)
    {
        SDL_RenderDrawLines(renderer, &x[0], x.size());
        SDL_RenderPresent(renderer);
        while (true)
        {
            if (SDL_PollEvent(&windowEvent))
            {
                if (SDL_MOUSEBUTTONDOWN == windowEvent.type)
                {
                    break;
                }
                if (SDL_QUIT == windowEvent.type)
                {
                    break;
                    quit = true;
                }
            }
        }
        if (quit)
        {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        x = koch(x);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
