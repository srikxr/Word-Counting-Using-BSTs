/*
WordTree.h - Srikar Chava 3/11/22


The code in this file serves as definitions of the functions and data types that need to be implemented within the
program. It inlcudes friend definitions of operator overload, a struct WordNode, and multiple private member functions as 
well as public functions that manipulate the tree or read the input.

*/

#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct WordNode {
    int value;
    string word;

    WordNode* left_; //left node
    WordNode* right_; //right node

    WordNode();  // initializes a node with left and right set to null and everything set to nothing
    WordNode(string word); // initializes a node with left and right nodes as nullptrs and the string that is passed in

};

class WordTree{
public:
    //constructors
    WordTree(); // default constructor, sets root nullptr
    ~WordTree(); // destructor calls remove method and deletes the root, causing deletion of whole tree

    //methods
    void add(WordNode node);
    void filter(string sentence); //method to filter out any symbols and make the whole word lower case
    int numWords() const; // method to return the number of unique words within the inputed text
    int countNodes() const; //method to return the number nodes in WordTree
    void printTree(ostream& out) const; //method to print WordTree
    WordNode* addString(string word, WordNode* node); //method to add a single word into the tree

    friend ostream& operator<<(ostream& out, const WordTree& tree); //Operator Overload to call print function

private:
    void insertIntoWordTree(WordNode*& node, string word); //inserts new WordNode
    void remove(WordNode* node); //removes a node, gets called by destructor
    int countSingleNodes(WordNode* node) const; // counts number of nodes
    int countTotalSingleNodes(WordNode* node) const; //counts unique number of words
    void printSingle(WordNode* node, ostream& out) const; //prints the values of a node, traverses the tree
    void clearMemory(WordNode* node); //helper method to delete memory using post order traversal


    WordNode* root_; //private member variable to define the root of the tree
};