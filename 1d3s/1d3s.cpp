#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}





//  This fuction will convert the given character to the encrypted representation.
char cipher_the_char(char value, char direction, int shift) {
  int number = number_from_letter(value);
  if (direction =='l')
  {
    shift *=-1;
  }

  number = (number + shift) % ALPHABET_LENGTH;
  if (number<0)
  {
    number += ALPHABET_LENGTH;
  }
  return letter_from_number(number);
}


/*
//Challenge! This is the code to decrypt the given number of characters.
char decrypt_char(int i)
//The code uses the trial and error method to decrypt and involves the user to read the output.
{
  std::ifstream inputFill;
  inputFill.open("input5.txt");
  char indChar;
  
      // i will denote the shift direction.
   while (inputFill>>indChar)
    {
     float shiftright = i;
     char direc = 'r';
     std::cout<<cipher_the_char(indChar, direc, shiftright);

    }
   std::cout<<"\n";
   std::cout<<"\n";

   char message = 'd'
   return message;
}


int main()
{for (int i = 1; i < ALPHABET_LENGTH; i++)
  {
  decrypt_char(i);
  }
}
*/



// This fuction will convert the given character to the encrypted representation
// This function uses the function cipher_the_char() to convert the given character to the encrypted one.
int main() {
// Initialize the object and opoen a file to read the data.
std::ifstream inputFile;
inputFile.open("input.txt");
char inputFromFile;
int shiftint;
// Reading the input for the shift Direction
inputFile >> inputFromFile;

// Initializing the the shift direction to the first character read.
char shiftDirection = inputFromFile;
// Converting the 1st character to ASCII code to check in if statements.
int code_of_shift_Direction=shiftDirection;


// If structure for checking if the first character read is 'l' or 'r'.
if (shiftDirection == 'r' || shiftDirection == 'l')
{ 
 // Checking if the second character read is a number.
 if ((inputFile >> shiftint))
  { 
    while(inputFile>>inputFromFile)
    {
      // Call the function to encrypt the character.
     std::cout<< cipher_the_char(inputFromFile, shiftDirection, shiftint);

    }
    std::cout<< std::endl;
  }

  else
  { std::cout<< "Oops: Could not read the shift number from the input file.\n";}
}
//Checks if the first character is a letter (Uppercase or lowercase)
else if ((shiftDirection>=65 && shiftDirection<91)||(shiftDirection>=97 && shiftDirection<123))
{ std::cout<< "Oops: Invalid direction in the input file.\n";}

//This checks if the first character is a number using the character codes of first character.
else if((shiftDirection>=48 && shiftDirection<=57))
{ std::cout<< "Oops: Invalid direction in the input file.\n";}

else
{ std::cout<< "Oops: Could not read the direction from the input file.\n";}

}