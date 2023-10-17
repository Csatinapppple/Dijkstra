#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <limits.h>
#include <stdbool.h>

constexpr bool D_KNOWN = true;
constexpr bool D_UNKNOWN = false;
constexpr int D_INFINITY = INT_MAX;

struct result{
	int *cost;
	int *map;
};

extern
void
print_arr(int *arr, int n);

extern
void print_arr_bool(int *arr, int n);
extern
void print_arr_cost(int *arr, int n);
extern
//returns unknown node index with least cost
int min_distance(int *known, int *cost, int n);
extern
//returns malloced result representing the map of costs and sequence
struct result dijkstra (int *graph, int source, int n);

#endif
