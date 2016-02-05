#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

static struct option const long_opts[] =
{
  {"bytes", required_argument, NULL, 'b'},
  {"input-file", required_argument, NULL, 'i'},
  {"output-file", required_argument, NULL, 'o'},
  {NULL, 0, NULL, 0}
};

int main(int argc, char *argv[])
{
        if (argc%2 != 1)
        {
                printf("USAGE: %s -i <input> -o <output> -b <bytes>\n", argv[0]);
                exit(1);
        }
        int i;
        int BUFFER_SIZE = 512;
        FILE *input, *output;
        char c;
        while ((c = getopt_long (argc, argv, "b:o:i:", long_opts, NULL))
                        != -1)
        {
                switch (c)
                {
                        case 'b':
                                BUFFER_SIZE = atoi(optarg);
                                if (BUFFER_SIZE < 4) BUFFER_SIZE = 512;
                                break;
                        case 'i':
                                input = fopen(optarg, "r+");
                                break;
                        case 'o':
                                output = fopen(optarg, "w");
                                break;
                        default:
                                printf("%d", c);
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
