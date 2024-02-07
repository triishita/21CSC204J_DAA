//linear search
#include <stdio.h>
void linearsearch(int arr[],int n,int key) {
    int element_found = 0,i;
    for (i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            element_found = 1;
            break;
        }
    }
    if (element_found == 1)
        printf("key found at position %d",i+1); //element found
    else
        printf("key not found in the array\n"); //element not found
}
int main() {  
    int n, i, key;
    printf("Enter number of elements: "); //input from user
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter array: "); //input from user
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //input element to be searched
    printf("\nEnter the key element to be searched: "); 
    scanf("%d", &key);
    linearsearch(arr,n,key); //function call
    return 0;
}
