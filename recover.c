#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

//typically the 512 refers to the number of
// blocks a disk reader can read or write
#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

//define byte as unsigned int
typedef uint8_t BYTE;

bool start_new_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    //accepts command line argument
    //or returns 1 if there is no file
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    //if file is null, it cannot be opened or found
    if (file == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    BYTE buffer [BLOCK_SIZE];
    //keeps count of the file index
    int file_index = 0;
    FILE *outfile;

    //initalize bollean variable to check
    //if all jpegs are in continuous fashion
    bool found_jpeg = false;
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        if (start_new_jpeg(buffer))
        {
            if (!found_jpeg)
            {
                found_jpeg = true;
            }
            else
            {
                fclose(outfile);
            }
            char file_name[FILE_NAME_SIZE];
            sprintf(file_name, "%03i.jpg", file_index++);
            // w represents writing with open file
            outfile = fopen(file_name, "w");
            if (outfile == NULL)
            {
                return 1;
            }
            //fwrite writes data specified by a void pointer to a file
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (found_jpeg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    fclose(outfile);
    fclose(file);
}
bool start_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
