#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct scores { //create variables for all scores
	int aces_score;
	int twos_score;
	int threes_score;
	int fours_score;
	int fives_score;
	int sixes_score;
	int three_ook_score;
	int four_ook_score;
	int full_house_score;
	int small_straight_score;
	int large_straight_score;
	int yahtzee_score;
	int chance_score;
	int total_score; 
};

int aces(struct scores user, int combo[]) { //calculate score for aces
	for (int i = 0; i < 5; i++) {
		if (combo[i] == 1) {   //detects if die is equal to 1
			user.aces_score++;   //score is sum of all 1s
		}
	}
	return user.aces_score;
}

int twos(struct scores user, int combo[]) { //calculate scores for twos
	for (int i = 0; i < 5; i++) {
		if (combo[i] == 2) {    //detects if die is equal to 2
			user.twos_score = user.twos_score + 2;  //score is sum of all 2s
		}
	}
	return user.twos_score;
}

int threes(struct scores user, int combo[]) { //calculate scores for threes
	for (int i = 0; i < 5; i++) {
		if (combo[i] == 3) {    //detects if die is equal to 3
			user.threes_score = user.threes_score + 3;  //score is sum of all 3s
		}
	}
	return user.threes_score;
}

int fours(struct scores user, int combo[]) { //calculate scores for fours
	for (int i = 0; i < 5; i++) {
		if (combo[i] == 4) {    //detects if die is equal to 4
			user.fours_score = user.fours_score + 4;  //score is sum of all 4s
		}
	}
	return user.fours_score;
}

int fives(struct scores user, int combo[]) { //calculate scores for fives
	for (int i = 0; i < 5; i++) {
		if (combo[i] == 5) {  //detects if die is equal to 5
			user.fives_score = user.fives_score + 5;  //score is sum of all 5s
		}
	}
	return user.fives_score;
}

int sixes(struct scores user, int combo[]) { //calculate scores for sixes
	for (int i = 0; i < 5; i++) {
		if (combo[i] == 6) {  //detects if die is equal to 6
			user.sixes_score = user.sixes_score + 6; //score is sum of all 7s
		}
	}
	return user.sixes_score;
}

void sort(int combo[]) { //function to order dice from lowest to highest
	int x = 0;
	int y = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (combo[i] > combo[j]) {  //compares die to next one 
				x = combo[i];        //swaps dice to make the smaller one come first
				y = combo[j];
				combo[i] = y;
				combo[j] = x;
			}
			else {
			}
		}
	}
}

int three_ook(struct scores user, int combo[]) {   //find three of a kind score
	sort(combo); //sort dice
	for (int i = 0; i < 5; i++) {   //sums value of dice
		user.three_ook_score = user.three_ook_score + combo[i];
	}
	if (combo[0] == combo[1] && combo[0] == combo[2]) { //checks all three possibilities for a three of a kind
	}
	else if (combo[1] == combo[2] && combo[1] == combo[3]) {
	}
	else if (combo[2] == combo[3] && combo[2] == combo[4]) {
	}
	else {
		user.three_ook_score = 0; //if none are found, score get sets to 0
	}
	return user.three_ook_score; //three of kind returns a score equal to the sum of all dice
}

int four_ook(struct scores user, int combo[]) { //find four of a kind score
	sort(combo);    //sorts dice
	int number_equal = 1;  //first die is equal to itself, so it starts at 1
	for (int i = 0; i < 5; i++) {
		if (combo[i] == combo[i + 1]) { //detects if dice within roll are equal to each other
			number_equal++;   //counter of how many dice are equal
		}
		else {
		}
		user.four_ook_score = user.four_ook_score + combo[i];  //adds value of all dice in roll
	}
	if (number_equal < 4) {  //detects if less than 4 dice are equal
		user.four_ook_score = 0;  //if less than 4 are equal, score gets set to 0
	}
	return user.four_ook_score;   //four of a kind returns a score equal to the sum of all dice
}

