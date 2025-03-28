#include "utils.h"

int fprime(int x) {
    if (x < 2 || x%2 == 0 )
        return 0;

    for (int d = 3; d*d <= x; d++) {
        if (x%d == 0)
            return 0;
        d++;
    }

    return 1;
}

int fpalindrome(int n1, int n2, char *s) {
    while ( n1 < n2 ) {
        if (s[n1] != s[n2]) {
            return 0;}
        n1++, n2--;
    }

    return 1;
}

void SolveTask1() {
    int N = 0, M = 0, maze[100][100] = {0};
    char code[500];
    scanf("%d %d\n", &N, &M);

    /*
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
    */

    scanf("%[^\n]s", code);

    int iposition = 0, jposition = 0, move = 0, move_num = 2;
    maze[0][0] = 1;

    char *word = strtok(code, " ");

    while (word) {
        if (word[0] == 'a') {
            char max_num = '0';
            for (int i = 1; i < strlen(word); i++)
                if (word[i] >= max_num) {
                    max_num = word[i];
                    move = i;
                }

            if (move == 1)  // dreapta
                    jposition++;
            if (move == 2)  // sus
                    iposition--;
            if (move == 3)  // stanga
                    jposition--;
            if (move == 4)  // jos
                    iposition++;
        }

        if (word[0] == 'b') {
            int prime = fprime(10 * (word[strlen(word) - 2] - '0') + \
                               (word[strlen(word) - 1] - '0'));

            int palindrome = fpalindrome(1, strlen(word)-1, word);

            if (palindrome && prime)  // stanga
                jposition--;
            if (palindrome && !prime)  // dreapta
                jposition++;
            if (!palindrome && prime)  // sus
                iposition--;
            if (!palindrome && !prime)  // jos
                iposition++;
        }

        if (word[0] == 'c') {
            int  n = word[1] - '0', k = word[2] - '0';
            int step = 3, cpyk = k, S = 0;

            while (cpyk) {
                if (step <= n + 2) {
                    S += word[step] - '0';
                    step += k;
                    cpyk--;
                } else {
                      step = (step-3) % n + 3;
                }
            }

            int r = S%4;

            if (r == 0) jposition--;  // stanga
            if (r == 1) iposition--;  // sus
            if (r == 2) jposition++;  // dreapta
            if (r == 3) iposition++;  // jos
        }

        maze[iposition][jposition] = move_num++;

        word = strtok(NULL, " ");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
}
