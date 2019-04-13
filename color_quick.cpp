#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <ctime>
using namespace std;

//random color array
vector<string> random_codes;
vector<string> random_codes_color;
vector<string> random_colors;

//universal color code suffix
string suffix = "\033[0m\n";

//color code prefix and corresponding color
string prefix[7][2] = {
	{"\033[1;31m", "red"},
	{"\033[1;32m", "green"},
	{"\033[1;33m", "yellow"},
	{"\033[1;34m", "blue"},
	{"\033[1;35m", "purple"},
	{"\033[1;36m", "cyan"},
	{"\033[1;37m", "white"}
};

int random_generation(){
	
	//random seed generation
	srand (time(NULL));

	//generating random numbers and serring values
	for(int i = 1; i <= 20 ; i++){
		
		//generating random numbers	
		int x = rand() %7;
		int y = rand() %7;

		//resize arrays to fit random strings
		random_codes.resize(i);
		random_codes_color.resize(i);
		random_colors.resize(i);
		
		//setting the strings to the arrays
		random_codes.push_back(prefix[x][0]);
		random_codes_color.push_back(prefix[x][1]);
		random_colors.push_back(prefix[y][1]);

	}


}

int main(){

	//variables that check if player wants to play more
	bool cont_play = true;
 	string keep_playing = "y";

 	//keeping player playing
	while(cont_play == true){

	//menu variables
	bool game_started = false;
	string start_message;

	//welcome message
	cout << prefix[1][0] << "Welcome to color quick!" << suffix;
	cout << prefix[5][0] << "Enter \"i\" for instructions" << suffix;
	cout << prefix[3][0] << "Enter \"c\" to see the possible color names" << suffix;
	cout << prefix[2][0] << "Enter \"b\" to begin" << suffix;
	cin >> start_message;	

	//main menu
	while (game_started == false){
		
		//starts game
		if (start_message == "b"){
			game_started = true;
		}

		//shows instructions
		else if(start_message == "i"){
			cout << "The goal of the game is to type the color" << endl << "of the word in the lease amount of time possible." << endl;
			cout << "for example even if the word is \"blue\" but" << endl << "it is the color red the correct answer is red." << endl;
			cout << "Now enter \"b\" to begin or \"c\" to see the colors" << endl;
			cin >> start_message;
		}

		//showing all colors in game
		else if(start_message == "c"){
			cout << "The colors are as follows:" << endl;

			//iterating through and showing each color
			for (int i = 0 ; i <= 6 ; i++){
				cout << prefix[i][0] << prefix[i][1] << suffix << endl;
			}

			cout << "Now enter \"b\" to begin or \"i\" for instructions" << endl;
			cin >> start_message;
		}

		//catching false inputs
		else{
			cout << "I do not understand that input please try again" << endl;
			cin >> start_message;
		}	
	}

	//start of game
	if (game_started == true){

		//initializing input variables
		string guess;
		bool guess_correct;
		string guess_code;

		//initializing game using function
		random_generation();

		//initalizing clock	
		clock_t start_time = clock();

		//selecting and checking user answers
		for(int i = 1; i <= 20 ; i++){

			//printing color to guess
			cout << random_codes.at(i) << random_colors.at(i) << suffix << endl;
			guess_correct = false;

			//iterating through prefix array and checking for correcr answer
			while (guess_correct == false){
				cin >> guess;

				//checking if guess is right
				if(guess == random_codes_color.at(i)){
					cout << i << "/20 complete" << endl;
					guess_correct = true;
				}
				else {
					cout << "incorrect try again" << endl;
					guess_correct = false;
				}
			}
		}
		
		//totaluing time and asking user if they want to play agaim
		clock_t end_time = clock();
		float total_time = end_time - start_time;
		cout << "It took you " <<  total_time/100 << " seconds to complete" << endl;
		cout << "Try again to beat your time \"y\" or \"n\"?" << endl;

		//seeing if player wants to play again
		bool selection_play = true;
		while(selection_play == true){
			cin >> keep_playing;

			//checking inputs
			if(keep_playing == "y"){
				selection_play = false;
				cont_play = true;
			}
			else if(keep_playing == "n"){
				cout << "Thanks for playing" << endl;
				selection_play = false;
				cont_play = false;
				break;
			}
			else{
				cout << "I do not understand this message" << endl;
				selection_play = true;
			}
		}
	}
	}

}