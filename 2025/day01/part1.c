#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[10];

    // file to read is specified on the command line.
    if (argc != 2) {
        printf("Usage: %s <file path>\n",argv[0]);
        return 1;
    }

    // Open file in read mode
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Read file one line at a time
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {

        // the text in buffer includes the newline if present, so get rid of it
        if (buffer[strlen(buffer)-1]=='\n'){
            buffer[strlen(buffer)-1] = '\0';
        }

        printf("%s\n", buffer); //
    }

    fclose(fp);
    return 0;
}