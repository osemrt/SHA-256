#include "../inc/declarations.h"

void performanceMode() {

	int N, i;
	char inputs[MAX_INPUT_COUNT][MAX_LINE];
	
	printf("Enter the input count: ");
	scanf("%d", &N);
	printf("\n");

	for (i = 0; i < N; i++) {
		printf("input%d: ", i);
		scanf("%s", inputs[i]);
	}

	printf("\n");


	printf("Analysis started. Please wait...\n\n");

	clock_t clk;
	char* messages[MAX_INPUT_COUNT];
	double runningTimes[MAX_INPUT_COUNT];
	int lengths[MAX_INPUT_COUNT];

	char digest[65]; /* 64-byte hex digest plus '\0' */
	for (i = 0; i < N; i++) {

		FILE* fp = fopen(inputs[i], "rb");
		if (fp != NULL)
			messages[i] = readEntireFile(fp);
		else
			messages[i] = inputs[i];

		//messages[i][strlen(inputs[i])] = '\0';
		lengths[i] = strlen(messages[i]);

		clk = clock(); /*start time*/
		sha256(messages[i], digest);
		clk = clock() - clk; /*calculate total time taken*/

		runningTimes[i] = ((double)clk / CLOCKS_PER_SEC);

		printf("digest[input%d]: %s\n", i, digest);
	}
	printf("\n\n");
	plot(runningTimes, lengths, N);
	while (getchar() != '\n'); // option TWO to clean stdin
	printf("\nPress any key to continue...\n");
	getchar();
}