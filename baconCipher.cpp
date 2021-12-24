#include <iostream>
#include <sstream>

int main() {
  std::string userInput = "";
  std::string lowerAlphabet = "abcdefghiklmnopqrstuwxyz";

  std::cout << "Enter your baconian input: ";
  std::cin >> userInput;

  // iterate in values of 5
  std::string substring = "";
  std::string binaryValue = "";
  std::string res = "";
  for (int i = 0; i < userInput.length(); i++) {
    substring = userInput.substr(i, 5);
    std::cout << substring << "\n";
    for (int j = 0; j < substring.length(); j++) {
      if (substring[j] == 'A') {
        binaryValue += '0';
      }
      else {
        binaryValue += '1';
      }
    }
    int binaryNum = std::stoi(binaryValue, nullptr, 2); // convert binary string to int
    res.push_back(lowerAlphabet[binaryNum]); 
    i += 4;
    binaryValue = ""; 
  }
  std::cout << res << "\n";
}
