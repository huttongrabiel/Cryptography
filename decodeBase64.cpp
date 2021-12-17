#include <iostream>
#include <sstream>

std::string decimalToBinary(int);
char binaryToAscii(std::string);
long int power(long int, long int);

int main() {
  std::string input = "c3ludCB2ZiA6IGEwX29icWxfczBldHJnX2RlX3BicXI=";
  int asciiValues[44]; // kinda cheating since i know the length of the input
 
  std::string base64Ascii = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz0123456789+/";

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == '=') {
      continue;
    }
    for (int j = 0; j < base64Ascii.length(); j++) {
      if (input[i] == base64Ascii[j]) {
        asciiValues[i] = j;
      } 
    }
  }

  std::string binaryValueString = "";

  int asciiValuesLength = sizeof(asciiValues) / sizeof(int);
  for (int i = 0; i < asciiValuesLength; i++) {
    binaryValueString+=decimalToBinary(asciiValues[i]);
  }
  
  std::string decodedValue = "";
  
  std::string base64DecodedString = "";
  for (int i = 0; i < binaryValueString.length(); i++) {
//    std::cout << binaryValueString.substr(i,8) << "\n"; 
    base64DecodedString.push_back(binaryToAscii(binaryValueString.substr(i, 8)));
    i += 7; // move to next set of 8 bits, sliding window style
  }
  std::cout << base64DecodedString << "\n";
}

/* int cur[32] has to be defined outside the function. If not defined
   outside the function, it attempts to allocate memory on top of
   already allocated memory, leading to memory corruption
*/
int cur[32]; 

// this function is broken somehow
std::string decimalToBinary(int asciiValue) {
 
  // set all values in cur to 4 
  int curLen = sizeof(cur) / sizeof(int); 
  for (int i = 0; i < curLen; i++) {
    cur[i] = 4;
  }

  int count = 0;
  do {
    cur[count] = asciiValue % 2;
    asciiValue /= 2;
    count++;
  } while (asciiValue > 0);

  std::string binaryValue = "";
  for (int i = curLen-1; i >= 0; i--) {
    if (cur[i] == 4) {
      continue; 
    }
    else {
      binaryValue.push_back(cur[i] + '0');
    }
  }

// add leading 0's if length is below six
  while (binaryValue.length() < 6) {
    binaryValue.insert(0, 1, '0');
  }
  return(binaryValue);
}

char binaryToAscii(std::string binaryValue) {
  int count;
  int splitInput[8];
  long int decimalNumber;
  long int num;

  std::stringstream convert(binaryValue);
  convert >> num;

  count = 0;
  do {
    splitInput[count] = num % 10;
    num /= 10;
    count++; 
  }  while (num != 0); 

  decimalNumber = 0;
  for (int i = 0; i < count; i++) {
    splitInput[i] *= power(2, i);
    decimalNumber += splitInput[i];
  }
  return((char)decimalNumber); // convert ascii value to char
}

long int power(long int base, long int exponent) {
  long int res = 1;
  for (int i = 0; i < exponent; i++) {
    res *= base;
  }
  return res;
}
