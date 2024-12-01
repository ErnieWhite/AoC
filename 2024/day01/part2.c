#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_function(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;

    return *x - *y;
}

int main(int argc, char *argv[])
{

    FILE *fp;
    char filename[100] = "input.txt";

    if (argc > 1) {
        strncpy(filename, argv[1], 100);
    }


    // array to store the numbers
    int left[1000] = { 0 };
    int right[1000] = { 0 };

    // Open the file in read mode
    fp = fopen(filename, "r");

    // Check if the file opened successfully
    if (fp == NULL) {
        printf("Error opoening the file.\n");
        return 1;
    }

    int count = 0;
    char buffer[100];
    int first_num;
    int second_num;

    while (fgets(buffer, 100, fp) != NULL) {
        sscanf(buffer, "%d %d", &first_num, &second_num);

        left[count] = first_num;
        right[count] = second_num;

        count++;
    }

    fclose(fp);
    qsort(left, 1000, sizeof(int), compare_function);
    qsort(right, 1000, sizeof(int), compare_function);

    int simularity = 0;
    for (int i = 0; i < 1000; i++) {
        count = 0;
        for (int j = 0; j < 1000; j++) {
            if (left[i] == right[j]) {
                count++;
            }
        }
        simularity  += left[i] * count;
    }

    printf("\n");
    printf("Simularity: %d\n", simularity);


    return 0;
}
