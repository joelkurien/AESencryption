//Joel John Kurien
//201951183

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdint.h>
#include<time.h>

//subbytes function
unsigned char mul2[] =
{
    0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
    0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
    0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
    0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
    0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
    0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
    0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
    0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
    0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
    0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
    0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
    0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
    0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
    0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
    0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
    0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5
};

unsigned char mul_3[] = 
{ 
    0x00,0x03,0x06,0x05,0x0c,0x0f,0x0a,0x09,0x18,0x1b,0x1e,0x1d,0x14,0x17,0x12,0x11,
    0x30,0x33,0x36,0x35,0x3c,0x3f,0x3a,0x39,0x28,0x2b,0x2e,0x2d,0x24,0x27,0x22,0x21,
    0x60,0x63,0x66,0x65,0x6c,0x6f,0x6a,0x69,0x78,0x7b,0x7e,0x7d,0x74,0x77,0x72,0x71,
    0x50,0x53,0x56,0x55,0x5c,0x5f,0x5a,0x59,0x48,0x4b,0x4e,0x4d,0x44,0x47,0x42,0x41,
    0xc0,0xc3,0xc6,0xc5,0xcc,0xcf,0xca,0xc9,0xd8,0xdb,0xde,0xdd,0xd4,0xd7,0xd2,0xd1,
    0xf0,0xf3,0xf6,0xf5,0xfc,0xff,0xfa,0xf9,0xe8,0xeb,0xee,0xed,0xe4,0xe7,0xe2,0xe1,
    0xa0,0xa3,0xa6,0xa5,0xac,0xaf,0xaa,0xa9,0xb8,0xbb,0xbe,0xbd,0xb4,0xb7,0xb2,0xb1,
    0x90,0x93,0x96,0x95,0x9c,0x9f,0x9a,0x99,0x88,0x8b,0x8e,0x8d,0x84,0x87,0x82,0x81,
    0x9b,0x98,0x9d,0x9e,0x97,0x94,0x91,0x92,0x83,0x80,0x85,0x86,0x8f,0x8c,0x89,0x8a,
    0xab,0xa8,0xad,0xae,0xa7,0xa4,0xa1,0xa2,0xb3,0xb0,0xb5,0xb6,0xbf,0xbc,0xb9,0xba,
    0xfb,0xf8,0xfd,0xfe,0xf7,0xf4,0xf1,0xf2,0xe3,0xe0,0xe5,0xe6,0xef,0xec,0xe9,0xea,
    0xcb,0xc8,0xcd,0xce,0xc7,0xc4,0xc1,0xc2,0xd3,0xd0,0xd5,0xd6,0xdf,0xdc,0xd9,0xda,
    0x5b,0x58,0x5d,0x5e,0x57,0x54,0x51,0x52,0x43,0x40,0x45,0x46,0x4f,0x4c,0x49,0x4a,
    0x6b,0x68,0x6d,0x6e,0x67,0x64,0x61,0x62,0x73,0x70,0x75,0x76,0x7f,0x7c,0x79,0x7a,
    0x3b,0x38,0x3d,0x3e,0x37,0x34,0x31,0x32,0x23,0x20,0x25,0x26,0x2f,0x2c,0x29,0x2a,
    0x0b,0x08,0x0d,0x0e,0x07,0x04,0x01,0x02,0x13,0x10,0x15,0x16,0x1f,0x1c,0x19,0x1a
};

