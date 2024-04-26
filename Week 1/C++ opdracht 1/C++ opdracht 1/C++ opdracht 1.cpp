// C++ opdracht 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool search(std::string& s, char& key) {
	size_t position = s.find(key);
	if (position != std::string::npos) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	std::string woord = "hallo";
	char letter = 'h';

	bool result = search(woord, letter);

	if (result == 1) {
		std::cout << "Letter " << letter << " is found in word " << woord << " ." << std::endl;
	}
	else{
		std::cout << "Letter " << letter << " is not found in word " << woord << " ." << std::endl;
	}

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
