#include "../inc/declarations.h"

void transform(SHA256* sha256, BYTE data[]) {
	// loop variables

	WORD W[64];
	WORD i, j;
	WORD a, b, c, d, e, f, g, h, T1, T2;

	// message Schedule [W0-W15]
	for (i = 0, j = 0; i < 16; i++, j += 4) {
		W[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
	}

	// message Schedule [W16-W63]
	for (; i < 64; i++) {
		W[i] = SIG1(W[i - 2]) + W[i - 7] + SIG0(W[i - 15]) + W[i - 16];
	}

	a = sha256->state[0];
	b = sha256->state[1];
	c = sha256->state[2];
	d = sha256->state[3];
	e = sha256->state[4];
	f = sha256->state[5];
	g = sha256->state[6];
	h = sha256->state[7];

	for (i = 0; i < 64; ++i) {
		T1 = h + EP1(e) + CH(e, f, g) + K[i] + W[i];
		T2 = EP0(a) + MAJ(a, b, c);
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
	}

	sha256->state[0] += a;
	sha256->state[1] += b;
	sha256->state[2] += c;
	sha256->state[3] += d;
	sha256->state[4] += e;
	sha256->state[5] += f;
	sha256->state[6] += g;
	sha256->state[7] += h;

}


