/* This file contains API functions to be used in main.c */
#include <stdio.h>
#include <stdlib.h>

/* Beginning address of alphabet where A is equal to 65 in ASCII table. */
#define	ALPHABET_SHIFT 65
/* Number of characters in alphabet */
#define NUMBEROFLETTER 26

void VC_Encrypt(char *text, unsigned int l_text, char * keyword)
{
	/* Allocate memory for output*/
	char * ciphertext = (char *)malloc(l_text*sizeof(char));

	/* To find the how many times the text is shifted, 65 is substracted from input_text and keyword and modulo of 26 is applied */
	/* After finding the shift, 65 is added to convert it again to ASCII value, and type cast to char */
	for(int i = 0; i<l_text; i++)
	{
		*(ciphertext+i) = (char)((((int)*(text+i) + (int)*(keyword+i) - ALPHABET_SHIFT*2) % NUMBEROFLETTER) +ALPHABET_SHIFT);
	}

	printf("Plaintext is encrypted. Ciphertext is %s\n",ciphertext);
	free(ciphertext);
}

void VC_Decrypt(char *text, unsigned int l_text, char * keyword)
{
	/* Allocate memory for output*/
	char * plaintext = (char *)malloc(l_text*sizeof(char));
	signed int shift = 0;
	/* To find the how many times the text is shifted, 65 is substracted from input_text and keyword and modulo of 26 is applied */
	/* If the output of shift is negative, it is shifted by 26 to be positive and part of the alphabet */
	/* After finding the shift, 65 is added to convert it again to ASCII value, and type cast to char */
	for(int i = 0; i<l_text; i++)
	{
		shift = ((int)*(text+i) - (int)*(keyword+i) - ALPHABET_SHIFT*2 ) % NUMBEROFLETTER;
		if(shift < 0)
		{
			shift += NUMBEROFLETTER;
		}
		*(plaintext+i) = (char)(shift+ALPHABET_SHIFT);
	}

	printf("Ciphertext is decrypted. Plaintext is %s\n",plaintext);
	free(plaintext);
}