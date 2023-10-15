#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlib.c"
#include "arr.c"

/*a b  c   d  e
a	0 10 100 0  30
b	0 0  0   50 0
c	0 0  0   0  0
d	0 0  10  0  0
e	0 0  60  20 0
*/

enum class state:int{
	UNKNOWN  = false,
	KNOWN = true,
	INFINITY = INT_MAX,
};

struct result{
	int *cost;
	int *map;
};


void print_arr_bool(int *arr, int n){
  for(int i = 0; i < n; i++){
    printf("node[%d] = %s, ",i , (arr[i] == (int)state::UNKNOWN) ? "unknown" : "known");
  }
  puts("");
}

void print_arr_cost(int *arr, int n){
  for(int i = 0; i<n; i++){
    switch(arr[i]){
      case (int) state::INFINITY: 
        printf("node[%d] = infinity, ", i);
        break;
      default:
        printf("node[%d] = %d, ", i, arr[i]);
        break;
    }
  }
  puts("");
}

//returns unknown node with least cost
int min_distance(int *known, int *cost, int n){
  int index,cmp=INT_MAX;
  for(int i = 0; i < n; i++){
    if(
      known[i] != (int) state::UNKNOWN &&
      cost[i] != (int) state::INFINITY &&
      cost[i] < cmp
        ){
      index = i, cmp= cost[i];
    }
  }
  return index;
}

//returns malloced result representing the map of costs and sequence
struct result dijkstra (int *graph, int source, int n){
	int size=n * sizeof(int),
			*cost= (int *) malloc(size),
			*known=	(int *)	malloc(size),
			known_size=0,
			*map=(int *)	alloca(size);
	
	set_int_arr(cost, (int) state::INFINITY, n);
	set_int_arr(known, (int) state::UNKNOWN, n);
	set_int_arr(map, 0, n);
	

  int current = source;
  cost[source] = 0;
  known[source] = true;

  print_arr_bool(known, n);
  print_arr_cost(cost, n);

	while( known_size != n ){
    
    int node = min_distance(known, cost, n);		
			
    

	}
	return (struct result) {.cost = cost, .map = map};
}

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

	return 0;
}

