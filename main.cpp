// Driver program for sheepHerder

#include "SheepHerder.h"

int main(int argc, char* args[]) {
	//Adjust window size using command line arguments
	/*if (argc == 3) { //if two arguments given
		width = atoi(args[1]);
		height = atoi(args[2]);
	} else if (argc != 1 && argc != 3) {
		cout << "No additional arguments or two are required. I could not understand this request. Please check our ReadMe for more a more detailed explaination" << endl;
		return 1;
	}*/

	SheepHerder shepherd;
	shepherd.playGame();
	
        return 0; 
}
