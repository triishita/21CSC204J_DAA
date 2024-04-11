#include <stdio.h>
#include <string.h>

#define d 256

void search(char pat[], char txt[], int q) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i+1);
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char txt[100]; // assuming maximum length of text
    char pat[100]; // assuming maximum length of pattern
    int q;

    printf("Enter the text: ");
    fgets(txt, sizeof(txt), stdin);
    printf("Enter the pattern to search for: ");
    fgets(pat, sizeof(pat), stdin);
    
    // Remove newline characters from input
    txt[strcspn(txt, "\n")] = '\0';
    pat[strcspn(pat, "\n")] = '\0';

    printf("Enter a prime number: ");
    scanf("%d", &q);

    search(pat, txt, q);
    
    return 0;
}
