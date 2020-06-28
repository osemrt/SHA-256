#include "../inc/declarations.h"

void finish(SHA256* sha256) {

	WORD i = sha256->dataLength;

	// padding
	if (sha256->dataLength < 56) {
		sha256->data[i++] = 0b10000000;
		while (i < 56) {
			sha256->data[i++] = 0b00000000;
		}
	}
	else {
		sha256->data[i++] = 0b10000000;
		while (i < 64) {
			sha256->data[i++] = 0b00000000;
		}
		transform(sha256, sha256->data);
		memset(sha256->data, 0, 56);
	}

	// Add the total message's length in bits
	sha256->bitLength += sha256->dataLength * 8;
	sha256->data[63] = sha256->bitLength;
	sha256->data[62] = sha256->bitLength >> 8;
	sha256->data[61] = sha256->bitLength >> 16;
	sha256->data[60] = sha256->bitLength >> 24;
	sha256->data[59] = sha256->bitLength >> 32;
	sha256->data[58] = sha256->bitLength >> 40;
	sha256->data[57] = sha256->bitLength >> 48;
	sha256->data[56] = sha256->bitLength >> 56;

	transform(sha256, sha256->data);

}