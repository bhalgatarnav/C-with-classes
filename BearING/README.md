# BearING Search Engine - Porter Stemming Algorithm Implementation

## Purpose
This repository contains the solution for Lab 6, where the goal was to implement 9 helper functions for the BearING search engine, specifically designed for the Porter Stemming Algorithm. The Porter Stemming Algorithm helps in reducing words to their core by removing suffixes, making it easier to match and compare words with similar meanings.

## Helper Functions
1. **is_vowel**
   - Input: a character
   - Output: boolean (true if the character is a vowel, false otherwise)
   - Determines if a given character is a vowel.

2. **is_consonant**
   - Input: a character
   - Output: boolean (true if the character is a consonant, false otherwise)
   - Determines if a given character is a consonant.

3. **ends_with_double_consonant**
   - Input: a string
   - Output: boolean
   - Checks if the last two characters of the string are both consonants and equal to each other.

4. **ends_with_cvc**
   - Input: a string
   - Output: boolean
   - Checks if the last three characters of the string form a consonant-vowel-consonant pattern.

5. **contains_vowel**
   - Input: a string
   - Output: boolean
   - Checks if the string contains at least one vowel.

6. **count_consonants_at_front**
   - Input: a string
   - Output: integer
   - Counts the number of consecutive consonants at the beginning of the string.

7. **count_vowels_at_back**
   - Input: a string
   - Output: integer
   - Counts the number of consecutive vowels at the end of the string.

8. **ends_with**
   - Input: two strings (candidate and suffix)
   - Output: boolean
   - Checks if the candidate string ends with the specified suffix.

9. **new_ending**
   - Input: a string, a number (suffix length), and a string (replacement)
   - Output: a new string
   - Replaces the last suffix length characters of the candidate string with the replacement string.

## Implementation Details
- All functions are implemented in the `helpers.cpp` file.
- Unit tests are provided to validate the correctness of each function.
- Comments conform to the specified format to enhance code readability and understanding.


## Contributions
Contributions are welcome! If you find any issues or have improvements to suggest, please open an issue or create a pull request.


Happy coding! 🚀
