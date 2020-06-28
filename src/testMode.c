#include "../inc/declarations.h"

void testMode() {
	printf("Type 'exit' to go back...\n\n");
	char* message = NULL;
	while (strcmp(message = readMessage(), "exit") != 0) {
		char digest[65]; /* 64-byte hex digest plus '\0' */
		sha256(message, digest);
		printf("digest: %s\n\n", digest);
	}
}
