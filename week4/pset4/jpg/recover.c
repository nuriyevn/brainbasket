#include <stdio.h>
#include <stdlib.h>

void* createFile(int n);

void* createFile(int n)
{
    char filename[10];
    sprintf(filename, "%03d.jpg", n);
    FILE *outfile = fopen(filename, "w");
    return outfile;
}

int main(int argc, char* argv[])
{
    int fileCount = 0;
    unsigned char byte[512];
    
    FILE *file = fopen("card.raw", "r");
    if (file == NULL)
    {
        printf("File could not opne or not found");
        return 1;
    }
    
    FILE *out = NULL;
    
    while (fread(byte, 512, 1, file)) 
    {
        
        if (byte[0] == 0xFF && 
            byte[1] == 0xD8 && 
            byte[2] == 0xFF && 
            byte[3] >> 4 == 0xE)
        {
            
            if (out != NULL)
                fclose(out);
            out = (FILE*)createFile(fileCount);
            fileCount++;
        }
        
        // Case if first empty blocks
        if (out != NULL)
            fwrite(byte, 512, 1, out);
    }
    
    if (out != NULL)
        fclose(out);
    
    fclose(file);
}
