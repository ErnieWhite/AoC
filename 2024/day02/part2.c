/*
 * --- Day 2: Red-Nosed Reports ---
 * 
 * Fortunately, the first location The Historians want to search isn't a long
 * walk from the Chief Historian's office.
 * 
 * While the Red-Nosed Reindeer nuclear fusion/fission plant appears to contain
 * no sign of the Chief Historian, the engineers there run up to you as soon as
 * they see you. Apparently, they still talk about the time Rudolph was saved
 * through molecular synthesis from a single electron.
 *
 * They're quick to add that - since you're already here - they'd really 
 * appreciate your help analyzing some unusual data from the Red-Nosed reactor.
 * You turn to check if The Historians are waiting for you, but they seem to
 * have already divided into groups that are currently searching every corner 
 * of the facility. You offer to help with the unusual data.
 *
 * The unusual data (your puzzle input) consists of many reports, one report 
 * per line. Each report is a list of numbers called levels that are separated 
 * by spaces. For example:
 *
 * 7 6 4 2 1
 * 1 2 7 8 9
 * 9 7 6 2 1
 * 1 3 2 4 5
 * 8 6 4 4 1
 * 1 3 6 7 9
 *
 * This example data contains six reports each containing five levels.
 *
 * The engineers are trying to figure out which reports are safe. The Red-Nosed 
 * reactor safety systems can only tolerate levels that are either gradually 
 * increasing or gradually decreasing. So, a report only counts as safe if 
 * both of the following are true:
 * 
 * The levels are either all increasing or all decreasing.
 * Any two adjacent levels differ by at least one and at most three.
 *
 * In the example above, the reports can be found safe or unsafe by checking 
 * those rules:
 * 
 * 7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2.
 * 1 2 7 8 9: Unsafe because 2 7 is an increase of 5.
 * 9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.
 * 1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing.
 * 8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease.
 * 1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3.
 * So, in this example, 2 reports are safe.
 * 
 * Analyze the unusual data from the engineers. How many reports are safe? 
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define filename_length (256)
#define max_per_line (8) // at most 8 readings per line

int main(int argc, char *argv[]) {

    int safe_count = 0;
    char filename[filename_length] = {0};

    // did the user specify a filename at the command line
    if (argc == 2) {
        strncpy(filename, argv[1], filename_length);
    } else {
        strncpy(filename, "input.txt", filename_length);
    }


    // open the specified file
    FILE *fp = fopen(filename, "r");

    // make sure the fopen was successfull
    if (fp == NULL) {
        printf("failed to open %s", filename);
    }

    char line[100] = {0};

    // process the input file

    while (fgets(line, 100, fp) != NULL) {
        // now process this line of readings
        
        // the input file at most has 8 readings per line
        int readings[8] = {0};
    
        // scan the string for ints and save how many we read in count
        int count = sscanf(line, "%d %d %d %d %d %d %d %d", &readings[0], &readings[1], &readings[2], &readings[3], &readings[4], &readings[5], &readings[6], &readings[7]);
        
        int change = readings[1] - readings[0];  // 1 for up -1 for down
        int last_slope = change / abs(change);

        int safe = 1; // assume safe until proven safe
        for (int i = 1; i < count; i++) {
            change = readings[i] - readings[i-1];
            int this_slope = change / abs(change); // are we going up or down
//            printf("r1: %2d r2: %2d ts: %2d ls: %2d c: %2d ", readings[i-1], readings[i], this_slope, last_slope, change);


            // what is considered safe
            // Any two adjacent levels differ by at least one and at most three.
            if (abs(change) < 1 || abs(change) > 3) {
                safe = 0;
 //               printf("Change out of spec ");
            } 

            // The levels are either all increasing or all decreasing.
            if (this_slope != last_slope) {
                safe = 0;
//                printf("Slope changed direction ");
            } 

//            printf("\n");
           
            last_slope = this_slope;
        }
//        printf("\n");
        if (safe) {
           safe_count++;
        }
    }
    printf("Safe Reports: %d\n", safe_count);
}
