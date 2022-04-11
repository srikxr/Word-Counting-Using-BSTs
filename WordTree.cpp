/*
WordTree.cpp - Srikar Chava 3/11/22

The code in this file serves as implementations of the functions that were defined in WordTree.h
The functions in this class will be used for mainpulation of the Binary Search Tree, as well as functions
relating to printing the BST and reading the inputs.

*/

#include <iostream>
#include "WordTree.h"
using namespace std;

//constructor method for WordNode, sets a default node with nothing in it.
WordNode::WordNode()
{
    word = "";
    value = 0; //empty values inside node

    left_ = nullptr;
    right_ = nullptr; //not pointing to any other nodes
}

//copy constructor method for WordNode struct, takes in a string and sets the string of the word same as parameter
WordNode::WordNode(string word)
{
    this->word = word; //sets node word to the inputted word
    value = 1; 

    left_ = nullptr;
    right_ = nullptr; // remains not pointing to anything
}

//default constructor sets root node = nullptr
WordTree::WordTree()
{
    root_ = nullptr; //root = nullptr
}

//destructor removes the root of the tree, deleting the entire tree
WordTree::~WordTree()
{
    remove(root_); //removes the root
    clearMemory(root_); // clears the memory and anything pointed to root
}

//add function takes in a WordNode and calls the insert function to add into the tree
void WordTree::add(WordNode node)
{
    insertIntoWordTree(root_, node.word);
}

//filter method deems if the inputted word is considered a word or not
//takes in the inputted text from main method as a string
void WordTree::filter(string sentence)
{
    char currentChar; //current char that is being processed
    string word;

    while (cin.get(currentChar))
    {
        word = "";

        while (isalpha(currentChar) || currentChar == '\'') //looks to see if the character is a letter or a space
        {
            currentChar = tolower(currentChar); //makes the text lowercase
            word += currentChar; // adds character to the string
            cin.get(currentChar); //gets a new character
        }

        if (!word.empty())
        {
            WordNode n1 = WordNode(word);
            add(n1); // adds the WordNode to the tree
        }
    }
}

//method to calculate the total number of words in the input
int WordTree::numWords() const
{
    return countTotalSingleNodes(root_); // calls countTotalSingleNodes and passes root_ to measure how many values are in the tree
}

//method to calculate the total number of nodes within the tree
int WordTree::countNodes() const
{
    return countSingleNodes(root_); //calls countSingleNodes and passes root_ to measure how many nodes are in the tree from root_
}

//method prints out the whole tree 
// takes in ostream object and calls the print single function
void WordTree::printTree(ostream& out) const
{
    printSingle(root_, out); //passes in the root and the ostream object
}

//ostream operator to output the overall tree and it's values
ostream& operator<<(ostream& out, const WordTree& tree)
{
    tree.printTree(out); // calls print tree function, which calls print function which traverses the tree and prints
    return out;
}

//method recursively adds a string into the current binary search tree 
//takes in string and WordNode object to add in the current binary search tree following the same order
void WordTree::insertIntoWordTree(WordNode*& node, string word)
{
    if (node == nullptr) // if node is nullptr, insert here
    {
        node = new WordNode;
        node->word = word;
        node->value++;
        return;
    }
  
    if (word < node->word)
    {
        insertIntoWordTree(node->left_, word); // checks for left child node
    }

    else if (word > node->word)
    {
        insertIntoWordTree(node->right_, word); // checks for right child node
    }
    else if (word == node->word)
    {
        node->value++; // increments value
    }

}

//remove function to delete a node
//gets used in destructor to remove the root node
void WordTree::remove(WordNode* node)
{
    if (node == nullptr)
    {
       remove(node->left_);
       remove(node->right_);
       delete node;
    }
}

//method counts the total number of nodes there are within the WordTree
int WordTree::countSingleNodes(WordNode* node) const
{
    if (node == nullptr)
    {
         return 0;
    }

    return 1 + countSingleNodes(node->left_) + countSingleNodes(node->right_); // adds up all the nodes
}

//method counts the total number of words within the inputted text
//it gets a node and takes it's value to see how many words there are
int WordTree::countTotalSingleNodes(WordNode* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    return node->value + countTotalSingleNodes(node->left_) + countTotalSingleNodes(node->right_); //adds up all node values
}

//print method traverses each node of the list and prints it out
// takes in a WordNode object as well as an ostream object
void WordTree::printSingle(WordNode* node, ostream& out) const
{
    if (node == nullptr)
        return;

    printSingle(node->left_, out);
    out << node->word << ": occured " << node->value << " times."<< endl;
    printSingle(node->right_, out);
}
	
//helper function to delete memory
//delete memory using POST ORDER TRAVERSAL
void WordTree::clearMemory(WordNode* node) 
{
	if (node) {
		clearMemory(node->left_);
		clearMemory(node->right_);  //recursively clears the memory through each node
		delete node;
		node = nullptr;
	}
}