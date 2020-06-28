#include "../inc/declarations.h"

void update(SHA256* sha256, BYTE data[], size_t len) {

	for (WORD i = 0; i < len; i++) {
		sha256->data[sha256->dataLength] = data[i];
		sha256->dataLength++;
		if (sha256->dataLength == 64) {
			transform(sha256, sha256->data);
			sha256->bitLength += 512;
			sha256->dataLength = 0;
		}
	}

}