unsigned char mul_9[] = 
{
    0x00,0x09,0x12,0x1b,0x24,0x2d,0x36,0x3f,0x48,0x41,0x5a,0x53,0x6c,0x65,0x7e,0x77,
    0x90,0x99,0x82,0x8b,0xb4,0xbd,0xa6,0xaf,0xd8,0xd1,0xca,0xc3,0xfc,0xf5,0xee,0xe7,
    0x3b,0x32,0x29,0x20,0x1f,0x16,0x0d,0x04,0x73,0x7a,0x61,0x68,0x57,0x5e,0x45,0x4c,
    0xab,0xa2,0xb9,0xb0,0x8f,0x86,0x9d,0x94,0xe3,0xea,0xf1,0xf8,0xc7,0xce,0xd5,0xdc,
    0x76,0x7f,0x64,0x6d,0x52,0x5b,0x40,0x49,0x3e,0x37,0x2c,0x25,0x1a,0x13,0x08,0x01,
    0xe6,0xef,0xf4,0xfd,0xc2,0xcb,0xd0,0xd9,0xae,0xa7,0xbc,0xb5,0x8a,0x83,0x98,0x91,
    0x4d,0x44,0x5f,0x56,0x69,0x60,0x7b,0x72,0x05,0x0c,0x17,0x1e,0x21,0x28,0x33,0x3a,
    0xdd,0xd4,0xcf,0xc6,0xf9,0xf0,0xeb,0xe2,0x95,0x9c,0x87,0x8e,0xb1,0xb8,0xa3,0xaa,
    0xec,0xe5,0xfe,0xf7,0xc8,0xc1,0xda,0xd3,0xa4,0xad,0xb6,0xbf,0x80,0x89,0x92,0x9b,
    0x7c,0x75,0x6e,0x67,0x58,0x51,0x4a,0x43,0x34,0x3d,0x26,0x2f,0x10,0x19,0x02,0x0b,
    0xd7,0xde,0xc5,0xcc,0xf3,0xfa,0xe1,0xe8,0x9f,0x96,0x8d,0x84,0xbb,0xb2,0xa9,0xa0,
    0x47,0x4e,0x55,0x5c,0x63,0x6a,0x71,0x78,0x0f,0x06,0x1d,0x14,0x2b,0x22,0x39,0x30,
    0x9a,0x93,0x88,0x81,0xbe,0xb7,0xac,0xa5,0xd2,0xdb,0xc0,0xc9,0xf6,0xff,0xe4,0xed,
    0x0a,0x03,0x18,0x11,0x2e,0x27,0x3c,0x35,0x42,0x4b,0x50,0x59,0x66,0x6f,0x74,0x7d,
    0xa1,0xa8,0xb3,0xba,0x85,0x8c,0x97,0x9e,0xe9,0xe0,0xfb,0xf2,0xcd,0xc4,0xdf,0xd6,
    0x31,0x38,0x23,0x2a,0x15,0x1c,0x07,0x0e,0x79,0x70,0x6b,0x62,0x5d,0x54,0x4f,0x46
};

unsigned char mul_11[] = 
{
    0x00,0x0b,0x16,0x1d,0x2c,0x27,0x3a,0x31,0x58,0x53,0x4e,0x45,0x74,0x7f,0x62,0x69,
    0xb0,0xbb,0xa6,0xad,0x9c,0x97,0x8a,0x81,0xe8,0xe3,0xfe,0xf5,0xc4,0xcf,0xd2,0xd9,
    0x7b,0x70,0x6d,0x66,0x57,0x5c,0x41,0x4a,0x23,0x28,0x35,0x3e,0x0f,0x04,0x19,0x12,
    0xcb,0xc0,0xdd,0xd6,0xe7,0xec,0xf1,0xfa,0x93,0x98,0x85,0x8e,0xbf,0xb4,0xa9,0xa2,
    0xf6,0xfd,0xe0,0xeb,0xda,0xd1,0xcc,0xc7,0xae,0xa5,0xb8,0xb3,0x82,0x89,0x94,0x9f,
    0x46,0x4d,0x50,0x5b,0x6a,0x61,0x7c,0x77,0x1e,0x15,0x08,0x03,0x32,0x39,0x24,0x2f,
    0x8d,0x86,0x9b,0x90,0xa1,0xaa,0xb7,0xbc,0xd5,0xde,0xc3,0xc8,0xf9,0xf2,0xef,0xe4,
    0x3d,0x36,0x2b,0x20,0x11,0x1a,0x07,0x0c,0x65,0x6e,0x73,0x78,0x49,0x42,0x5f,0x54,
    0xf7,0xfc,0xe1,0xea,0xdb,0xd0,0xcd,0xc6,0xaf,0xa4,0xb9,0xb2,0x83,0x88,0x95,0x9e,
    0x47,0x4c,0x51,0x5a,0x6b,0x60,0x7d,0x76,0x1f,0x14,0x09,0x02,0x33,0x38,0x25,0x2e,
    0x8c,0x87,0x9a,0x91,0xa0,0xab,0xb6,0xbd,0xd4,0xdf,0xc2,0xc9,0xf8,0xf3,0xee,0xe5,
    0x3c,0x37,0x2a,0x21,0x10,0x1b,0x06,0x0d,0x64,0x6f,0x72,0x79,0x48,0x43,0x5e,0x55,
    0x01,0x0a,0x17,0x1c,0x2d,0x26,0x3b,0x30,0x59,0x52,0x4f,0x44,0x75,0x7e,0x63,0x68,
    0xb1,0xba,0xa7,0xac,0x9d,0x96,0x8b,0x80,0xe9,0xe2,0xff,0xf4,0xc5,0xce,0xd3,0xd8,
    0x7a,0x71,0x6c,0x67,0x56,0x5d,0x40,0x4b,0x22,0x29,0x34,0x3f,0x0e,0x05,0x18,0x13,
    0xca,0xc1,0xdc,0xd7,0xe6,0xed,0xf0,0xfb,0x92,0x99,0x84,0x8f,0xbe,0xb5,0xa8,0xa3
};

