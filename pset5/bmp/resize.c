/****************************************************************************
 * resize.c
 *
 * CC50
 * Pset 5
 *
 * Redimensionador de BMP's de 24 bits.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int
main(int argc, char *argv[])
{
	// ensure proper usage
	if (argc != 4)
	{
		printf("Usage: resize n infile outfile\n");
		return 1;
	}

	int n = atoi(argv[1]);
	if (n > 100 || n < 1)
	{
		printf("Valor de redimensionamento: 0 a 100.\n");
		return 2;
	}

	// remember filenames
	char *infile = argv[2];
	char *outfile = argv[3];

	// open input file 
	FILE *inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		printf("Could not open %s.\n", infile);
		return 3;
	}

	// open output file
	FILE *outptr = fopen(outfile, "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		fprintf(stderr, "Could not create %s.\n", outfile);
		return 4;
	}

	// read infile's BITMAPFILEHEADER
	BITMAPFILEHEADER bf;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

	// read infile's BITMAPINFOHEADER
	BITMAPINFOHEADER bi;
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

	// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
	if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
		bi.biBitCount != 24 || bi.biCompression != 0)
	{
		fclose(outptr);
		fclose(inptr);
		fprintf(stderr, "Unsupported file format.\n");
		return 5;
	}

	int o_biWidth = bi.biWidth, o_biHeight = bi.biHeight;
	bi.biWidth = bi.biWidth * n, bi.biHeight = bi.biHeight * n;

	int o_padding = (4 - (o_biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

	bi.biSizeImage = (abs(bi.biHeight * bi.biWidth * sizeof(RGBTRIPLE))) + (padding * abs(bi.biHeight));
	bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (bi.biSizeImage);

	// write outfile's BITMAPFILEHEADER
	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

	// write outfile's BITMAPINFOHEADER
	fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

	// iterate over infile's scanlines
	for (int i = 0, biHeight = abs(o_biHeight); i < biHeight; i++)
	{
		fpos_t position;
		fgetpos(inptr, &position);

		for (int r = 0; r < n; r++)
		{
			if (r < n)
				fsetpos(inptr, &position);

			// iterate over pixels in scanline
			for (int j = 0; j < o_biWidth; j++)
			{
				// temporary storage
				RGBTRIPLE triple;

				// read RGB triple from infile
				fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

				for (int k = 0; k < n; k++)
					// write RGB triple to outfile
					fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
			}

			// skip over padding, if any
			fseek(inptr, o_padding, SEEK_CUR);

			// write padding to outfile
			for (int k = 0; k < padding; k++)
				fputc(0x00, outptr);
		}
	}

	// close infile
	fclose(inptr);

	// close outfile
	fclose(outptr);

	// that's all folks
	return 0;
}
