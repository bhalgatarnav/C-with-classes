# Lab 5 - 1d3s Encryption

## Introduction

This lab focuses on encryption, specifically the implementation of the Caesar Cipher. The Caesar Cipher is a substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet. This lab aims to create a C++ program named 1d3s that reads a key and plaintext message from a file, encrypts the message using the Caesar Cipher, and prints the encrypted version.

## Program Design

### Pseudocode

```plaintext
Read the encryption key (shift number and direction) and plaintext from a file
Handle errors in the formatting of the input file
For each character in the plaintext
    Calculate the index of the plaintext character
    Calculate the index of the ciphertext character
    Handle situations where the index of the ciphertext character is longer than the alphabet
    Handle the situation where the index of the ciphertext character is shorter than the alphabet
    Convert the (possibly adjusted) index of the ciphertext character to the actual ciphertext character
    Print the ciphertext to the screen
```

### Algorithm Practice Chart

The algorithm practice chart involves implementing the Caesar Cipher algorithm using modulo arithmetic and considering corner cases when shifting characters.

## Critical Thinking Task

The critical thinking task involves describing a mechanical process for converting between generic for loops and while loops. This requires understanding the components of both types of loops and how they can be transformed while maintaining functionality.

## Programming

The programming task requires implementing the 1d3s application in C++. The program should read input from a file named `input.txt`, handle errors in formatting, and correctly calculate and print the ciphertext.

## Question

The question task encourages students to ask questions related to the material covered in the lab. This provides an opportunity for clarification and ensures that students engage with the content.

## Contents in the folder

1. Pseudocode (PDF): `design.pdf`
2. Algorithm Practice Chart (PDF): `cipher-practice.pdf`
3. C++ Source Code: `1d3s.cpp`
4. Critical Thinking Task Response (PDF): `equivalent.pdf`
5. Written Question about the Material (PDF): `question.pdf`

## File Description

1d3s.cpp: This file is the main solution for the lab. It includes functions that perform encryption and decryption using the Caesar Cipher algorithm. The functions read the encryption key (shift number and direction) and plaintext from a file, handle formatting errors, and output the encrypted or decrypted message.
## Learning Objectives

- Writing boolean expressions using relational and logical operators
- Using if-statements to implement selective program execution
- Using algorithmic thinking to design programs
- Writing syntactically correct for, while, and do-while loops
- Identifying the components of for, while, and do-while loops
- Understanding the difference between pre- and post-test loops
- Using each of the three types of loops in the appropriate situation
- Using methods on file stream objects to read/write files

---

Feel free to reach out if you have any questions or need further clarification on the solution!
