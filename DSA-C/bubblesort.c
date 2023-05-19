#include <stdio.h>

void bubblesort(int arr[], int size){
	for(int step = 0; step < size - 1; step++){
		for(int i = 0; i < size - step - 1; i++){
			if(arr[i] > arr[i+1]){
				//swap
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}

//printing array "after/before"
void printarr(int arr[], int size){
	for (int i = 0; i < size; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n")
}

//driver code
void main(){
	
	int data[], i;
	int size;
	printf("Enter the size of array\n");
	scanf("%d",size);
	for(i = 0; i < size + 1; i++){
		printf("\nEnter the data: ");
		scanf("%d", arr[i]);
	}
	bubblesort(arr, size);

	printf("\nSorted Array in ascending order");
	printarr(arr, size);
}