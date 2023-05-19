#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];

	int i = (low - 1);

	for (int j = low; j < high; ++j) {
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);

}

void quicksort(int arr[], int low, int high){
	if(low < high){
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}

void printArr(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[] = {8, 7, 2, 1, 0, 9, 6};
  
  int size = sizeof(arr) / sizeof(arr[0]);
  
  printf("Unsorted Array\n");
  printArr(arr, size);

  
  // perform quicksort on data
  quicksort(arr, 0, size - 1);
  
  printf("Sorted array in ascending order: \n");
  printArr(arr, size);
}