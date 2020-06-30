#pragma once

#include "common.h"

void showMenu();
void clearScreen();
char* readMessage();
char* readEntireFile(FILE* fp);

void sha256(char message[], char digest[]);
void init(SHA256* sha256);
void update(SHA256* sha256, BYTE data[], size_t len);
void finish(SHA256* sha256);
void getDigest(SHA256* sha256, char digest[]);
void testMode();
void performanceMode();