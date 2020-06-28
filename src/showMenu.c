#include "../inc/declarations.h"

void showMenu() {
	int choice;
	do
	{
		clearScreen();
		printf("\n\n");
		printf("\tMENU");
		printf("\n------------------------------\n");
		printf("1:Test Mode");
		printf("\n2:Performans Mode");
		printf("\n3:Exit");
		printf("\n------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			/* Test Mode */
			clearScreen();
			testMode();

			break;
		case 2:
			/* Performance Mode */
			clearScreen();
			
			break;
		case 3:
			exit(0);
			break;
		default:
			clearScreen();
			printf("Invalid Input. Please Enter valid Input... ");
		}
	} while (choice != 3);

	return;
}