#include <stdio.h>
#include <string.h>
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

void gameLoop()
{
	
	printf("\nYou have now started the game");
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
		scanf("%d", &menuInput);
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

