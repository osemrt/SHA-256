#include "../inc/declarations.h"

char* readMessage() {
	char input[2048];
	printf("input: ");
	scanf("%s", input);
	
	FILE* fp = fopen(input, "rb");
	if (fp != NULL)
		return readEntireFile(fp);

	input[strlen(input)] = '\0';
	return input;

}