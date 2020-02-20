/* Programming Assignment #1 							*
 * Niyazi Toker - 272001005  							*
 * Compiled: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0  *
 *														*
 * To build 	-> make build							*
 * To execute 	-> make run 							*
 * To remove 	-> make clean							*/

/* This file contains main execution implementation */
#include <stdio.h>
#include <stdlib.h>
#include "vigenere_cipher.h"

/* Since the functions are static and will be used on this source file, no need to create one more header for main.c*/
static void get_plaintext();
static void get_ciphertext();
static void get_key();
static void VC_LengthAdapter( unsigned int l_text, char * keyword, unsigned int l_keyword);

/* Pointer to text to be taken form user. It can be plaintext or ciphertext. */
/* Pointer to key  to be taken from user. */
/* Length of input text. */
/* Length of key. */
char 			* input_text = NULL;
char 			* key 		 = NULL;
unsigned int 	l_input_text = 0U;
unsigned int 	l_key 	   	 = 0U;

int main()
{
	unsigned int operation= 0U;

	/* Ask user to select operation and store on operation variable. */
	printf("Select operation enter the number:\n");
	printf("1-Encrypt\t2-Decrypt\n");
	scanf("%d", &operation);

	if(1U == operation)
	{
		/* Take plaintext and key and call VC_LengthAdapter and VC_Encrypt functions */
		get_plaintext();
		get_key();
		VC_LengthAdapter(l_input_text,key,l_key);
		VC_Encrypt(input_text,l_input_text,key);
	}
	else if(2U == operation)
	{
		/* Take ciphertext and key and call VC_LengthAdapter and VC_Decrypt functions */
		get_ciphertext();
		get_key();
		VC_LengthAdapter(l_input_text,key,l_key);
		VC_Decrypt(input_text,l_input_text,key);
	}
	else
	{
		printf("Invalid operation selected.Please run code again and select valid operation.\n");
	}
	/* Release the allocated memory */
	free(input_text);
	free(key);
	return 0;
}

/* This function takes the plaintext length and plaintext from user and stores on l_input_text and input_text */
/* Since the key length will be the same with inputtext to encrypt/decrypt, length of inputtext memory is allocated for key */
static void get_plaintext()
{
	printf("Enter size of plaintext:");
	scanf("%d",&l_input_text);
	/* Since the return of malloc is void*, type cast is applied to type of input_text/key. */
	input_text = (char *)malloc(l_input_text*sizeof(char));
	key = (char *)malloc(l_input_text*sizeof(char));
	printf("Enter plaintext:");
	scanf("%s",input_text);
}

/* This function takes the cipher length and cipher from user and stores on l_input_text and input_text */
/* Since the key length will be the same with inputtext to encrypt/decrypt, length of inputtext memory is allocated for key */
static void get_ciphertext()
{
	printf("Enter size of ciphertext:");
	scanf("%d",&l_input_text);
	/* Since the return of malloc is void*, type cast is applied to type of input_text/key. */
	input_text = (char *)malloc(l_input_text*sizeof(char));
	key = (char *)malloc(l_input_text*sizeof(char));
	printf("Enter ciphertext:");
	scanf("%s",input_text);	
}

/* This function takes the key length and key from user and stores on l_key and key */
static void get_key()
{
	printf("Enter size of key:");
	scanf("%d",&l_key);
	printf("Enter key:");
	scanf("%s",key);
}

/* This function adapts the key to encrypt/decrypt input text. It repeats the key until the length of input text maches */
static void VC_LengthAdapter(unsigned int l_text, char * keyword, unsigned int l_keyword)
{
	unsigned int address_offset = 0U;
	unsigned int non_devisible = 0U;
	/* Check the length of input text is divisible or not. If not, set non-devisible to 1. */
	/* If it is not divisible, one more loop is required for repetation to add some characters in key*/
	if(0U != l_text%l_keyword)
	{
		non_devisible = 1U;
	}
	/* For all character in key */
	for (int i = 0; i< l_keyword;i++)
	{
		/* For repetation */
		for ( int j = 0 ; j< (l_text/l_keyword) + non_devisible ; j++)
		{
			/*For each char, it calculates the offset, and place the character that offset address*/
			address_offset = i+ l_keyword*j ;
			/* This check, eliminates the character placement where will be placed out of scope which is bigger than length of input text*/
			if(address_offset < l_text )
			{
				*(keyword + address_offset) = *(keyword+i);
			}		
		}
	}
}
