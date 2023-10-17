#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>

#include "dijkstra.hpp"
#include "tools.h"

int main()
{
	int n = 5;
	/* Let us create the example graph discussed above */
	int size =  n * n;
	int *graph = (int *) alloca( size * sizeof(int) );
	
	set_int_arr(graph, 0, size );

	print_2darr(graph, n , n);
	
	set_element(graph, n, 0, 1, 10);
	set_element(graph, n, 0, 2, 100);
	set_element(graph, n, 0, 4, 30);
	set_element(graph, n, 1, 3, 50);
	set_element(graph, n, 3, 2, 10);
	set_element(graph, n, 4, 2, 60);
	set_element(graph, n, 4, 3, 20);
	
	print_2darr(graph, n , n);
	
	struct result r = dijkstra(graph,0,n);
	
	print_arr(r.map, n);
	print_arr(r.cost, n);

	return 0;
}
