#include <iostream>

/* ROT cipher implementation. Can rotate left or right, and by any amount
   that the user specifies. */

int main() {
  int rotateAmount;
  char leftOrRight;
  std::string userInput;

  std::cout << "Enter amount of positions to rotate by: ";
  std::cin >> rotateAmount;

  while (leftOrRight != 'l' && leftOrRight != 'r') {
    std::cout << "Left or Right(l/r): ";
    std::cin >> leftOrRight;
  }
  
  std::cout << "Enter string to rotate: ";
  std::cin >> userInput;

  std::string upperCaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string lowerCaseAlphabet = "abcdefghijklmnopqrstuvwxyz";

  /* Logic:
      * When rotating, you take the amount to rotate by and add it to the index
        If the index is larger than the length of the alphabet, we have to mod 
        the index value by the length value, ie. index=14 len=10 14 % 10 = 4 
  */

  // uppcase characters are less than 90 and lowercase are greater than 97
  int alphabetIndex = 0;
  int indexOfChar = 0;
  for (int i = 0; i < userInput.length(); i++) {
    indexOfChar = lowerCaseAlphabet.find(userInput[i]);
    if (leftOrRight == 'r') {
      alphabetIndex = indexOfChar + rotateAmount;
    }
    else {
      if (indexOfChar - rotateAmount < 0) {
        alphabetIndex = rotateAmount - indexOfChar;
      }
      else {
        alphabetIndex = indexOfChar - rotateAmount;
      }
    }
    while (alphabetIndex > 25) { // wrapping around to text
      alphabetIndex %= 25;
      alphabetIndex--; // accounting for indexes starting at 0
    }
    if ((int)userInput[i] <= 90) { 
      userInput[i] = upperCaseAlphabet[alphabetIndex];
    }
    else {
      userInput[i] = lowerCaseAlphabet[alphabetIndex];
    }
  }

  std::cout << userInput << "\n";
}
