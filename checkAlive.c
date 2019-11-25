#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 40
int checkAlive(int grid[ROWS][COLS],int x,int y){
  int count = 0;
	if (grid[x-1][y] == 1 && (x- 1) >= 0) {
		count += 1;
	} if (grid[x+1][y] == 1 && (x + 1) < ROWS) {
		count += 1;
	} if (grid[x-1][y-1] == 1 && (x - 1) >= 0 && (y - 1) >= 0) {
		count += 1;
	} if (grid[x-1][y+1] == 1 && (x - 1) >= 0 && (y + 1) < COLS) {
		count += 1;
	} if (grid[x+1][y+1] == 1 && (x + 1) < ROWS && (y + 1) < COLS) {
		count += 1;
	} if (grid[x+1][y-1] == 1 && (x + 1) < ROWS && (y - 1) >= 0) {
		count += 1;
	} if (grid[x][y-1] == 1 && (y - 1) >= 0) {
		count += 1;
	} if (grid[x][y+1] == 1 && (y + 1) < COLS) {
		count += 1;
	}
	return count;
}
