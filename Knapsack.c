#include <stdio.h>
#include <stdlib.h>

struct Item {
	int profit, weight;
};

int cmp(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double r1 = (double)item1->profit / (double)item1->weight;
    double r2 = (double)item2->profit / (double)item2->weight;
    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    else
        return 0;
}

double fractionalKnapsack(int W, struct Item arr[], int N) {
	qsort(arr, N, sizeof(struct Item), cmp);

	double finalvalue = 0.0;

	for (int i = 0; i < N; i++) {
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}
		else {
			finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
			break;
		}
	}

	return finalvalue;
}

int main() {
	int W, N;

	printf("Enter the knapsack capacity: ");
	scanf("%d", &W);

	printf("Enter the number of items: ");
	scanf("%d", &N);

	struct Item *arr = (struct Item *)malloc(N * sizeof(struct Item));

	printf("Enter the profit and weight of each item:\n");
	for (int i = 0; i < N; i++) {
		printf("Item %d: ", i + 1);
		scanf("%d %d", &arr[i].profit, &arr[i].weight);
	}

	printf("Maximum value in knapsack = %.2lf\n", fractionalKnapsack(W, arr, N));

	free(arr);
	
	return 0;
}
