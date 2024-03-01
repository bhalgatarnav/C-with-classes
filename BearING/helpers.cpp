#include <string>

/*
 * is_vowel
 *
 * Determine whether _c_ is a vowel. Note: 'y' is *not* a vowel.
 *
 * input: c: The character to check for "vowelness". type char
 * output: true, if _c_ is a vowel; false, otherwise. type boolean
 */

bool is_vowel(char c)

{
    const char vovels[] = {'a',
    'e',
    'i',
    'o',
    'u'};

    for (int i = 0; i < sizeof(vovels); i++)
    {
        if (c == vovels[i])
        {
            return true;
        }
    }
    //return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

/*
 * is_consonant
 *
 * Determine whether _c_ is a consonant. Note: 'y' is a consonant.
 *
 * input: c: The character to check for "consonantness". type char
 * output: true, if _c_ is a consonant; false, otherwise. type boolean
 */

bool is_consonant(char c)

{
    const char consonants[] = { 
    'b',
    'c',
    'd',
    'f',
    'g',
    'h',
    'j',
    'k',
    'l',
    'm',
    'n',
    'p',
    'q',
    'r',
    's',
    't',
    'v',
    'w',
    'x',
    'y',
    'z'};
    for (int i = 0; i < sizeof(consonants); i++)
    {
        if (c == consonants[i])
        {
            return true;
        }
    }
    //return!is_vowel(c);
}

/*
 * ends_with_double_consonant
 *
 * Determine whether _str_ ends with the same two letters
 * and those letters are both consonants. If _str_ has fewer
 * than two letters, the result is false.
 *
 * input: _str_: The string to check for a double-consontant ending.
 * output: true, if the string ends in the same two letters *and*
 *         those letters are both consontants; false, otherwise.
 *         false, if the string is shorter than 2 characters long.
 */

bool ends_with_double_consonant(std::string str)

{
    if (str.length() < 2)
    {
        return false;
    }
    return is_consonant(str[str.length() - 2]) && is_consonant(str[str.length() - 1]);
}

/*
 * ends_with_cvc
 *
 * Determine whether _str_ ends with the combination of
 * a consonant, a vowel and a consonant. If _str_ is shorter
 * than three characters, the function returns false.
 *
 * input: str: The string to test for a consonant, vowel,
 *        consonant ending.
 * output: true, if _str_ ends in a combination of a consonant,
 *         vowel and consonant. false, otherwise. If _str_ is
 *         shorter than three characters, ends_with_cvc will return
 *         false.
 */

bool ends_with_cvc(std::string str)

{
    if (str.length() < 3)
    {
        return false;
    }
    return is_consonant(str[str.length() - 3]) && is_vowel(str[str.length() - 2]) && is_consonant(str[str.length() - 1]);
}



