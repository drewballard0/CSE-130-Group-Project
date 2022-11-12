#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


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

int aces(struct scores user, int roll[]) { //calculate score for aces
	for (int i = 0; i < 5; i++) {
		if (roll[i] == 1) {
			user.aces_score++;
		}
	}
	return user.aces_score;
}	

int twos(struct scores user, int roll[]) { //calculate scores for twos
	for (int i = 0; i < 5; i++) {
		if (roll[i] == 2) {
			user.twos_score = user.twos_score + 2;
		}
	}
	return user.twos_score;
}

int threes(struct scores user, int roll[]) { //calculate scores for threes
	for (int i = 0; i < 5; i++) {
		if (roll[i] == 3) {
			user.threes_score = user.threes_score + 3;
		}
	}
	return user.threes_score;
}

int fours(struct scores user, int roll[]) { //calculate scores for fours
	for (int i = 0; i < 5; i++) {
		if (roll[i] == 4) {
			user.fours_score = user.fours_score + 4;
		}
	}
	return user.fours_score;
}

int fives(struct scores user, int roll[]) { //calculate scores for fives
	for (int i = 0; i < 5; i++) {
		if (roll[i] == 5) {
			user.fives_score = user.fives_score + 5;
		}
	}
	return user.fives_score;
}

int sixes(struct scores user, int roll[]) { //calculate scores for sixes
	for (int i = 0; i < 5; i++) {
		if (roll[i] == 6) {
			user.sixes_score = user.sixes_score + 6;
		}
	}
	return user.sixes_score;
}

void score_card() { //print score card for each new round
	printf("\nCategory\t\tUser\tComputer\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("1. Aces\t\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("2. Twos\t\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("3. Threes\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("4. Fours\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("5. Fives\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("6. Sixes\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("7. Three Of A Kind\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("8. Four Of A Kind\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("9. Full House\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("10. Small Straight\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("11. Large Straight\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("12. Yahtzee\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("13. Chance\t\tVAR\tVAR\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("Total\t\t\tVAR\tVAR\n");
}

int scoreMain(int roll[]) { //roll is the players roll from Main()
	struct scores user = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //initalize all scores to 0 at start of game for user
	struct scores comp = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //same but for computer opponent 
	bool check[15] = { false }; //create system to check if category has already been used
	int choice;
	int round_number = 0;

	while (round_number < 13) { //ensure only 13 rounds are played
			score_card(); //print score card
			printf("Please choose a category: ");
			scanf_s("%d", &choice); //user picks category
		if (check[choice] == true) { //check to see if category has already been used
				printf("Cannot use same category twice.");
				system("clear");
		}
		else {
			switch(choice) { //based on user input, assigns points
				case 1:
					printf("Score is: %d", aces(user, roll)); //finds score
					check[1] = true; //prevent category from being chosen again
					round_number++; //iterate to make sure only 13 rounds are played
					system("clear");
				break;
				case 2:
					printf("Score is: %d", twos(user, roll));
					check[2] = true;
					round_number++;
					system("clear");
				break;
				case 3:
					printf("Score is: %d", threes(user, roll));
					check[3] = true;
					round_number++;
					system("clear");
				break;
				case 4:
					printf("Score is: %d", fours(user, roll));
					check[4] = true;
					round_number++;
					system("clear");
				break;
				case 5:
					printf("Score is: %d", fives(user, roll));
					check[5] = true;
					round_number++;
					system("clear");
				break;
				case 6:
					printf("Score is: %d", sixes(user, roll));
					check[6] = true;
					round_number++;
					system("clear");
				break;
				case 7:
				break;
				case 8:
				break;
				case 9:
				break;
				case 10:
				break;
				case 11:
				break;
				case 12:
				break;
				case 13:
				break;
				default: //prevent any number above 13 from working. does not iterate, user gets another chance to input
					printf("Not a valid option."); 
					system("clear");
			}
		}	
	}
	return 0;
}