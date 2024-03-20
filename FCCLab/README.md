## FCC: Friendly Communication Checker

This program implements a simple autocorrect system called FCC (Friendly Communication Checker). It corrects common typos in a sentence based on user-defined configurations. 

### Files:

* **fcc.cpp:** Contains the source code for the FCC program.
* **main.cpp:** Contains the `main` function and unit tests.
* **fixme.txt:** Contains the sentence to be corrected.
* **typos.txt:** Contains a list of commonly misspelled words.
* **fixos.txt:** Contains the corresponding correct spellings for the typos.

### Usage:

1. Edit the `typos.txt` and `fixos.txt` files to configure the typos and their corresponding fixes. 
2. Place the sentence to be corrected in `fixme.txt`.
3. Compile and run the program. 

The program will output the corrected sentence and the number of corrections made. 

### Algorithm:

The `fcc` function implements the core logic of the program. It reads the typos and fixos from their respective files, parses the sentence to be corrected, and performs the following steps:

1. For each word in the sentence:
    * Check if the word is present in the `typos` vector.
    * If found, replace it with the corresponding fixo from the `fixos` vector.
    * Otherwise, keep the word unchanged.
2. Append a period to the corrected sentence.
3. Print the corrected sentence and the number of corrections made.

The program also uses helper functions like `read_from_file` to read words from a file and store them in a vector. 

### Notes:

* This is a basic implementation and can be further enhanced to handle more complex scenarios.
* The program assumes that the input files are formatted correctly and contain valid data. 

### Critical Thinking: Algorithmic Fairness

This lab also explores the concept of algorithmic fairness and the potential for algorithms to perpetuate biases and harm certain groups. The Data & Society Research Institute is highlighted as an organization actively researching and advocating for fairness in the application of algorithms to big data. 

