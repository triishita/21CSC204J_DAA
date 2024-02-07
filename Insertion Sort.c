// C program for insertion sort
#include <math.h>
#include <stdio.h>
 
/* Function to sort an array 
using insertion sort*/
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        //swapping
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
int main() {
    int n;
    printf("Enter no. of elements: "); //input from user
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: "); //input from user
    for(int i=0; i<n;i++) {
        scanf("%d",&arr[i]);
    }
    insertionSort(arr, n); //function call
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
