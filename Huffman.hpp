/******************************************************************
* Programming Project 4 Huffman Code Generator: Huffman.cpp       *
* This program takes in a string and compress it into a binary    *
* algothrim and serializes them based on their prefixes and other *
* particular criteria via sorting through a heap-based queue and  *
* binary tree.                                                    *
* By: Curtis Smith III                                            *                                                                
*******************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include<stack>
#include <stdio.h>
#include <string>
#include <vector>

#include "HeapQueue.hpp"


class HuffmanTree : public HuffmanTreeBase {
public:
	
	void convert(HuffmanNode* root, std::string str, std::map<char, std::string> &binary);     // converting string into binary
    void postorderTraversal(HuffmanNode* root);                                          // sort chars with postorder traversal                            
	std::string compress(const std::string inputStr);                                     // function to compress input string
	std::string serializeTree() const;                                                    //serialize tree based on internal/external nodes
	std::string decompress(const std::string inputCode, const std::string serializedTree);// return original string decompressed

private:
	HeapQueue<HuffmanNode*, HuffmanNode::Compare> minHeap; //minheap
	HuffmanNode *node, *t; //nodes
	std::string temp = ""; //temp to be used in .cpp implementation
	std::string answer = ""; //string to be used for result
    std::string serializedTree = ""; //serialized tree string to be returned
	
   
};

#endif
