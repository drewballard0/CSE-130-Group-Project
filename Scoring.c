#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct scores{ //create variables for all scores
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
		if (difference != 1) {        //only activates if dice are in sequence
			if (difference == 0 && skipped == false) {  //however, they could be equal. in this case the possibility of a small straight isn't gone
				skipped = true; //only one die can be skipped if there is to be a small straight, so skipped is set to true
				continue; //skips the rest of the loop. now no other dice can be skipped
			}
			else {
				sequential = false; //if difference is not 0 or 1, dice are not in sequence
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
			user.yahtzee_score = 50;  //if they are equal it scores 50
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

int total_score(struct scores user, int choice) {  //function to update total score
	switch(choice) {   //adds category score to total score
	case 1:
		user.total_score = user.total_score + user.aces_score;
		break;
	case 2:
		user.total_score = user.total_score + user.twos_score;
		break;
	case 3:
		user.total_score = user.total_score + user.threes_score;
		break;
	case 4:
		user.total_score = user.total_score + user.fours_score;
		break;
	case 5:
		user.total_score = user.total_score + user.fives_score;
		break;
	case 6:
		user.total_score = user.total_score + user.sixes_score;
		break;
	case 7:
		user.total_score = user.total_score + user.three_ook_score;
		break;
	case 8:
		user.total_score = user.total_score + user.four_ook_score;
		break;
	case 9:
		user.total_score = user.total_score + user.full_house_score;
		break;
	case 10:
		user.total_score = user.total_score + user.small_straight_score;
		break;
	case 11:
		user.total_score = user.total_score + user.large_straight_score;
		break;
	case 12:
		user.total_score = user.total_score + user.yahtzee_score;
		break;
	case 13:
		user.total_score = user.total_score + user.chance_score;
		break;
	default:
		break;
	}
	return user.total_score;   //returns total score to main
	}


void score_card(struct scores user) { //print score card for each new round
	printf("\nCategory\t\tUser\tComputer\n");
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("1. Aces\t\t\t%d\tVAR\n", user.aces_score); //each round, dynamically updates scores for each category
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("2. Twos\t\t\t%d\tVAR\n", user.twos_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("3. Threes\t\t%d\tVAR\n", user.threes_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("4. Fours\t\t%d\tVAR\n", user.fours_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("5. Fives\t\t%d\tVAR\n", user.fives_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("6. Sixes\t\t%d\tVAR\n", user.sixes_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("7. Three Of A Kind\t%d\tVAR\n", user.three_ook_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("8. Four Of A Kind\t%d\tVAR\n", user.four_ook_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("9. Full House\t\t%d\tVAR\n", user.full_house_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("10. Small Straight\t%d\tVAR\n", user.small_straight_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("11. Large Straight\t%d\tVAR\n", user.large_straight_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("12. Yahtzee\t\t%d\tVAR\n", user.yahtzee_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("13. Chance\t\t%d\tVAR\n", user.chance_score);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	printf("Total\t\t\t%d\tVAR\n", user.total_score);
}

int scoreMain(int combo[]) {
	struct scores user = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //initalize all scores to 0 at start of game for user
	struct scores comp = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //same but for computer opponent 
	bool check[15] = { false }; //create system to check if category has already been used
	int choice;
	int round_number = 0;
	while (round_number < 13) { //ensure only 13 rounds are played
			score_card(user); //print score card
			printf("Please choose a category: ");
			scanf_s("%d", &choice); //user picks category
		if (check[choice] == true) { //check to see if category has already been used
				printf("Cannot use same category twice.");
				system("clear"); //clear screen
		}
		else {
			check[choice] = true;
			round_number++;
			switch(choice) { //based on user input, assigns points
				case 1:
					user.aces_score = aces(user, combo); //finds score
					printf("Score is: %d", user.aces_score); //prints score
				break;
				case 2:
					user.twos_score = twos(user, combo);
					printf("Score is: %d", user.twos_score);
				break;
				case 3:
					user.threes_score = threes(user, combo);
					printf("Score is: %d", user.threes_score);
				break;
				case 4:
					user.fours_score = fours(user, combo);
					printf("Score is: %d", user.fours_score);
				break;
				case 5:
					user.fives_score = fives(user, combo);
					printf("Score is: %d", user.fives_score);
				break;
				case 6:
					user.sixes_score = sixes(user, combo); 
					printf("Score is: %d", user.sixes_score);
				break;
				case 7:
					user.three_ook_score = three_ook(user, combo);
					printf("Score is: %d", user.three_ook_score);
				break;
				case 8:
					user.four_ook_score = four_ook(user, combo);
					printf("Score is: %d", user.four_ook_score);
				break;
				case 9:
					user.full_house_score = full_house(user, combo);
					printf("Score is: %d", user.full_house_score);
				break;
				case 10:
					user.small_straight_score = small_straight(user, combo);
					printf("Score is: %d", user.small_straight_score);
				break;
				case 11:
					user.large_straight_score = large_straight(user, combo);
					printf("Score is: %d", user.large_straight_score);
				break;
				case 12:
					user.yahtzee_score = yahtzee(user, combo);
					printf("Score is: %d", user.yahtzee_score);
				break;
				case 13:
					user.chance_score = chance(user, combo);
					printf("Score is: %d", user.chance_score);
				break;
				default: //prevent any number above 13 from working. does not iterate, user gets another chance to input
					printf("Not a valid option.");
			}
			user.total_score = total_score(user, choice);  //updates total score
			system("clear");
		}
	}
	score_card(user);   //prints final score sheet after all rounds have been played
	return 0;
}