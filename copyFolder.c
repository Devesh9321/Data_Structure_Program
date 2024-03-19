
/****************************************
*   Auther : Devesh Patil + chatgpt     *
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Function to copy a file
void copyFile(const char *sourcePath, const char *destinationPath)
{
    FILE *sourceFile = fopen(sourcePath, "rb");
    FILE *destinationFile = fopen(destinationPath, "wb");

    if (sourceFile == NULL || destinationFile == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
}

// Function to copy all files in a directory
void copyDirectory(const char *sourceDir, const char *destDir)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(sourceDir)))
    {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    if (mkdir(destDir) == -1)
    {
        perror("Error creating destination directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char sourcePath[1024];
        char destPath[1024];
        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (entry->d_type == DT_DIR)
        {
            copyDirectory(sourcePath, destPath);
        }
        else
        {
            copyFile(sourcePath, destPath);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s source_directory destination_directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    copyDirectory(argv[1], argv[2]);

    printf("DVD contents copied successfully.\n");
    return EXIT_SUCCESS;
}
