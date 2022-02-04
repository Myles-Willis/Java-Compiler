#include <stdio.h>
#include <stdlib.h>

int main() {
    char *filename = "foo.baz";
    FILE *f = fopen(filename, "r");
    if (f == 0) {
        printf("%s not found.\n", filename);
        exit(0);
    }
    int i = fgetc(f);
    while (i != EOF) {
        printf("%c", (char) i);
        i = fgetc(f);
    }
    return 0;
}