unsigned char mul_13[] = 
{
    0x00,0x0d,0x1a,0x17,0x34,0x39,0x2e,0x23,0x68,0x65,0x72,0x7f,0x5c,0x51,0x46,0x4b,
    0xd0,0xdd,0xca,0xc7,0xe4,0xe9,0xfe,0xf3,0xb8,0xb5,0xa2,0xaf,0x8c,0x81,0x96,0x9b,
    0xbb,0xb6,0xa1,0xac,0x8f,0x82,0x95,0x98,0xd3,0xde,0xc9,0xc4,0xe7,0xea,0xfd,0xf0,
    0x6b,0x66,0x71,0x7c,0x5f,0x52,0x45,0x48,0x03,0x0e,0x19,0x14,0x37,0x3a,0x2d,0x20,
    0x6d,0x60,0x77,0x7a,0x59,0x54,0x43,0x4e,0x05,0x08,0x1f,0x12,0x31,0x3c,0x2b,0x26,
    0xbd,0xb0,0xa7,0xaa,0x89,0x84,0x93,0x9e,0xd5,0xd8,0xcf,0xc2,0xe1,0xec,0xfb,0xf6,
    0xd6,0xdb,0xcc,0xc1,0xe2,0xef,0xf8,0xf5,0xbe,0xb3,0xa4,0xa9,0x8a,0x87,0x90,0x9d,
    0x06,0x0b,0x1c,0x11,0x32,0x3f,0x28,0x25,0x6e,0x63,0x74,0x79,0x5a,0x57,0x40,0x4d,
    0xda,0xd7,0xc0,0xcd,0xee,0xe3,0xf4,0xf9,0xb2,0xbf,0xa8,0xa5,0x86,0x8b,0x9c,0x91,
    0x0a,0x07,0x10,0x1d,0x3e,0x33,0x24,0x29,0x62,0x6f,0x78,0x75,0x56,0x5b,0x4c,0x41,
    0x61,0x6c,0x7b,0x76,0x55,0x58,0x4f,0x42,0x09,0x04,0x13,0x1e,0x3d,0x30,0x27,0x2a,
    0xb1,0xbc,0xab,0xa6,0x85,0x88,0x9f,0x92,0xd9,0xd4,0xc3,0xce,0xed,0xe0,0xf7,0xfa,
    0xb7,0xba,0xad,0xa0,0x83,0x8e,0x99,0x94,0xdf,0xd2,0xc5,0xc8,0xeb,0xe6,0xf1,0xfc,
    0x67,0x6a,0x7d,0x70,0x53,0x5e,0x49,0x44,0x0f,0x02,0x15,0x18,0x3b,0x36,0x21,0x2c,
    0x0c,0x01,0x16,0x1b,0x38,0x35,0x22,0x2f,0x64,0x69,0x7e,0x73,0x50,0x5d,0x4a,0x47,
    0xdc,0xd1,0xc6,0xcb,0xe8,0xe5,0xf2,0xff,0xb4,0xb9,0xae,0xa3,0x80,0x8d,0x9a,0x97
};

