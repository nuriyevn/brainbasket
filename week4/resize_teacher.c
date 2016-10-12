#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1])  ; 
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    //determine new headers
    BITMAPFILEHEADER bf2=bf;
    BITMAPINFOHEADER bi2=bi;
    bi2.biWidth = bi.biWidth * n ;
    bi2.biHeight = bi.biHeight * n ; 
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    int ImageSize = (bi2.biWidth * sizeof(RGBTRIPLE)) * bi2.Height; 
    bf2.bfSize = ImageSize + padding_outfile ;
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2,  sizeof(BITMAPFILEHEADER), 1, outptr);    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);
    // determine padding for scanlines
    //determine new padding
    
    int padding_infile = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
     int padding_outfile = (4 - ( bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight =  abs (bi.biHeight) ; i <  biHeight ; i++)
    {
    //   
       {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            // write RGB triple to outfile
            for (int z = 0 ; z < n ; z++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
                
            }
        
        } // then add it back (to demonstrate how)
        for (int k = 0; k < padding_outfile; k++)
        {
            fputc(0x00, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding_outfile, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
