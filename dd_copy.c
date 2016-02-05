#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        if (argc%2 != 1) {
                printf("USAGE: %s -i <input> -o <output>\n", argv[0]);
                exit(1);
        }
        int i;
        int BUFFER_SIZE = 512;
        FILE *input, *output;
        for(i=1; i<argc; ++i) {
                if (strcmp(argv[i], "-i") == 0) {
                        ++i;
                        input = fopen(argv[i], "r+");
                }
                if (strcmp(argv[i], "-o") == 0) {
                        ++i;
                        output = fopen(argv[i], "w");
                }
                if (strcmp(argv[i], "-b") == 0) {
                        ++i;
                        BUFFER_SIZE = atoi(argv[i]);
                        if (BUFFER_SIZE < 4) BUFFER_SIZE = 512;
                }
        }
        if (!input) input = stdin;
        if (!output) output = stdout;

        char in[BUFFER_SIZE];

        while (NULL != fgets(in, BUFFER_SIZE-1, input)) {
                fprintf(output, "%s", in);
        }

        return 0;
}
