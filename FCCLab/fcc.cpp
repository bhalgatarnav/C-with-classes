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

/**
 * <returnIndex>
 * The function should return index of typo in the typos file.
 * input: string
 * output: index
 * 
*/
int returnIndex(std::string typo, std::vector<std::string> typos) {
  for (int i = 0; i < typos.size(); i++) {
    if (typos[i] == typo) {
      return i;
    }
  }
  return -1;
}


int fcc(const std::string &fixme_filename, const std::string &typo_filename,
        const std::string &fixo_filename, std::string &fixed_sentence) {
    /**
     * fixme_filename: will be the name of the file that contains the sentence to fix.
     * typo_filename: will be the name of the file that contains the typos.
     * fixo_filename: will be the name of the file that contains the fixos for the typos.
     * fixed_sentence: will be the name of the file where the fixed sentence is stored.
    */
   
    // Vectors consisting the Words extracted from the file.
    std::vector<std::string> fixos;
    std::vector<std::string> typos;

    // Opening all the files to read the content.
    std::ifstream inputFixosFile;
    inputFixosFile.open(fixo_filename);

    std::ifstream inputTyposFile;
    inputTyposFile.open(typo_filename);
    
    std::ifstream inputFixmeFile;
    inputFixmeFile.open(fixme_filename);

    // Initialise the Counter Variable.
    int count = 0;

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

  if (typos.size()!=fixos.size()){
    return -1; 
  }

  else {
  std::string fixme;
  while(more_to_read(inputFixmeFile)){
    inputFixmeFile >> fixme;
    // Call the funtion returnIndex to check if it is a typo.
    if (returnIndex(fixme, typos) == -1){
      fixed_sentence += fixme + " ";
    } else {
      // Access that same index and check the word in fixos file.
      fixed_sentence += fixos[returnIndex(fixme, typos)] + " ";
      count++;
    }
    
  }

  // Removing the extra space and replacing that with a full stop.
  fixed_sentence = fixed_sentence.substr(0, fixed_sentence.size()-1);
  fixed_sentence += ".";

  return count;
  }
  
}


/**
 * <appendSentence>
 * The function would append and create the corrected sentence.
 * input: string
 * output: void
*/