unsigned char mul_14[] = 
{
    0x00,0x0e,0x1c,0x12,0x38,0x36,0x24,0x2a,0x70,0x7e,0x6c,0x62,0x48,0x46,0x54,0x5a,
    0xe0,0xee,0xfc,0xf2,0xd8,0xd6,0xc4,0xca,0x90,0x9e,0x8c,0x82,0xa8,0xa6,0xb4,0xba,
    0xdb,0xd5,0xc7,0xc9,0xe3,0xed,0xff,0xf1,0xab,0xa5,0xb7,0xb9,0x93,0x9d,0x8f,0x81,
    0x3b,0x35,0x27,0x29,0x03,0x0d,0x1f,0x11,0x4b,0x45,0x57,0x59,0x73,0x7d,0x6f,0x61,
    0xad,0xa3,0xb1,0xbf,0x95,0x9b,0x89,0x87,0xdd,0xd3,0xc1,0xcf,0xe5,0xeb,0xf9,0xf7,
    0x4d,0x43,0x51,0x5f,0x75,0x7b,0x69,0x67,0x3d,0x33,0x21,0x2f,0x05,0x0b,0x19,0x17,
    0x76,0x78,0x6a,0x64,0x4e,0x40,0x52,0x5c,0x06,0x08,0x1a,0x14,0x3e,0x30,0x22,0x2c,
    0x96,0x98,0x8a,0x84,0xae,0xa0,0xb2,0xbc,0xe6,0xe8,0xfa,0xf4,0xde,0xd0,0xc2,0xcc,
    0x41,0x4f,0x5d,0x53,0x79,0x77,0x65,0x6b,0x31,0x3f,0x2d,0x23,0x09,0x07,0x15,0x1b,
    0xa1,0xaf,0xbd,0xb3,0x99,0x97,0x85,0x8b,0xd1,0xdf,0xcd,0xc3,0xe9,0xe7,0xf5,0xfb,
    0x9a,0x94,0x86,0x88,0xa2,0xac,0xbe,0xb0,0xea,0xe4,0xf6,0xf8,0xd2,0xdc,0xce,0xc0,
    0x7a,0x74,0x66,0x68,0x42,0x4c,0x5e,0x50,0x0a,0x04,0x16,0x18,0x32,0x3c,0x2e,0x20,
    0xec,0xe2,0xf0,0xfe,0xd4,0xda,0xc8,0xc6,0x9c,0x92,0x80,0x8e,0xa4,0xaa,0xb8,0xb6,
    0x0c,0x02,0x10,0x1e,0x34,0x3a,0x28,0x26,0x7c,0x72,0x60,0x6e,0x44,0x4a,0x58,0x56,
    0x37,0x39,0x2b,0x25,0x0f,0x01,0x13,0x1d,0x47,0x49,0x5b,0x55,0x7f,0x71,0x63,0x6d,
    0xd7,0xd9,0xcb,0xc5,0xef,0xe1,0xf3,0xfd,0xa7,0xa9,0xbb,0xb5,0x9f,0x91,0x83,0x8d
};

