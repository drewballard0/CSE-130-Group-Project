#include <stdio.h>
#include <string.h>
void options()
{
	
	printf("\nNow in options");
}

void manual()
{
	
	printf("\n-----\nRules\n-----\n");
	
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
			"Welcome to Yatzhee in C"
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

