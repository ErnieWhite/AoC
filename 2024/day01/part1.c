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
    int left_location_ids[1000] = { 0 };
    int right_location_ids[1000] = { 0 };

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
        printf("%d %d", first_num, second_num);

        left_location_ids[count] = first_num;
        right_location_ids[count] = second_num;

        count++;
    }

    fclose(fp);
    qsort(left_location_ids, 1000, sizeof(int),compare_function);
    qsort(right_location_ids, 1000, sizeof(int),compare_function);

    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += abs(left_location_ids[i] - right_location_ids[i]); 
        printf("%d %d %d %d\n",i, left_location_ids[i], right_location_ids[i], abs(left_location_ids[i] - right_location_ids[i]));
    }

    printf("\n");
    printf("Sum: %d\n", sum);


    return 0;
}
