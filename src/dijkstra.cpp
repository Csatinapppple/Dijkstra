#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dijkstra.hpp"
#include "tools.h"


void print_arr_bool(int *arr, int n){
  for(int i = 0; i < n; i++){
    printf("node[%d] = %s, ",i , (arr[i] == D_UNKNOWN) ? "unknown" : "known");
  }
  puts("");
}

void print_arr_cost(int *arr, int n){
  for(int i = 0; i<n; i++){
    switch(arr[i]){
      case D_INFINITY: 
        printf("node[%d] = infinity, ", i);
        break;
      default:
        printf("node[%d] = %d, ", i, arr[i]);
        break;
    }
  }
  puts("");
}

//returns unknown node index with least cost
int min_distance(int *known, int *cost, int n){
  int index=-1,cmp=D_INFINITY;
  for(int i = 0; i < n; i++){
    if(
      known[i] == D_UNKNOWN &&
			cost[i] != D_INFINITY &&
      cost[i] < cmp
        ){
      index = i, cmp= cost[i];
    }
  }
  return index;
}

//returns malloced result representing the map of costs and sequence
void dijkstra (int *graph,int *map, int *cost, int source, int n){
	int size=n * sizeof(int),
			*known=	(int *)	alloca(size),
			known_size=0;
	
	set_int_arr(cost, D_INFINITY, n);
	set_int_arr(known, D_UNKNOWN, n);
	set_int_arr(map, 0, n);

  int current = source;
  cost[source] = 0;

  print_arr_bool(known, n);
  print_arr_cost(cost, n);

	while( known_size != n ){
    
    int current_node = min_distance(known, cost, n);		
		printf("current_node = %d\n", current_node);
		known[current_node] = D_KNOWN;

		for(int node_path = 0; node_path < n; node_path++){
			
			printf("%d \n", (current_node * n) + node_path);

			int current_node_cost = cost[current_node];
			int path_value = graph[current_node * n + node_path];
			int total_cost = path_value + current_node_cost;
			if(
				path_value != 0 &&
				cost[node_path] > total_cost
			){
				puts("in");
				cost[node_path] = total_cost;
				map[node_path] = current_node;
			}
			
		}

 		known_size++;
		printf("known_size = %d\n",known_size);

	}

}
