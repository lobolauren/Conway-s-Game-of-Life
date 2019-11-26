#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define ROWS 20
#define COLS 40

void printGrid(int grids[ROWS][COLS],int ticker) {
	int i, j;
	printf(" ---------------------------------------- \n");
    for (i = 0; i < ROWS; i++) {
    	printf("|");
        for (j = 0; j < COLS; j++) {
        	if (grids[i][j] == 1) {
        		printf("X");
        	} else {
        		printf(" ");
        	}
        }
        printf("|");
        printf("\n");
    }
    printf(" ---------------------------------------- %d\n",(ticker));

}
