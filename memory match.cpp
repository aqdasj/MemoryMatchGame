// Aqdas Juya , 05/06/2024 , ajuya@pdx.edu ,  Program # 2 , cs 162
// In this game, the first player enters a sentence, and the second player has a short time to memorize it.
//After the memorization period, the second player tries to recall and repeat the sentence as accurately as possible. 
//The game evaluates their memory based on how many words are correctly recalled, ignoring any differences in case or punctuation.


#include <ctime>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

const int SIZE {121};


void welcome();
void clearscreen();
void stopScrean (char words[], int sec); 
void s_input(char array[]);
int count_match( char words[], char compare[]);


using namespace std;
// This is the main function where all the other function come into the main function. 
int main()
{
	char phrase[SIZE];
	char secound_input[SIZE];
	int matched_words {0};
	int attempts {0};
	int option {0};
	welcome();

	cout << "\nWould you like to start (Enter '1' if you want to continue and '2' or any other numbers if you want to quit: ";
	cin >> option; 
	cin.ignore(100,'\n');


	while(option == 1)
	{
	attempts = 0;
	matched_words = 0;
	
	        cout << "\nPlease enter the character to match: ";
	        cin.getline(phrase,SIZE);
		s_input(phrase);
		int total_cars = strlen(phrase);
		while (attempts < 2 && matched_words < total_cars /2) {
			clearscreen();
			stopScrean(phrase, 4);
			cout << "\nPlease enter the character to match: ";
		        cin.getline(secound_input,SIZE);
			s_input(secound_input);
			matched_words = count_match(phrase, secound_input);
			attempts++;
			if(matched_words >= total_cars / 2) {
				cout << "\nYour matched words are at least 50% correct or more. \n"<< endl;
			} else {
				cout << "\nThe matched words are fewer then 50% correct. \n"<< endl; 
			}
		}


		cout << "The total matched words is: "<< matched_words << endl;
	        cout << "\nWould you like to start (please enter '1' if you want to continue and '2' or any other number if you want to quit: ";
	        cin >> option; 
       		cin.ignore(100,'\n');

	}
	cout << "\nThank you for using this game!!!\n" << endl; 


	return 0;
}

// This is the function that would cound the numbers of matched form the first sentance and the secound sentance
// This function takes the array of the first phrase and the secound input and return the number of words matched between them. 
int count_match(char words[], char compare[]) {
	int counter = 0; 
	int length = strlen(words);
	int length_two = strlen(compare);

	for(int i = 0; i <length && i < length_two; ++i) {
		if(words[i] == compare[i]) {
			++counter;
		}
	}
	return counter;
}


// This is a void function that will take the phrase and turn them into a lower case letter.
// This function will also avoid the punctuation which helps in to count the numbers easily. 
void s_input( char array[])
{


	for(int i {0}; array[i] != '\0'; ++i) {
		if(!(isalpha(array[i]))) {
			array[i] = ' ';
		}
		array[i] = tolower(array[i]);
	}

	return;
}
// This is a void function where it will welcome the user and also explain the program.
void  welcome()
{

	cout << "\nWelcome to our matching program!! " << endl; 
	cout << "\nThis game will include two players. The first player will enter a sentence, and the second player will have a limited time to memorize it. " 
	     << "Following the memory period, the second player attempts to recall and repeat the line as precisely as possible. " 
	     <<	"After they have answered and made all of their attempts, they will receive an answer indicating whether or not their answer was correct. "
	     << "Please remember that if you are fewer the 50% correct this program will show you the answer again and you get a chance to rewrite it again. \n";
	cout <<endl;
}
// This is void function where it will clear the screen by puting 90 spaces.
void clearscreen()
{
	for(int i = 0; i < 90; ++i)
	{

		cout << '\n';
	}
}
// This is a void function where it stops the screand by using the sleep function. 
// This function also gets the first phrase and show it to the user. 
// it also pass the count of secound by int sec. 
void stopScrean (char words[], int sec) 
{
	cout << "Memorize this sentence carefully: " << words << endl;
	sleep(sec);
	clearscreen();
}


