#include <stdio.h>  /* printf */
#include <string.h> /* strlen, strncpy */
#include "config.h" /* digits, big_endian */

void print_float(char *str);
void reverse_chars(char *bytes);

/* NOTE: This assumes 4 byte floats */
int main(int argc, char *argv[])
{
	/* If we get no string, print help and ditch */
	if (argc < 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return 1;
	}

	/* This is our string */
	char *string = argv[1];
	int   length = strlen(string);
	
	/* Print the start of the program */
	printf("#include <stdio.h>\n\nstatic float text[] =\n{\n");

	/* Loop to print the floats */
	for (int i = 0; i < length; i += 4)
	{	
		printf("\t");
		print_float(&string[i]);
		printf(",\n");
	}
	
	/* Print the leftovers we missed, includes null-terminator by design */
	if (length % 4)
	{
		char copy[4] = { 0 };
		int index = length - (length % 4);
		strncpy(copy, &string[index], 4);
		printf("\t");
		print_float(copy);
		printf("\n");
	}
	else
	{
		printf("\t0\n");
	}

	/* Print the rest  of the program */
	printf("};\n\nint main()\n{\n\tputs((char*)text);\n}\n");

	return 0;
}

/* This prints 4 bytes as a float
 * Relies on digits and big_endian from config.h
 */
void print_float(char *str)
{
	if (big_endian)
	{
		/* In-place modification */
		reverse_chars(str);
	}

	printf("%.*e", digits, *(float*)str);
}

/* This reverses the first 4 characters in the string */
void reverse_chars(char *bytes)
{
	/* 1st pair (out of place swap) */
	char b = bytes[0];
	bytes[0] = bytes[3];
	bytes[3] = b;

	/* 2nd pair (out of place swap) */
	b = bytes[1];
	bytes[1] = bytes[2];
	bytes[2] = b;
}
