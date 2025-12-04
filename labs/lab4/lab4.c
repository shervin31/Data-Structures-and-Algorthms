// Define return results
#define MALLOC_FAILED -1   // error code for malloc failure
#define TOO_MANY_LINES -2  // error code for array of strings size exceeded

#define MAX_LINE 128 // Max. length of a string
#define MAX_LINES 500 // Max. number of lines in an array of strings

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int read_strings(char **strings, const int size, FILE *fp) {
    int lines = 0;        // Initialize the line count
    char line[MAX_LINE];  // Local storage for the current line of text
    int length = 0;       // The length of a line from the file

    while((lines >= 0) && (fgets(line, sizeof line, fp) != NULL)) {

        // Verify room in strings
        if(lines < size) {
            // Trim end of line characters (Windows, Mac, or Linux)
            length = strcspn(line, "\r\n");
            line[length] = '\0';

            // Allocate and verify dynamic storage for line with space for trailing NULL
            if((strings[lines] = malloc(length + 1)) != NULL) {
                // Copy line to strings
                strcpy(strings[lines], line);
                lines++;  // Increment the line count.
            } else {
                // Set error code
                lines = MALLOC_FAILED;
            }
        } else {
            // Set error code
            lines = TOO_MANY_LINES;
        }
    }
    return lines;
}

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    char *filename = "testing.txt";
    char *strings[MAX_LINES];
    FILE *fp = fopen(filename, "r");
    int lines = read_strings(strings, MAX_LINES, fp);
    printf("%d", lines);
    fclose(fp);
    return 0;
}