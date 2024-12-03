#define _DEFAULT_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


void printUsage(const char *programName) {
    fprintf(stdout,"Usage: %s [-d <arg>] [-r] [-f]\n", programName);
    fprintf(stdout,"\t-d <arg>  The directory to scan\n");
    fprintf(stdout,"\t-r        count regular files\n");
    fprintf(stdout,"\t-f        count folders\n");
    fprintf(stdout,"\t-h        print this help\n");
}


/* When complete, this program scans a provided directory to report the number of files inside. */
int main(int argc, char *argv[]) {

    int opt;
    int numberOfDirectories = 0;
    int numberOfRegularFiles = 0;
    bool regularFiles = false;
    bool directories = false;
    bool dirSpecified = false;

    char directory[256];

    while ( (opt = getopt(argc, argv, "d:rfh")) != -1 ) {
        switch (opt) {
            case 'd':
                strncpy(directory, optarg, 255);
                dirSpecified = true;
                break;
            case 'r':
                regularFiles = true;
                break;
            case 'f':
                directories = true;
                break;
            case 'h':
                printUsage(argv[0]);
                exit(0);
            default:
                printUsage(argv[0]);
                exit(1);
        }
    }

    if (dirSpecified == false) {
        fprintf(stderr, "Error: directory is required\n");
        exit(3);
    }

    // Open the directory
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent *entry;

    // Read entries from the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            numberOfDirectories++;
        } else if (entry->d_type == DT_REG) {
            numberOfRegularFiles++;
        }
    }
    
    if (regularFiles == true) {
        printf("regular files: %d\n", numberOfRegularFiles);
    }

    if (directories == true) {
        printf("directories: %d\n", numberOfDirectories);
    }

    // Check for read errors
    if (errno != 0) {
        perror("Error reading directory");
        closedir(dir);
        return 1;
    }

    // Close the directory
    if (closedir(dir) == -1) {
        perror("Error closing directory");
        return 1;
    }

    return 0;
}
