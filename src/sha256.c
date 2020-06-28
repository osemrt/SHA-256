#include "../inc/declarations.h"

void sha256(char message[], char digest[]) {
	SHA256 sha256;
	init(&sha256);
	update(&sha256, message, strlen(message));
	finish(&sha256);
	getDigest(&sha256, digest);
}