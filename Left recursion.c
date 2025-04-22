#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char* production) {
    char nonTerminal = production[0];
    char Alpha[50] = " ", Beta[50] = " ";
    int i = 3;

    //alpha
    if (production[i] == nonTerminal) {
        i++;
        int j = 0;
        while (production[i] != '|' && production[i] != '\0') {
            Alpha[j++] = production[i++];
        }
        Alpha[j] = '\0';
    }

//for beta
    if (production[i] == '|') {
        i++;
        int k = 0;
        while (production[i] != '\0') {
            Beta[k++] = production[i++];
        }
        Beta[k] = '\0';
    }


    // Print alpha and beta
    printf("Alpha: %s\n", Alpha);
    printf("Beta: %s\n", Beta);

    //  grammar without left recursion
    printf("%c -> %s%c'\n", nonTerminal, Beta, nonTerminal);
    printf("%c' -> %s%c' | Epsillon\n", nonTerminal, Alpha, nonTerminal);
}

int main() {
    char production[100];
    printf("Enter a production: ");
    scanf("%s", production);
    eliminateLeftRecursion(production);

    return 0;
}

