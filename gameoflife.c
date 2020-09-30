/*
 * model.c
 * provides the grid (model) 
 * and functions to handle the grid for the game of life
 */
#include "gameoflife.h"
int grid[M][N] = {0}; 	/*M and N are constants defined in gameOfLife.h*/

/**
 * seçilen başlangıç ​​durumuna göre başlatır
 */
 

int initGrid(int initialState){
	int x,y;
	if(initialState==1){
		for(x=4; x<M; x=x+10){  /*blinker koyulması*/
			for(y=4; y<x; y=y+10){
		 }
	    
	    grid[x-1][y]=1;
		grid[x][y]=1;
		grid[x+1][y]=1;
		}
	}
	else if(2==initialState){  /*glider koyulması*/
		for(int x=4; x<N; x=x+10){
			for(y=4; y<x; y=y+10){
		    }
		    grid[x-1][y]=1;
		    grid[x][y-2]=1;
		    grid[x][y]=1;
		    grid[x+1][y-1]=1;
		    grid[x+1][y]=1;
	    }
    }
    return 0;

}

/**
 * pozisyondaki (x, y) hücrenin canlı komşularının sayısını döndürür
 */
int getNumberOfLiveNeighbors(int x, int y){
	 int sidecells=0; /*komşu sayısını tutar*/
     for(int a=x-1; a <= x+1; a++){
	     for(int b=y-1; b<= y+1; b++){
			   if(!(a==x && b==y)){
				   if(grid[a][b]==1){
				      sidecells++;
		       }
	        }
	     }
     }
	return sidecells;
	
}

/**
 * oyununun güncelleme kurallarını takip ederek her bir hücreyi günceller
 */
int updateGrid(){
	
	int grid_available[M][N];  /* değişmeyen değerleri saklar */
	int neighbor[M][N]; /* (x,y) noktasındaki canlı komşu sayısını tutar */
	for(int x=0; x<M; x++){
		for(int y=0; y<N; y++){
			neighbor[x][y]=getNumberOfLiveNeighbors(x,y);
			
			if(neighbor[x][y]<2){        /*2'den büyükse*/
				grid_available[x][y]=0;
			}
			if(neighbor[x][y]==3){       /*3'e eşit olduğunda canlıysa değişmemesini ölüyse canlı olmasını sağlar */
				grid_available[x][y]=1;
			}
			if(neighbor[x][y]==2){       /*2'e eşitse önceki değerin aynı kalmasını sağlar */
				grid_available[x][y]=grid[x][y];
			}
			else if(neighbor[x][y]>3){   /*3'den büyükse*/
				grid_available[x][y]=0;
			}
	    }
   }
   for(int a=0; a<M; a++){            /*değişmeyen değerleri gride yerleştirir*/
		for(int b=0;  b<N; b++){
			grid[a][b]=grid_available[a][b];
        }
   }
	return 0;
}
