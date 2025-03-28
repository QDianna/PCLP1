#include "utils.h"

void fcaesar(int key, char encrypted_msg[1000], char initial_msg[1000]) {
    int lenght = strlen(encrypted_msg);

        for (int i = 0; i < lenght; i++) {
            if (encrypted_msg[i] >= 'a' && encrypted_msg[i] <= 'z') {
                if (key <= encrypted_msg[i]- 'a') {
                    initial_msg[i] = encrypted_msg[i] - key;

                } else {
                    int keycpy = key;
                    keycpy -= (encrypted_msg[i]- 'a');
                    keycpy = keycpy % 26;
                    if (keycpy == 0)
                        initial_msg[i] = 'a';
                    else
                        initial_msg[i] = 'z' - keycpy + 1;
                }
            }

            if (encrypted_msg[i] >= '0' && encrypted_msg[i] <= '9') {
                if (key <= encrypted_msg[i]- '0') {
                    initial_msg[i] = encrypted_msg[i] - key;

                } else {
                    int keycpy = key;
                    keycpy -= (encrypted_msg[i]- '0');
                    keycpy = keycpy % 10;
                    if (keycpy == 0)
                        initial_msg[i] = '0';
                    else
                        initial_msg[i] = '9' - keycpy + 1;
                }
            }

            if (encrypted_msg[i] >= 'A' && encrypted_msg[i] <= 'Z') {
                if (key <= encrypted_msg[i] - 'A') {
                    initial_msg[i] = encrypted_msg[i] - key;

                } else {
                    int keycpy = key;
                    keycpy -= (encrypted_msg[i] - 'A');
                    keycpy = keycpy % 26;
                    if (keycpy == 0)
                        initial_msg[i] = 'A';
                    else
                        initial_msg[i] = 'Z' - keycpy + 1;
                }
            }
        }
        initial_msg[lenght] = NULL;
}

void SolveTask2() {
    char cipher[20], encrypted_msg[1000], initial_msg[1000];
    int key = 0;

    scanf("%s", cipher);
    scanf("%d\n", &key);
    scanf("%[^\n]s", encrypted_msg);

    if (strcmp(cipher, "caesar") == 0)
        fcaesar(key, encrypted_msg, initial_msg);

    printf("%s", initial_msg);
}
