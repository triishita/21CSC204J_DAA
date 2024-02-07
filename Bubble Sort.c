//bubble sort
#include <stdio.h>  
  
//funcion for sorting array
void bubble_sort(int arr[], int n) {  
  int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (arr[j] > arr[j + 1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
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
    bubble_sort(arr, n); //function call
    printf("Sorted array: "); //final sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  
    }  
    return 0;  
}  
