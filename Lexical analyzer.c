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
                   (input[i] >= 'A' && input[i] <= 'Z') ) {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            i--;  // Adjust for the last increment in the loop

            // Check if it's a keyword
            if (strcmp(word, "int") == 0 || strcmp(word, "return") == 0 ||
                strcmp(word, "if") == 0 || strcmp(word, "else") == 0) {
                printf("%s is a keyword\n", word);
            } else {
                printf("%s is an variable\n", word);
            }

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
        }
    }

    return 0;
}
