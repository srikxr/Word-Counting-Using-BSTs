/*
Countwords.cpp - Srikar Chava 3/11/22


The code in this file serves as the main driver for the rest of the implementations.
This file will take in the input through cin, it can be either a text file or a typed out sentence,
and it will parse it through a filter function, which will add text to the tree. This function then 
will print the tree, with the contents of words and their occurences as well as the total unique and general
words in the input.

*/
#include <iostream>
#include "WordTree.h"
using namespace std;

int main()
{    
    WordTree tree; // the new tree object
    string sentence = ""; // empty string for characters to be added into

    cout << "Enter a Sentence: " << endl; // enter a sentence if user did not pass in a text file
    
    char c; 
    while(true) {
        c = cin.get(); //gets character one by one from the input
        sentence += c; // adds character the sentence
        tree.filter(sentence); // eventually the sentence gets filtered by passing through filter method

        if (c == EOF) { // when the program reaches the end of the file, while loop breaks
            break;
        }
    }

    int wordcount = tree.numWords(); // assigns numwords of the given tree to variable
    
    cout << "\nWord counts:\n\n"; 
    cout << tree; // operator overload couts the tree and the values in an orderly list

    cout << "\nTotal number of words in text: " << wordcount << ".\n"; // couts the overall wordcount from numWords
    cout << "Number of distinct words appearing in text: " << tree.countNodes() << ".\n"; //couts the number of nodes, which is also the number of unique words.
    return 0;
}