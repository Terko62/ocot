#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int encode(void);
int decode(void);
char * read_input(void);
long pow2(int);

// ================================
// DO NOT MODIFY THE FOLLOWING CODE
// ================================
int main(int argc, char *argv[])
{
    int retcode = 1;

    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-e") == 0)) {
        retcode = encode();
    } else if (argc == 2 && strcmp(argv[1], "-d") == 0) {
        retcode = decode();
    } else {
        fprintf(stderr, "usage: %s [-e|-d]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (retcode != 0) {
        fprintf(stderr, "an error occured\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int decode(void)
{
    // TODO: implement Ascii85 decoding
    return 0;
}

int encode(void)
{
    // TODO: implement Ascii85 encoding
    char *input = read_input();
    long word = 0;
    int i = 0;
    while (i < 1)//(input[i] != '\n')
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Input: %c of value: %d\n",input[i*4+j], input[i*4+j]);
            printf("Multiplicior: %d\n", (int)pow2((3-j)*8));
            printf("%ld\n",(long)input[i*4+j]*((long) pow2((3-j)*8)));
            word += input[i*4+j]*((int) pow2((3-j)*8));
        }
        i++;
    }
    printf("%ld\n",word);
    return 0;
}


//** reads input and returns pointer at start of string
//*
//*/ @return pointer at input
char * read_input(void)
{
    char c[256];
    char *p = c;
    int i = 0;
    printf("into the loop\n");
    int condition = 1;
    do
    {
//        if ((c[i] = getchar())<0)
//        {
//            break;
//        }
        c[i] = getchar();
        printf("Loaded: '%c' of value %d \n", c[i], c[i]);
        i++;
    }
    while (c[i] != '\n');
    int len = i;
    printf("out of the loop\n\n");
    printf("Full load:\n");
    for (i = 0;  i < len; i++)
    {
        printf("%c",p[i]);
    }
    return p;
}

long pow2(int n)
{
    int val = 2;
    for (int i = 0; i < n; i++)
    {
        val *= 2;
    }
    return val;
}