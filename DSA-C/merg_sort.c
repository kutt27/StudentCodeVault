#include <stdio.h>

// merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r){
	// create L -> arr[p..q] and M -> arr[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], M[n2];

	for (int i = 0; i < n1; i++){
    	L[i] = arr[p + i];
	}
  	for (int j = 0; j < n2; j++){
    	M[j] = arr[q + 1 + j];
  	}

    // maintaining current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    // until we reach eaither end of L or M, pick larger among elements
    // L and M and place them in the correct position at arr[p..r]
    while(i < n1 && j < n2){
    	if(L[i] <= M[j]){
    		arr[k] = L[i];
    		i++;
    	}
    	else{
    		arr[k] = M[j];
    		j++;
    	}
    	k++;
    }

    //when running out of elements in either M or L, pick up the remaining
    //element and put it into arr[p..r]
    while(i < n1){
    	arr[k] = L[i];
    	i++;
    	k++;
    }

    while(j < n2){
    	arr[k] = M[j];
    	j++;
    	k++;
    }
}

// divide the array into two subarrays, sort them and merge them
void mergesort(int arr[], int l, int r){
	if(l < r){
		 //q is the point where the array is divided into two subarrays
		int q = (l + r) / 2;

		mergesort(arr, l, q);
		mergesort(arr, q + 1, r);

		//merge the sorted subarrays
		merge(arr, l, q, r);
	}
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[0]);
  printf("\n");
}

void main(){
	int arr[] = {6, 5, 12, 10, 9, 1};
	int size = sizeof(arr) / sizeof(arr[0]);

	mergesort(arr, 0, size - 1);

	printf("Sorted array: \n");
	printArray(arr, size);
}