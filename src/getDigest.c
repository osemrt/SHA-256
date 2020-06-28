#include "../inc/declarations.h"

void getDigest(SHA256* sha256, char digest[]) {

	BYTE hash[32];

	// Since this implementation uses little endian byte ordering and SHA uses big endian,
	// reverse all the bytes when copying the final state to the output hash.
	for (WORD i = 0; i < 4; ++i) {
		hash[i] = (sha256->state[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4] = (sha256->state[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8] = (sha256->state[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (sha256->state[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (sha256->state[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (sha256->state[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (sha256->state[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (sha256->state[7] >> (24 - i * 8)) & 0x000000ff;
	}

	int length = 0;
	for (int j = 0; j < 32; j++) {
		length += sprintf(digest + length,"%02x", hash[j]);
	}
}