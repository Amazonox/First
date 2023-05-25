#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <math.h>
#include "storage/mathVector.cpp"
#include "storage/matrix.cpp"
#include "test.cpp"
using namespace std;

const int WITH = 800, HEIGHT = 600;

struct vectorTouple
{
    vector<SDL_Point> newPoints;
    vector<SDL_Point> oldPoints;
};

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Hello SDL World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WITH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    
    SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, 0 );


    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    SDL_RenderClear( renderer );

    SDL_SetRenderDrawColor( renderer,0, 255, 0, 255 );

    vector<SDL_Point> x = { { 200, 400 }, { 600, 400 }};
    vector<SDL_Point> y;
    vector<SDL_Point> remover;


    

    if ( NULL == window )
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;
    int i = 0;
    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }
        }
        for(int i = 0; i<x.size();i++){
            SDL_RenderDrawLine(renderer, x[i].x, x[i].y, x[i+1].x, x[i+1].y);
            SDL_RenderPresent( renderer );
    }

    SDL_DestroyWindow( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}
}

vectorTouple koch(vector<SDL_Point> oldPoints, int n, SDL_Renderer *renderer){
    Test test;
    test.print();
    vector<SDL_Point> newPoints;
    vector<SDL_Point> remover;
    newPoints.push_back(oldPoints[0]);
    SDL_Point p = {oldPoints[0].x + (oldPoints[1].x-oldPoints[0].x)/3, oldPoints[0].y/* + (oldPoints[1].y-oldPoints[0].y)/3*/};
    MathVector<double> vec {static_cast<double>(oldPoints[1].x-oldPoints[0].x), static_cast<double>(oldPoints[1].y-oldPoints[0].y)};
    double norm = vec.normalise();
    Matrix<double> m {{cos(45), -sin(45)}, {sin(45), cos(45)}};
    vec = m*vec;
    vec = vec*(norm/3);
    SDL_Point q = {p.x + vec.get(0), p.y + vec.get(1)};
    newPoints.push_back(q);
    newPoints.push_back(p);
    remover.push_back(p);
    /**
    SDL_Point q = {p.x + (oldPoints[1].x-oldPoints[0].x)/3, oldPoints[0].y + (oldPoints[1].y-oldPoints[0].y)/3}

    for(int i = 0; i<x.size();i+=2){
        y.push_back(x[i]);
        SDL_Point p = {x[i].x + (x[i+1].x-x[i].x)/3, x[i].y + (x[i+1].y-x[i].y)/3};
        y.push_back(p);
        remover.push_back(p);
        SDL_Point q = { };
        SDL_RenderPresent( renderer );  
        }
        **/
    vectorTouple result = {newPoints, remover};
    return result;
    }

