/* This file is a header file of vigenere_cipher.c 
   It contains external functions .
 */
#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

extern void VC_Encrypt(char *text, unsigned int l_text, char * keyword);
extern void VC_Decrypt(char *text, unsigned int l_text, char * keyword);

#endif /*VIGENERE_CIPHER_H*/