#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include "fcc.h"

bool more_to_read(std::ifstream &file) {
  file >> std::noskipws;
  while (file.peek() == ' ') {
    char discard;
    file >> discard;
  }
  return !(file.eof() || std::iscntrl(file.peek()));
}

int fcc(const std::string &fixme_filename, const std::string &typo_filename,
        const std::string &fixo_filename, std::string &fixed_sentence) {
    /**
     * fixme_filename: will be the name of the file that contains the sentence to fix.
     * typo_filename: will be the name of the file that contains the typos.
     * fixo_filename: will be the name of the file that contains the fixos for the typos.
     * fixed_sentence: will be the name of the file where the fixed sentence is stored.
    */

    std::vector<std::string> fixos;
    std::vector<std::string> typos;

    std::ifstream inputFixosFile;
    inputFixosFile.open(fixo_filename);

    std::ifstream inputTyposFile;
    inputTyposFile.open(typo_filename);
    

    /**
     * A while loop that will read the fixo_filename and typo_filename files and store the words in the fixos and typos vectors.
     * The function `more_to_read` is used to determine if there are any words left in the file.
    */

    while(more_to_read(inputFixosFile)){
        std::string fixo;
        inputFixosFile >> fixo;
        fixos.push_back(fixo);
    }
    while(more_to_read(inputTyposFile)){
        std::string typo;
        inputTyposFile >> typo;
        typos.push_back(typo);
    }
/**
 * Checking the vectors for the contents:
 * for (auto str : typos) {
   std::cout << "str: #" << str << "#\n";
    }

    for (auto str : fixos) {
   std::cout << "str: #" << str << "#\n";
    }
*/
  
if (typos.size()!=fixos.size())

{
 return -1; 
}

  return -1;
}