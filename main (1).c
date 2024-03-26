#include <stdbool.h>
#include <stdio.h>

int N;

void printSolution(int board[N][N], int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(board[i][j])
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col, int N)
{
	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQUtil(int board[N][N], int col, int N)
{
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col, N)) {
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1, N))
				return true;
			board[i][col] = 0;
		}
	}

	return false;
}

bool solveNQ(int N)
{
	int board[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}

	if (solveNQUtil(board, 0, N) == false) {
		printf("Solution does not exist");
		return false;
	}

	printSolution(board, N);
	return true;
}

int main()
{
	printf("Enter the value of N: ");
	scanf("%d", &N);
	solveNQ(N);
	return 0;
}
