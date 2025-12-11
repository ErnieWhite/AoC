#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[10];
    char direction;
    int distance = 0;
    int position = 50; // the dial starts at 50
    int password = 0;

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

        printf("%s\t", buffer); //

        sscanf(buffer, "%c%d", &direction, &distance);

        if (direction == 'L') {
            position -= distance;
        } else {
            position += distance;
        }


        position = (position % 100 + 100) % 100; // wrap around 0-99 safely

        if (position == 0) {
            password++;
        }

        printf("%c %d -> %d\n",direction, distance, position);
    }

    printf("Password: %d\n", password);

    fclose(fp);
    return 0;
}