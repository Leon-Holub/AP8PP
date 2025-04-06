#include <stdio.h>

int main()
{
    while(!feof(stdin)){
        fprintf(stdout, "Char: %c\n", fgetc(stdin));
        fflush(stdout);
    }
    return 0;
}


