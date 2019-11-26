#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ROWS 20
#define COLS 40

/*
 * Program Name:cgol.c
 * Author(s): Lauren Lobo
 * Purpose:
 */
#include "printGrid.c"
#include "checkAlive.c"
#include "checkEqual.c"

int main ( int argc, char *argv[] ) {

	FILE *f1;
	FILE *f2;
	int array[100000];
	int grid[ROWS][COLS];
	int futureGrid[ROWS][COLS];
	int cycle=0;
	int tickNum=1;
	int neighbours = 0;
	int cont =1;
	int sameTick = 1;
	int a,j = 0;
	char start[3];
	char next[3];
	char newTick[10];
	int reAsk=1;
	int yorn =1;
	
	int counter=0;

		if (argc == 3){
			cycle = atoi(argv[2]);
		}else{
			cycle = 50;

		}



		if (argc < 2 || argc>3){
			printf("usage: ./cgol filename.seed ##\n");
		}

		char *file = argv[1];
		f1= fopen(file, "r");
		char *file2 = argv[1];
		f2= fopen(file2, "r");
		if (f1 == NULL){
			printf("Invaild file: file cannot be found\n");
			exit(1);
		}

		 	for(a = 0; a < ROWS; a++) {
		 		for (j = 0; j < COLS; j++) {
		 			fscanf(f1,"%d", &grid[a][j]);
		 		}
		 	}
			while (fscanf(f2,"%d",&array[counter])==1){
				counter++;
			}

			if (counter !=800){
				printf("invalid file due to size. This program accepts 20X40. \n");
				exit(1);
			}

		printGrid(grid,tickNum);
		while (yorn==1){
			printf("Would you like to start?[y or n] : ");
			fgets(start,300,stdin);
			if ((strcmp(start,"y\n")==0)||(strcmp(start,"Y\n")==0)){
				cont = 1;
				yorn=0;
			}else if ((strcmp(start,"n\n")==0)||(strcmp(start,"N\n")==0)){
				cont = 0;
				yorn =0;
				printf("Thanks for playing conway's game of life!\n");
			}else{
				printf("inalid input: must be y or n\n");
				yorn = 1;
			}
	}
			while((cont == 1 )&& (tickNum < cycle) ){
				system("clear");
				printGrid(grid,tickNum);
				system("sleep 0.25");



				for(a = 0; a < ROWS; a++) {
					for (j = 0; j < COLS; j++) {

						if (grid[a][j] == 1) {
							neighbours = checkAlive(grid,a,j);
						if(neighbours < 2 || neighbours > 3){
												 futureGrid[a][j] = 0;
						}else{
												 futureGrid[a][j] = 1;
	   				 }

							neighbours = 0;
						} else if (grid[a][j] == 0) {
								neighbours = checkAlive(grid,a,j);
							if (neighbours == 3) {
								futureGrid[a][j] = 1;
							} else {
								futureGrid[a][j] = 0;
							}
							neighbours = 0;
						}
					}
				}

						if (checkEqual(grid,futureGrid)){
							printf("The seed will no longer change. The program will now exit\n");
							cont=0;
						}

				tickNum++;
				system("clear");
				printGrid(futureGrid,tickNum);


				/*printf("%d\n", tickNum);*/
				system ( "sleep 0.25" );

				for (a = 0; a < ROWS; a++) {
					for (j = 0; j < COLS; j++) {
						if (grid[a][j] != futureGrid[a][j]) {
							sameTick = 0;
						}
					}
				}
				if (sameTick == 1) {
					cont = 0;
				}
				for (a = 0; a < ROWS; a++) {
					for (j = 0; j < COLS; j++) {
						grid[a][j] = futureGrid[a][j];
					}
				}
				reAsk =1;
				if (tickNum == cycle) {
					while (reAsk ==1){
						printf("Continue? (y or n) \n");
						fgets(next, 300, stdin);
						if (strcmp(next, "y\n") == 0) {
							printf("How many ticks would you like to view ");
							fgets(newTick, 10, stdin);
							cycle += atoi(newTick);
							cont = 1;
							reAsk = 0;
						} else if (strcmp(next, "n\n") == 0) {
							printf("Thanks for playing conway's game of life!\n");
							cont = 0;
							reAsk=0;
						}else{
							reAsk =1;
						}
				}
			}
		}


	return (0);
}
