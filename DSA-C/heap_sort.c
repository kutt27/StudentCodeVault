#include <stdio.h>

// swap function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//heapify function
void heapify(int arr[], int size, int i){
	//find the largest among root, left and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < size && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < size && arr[right] > arr[largest]){
		largest = right;
	}

	//swap and continue heapifying if root is not largest
	if(largest != i){
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest);
	}
}

// heap sort function
void heapsort(int arr[], int size){
	// build max heap
	for(int i = size / 2 - 1; i >= 0; i--){
		heapify(arr, size, i);
	}

	//heap sort
	for(int i = size - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		//heapify root element to get highest element at root again
		heapify(arr, i , 0);
	}
}

// Print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i){
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
  
  // Driver code
  int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
  
    heapsort(arr, size);
  
    printf("Sorted array is \n");
    printArray(arr, size);
  }