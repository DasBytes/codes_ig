#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z')) {

            char word[20];
            int j = 0;
            while ((input[i] >= 'a' && input[i] <= 'z') ||
                   (input[i] >= 'A' && input[i] <= 'Z')) {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            i--;

            if (strcmp(word, "int") == 0 || strcmp(word, "return") == 0 ||
                strcmp(word, "if") == 0 || strcmp(word, "else") == 0) {
                printf("%s is a keyword\n", word);
            } else {
                printf("%s is a variable\n", word);
            }

        } else if (input[i] >= '0' && input[i] <= '9') {  // Number detection
            char number[20];
            int j = 0;
            while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
                number[j++] = input[i++];
            }
            number[j] = '\0';
            i--;
            printf("%s is a number\n", number);

        } else if (input[i] == '=' || input[i] == '>' || input[i] == '<' ||
                   input[i] == '!' || input[i] == '&' || input[i] == '|' ||
                   input[i] == '+' || input[i] == '-' || input[i] == '*' ||
                   input[i] == '/' || input[i] == '%') {

            printf("%c", input[i]);

            if ((input[i] == '>' && input[i + 1] == '=') ||
                (input[i] == '<' && input[i + 1] == '=') ||
                (input[i] == '!' && input[i + 1] == '=') ||
                (input[i] == '&' && input[i + 1] == '&') ||
                (input[i] == '|' && input[i + 1] == '|')) {
                printf("%c", input[++i]);
            }
            printf(" is an operator\n");

        } else if (input[i] == ';') {  // Semicolon detection
            printf("; is a colon\n");
        }
    }

    return 0;
}
