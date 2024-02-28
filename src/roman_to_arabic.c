#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define NMAX 16  // +1 на \0

int input(char str[NMAX], int *size);
int to_value(char ch);

int main(void) {
    int size = 0;
    char str[NMAX] = "";
    int in = input(str, &size);
    if (in == 1) {
        fprintf(stderr, "%s", "Puck you, Verter!");
        return 1;
    } else if (in == 2) {
        printf("%d", 0);
    } else {
        int res = 0;
        int i = 0;
        while (i < size) {
            int prev = to_value(str[i]);
            int next = to_value(str[i + 1]);
            if (prev < next) {
                res = res + next - prev;
                i += 2;
            } else {
                res = res + prev;
                i++;
            }
        }
        printf("%d", res);
    }
    return 0;
}

int input(char str[NMAX], int *size) {
    int exit = 0;
    int count = 0;
    while (scanf("%c", &str[count]) == 1 && str[count] != '\n') {
        str[count] = toupper(str[count]);
        if (str[count] != 'I' && str[count] != 'V' && str[count] != 'X' && str[count] != 'L' &&
            str[count] != 'D' && str[count] != 'M' && str[count] != 'C' && str[count] != 'N' &&
            str[count] != 'H' && str[count] != 'U' && str[count] != 'A') {
            exit = 1;
            break;
        }
        count++;
    }
    if (strcmp(str, "NULLA\n") == 0 || strcmp(str, "N\n") == 0 || strcmp(str, "NIHIL\n") == 0) {
        exit = 2;
    }
    *size = count;
    return exit;
}

int to_value(char ch) {
    int exit = 0;
    if (ch == 'I')
        exit = 1;
    else if (ch == 'V')
        exit = 5;
    else if (ch == 'X')
        exit = 10;
    else if (ch == 'L')
        exit = 50;
    else if (ch == 'C')
        exit = 100;
    else if (ch == 'D')
        exit = 500;
    else if (ch == 'M')
        exit = 1000;
    return exit;
}