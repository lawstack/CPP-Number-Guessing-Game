#include <iostream>
#include <cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printWelcomeMessage() {
    
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;
    std::cout << "You have N chances to guess the correct number." << std::endl;

}

void difficultyMessage() {
    
    std::cout << "Please select the difficulty level:" << std::endl;
    std::cout << "1. Easy (10 chances)" << std::endl;
    std::cout << "2. Medium (5 chances)" << std::endl;
    std::cout << "3. Hard (3 chances)" << std::endl;

}

void playOrQuitMessage() {

    std::cout << "Press 1 to Play" << std::endl;
    std::cout << "Press 2 to Quit" << std::endl;
}

int numberOfChances(int input) {
    int chance=0;

    switch (input)
    {
    case 1:
        chance = 10 ;
        break;

    case 2:
        chance = 5;
        break;

    case 3:
        chance = 3;
        break;
    
    default:
        chance = 0;
    }
    
    return chance;
}

void guessed(int n, int rn, int a) {
	
	if(n<rn) {
		
		std::cout << "Incorrect, the number is greater than " << n << std::endl;
	
	} else if (n>rn) {
		
		std::cout << "Incorrect, the number is less than " << n << std::endl;
	
	} else {
		
		std::cout << "Congratulations! You guessed the correct number in " << a << " attempts." << std::endl;
		exit(EXIT_SUCCESS);
	}
}

int main() {
	
	srand(time(0));
	tm_sec sec;
	
    int guess = 0, choice = 0, dl = 0, attempts=0, score=0, randomNumber = (std::rand() % 100) + 1;
    std::string difficultyLevel[] = {"Easy","Medium","Hard"};
    
    printWelcomeMessage();
    std::cout << std::endl;
    
	playOrQuitMessage();
    
	std::cout << "Choice: ";
    std::cin >> choice;
	
	
		difficultyMessage();
		std::cout << std::endl;		
		std::cout << "Difficulty level: ";
		std::cin >> dl;
		
		int chances = numberOfChances(dl);
		
		std::cout << "Great You have selected the " << difficultyLevel[dl-1] <<" difficulty level." << std::endl;
		std::cout << "Let's start the game!" << std::endl << std::endl;
		
	do {	
		
		std::cout << "Enter your guess: ";
		std::cin >> guess;
		std::cout << std::endl;
			
		attempts++;	
		guessed(guess, randomNumber, attempts);
		chances--;	
	}
	
	while(chances!=0);

    


    return 0;
}
