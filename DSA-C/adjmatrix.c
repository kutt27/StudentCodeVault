#include <stdio.h>
#define V 4

//initialize the matrix to zero
void init(int arr[][V]){
	int i, j;
	for( i=0; i < V; i++){
		for(j=0 ; j < V; j++){
			arr[i][j];
		}
	}
}

//adding edge
void addedge(int arr[][V], int i, int j){
	arr[i][j] = 1;
	arr[j][i] = 1;
}

//print the matrix
void printMatrix(int arr[][V]){
	int i, j;

	for(i = 0; i < V; i++){
		printf("%d",i);
		for(j = 0; j < V; j++){
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}

//driver code
int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  addedge(adjMatrix, 0, 1);
  addedge(adjMatrix, 0, 2);
  addedge(adjMatrix, 1, 2);
  addedge(adjMatrix, 2, 0);
  addedge(adjMatrix, 2, 3);

  printMatrix(adjMatrix);

  return 0;
}