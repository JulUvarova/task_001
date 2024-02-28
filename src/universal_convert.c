#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define NMAX 16  // +1 на \0

int input_rom(char str[NMAX], int *size);
int to_value(char ch);
int to_arabic();
int to_roman();
void repeat(int count, char ch);
void print(int num, char min, char med, char max);

int main(void) {
    int case_v = 0;
    if ((scanf("%d", &case_v) != 1 || case_v < 1 || case_v > 2) || (case_v == 1 && to_arabic() == 1) ||
        (case_v == 2 && to_roman() == 1)) {
        fprintf(stderr, "%s", "Puck you, Verter!");
        return 1;
    }
    return 0;
}

int to_arabic() {
    int exit = 0;
    char str[NMAX] = "";
    int size = 0;
    int in = input_rom(str, &size);
    if (in == 1) {
        exit = 1;
    } else if (in == 2) {
        printf("0");
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
    return exit;
}

int to_roman() {
    int exit = 0;
    int number = 0;
    if (scanf("%d", &number) != 1 || number < 0 || number > 3999) {
        exit = 1;
    } else if (number == 0) {
        printf("nulla");
    } else if (number > 999) {
        int unit = number % 10;
        int decade = number / 10 % 10;
        int hundred = number / 100 % 10;
        repeat(number / 1000, 'M');
        print(hundred, 'C', 'D', 'M');
        print(decade, 'X', 'L', 'C');
        print(unit, 'I', 'V', 'X');
    } else if (number > 99) {
        int unit = number % 10;
        int decade = number / 10 % 10;
        int hundred = number / 100;
        print(hundred, 'C', 'D', 'M');
        print(decade, 'X', 'L', 'C');
        print(unit, 'I', 'V', 'X');
    } else if (number > 9) {
        int unit = number % 10;
        int decade = number / 10;
        print(decade, 'X', 'L', 'C');
        print(unit, 'I', 'V', 'X');
    } else {
        print(number, 'I', 'V', 'X');
    }
    return exit;
}

void print(int num, char min, char med, char max) {
    if (num <= 3) {
        repeat(num, min);
    } else if (num == 4) {
        printf("%c%c", min, med);
    } else if (num == 5) {
        printf("%c", med);
    } else if (num < 9) {
        printf("%c", med);
        repeat(num - 5, min);
    } else if (num == 9) {
        printf("%c%c", min, max);
    }
}

int input_rom(char str[NMAX], int *size) {
    int exit = 0;
    if (scanf("%15s", str) != 1) {
        exit = 1;
    } else {
        *size = strlen(str);
        for (int i = 0; i < *size; i++) {
            str[i] = toupper(str[i]);
            if (str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'D' &&
                str[i] != 'M' && str[i] != 'C' && str[i] != 'N' && str[i] != 'H' && str[i] != 'U' &&
                str[i] != 'A') {
                exit = 1;
                break;
            }
        }
    }
    if (strcmp(str, "NULLA") == 0 || strcmp(str, "N") == 0 || strcmp(str, "NIHIL") == 0) {
        exit = 2;
    }
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

void repeat(int count, char ch) {
    for (int i = 0; i < count; i++) {
        printf("%c", ch);
    }
}