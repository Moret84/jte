/********************************************************************************************
	Base64 encoding implementation based on openSSL
	
	Author: CARSON 
	Date: 11.04.2006
	URL: http://www.ioncannon.net/programming/34/howto-base64-encode-with-cc-and-openssl/
	
	-- EDIT --
	Author: Martin Albrecht <martin.albrecht@javacoffee.de>
	Date: 22.08.2009
	URL: http://code.google.com/p/smtpmail
	
DEPENDENCIES:
-------------
	- openSSL-devel (http://www.deanlee.cn/programming/openssl-for-windows/)
	
DESCRIPTION:
------------
	This is a simple base64 encoding implementation, 
	based on the openSSL library.
	I found this code on http://www.ioncannon.net
	
	To compile this code you need the openSSL development
	libraries. In Windows I copied all the headers and lib
	files into my Dev-Cpp folder and compiled the code with
	the command:
	
		gcc base64.c -l libeay32
	
	In Linux/Unix it is:
	
		gcc base64.c -l ssl
	
	WINDOWS NOTE: After compiling, you need the libeay32.dll file in
	the directory of your compiled binary!
	
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

#include "base64.h"


/*
	Encode a string to base64 and return it
*/
char *b64_encode(char *string, int length)
{
  BIO *bmem=NULL, *b64=NULL;
  BUF_MEM *bptr=NULL;
  char *buff=NULL;

  b64 = BIO_new(BIO_f_base64());
  bmem = BIO_new(BIO_s_mem());
  b64 = BIO_push(b64, bmem);
  BIO_write(b64, string, length);
  BIO_flush(b64);
  BIO_get_mem_ptr(b64, &bptr);

  buff = malloc(bptr->length);
  
  #ifdef _WIN32
	memset(buff,0,sizeof(char*));
	memcpy(buff, bptr->data, bptr->length-1);
  #else
	bzero(buff, sizeof(char*));
	sprintf(buff, "%s", bptr->data);
  #endif
  
  buff[bptr->length-1] = '\0';
  BIO_free_all(b64);
  return buff;
}


/*
	Decode a string to plain text and return it
*/
char *b64_decode(char *input, int length)
{
	BIO *b64, *bmem;

	char *buffer = (char *)malloc(strlen(input));
	memset(buffer, 0, length);

	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new_mem_buf(input, length);
	bmem = BIO_push(b64, bmem);

	BIO_read(bmem, buffer, length);

	BIO_free_all(bmem);
	return buffer;
}

