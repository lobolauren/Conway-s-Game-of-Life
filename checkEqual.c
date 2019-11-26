#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define ROWS 20
#define COLS 40

int checkEqual(int grid1[ROWS][COLS],int grid2[ROWS][COLS]) {
	int i,j =0;
	

	/*while (starter==0){*/
	for (i=0;i<ROWS;i++){
		for (j=0;j<COLS;j++){
			if (grid1[i][j]!=grid2[i][j]){
				return false;

	}
	}
}
return true;
}
