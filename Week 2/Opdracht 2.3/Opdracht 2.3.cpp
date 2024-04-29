// Opdracht 2.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

std::string convertToLowerCase(std::string word) {
    std::string result = "";

    for (char c : word) {
        result += tolower(c);
    }

    return result;
}

void checkPalindrome(std::string word) {
    std::string lowerword = convertToLowerCase(word);
    std::string reverse = lowerword;
    std::reverse(reverse.begin(), reverse.end());

    if (reverse.compare(lowerword) == 0) {
        std::cout << "the word " << word << " is a palindrome" << std::endl;
    }
    else {
        std::cout << "the word " << word << " is not a palindrome" << std::endl;
    }

}

int main()
{
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;

    checkPalindrome(word);
}


