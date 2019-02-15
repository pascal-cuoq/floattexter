#include <stdio.h>  /* printf */
#include <string.h> /* strlen, strncpy */
#include "config.h" /* digits */

/* This prints bytes as a float
 * Relies on digits and from config.h
 */
void print_as_float(char *bytes)
{
	printf("%.*e", digits, *(float*)bytes);
}

/* TODO: This assumes sizeof(float) byte floats */
int main(int argc, char *argv[])
{
	/* If we get no string, print help and ditch */
	if (argc < 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return 1;
	}

	/* Input string */
	char *string = argv[1];
	int   length = strlen(string);
	
	/* Print the start of the program */
	printf("#include <stdio.h>\n\nstatic float text[] =\n{\n");

	/* Loop to print the floats */
	for (int i = 0; i < length; i += sizeof(float))
	{	
		printf("\t");
		print_as_float(&string[i]);
		printf(",\n");
	}
	
	/* Print the leftovers we missed, includes null-terminator by design
	 * TODO: Make this less bad somehow
	 */
	if (length % sizeof(float))
	{
		char copy[sizeof(float)] = { 0 };
		int index = length - (length % sizeof(float));
		strncpy(copy, &string[index], sizeof(float));
		printf("\t");
		print_as_float(copy);
		printf("\n");
	}
	else
	{
		/* Relies on 0.0f containing a null byte */
		printf("\t0\n");
	}

	/* Print the rest  of the program */
	printf("};\n\nint main()\n{\n\tputs((char*)text);\n}\n");

	return 0;
}
