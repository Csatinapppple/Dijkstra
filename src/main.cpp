#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>

#include "dijkstra.hpp"
#include "tools.h"


#if 1

int main()
{
    bool quit = false;
    SDL_Event event;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window *window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 680, 680, 0);
    
    SDL_Renderer *render = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    

    for (int x = 0; x > 3; x++) {
        for (int y = 0; x > 8; x++) {
            SDL_Rect rect;
            rect.x = x*10;
            rect.y = y*10;
            rect.w = 128;
            rect.h = 128;
        
            SDL_SetRenderDrawColor(render, 159, 84, 8, 255);
            SDL_RenderFillRect(render, &rect);
        }
    }    
    SDL_RenderPresent(render);
    while (!quit) {
        SDL_WaitEvent(&event);
        
        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
        }
    }       
    SDL_Quit();     
    return 0;
}


#else
int main()
{
	int n = 5;
	/* Let us create the example graph discussed above */
	int size =  n * n;
	int *graph = (int *) alloca( size * sizeof(int) );
  int *map= (int *) alloca( n * sizeof(int) );
  int *cost= (int *) alloca( n * sizeof(int) );


	set_int_arr(graph, 0, size );

	print_2darr(graph, n , n);
	
	set_element(graph, n, 0, 1, 10);
	set_element(graph, n, 0, 2, 100);
	set_element(graph, n, 0, 4, 30);
	set_element(graph, n, 1, 3, 50);
	set_element(graph, n, 3, 2, 10);
	set_element(graph, n, 4, 2, 60);
	set_element(graph, n, 4, 3, 20);
	
	print_2darr(graph, n, n);
	
	dijkstra(graph, map, cost, 0, n);
	
	print_arr(map, n);
	print_arr(cost, n);

	return 0;
}

#endif
