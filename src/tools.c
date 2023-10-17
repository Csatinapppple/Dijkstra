
#include <cstdio>
#include "tools.h"

void print_2darr(int *arr, int x, int y){
  for ( int ii = 0; ii < y; ii++ ){
    for ( int jj = 0; jj <  x ; jj++ ){
      printf("%d ", arr[ x * ii + jj]);
    }
    puts("");
  }
}

void set_element(int *arr,int width, int row, int col, int value){
    arr[width * row + col] = value;
}

void set_int_arr(int *arr, int value,int n){
	for (int i = 0; i < n; i++){
		arr[i] = value;
	}
}
