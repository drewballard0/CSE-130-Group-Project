#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int reroll(int combo[]);

void options()
{
	
	printf("\nNow in options");
}

void manual()
{
	
	printf("\n-----\nRules\n-----\n");
	printf("\n The ojective is roll the dice for combinations, and have the highest score after 13 rounds.");
	printf("\n each turn a player has 3 opporunties to roll the dice");
	printf("\n On your first roll you will roll all five dice. Set any scoring combinations aside.");
	printf("\n On your second roll you can reroll all the dice or just the non scoring dice.");
	printf("\n On your third roll you must enter the score of one scoring combination aquired on your score card.");

	
	//insert rules here, you can delete all these comments
	//for example, "each turn a player has 3 opporunties to roll the dice"
	//you can look up the rules and put them here as print statements
}

void diceRoll()
{
	int i,x;
	int input, numReroll;//user input
	int convInt = 0;//helps convert array to int
	int combo[5];//dice 5 digit combo
	time_t t;
	
	char diceOne[] = ("\n-----\n|   |\n| o |\n|   |\n-----");
	char diceTwo[] = ("\n-----\n|o  |\n|   |\n|  o|\n-----");
	char diceThree[] = ("\n-----\n|o  |\n| o |\n|  o|\n-----");
	char diceFour[] = ("\n-----\n|o o|\n|   |\n|o o|\n-----");
	char diceFive[] = ("\n-----\n|o o|\n| o |\n|o o|\n-----");
	char diceSix[] = ("\n-----\n|o o|\n|o o|\n|o o|\n-----");
	//this is the dice displays ins ASCII
	
	srand((unsigned) time(&t));//declare rand
	
	for( i = 0 ; i < 5 ; i++ ) 
	{
		combo[i] = ("%d", rand() % 6 +1);//puts random nums in array
		
		convInt = 10 * convInt + combo[i];//converts array to an int
		
		if (combo[i] == 1) //turns the 5 digit array into dice display
		{
			printf("%s",diceOne);
		}
		if (combo[i] == 2)
		{
			printf("%s",diceTwo);
		}
		if (combo[i] == 3)
		{
			printf("%s",diceThree);
		}
		if (combo[i] == 4)
		{
			printf("%s",diceFour);
		}
		if (combo[i] == 5)
		{
			printf("%s",diceFive);
		}
		if (combo[i] == 6)
		{
			printf("%s",diceSix);
		}
		
	}
	printf("\nYour role set: %d ",convInt);
	printf("\n--------------------\n");
	reroll(combo);
}

int reroll(int combo[])
{
	int input,numReroll, convInt = 0, i;
	printf("Do you want to reroll? \n1.Yes\n2.No\nEnter: ");
	scanf_s("%d", &input);

	if (input == 1) {
		printf("\nHow many dice you want to reroll?: ");
		scanf_s("%d", &numReroll);
		for (i = 0; i < numReroll; i++) {
			printf("From 1 to 5, Reroll dice: ");
			scanf_s("%d", &input);
			combo[input -1] = ("%d", rand() % 6 + 1);

		}
		for (i = 0; i < 5; i++)
		{
			convInt = 10 * convInt + combo[i];
		}
		printf("\n----------------------\nYour new roll is: %d\n----------------------\n", convInt);

		reroll(combo);
	}
	else if (input == 2) {
		scoreMain(combo);
	}
	return 0;
}

void gameLoop()
{
	int readyInput;
	
	printf("\nRoll your set of 5 dice? type 1 when ready.\nInput: ");
	scanf_s("%d", &readyInput);
	diceRoll();
	
}


void main(){
	int menuInput;
	printf("\n-----------------------\n"
			"Welcome to Yahtzee in C"
			"\n-----------------------\n");
	while(1)
	{
		printf("\n---------\n1.Start \n2.Manual \n3.Options\n---------");
		printf("\nYour option: ");
		scanf_s("%d", &menuInput);
		if (menuInput == 1)
		{
			gameLoop();
			break;
		}
		if (menuInput == 2)
		{
			manual();
			break;
		}
		if (menuInput == 3)
		{
			options();
			break;
		}
	}
}

