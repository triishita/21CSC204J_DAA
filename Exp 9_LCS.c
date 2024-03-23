#include <stdio.h>
#include <string.h>

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(char X[], char Y[], int m, int n, char result[]) {
    // Initializing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
    int i, j;
    // Following steps build L[m+1][n+1] in bottom up fashion.
    // Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }
    
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    int length = L[m][n];
    
    // Backtrack to find the LCS string
    int index = length;
    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    // Null-terminate the LCS string
    result[length] = '\0';
    
    return length;
}


// Driver code
int main() {
    char S1[100], S2[100], lcsString[100];
    printf("Enter string 1: ");
    scanf("%s", S1);
    printf("Enter string 2: ");
    scanf("%s", S2);

    int m = strlen(S1);
    int n = strlen(S2);

    // Function call
    int length = lcs(S1, S2, m, n, lcsString);
    
    // Printing the length of LCS and the LCS string
    printf("Length of LCS is %d\n", length);
    printf("LCS string is: %s\n", lcsString);

    return 0;
}