unsigned char** inv_mixcol(unsigned char plainText[4][4]){
	unsigned char **encrypt;
    encrypt = malloc(sizeof(unsigned char*)*4);

    int x;
    for(x=0; x<4; x++)
        encrypt[x] = malloc(sizeof(unsigned char*)*4);
        
	unsigned char tempC[4][4];
	
	int i,j;
	for (i = 0; i < 4; i++)
    {
        tempC[0][i] = (unsigned char) (mul_14[plainText[0][i]] ^ mul_11[plainText[1][i]] ^ mul_13[plainText[2][i]] ^ mul_9[plainText[3][i]]);
        tempC[1][i] = (unsigned char) (mul_9[plainText[0][i]] ^ mul_14[plainText[1][i]] ^ mul_11[plainText[2][i]] ^ mul_13[plainText[3][i]]);
        tempC[2][i]= (unsigned char) (mul_13[plainText[0][i]] ^ mul_9[plainText[1][i]] ^ mul_14[plainText[2][i]] ^ mul_11[plainText[3][i]]);
        tempC[3][i] = (unsigned char) (mul_11[plainText[0][i]] ^ mul_13[plainText[1][i]] ^ mul_9[plainText[2][i]] ^ mul_14[plainText[3][i]]);
    }
    
    for (i = 0; i < 4; i++){
    	for(j=0; j<4; j++){
    		encrypt[i][j] = tempC[i][j];	
		}
	}
    	
    return encrypt;
}
unsigned char subbytes(unsigned char value){
    unsigned char mat[16][16] = {
        {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
        {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
        {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
        {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
        {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
        {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
        {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
        {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
        {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
        {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
        {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
        {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
        {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
        {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
        {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
        {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}
    };

    int x = value>>4;
    int y = value & 15;
    return mat[x][y];
}

unsigned char** shiftRows_inv(unsigned char m[4][4]){
    unsigned char **encrypt;
    encrypt = malloc(sizeof(unsigned char*)*4);

    int x;
    for(x=0; x<4; x++)
        encrypt[x] = malloc(sizeof(unsigned char*)*4);

   
    unsigned char t=m[1][3];
    m[1][3]=m[1][2];
    m[1][2]=m[1][1];
    m[1][1]=m[1][0];
    m[1][0]=t;
    
    
    unsigned char temp[4];
    temp[2]=m[2][0];
    temp[3]=m[2][1];
    temp[0]=m[2][2];
    temp[1]=m[2][3];
    int i;
    for(i=0;i<4;i++)
    m[2][i]=temp[i];
   
    temp[3]=m[3][0];
    temp[0]=m[3][1];
    temp[1]=m[3][2];
    temp[2]=m[3][3];
    
	for(i=0;i<4;i++)
    m[3][i]=temp[i];
    
	int j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			encrypt[i][j] = m[i][j];
		}
	}  	
	
	return encrypt;
}

//shiftRow function
unsigned char **shiftRow(unsigned char state[4][4]){

    unsigned char **matrix;
    matrix = malloc(sizeof(unsigned char*)*4);

    int k;
    for(k=0; k<4; k++)
        matrix[k] = malloc(sizeof(unsigned char*)*4);

    int i,j,n; unsigned char temp;
    for(i=1;i<2;i++){
        temp =state[i][0];
        //printf("\t%x",temp);
        for(j=0;j<4;j++){
            n = ((i+j)>3?(i+j)-4:i+j);
            state[i][j]=state[i][n];        
        }
        state[i][j-i]=temp;

    }

    temp =state[2][0];
    state[2][0]=state[2][2];
    state[2][2]=temp;
    temp =state[2][1];
    state[2][1]=state[2][3];
    state[2][3]=temp;

    temp =state[3][0];
    state[3][0]=state[3][3];
    state[3][3]=state[3][2];
    state[3][2]=state[3][1];
    state[3][1]=temp;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            matrix[i][j] = state[i][j];
        }
    }
    
    return matrix;
}

//Mix Columns Function
char xfx(unsigned char soo){
	char temp = soo;
	char g;
	if(temp>>7 == 0)
		g = soo<<1;
	else
		g = (soo<<1)^27;
	return g;
}

unsigned char** mixColumns(unsigned char mat[4][4]){

    unsigned char **encrypt;
    encrypt = malloc(sizeof(unsigned char*)*4);

    int k;
    for(k=0; k<4; k++)
        encrypt[k] = malloc(sizeof(unsigned char*)*4);

    int r,c;
    for(c=0; c<4; c++)
        for(r=0; r<4; r++)
            encrypt[r][c] = xfx(mat[r%4][c]) ^ xfx(mat[(r+1)%4][c]) ^ mat[(r+1)%4][c] ^ mat[(r+2)%4][c] ^ mat[(r+3)%4][c];
	
    return encrypt;
}


unsigned char keys[16];
//Key Word Generation
unsigned char** words_generation(){
    
    unsigned char **sched;
    sched = (unsigned char**)malloc(44*sizeof(unsigned char*));

    int x;
    for(x=0; x<44; x++)
        sched[x] = (unsigned char*)malloc(4*sizeof(unsigned char));
    
    static int value = 0;

	unsigned char words[44][4];
    unsigned char rconst[11] = { 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};

    int i;
    for(i=0; i<4; i++){
        words[i][0] = keys[4*i];
        words[i][1] = keys[4*i+1];
        words[i][2] = keys[4*i+2];
        words[i][3] = keys[4*i+3];
    }

    unsigned char temp[4];
    for(i=4; i<44; i++){
        temp[0] = words[i-1][0];
        temp[1] = words[i-1][1];
        temp[2] = words[i-1][2];
        temp[3] = words[i-1][3];

        if(i%4 == 0){
            unsigned char k = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = k;

            temp[0] = subbytes(temp[0]);
            temp[1] = subbytes(temp[1]);
            temp[2] = subbytes(temp[2]);
            temp[3] = subbytes(temp[3]);

            temp[0] = temp[0] ^ rconst[i/4];
        }

        words[i][0] = words[i-4][0] ^ temp[0];
        words[i][1] = words[i-4][1] ^ temp[1];
        words[i][2] = words[i-4][2] ^ temp[2];
        words[i][3] = words[i-4][3] ^ temp[3];
    }
    
    int y,z;
    for(y=0; y<44; y++){
        for(z=0; z<4; z++){
            sched[y][z] = words[y][z];
        }
    }
	
    return sched;
}

//Key Generation
unsigned char** key_generate(int round_no){
    unsigned char** word_matrix;
    word_matrix = words_generation();

    unsigned char **key_mat;
    key_mat = malloc(sizeof(unsigned char*)*4);

    int x;
    for(x=0; x<4; x++)
        key_mat[x] = malloc(sizeof(unsigned char*)*4);

    int i,j,k;
    for(i=(4*round_no),k=0; i<(4*round_no+4); i++,k++){
        for(j=0; j<4; j++){
            key_mat[k][j] = word_matrix[i][j];
        }
    }
    return key_mat;
}

//aes-128 encryption
unsigned char** aes_encrypt(unsigned char text_key[4][4]){

    unsigned char **encrypt;
    encrypt = malloc(sizeof(unsigned char*)*4);

    int x;
    for(x=0; x<4; x++)
        encrypt[x] = malloc(sizeof(unsigned char*)*4);

    int i, j;

    int k;
    //The first 9 round functions
    //Subbytes -> ShiftRows -> Mix Columns
    for(k=0; k<9; k++){
        //subbytes
        unsigned char** key_mat;
        key_mat = key_generate(k);
		
        int y,z;
        for(y=0; y<4; y++){
            for(z=0; z<4; z++){
                text_key[y][z] = text_key[y][z] ^ key_mat[y][z];
            }
        }
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                text_key[i][j] = subbytes(text_key[i][j]);
            }
        } 
		       		
        //shift rows
        unsigned char** shift_matrix = shiftRow(text_key);

        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                text_key[i][j] = shift_matrix[i][j];
            }
        }
		
        //mix columns
        unsigned char** mix_matrix = mixColumns(text_key);
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                text_key[i][j] = mix_matrix[i][j];
            }
        }
        
    }
    unsigned char** lkey_mat = key_generate(9);

    int y,z;
    for(y=0; y<4; y++){
        for(z=0; z<4; z++){
            text_key[y][z] = text_key[y][z] ^ lkey_mat[y][z];
        }
    }

	
    // Subbytes -> Shiftrows
    for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                text_key[i][j] = subbytes(text_key[i][j]);
            }
        } 

    unsigned char** shift_matrix = shiftRow(text_key);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            text_key[i][j] = shift_matrix[i][j];
        }
    }

	unsigned char** lnkey_mat = key_generate(10);

    for(y=0; y<4; y++){
        for(z=0; z<4; z++){
            text_key[y][z] = text_key[y][z] ^ lnkey_mat[y][z];
        }
    }
    
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            encrypt[i][j] = text_key[i][j];
        }
    }
    return encrypt;
}