int full_house(struct scores user, int combo[]) {
	sort(combo); //sorts dice
	if (combo[0] == combo[1] && combo[0] == combo[2] && combo[3] == combo[4]) {
		user.full_house_score = 25;  //assigns points if true, full house always scores 25
	}     			                                                                 //checks two possibilities for a full house
	else if (combo[0] == combo[1] && combo[2] == combo[3] && combo[3] == combo[4]) {
		user.full_house_score = 25;
	}
	else {
		user.full_house_score = 0; //if not a full house, score gets set to 0
	}
	return user.full_house_score;
}

int small_straight(struct scores user, int combo[]) {
	sort(combo);  //sorts dice
	int difference; 
	bool sequential = true;  //bool used to determine if dice are in sequence or not
	bool skipped = false;    //bool used to see if die was skipped
	for (int i = 0; i < 4; i++) {
		difference = combo[i + 1] - combo[i];   //calculates difference between die and the next one
		if (difference != 1) {        //only activates if dice are not in sequence
			if (difference == 0 && skipped == false) {  //however, they could be equal. in this case the possibility of a small straight isn't gone
				skipped = true; //only one die can be skipped if there is to be a small straight, so skipped is set to true
				continue; //skips the rest of the loop. now no other dice can be skipped
			}
			else {
				sequential = false; //if difference is not 0 or 1, dice are not in sequence and are not equal
			}
			break;
		}
		else {
		}
	}
	if (sequential == true) {  //if dice are sequential and only up to one die was skipped, points are assigned
		user.small_straight_score = 30;  //small straight always scores 30
	}
	else {
		user.small_straight_score = 0; //otherwise score is set to 0
	}
	return user.small_straight_score;
}

int large_straight(struct scores user, int combo[]) {
	sort(combo); //sorts dice
	int difference;
	for (int i = 0; i < 4; i++) {
		difference = combo[i + 1] - combo[i];  //finds differnce between the die and the one after it
		if (difference != 1) {  //if difference is not 1, score gets set to 0. in this case no dice can be skipped
			user.large_straight_score = 0;   //if dice aren't sequential, score gets set to 0
			break;  //gets out of loop
		}
		else {
			user.large_straight_score = 40;   //if all dice are sequential, points get assigned. large straight always scores 40
		}
	}
	return user.large_straight_score;
}



int yahtzee(struct scores user, int combo[]) {
	for (int i = 0; i < 5; i++) {
		if (combo[0] != combo[i]) {  //compares the first die to all others
			user.yahtzee_score = 0; //if they aren't equal, yahtzee score is set to 0
			break;
		}
		else {
			user.yahtzee_score = 50;  //if they are all equal it scores 50
		}
	}
	return user.yahtzee_score;
}

int chance(struct scores user, int combo[]) {
	for (int i = 0; i < 5; i++) {  //adds up values of all dice
		user.chance_score = user.chance_score + combo[i];
	}
	return user.chance_score;   //always returns sum of all dice
}

int total_score(struct scores *user, int choice) {  //function to update total score
	switch (choice) {   //adds category score to total score
	case 1:
		user->total_score = user->total_score + user->aces_score;
		break;
	case 2:
		user->total_score = user->total_score + user->twos_score;
		break;
	case 3:
		user->total_score = user->total_score + user->threes_score;
		break;
	case 4:
		user->total_score = user->total_score + user->fours_score;
		break;
	case 5:
		user->total_score = user->total_score + user->fives_score;
		break;
	case 6:
		user->total_score = user->total_score + user->sixes_score;
		break;
	case 7:
		user->total_score = user->total_score + user->three_ook_score;
		break;
	case 8:
		user->total_score = user->total_score + user->four_ook_score;
		break;
	case 9:
		user->total_score = user->total_score + user->full_house_score;
		break;
	case 10:
		user->total_score = user->total_score + user->small_straight_score;
		break;
	case 11:
		user->total_score = user->total_score + user->large_straight_score;
		break;
	case 12:
		user->total_score = user->total_score + user->yahtzee_score;
		break;
	case 13:
		user->total_score = user->total_score + user->chance_score;
		break;
	default:
		break;
	}
	return user->total_score;   //returns total score
}

