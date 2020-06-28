#include "../inc/declarations.h"


char* readEntireFile(FILE* fp) {
	char* file = NULL;

	/* Go to the end of the file. */
	if (fseek(fp, 0L, SEEK_END) == 0) {
		/* Get the size of the file. */
		long bufsize = ftell(fp);
		if (bufsize == -1) {
			/* Error */
			printf("An error has occurred while reading the file!");
		}
		else {
			/* Allocate our buffer to that size. */
			file = malloc(sizeof(char) * (bufsize + 1));

			/* Go back to the start of the file. */
			if (fseek(fp, 0L, SEEK_SET) != 0) { /* Error */ }

			/* Read the entire file into memory. */
			size_t newLen = fread(file, sizeof(char), bufsize, fp);
			if (newLen == 0) {
				printf("Error reading file");
			}
			else {
				file[newLen] = '\0'; 
			}
		}

		fclose(fp);

	}

	return file;
}