unsigned char inv_subbytes(unsigned char value){
	unsigned char inv_mat[16][16] = {
	{0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb},
    {0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb},
    {0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e},
    {0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25},
    {0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92},
    {0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84},
    {0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06},
    {0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b},
    {0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73},
    {0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e},
    {0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b},
    {0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4},
    {0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f},
    {0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef},
    {0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61},
    {0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d}
	};
	
	int x = value >> 4;
	int y = value & 15;
	return inv_mat[x][y];
}


unsigned char** aes_decrypt(unsigned char cipher_key[4][4]){
	unsigned char **decrypt;
    decrypt = malloc(sizeof(unsigned char*)*4);

    int x;
    for(x=0; x<4; x++)
        decrypt[x] = malloc(sizeof(unsigned char*)*4);
    
    unsigned char** lnkey_mat = key_generate(10);

    int i,j,y,z;
    for(y=0; y<4; y++){
        for(z=0; z<4; z++){
            cipher_key[y][z] = cipher_key[y][z] ^ lnkey_mat[y][z];
        }
    }
    
    unsigned char** inv_shift = shiftRows_inv(cipher_key);
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            cipher_key[i][j] = inv_shift[i][j];
        }
    }
    
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            cipher_key[i][j] = inv_subbytes(cipher_key[i][j]);
        }
    }
    
    unsigned char** lkey_mat;
    lkey_mat = key_generate(9);
	
    for(y=0; y<4; y++){
        for(z=0; z<4; z++){
            cipher_key[y][z] = cipher_key[y][z] ^ lkey_mat[y][z];
        }
    }
    
    int k;
    for(k=8; k>=0; k--){
		
        int y,z;
        
        //mix columns
        unsigned char** mix_matrix;
		mix_matrix = inv_mixcol(cipher_key);
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                cipher_key[i][j] = mix_matrix[i][j];
            }
        }
		
		unsigned char** shift_matrix;
		shift_matrix = shiftRows_inv(cipher_key);

        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                cipher_key[i][j] = shift_matrix[i][j];
            }
        }
			
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                cipher_key[i][j] = inv_subbytes(cipher_key[i][j]);
            }
        }
        
		unsigned char** key_mat;
        key_mat = key_generate(k);
        
	    for(i=0; i<4; i++){
        	for(j=0; j<4; j++){
            	cipher_key[i][j] = cipher_key[i][j] ^ key_mat[i][j];
        	}
        }	
    }
    
    for(y=0; y<4; y++){
        for(z=0; z<4; z++){
            decrypt[y][z] = cipher_key[y][z];
        }
    }
    return decrypt;
}
int main(){
	char message[16];
	printf("Enter a string of length 16 characters [0-9][a-z]: ");
    gets(message);
    printf("The initial plaintext is: %s\n", message);
    printf("Enter the secret key of 16 character [0-9][a-z]: ");
	gets(keys);
	printf("The initial secret key is: %s\n", keys);

    unsigned char matrix[4][4];
    int i,j;
    int k=0;
    for(i=0; i<4; i++){
    	for(j=0; j<4; j++){
    		matrix[i][j] = message[k];
    		k++;
		}
	}
		
	printf("\n");
    unsigned char** aes_matrix;
    aes_matrix = aes_encrypt(matrix);

	unsigned char cipher_text[16] = "";
	int c=0;    
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
             strncat(cipher_text, &aes_matrix[i][j], 1);
        }
    }
    
    printf("The initial cipher text:");
    for(i=0; i<16; i++)
    	printf("%x ", cipher_text[i]);
    printf("\n");
    
    unsigned char cipher_mat[4][4];
    k = 0;
    for(i=0; i<4; i++){
    	for(j=0; j<4; j++){
    		cipher_mat[i][j] = cipher_text[k];
    		k++;
		}
	}
	
	printf("\n");
	
	srand(time(0));
	unsigned char randKey[16];
	for(i=0;i<16;i++){   
        randKey[i]= (unsigned char)rand()%(255);
    }
	
	strcpy(keys, randKey);
	printf("The random secret key: ");
    for(i=0; i<16; i++)
    	printf("%x ", keys[i]);
    printf("\n");
    
    printf("The second pre-image text is: ");
	unsigned char** decrypt;
    decrypt = aes_decrypt(cipher_mat);
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
        	 printf("%x ", decrypt[i][j]);
             matrix[i][j] = decrypt[i][j];
        }   
    }
    printf("\n");
    aes_matrix = aes_encrypt(matrix);
    
    printf("Verification: ");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
             printf("%x ", aes_matrix[i][j]);
        }
    }
    
    return 0;
}
