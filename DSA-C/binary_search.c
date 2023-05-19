#include <stdio.h> 

void swap(int* x, int* y) {
    int temp = *xp;
    *x = *y;
    *y = temp;
}

int binarySearch(int a[], int beg, int end, int val){    
    int mid;    
    if(end >= beg){
        mid = beg + (end - beg) / 2;
        if(a[mid] == val){                 
            return mid+1;    
        }
        else if(a[mid] < val){  
            return binarySearch(a, mid+1, end, val);    
        }
        else{  
            return binarySearch(a, beg, mid-1, val);    
        }          
    }    
    return -1;     
}  

int main() {  
    int arr[20], size, temp;
    int key;
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    for(int i = 0; i < size; i++){
        printf("\nGive the %d element: ", i);
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < size; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    printf("\n");

    printf("\nWhich element you need to search: ");
    scanf("%d",&key);  
    int value = binarySearch(arr, 0, size-1, key);
    if (value == -1)  
        printf("\nElement is not present in the array");  
    else  
        printf("\nElement is found on index %d of the array", value);  
    return 0;  
} 