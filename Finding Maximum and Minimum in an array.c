#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, leftMinmax, rightMinmax;
    int mid;

    // If there is only one element
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    leftMinmax = findMinMax(arr, low, mid);
    rightMinmax = findMinMax(arr, mid + 1, high);

    // Compare minimums and maximums of two halves
    if (leftMinmax.min < rightMinmax.min)
        minmax.min = leftMinmax.min;
    else
        minmax.min = rightMinmax.min;

    if (leftMinmax.max > rightMinmax.max)
        minmax.max = leftMinmax.max;
    else
        minmax.max = rightMinmax.max;

    return minmax;
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair minmax = findMinMax(arr, 0, n - 1);
    printf("Minimum element: %d\n", minmax.min);
    printf("Maximum element: %d\n", minmax.max);

    return 0;
}
