#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
        if (argc%2 != 1) {
                printf("USAGE: %s -i <input> -o <output>\n", argv[0]);
        }
        int i;
        int BUFFER_SIZE = 512;
        FILE *input, *output;
        for(i=1; i<argc; ++i) {
                printf("argument %d : %s\n", i, argv[i]);
                if (strcmp(argv[i], "-i") == 0) {
                        printf("flag matches\n");
                        ++i;
                        input = fopen(argv[i], "r+");
                }
                if (strcmp(argv[i], "-o") == 0) {
                        printf("flag matches\n");
                        ++i;
                        output = fopen(argv[i], "w");
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