int get_score(struct scores user, int choice, int combo[]) {
	switch (choice) {
	case 1:
		return aces(user, combo);
	case 2:
		return twos(user, combo);
	case 3:
		return threes(user, combo);
	case 4:
		return fours(user, combo);
	case 5:
		return fives(user, combo);
	case 6:
		return sixes(user, combo);
	case 7:
		return three_ook(user, combo);
	case 8:
		return four_ook(user, combo);
	case 9:
		return full_house(user, combo);
	case 10:
		return small_straight(user, combo);
	case 11:
		return large_straight(user, combo);
	case 12:
		return yahtzee(user, combo);
	case 13:
		return chance(user, combo);
	default:
		return 0;
	}
}
void score_card(struct scores *user, struct scores *comp) { //print score card for each new round
	printf("\nCategory\t\tUser\tComputer\n");
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("1. Aces\t\t\t%d\t%d\n", user->aces_score, comp->aces_score); //each round, dynamically updates scores for each category
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("2. Twos\t\t\t%d\t%d\n", user->twos_score, comp->twos_score); //pointers used to pass by reference since score is updated in a function
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("3. Threes\t\t%d\t%d\n", user->threes_score, comp->threes_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("4. Fours\t\t%d\t%d\n", user->fours_score, comp->fours_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("5. Fives\t\t%d\t%d\n", user->fives_score, comp->fives_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("6. Sixes\t\t%d\t%d\n", user->sixes_score, comp->sixes_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("7. Three Of A Kind\t%d\t%d\n", user->three_ook_score, comp->three_ook_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("8. Four Of A Kind\t%d\t%d\n", user->four_ook_score, comp->four_ook_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("9. Full House\t\t%d\t%d\n", user->full_house_score, comp->full_house_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("10. Small Straight\t%d\t%d\n", user->small_straight_score, comp->small_straight_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("11. Large Straight\t%d\t%d\n", user->large_straight_score, comp->large_straight_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("12. Yahtzee\t\t%d\t%d\n", user->yahtzee_score, comp->yahtzee_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("13. Chance\t\t%d\t%d\n", user->chance_score, comp->chance_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("Total\t\t\t%d\t%d\n", user->total_score, comp->total_score);
}

void update_score(struct scores *user, int choice, int combo[]) {
	switch (choice) { 
	case 1:
		user->aces_score = aces(*user, combo);
		break;
	case 2:
		user->twos_score = twos(*user, combo);
		break;
	case 3:
		user->threes_score = threes(*user, combo);
		break;
	case 4:
		user->fours_score = fours(*user, combo);
		break;
	case 5:
		user->fives_score = fives(*user, combo);
		break;
	case 6:
		user->sixes_score = sixes(*user, combo);
		break;
	case 7:
		user->three_ook_score = three_ook(*user, combo);
		break;
	case 8:
		user->four_ook_score = four_ook(*user, combo);
		break;
	case 9:
		user->full_house_score = full_house(*user, combo);
		break;
	case 10:
		user->small_straight_score = small_straight(*user, combo);
		break;
	case 11:
		user->large_straight_score = large_straight(*user, combo);
		break;
	case 12:
		user->yahtzee_score = yahtzee(*user, combo);
		break;
	case 13:
		user->chance_score = chance(*user, combo);
		break;
	default:
		break;
	}

	total_score(user, choice);
}



void roll(int combo[], int kept) { //rolls any dice that are not kept, given an array of dice and an integer representation of kept dice
	time_t t;
	srand((unsigned)time(&t));
	int test = 1; //variable to be repeatedly multiplied by 2 to be used in bitwise and operations


	for (int i = 0; i < 5; i++) { //loops through all 5 dice
		if ((kept & test) == 0 ) { //uses a bitwise and to test if the die is kept, 
			combo[i] = ("%d", rand() % 6 + 1);
		}
		test *= 2; //multiplies by two so that bitwise and checks the next digit
	}
}

void displayDie(int face) {
	switch (face) {
	case 1: 
		printf("\n-----\n|   |\n| o |\n|   |\n-----");
		break;
	case 2:
		printf("\n-----\n|o  |\n|   |\n|  o|\n-----");
		break;
	case 3:
		printf("\n-----\n|o  |\n| o |\n|  o|\n-----");
		break;
	case 4:
		printf("\n-----\n|o o|\n|   |\n|o o|\n-----");
		break;
	case 5:
		printf("\n-----\n|o o|\n| o |\n|o o|\n-----");
		break;
	case 6:
		printf("\n-----\n|o o|\n|o o|\n|o o|\n-----");
		break;
	}
}

void displayDice(int combo[]) {
	for (int i = 0; i < 5; i++) {
		displayDie(combo[i]);
		printf("\n");
	}
}

void playerRound(int combo[], struct scores *user, bool check[], struct scores *comp) { //runs one round of the game for the player, ends with single category selection
	score_card(user, comp); //displays the scorecard to the user

	int kept = 0; //tracks dice to be kept, used as if it is a 5 digit binary number, with each digit representing a kept die
	roll(combo, kept); //first roll
	displayDice(combo);
	char input[20]; //string for user input
	int test = 1; //variable used in bitwise or calculations to assign if a die is kept

	for (int i = 0; i < 5; i++) { //allows player to select dice to keep
		printf("Do you wish to keep die #%d? type \"yes\" or \"no\": ", i + 1);
		scanf("%s", input);

		if (strcmp(input, "yes") == 0) { 
			kept = kept | test; //bitwise or assigns a 1 in the proper place if that die is to be kept
		}
		test *= 2; //multiplies by 2 so that next test assigns to the next binary digit
	}

	roll(combo, kept); //second roll
	kept = 0;
	displayDice(combo);
	test = 1;

	for (int i = 0; i < 5; i++) { //allows user to select dice to keep
		printf("Do you wish to keep die #%d? type \"yes\" or \"no\": ", i + 1);
		scanf("%s", input);

		if (strcmp(input, "yes") == 0) {
			kept = kept | test; //bitwise or assigns a 1 in the proper place if that die is to be kept
		}
		test *= 2; //multiplies by 2 so that next test assigns to the next binary digit
	}

	roll(combo, kept); //third roll
	displayDice(combo);

	score_card(user, comp); //displays the scorecard 

	printf("Please input the number for the chosen scoring category: ");
	int choice;
	scanf("%d", &choice); //asks player to choose scoring category
	

	while (check[choice] || choice < 0 || choice > 13) { //tests for invalid input
		printf("Please enter a valid option: ");
		scanf("%d", &choice);
		
	}
	update_score(user, choice, combo); //score updated
	check[choice] = true; //assigns chosen category to true so that it may not be selected again
}

int bestKeep(int combo[], bool check[]) { //returns the best combination of dice to keep
	int keep = 0; //tracks the dice to be kept, with each digit of a 5 digit binary number representing the 5 dice
	int better = 0; //this tracks how many combinations of potential dice rolls yield a better result than keeping all dice
	int best = 0; //this is the highest achieved result of the previous variable
	int dice[] = { 0,0,0,0,0 }; //the dice to be compared to combo
	struct scores temp = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0  }; //this is needed for the get_score function to run

	// the following is just looping through all possible dice configurations while skipping kept dice
	// finds the set of dice to keep that improves the score the most number of times
	// this is not trying to achieve perfect play, but just be better than random choices
	for (int i = 0; i < 32; i++) { //loops through all possible combinations of kept dice
		better = 0;
		for (int j = 0; j < 13; j++) { //loops through all scoring categories
			dice[0] = combo[0];
			dice[1] = combo[1];
			dice[2] = combo[2];
			dice[3] = combo[3];
			dice[4] = combo[4];
			if (!check[j]) {
				for (int d1 = 1; d1 <= 6; d1++) { //loops through all possible results of first die being kept
					for (int d2 = 1; d2 <= 6; d2++) { 
						for (int d3 = 1; d3 <= 6; d3++) {
							for (int d4 = 1; d4 <= 6; d4++) {
								for (int d5 = 1; d5 <= 6; d5++) {
									if (i & 1 == 0) {
										dice[0] = d1;
									}
									if (i & 2 == 0) {
										dice[1] = d2;
									}
									if (i & 4 == 0) {
										dice[2] = d3;
									}
									if (i & 8 == 0) {
										dice[3] = d4;
									}
									if (i & 16 == 0) {
										dice[4] = d5;
									}

									if (get_score(temp, j, dice) > get_score(temp, j, combo)) {
										better++;
									}
								}
							}
						}
					}
				}
			}
		}
		if (better > best) { //checks if the last tested combination of kept dice is better than the previous best
			keep = i; //updates keep with the new best combination
			best = better;
		}
	}

	return keep;
}

int bestChoice(int combo[], bool check[]) { //returns the highest scoring category given a set of 5 dice and an array of which categories are already used
	int choice = 0; //tracks the best choice found
	struct scores temp;

	for (int i = 0; i < 13; i++) { //sets choice to the first valid category
		if (!check[i]) {
			choice = i;
			break;
		}
	}

	for (int i = 0; i < 13; i++) { //loops through all scoring categories
		if (!check[i]) { //checks if category is already used
			if (get_score(temp, i, combo) > get_score(temp, choice, combo)) { //checks if score is better than previous best choice
				choice = i;
			}
		}
	}

	return choice;
}

 void compRound(int combo[], struct scores *user, bool check[]) { //runs through one round of the game for the computer, scores one category
	int kept = 0;
	printf("It is now the computer's turn.\n");

	printf("The first roll is: "); 
	roll(combo, kept); //computers first roll
	displayDice(combo);

	printf("The second roll is: "); 
	roll(combo, bestKeep(combo, check)); //computers second roll
	displayDice(combo);

	printf("\nThe third roll is: ");
	roll(combo, bestKeep(combo, check)); //computers third roll
	displayDice(combo);

	int choice = bestChoice(combo, check);
	check[choice] = true; //sets the selected choice to true, so that the computer does not select it again

	update_score(user, choice, combo); //score of computer is updated

	printf("---------------END OF COMPUTER TURN");
} 

void options()
{

	printf("\nNow in options");
}

void manual()
{

	printf("\n-----\nRules\n-----\n");
	printf("\n The ojective is to roll the dice for combinations, and have the highest score after 13 rounds.");
	printf("\n each turn a player has 3 opporunties to roll the dice");
	printf("\n On your first roll you will roll all five dice. Set any scoring combinations aside.");
	printf("\n On your second roll you can reroll all the dice or select dice, keeping the others");
	printf("\n On your third roll you must enter the score of one scoring combination aquired on your score card.");


	//insert rules here, you can delete all these comments
	//for example, "each turn a player has 3 opporunties to roll the dice"
	//you can look up the rules and put them here as print statements
}

int main() {
	int menuInput;
	int readyInput;
	struct scores user = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //initalize all scores to 0 at start of game for user
	struct scores comp = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //same but for computer opponent 
	bool pcheck[] = { false, false, false, false, false, false, false, false, false, false, false, false, false };
	bool ccheck[] = { false, false, false, false, false, false, false, false, false, false, false, false, false };
	int combo[] = { 0,0,0,0,0 };

	printf("\n-----------------------\n"
		"Welcome to Yahtzee in C"
		"\n-----------------------\n");
	while (1)
	{
		printf("\n---------\n1.Start \n2.Manual \n3.Options\n---------");
		printf("\nYour option: ");
		scanf("%d", &menuInput);
		if (menuInput == 1)
		{
			printf("\nType 1 when ready.\nInput: ");
			scanf("%d", &readyInput);
			
			for (int i = 0; i < 13; i++) { //loops through all 13 game rounds
				compRound(combo, &comp, ccheck);
				playerRound(combo, &user, pcheck, &comp);
				system("clear"); //clears screen at end of round
			}

			system("clear"); //clears screen at end of game
			
			if (user.total_score > comp.total_score) { //checks if player has won
				printf("You win!");
			}
			else if (user.total_score < comp.total_score) { //checks if player has lost
				printf("You lose!");
			}
			else {
				printf("You tied!");
			}

			printf("\n\n\n");
			score_card(&user, &comp); //displays final scorecard

			break;
		}
		if (menuInput == 2)
		{
			manual();
		}
		if (menuInput == 3)
		{
			options();
		}
	}
}