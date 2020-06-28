#include "../inc/declarations.h"

void init(SHA256* sha256) {
	sha256->dataLength = 0;
	sha256->bitLength = 0;

	// the first 32 bits of the fractional parts of the square roots of the first eight prime numbers
	sha256->state[0] = 0x6a09e667;
	sha256->state[1] = 0xbb67ae85;
	sha256->state[2] = 0x3c6ef372;
	sha256->state[3] = 0xa54ff53a;
	sha256->state[4] = 0x510e527f;
	sha256->state[5] = 0x9b05688c;
	sha256->state[6] = 0x1f83d9ab;
	sha256->state[7] = 0x5be0cd19;
}