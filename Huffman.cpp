#include "Huffman.hpp"

//place chars into a string and convert them (encode)
void HuffmanTree::convert(HuffmanNode* root, std::string str, std::map<char, std::string> &binary) 
{
        if (root == nullptr) {return;}
        //if the root is the leaf, get char and plate in tree
        
        if (root->isLeaf()) 
        {
            binary[root->getCharacter()] = str;
        }
            convert(root->left, str + "0", binary);
            convert(root->right, str + "1", binary);

            if(root->isLeaf())
            {   
                //as indicated in instructions, add a L, push char
                serializedTree.push_back('L');
                serializedTree.push_back(root->getCharacter());
            }
            // if its not the leaf then it is an internal node/branch
            else
            {  
                //push B
                serializedTree.push_back('B');
            }

}

// traverse through the tree using postorder
void HuffmanTree::postorderTraversal(HuffmanNode* root) 
{   
    // if null, return null pointer
    if(root == nullptr)
    {   
        //recur left side
        postorderTraversal(root->left);
        //recur on right side
        postorderTraversal( root->right);
        
        // verify its the last node
        if(root->isLeaf())
        {   
            std::cout <<"L"<< root->getCharacter();
            // add a L to the tree
            serializedTree.push_back('L');
            serializedTree.push_back(root->getCharacter());
        }
        // if its not the leaf, it is an internal node/branch
        else
        {   
            //add B and push back
            std::cout<<"B";
            serializedTree.push_back('B');
        }
    
    }
}

// compress function
std::string HuffmanTree::compress(const std::string inputStr) 
{
    // count for map
    std::map<char, int> n;

    // read input string using for loop
    for (char ch : inputStr) 
    {
        n[ch]++;
    }

    // count elements and insert elements for compression 
    for (auto e : n) {
        minHeap.insert(new HuffmanNode(e.first, e.second));
    }

    //i used a while loop to find min elements 
    while (minHeap.size() > 1) 
    {
        //if left is min remove
        HuffmanNode *left = minHeap.min();
        minHeap.removeMin();
        //if right is min then remove
        HuffmanNode *right = minHeap.min();
        minHeap.removeMin();
        
        //sum of frequencies
        int sum = left->getFrequency() + right->getFrequency();
        //insert new node to minheap
        minHeap.insert(new HuffmanNode('\0', sum, t, left, right));
    }

    // is root min>
    HuffmanNode* root = minHeap.min();

    
    std::map<char, std::string> sortedMap;

    // traverse using postorder function, and then convert to binary (starnig at the root)
    postorderTraversal(root);
    convert(root, "", sortedMap);

    std::string temp2 = "";
    for (char ch : inputStr) 
    {
        //adding chars to the string
        temp2 += sortedMap[ch];
    }

    answer = temp2;
    temp=inputStr;
    //returning string
    return temp2;
}

//decompressing function
std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree) 
{
    // using stacks for nodes
    std::stack<HuffmanNode *>nodeStack;
    
    // for-loop to search through the contents of the serialized tree and retrieving the elements
    for(unsigned int i=0; i<serializedTree.length(); i++)
    {
        //checking for a L
        if(serializedTree[i] == 'L')
        {
            i++;
            // get next char
            char ch = serializedTree[i];
            //create a new node and add to stack
            HuffmanNode* newNode = new HuffmanNode(ch, 0, nullptr, nullptr, nullptr);
            nodeStack.push(newNode);
        }

        //else means its a brach/internal node
        else
        {
            // pop the top nodes
            HuffmanNode* second = nodeStack.top();
            nodeStack.pop();
            HuffmanNode* first = nodeStack.top();
            nodeStack.pop();
            //create another new node and add
            HuffmanNode* newNode = new HuffmanNode(0, 0, nullptr, first, second);
            
            // push back into stack
            nodeStack.push(newNode);
        }
    }
    
    
    // root
    HuffmanNode* root = nodeStack.top();
    HuffmanNode* curr;
    
   
   //if the node is found then store it
    bool found = false;
    unsigned int j = 0;

   
    //decoded string to be returned
    std::string decoded = "";
    
    

    while(j < inputCode.length())
    {
       //get tge chars

        if(!found)
        {
            curr = root;
            found = true;
        }
        else
        {
            //if char
            if(curr->isLeaf())
            {
                //set found to false
                found= false;
                
                //push result into decoded string
                decoded.push_back( curr->getCharacter() );   
            }

            // move to either side based on the 0 or 1

            else
            {  
                if(inputCode[j] == '0' )
                    curr = curr->left;
                else
                    curr= curr->right;
                j++;
            }
        }
    }
    
    //push back into decoded string and return it 
    decoded.push_back(curr->getCharacter());
    return decoded;

}


std::string HuffmanTree::serializeTree() const 
{
    return serializedTree;
}
