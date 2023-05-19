#include <stdio.h>  
int linearSearch(int a[], int n, int key) {
  for (int i = 0; i < n; i++){  
        if (a[i] == key)  
        return i;  
    }  
  return -1;  
}  
int main() {  
  	int arr[20], size;
	int key;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	for(int i = 0; i < size; i++){
		printf("\nGive the %d element: ", i);
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("\nWhich element you need to search: ");
	scanf("%d",&key);  
	int value = linearSearch(arr, size, key);
  	if (value == -1)  
  		printf("\nElement is not present in the array");  
  	else  
  		printf("\nElement is found on index %d of the array", value);  
  	return 0;  
} 