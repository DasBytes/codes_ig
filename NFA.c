#include <stdio.h>
#include <string.h>

void stateX(const char *n);
void stateY(const char *n);
void stateZ(const char *n);

void stateX(const char *n) {
    if (strlen(n) == 0) {
        printf("string not accepted\n");
    } else {
        if (n[0] == 'a') {
            stateY(n + 1);
        } else if (n[0] == 'b') {
            printf("string not accepted\n");
        }
    }
}

void stateY(const char *n) {
    if (strlen(n) == 0) {
        printf("string not accepted\n");
    } else {
        if (n[0] == 'a') {
            printf("string not accepted\n");
        } else if (n[0] == 'b') {
            stateZ(n + 1);
        }
    }
}

void stateZ(const char *n) {
    if (strlen(n) == 0) {
        printf("string accepted\n");
    } else {
        if (n[0] == 'a') {
            stateZ(n + 1);
        } else if (n[0] == 'b') {
            stateZ(n + 1);
        }
    }
}

int main() {

    const char *n1 = "a";
    printf("%s\n", n1);
    stateX(n1);

    const char *n2 = "ba";
    printf("%s\n", n2);
    stateX(n2);

    const char *n3 = "abab";
    printf("%s\n", n3);
    stateX(n3);

    const char *n4 = "ab";
    printf("%s\n", n4);
    stateX(n4);

    return 0;
}
