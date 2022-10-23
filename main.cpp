#include <cstdlib>
#include <iostream>
#include <time.h>
#include <list>

using namespace std;

class TreeNode
{
private:
    int value;
    TreeNode* left;
    TreeNode* right;
    
public:
    TreeNode(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
    
    TreeNode* addNode(TreeNode* currentNode, int value)
    {
        if (currentNode == NULL)
        {
            return new TreeNode(value);
        }
        
        if (value <= currentNode->value) 
        {
            currentNode->left = addNode(currentNode->left, value);
        }
        else
        {
            currentNode->right = addNode(currentNode->right, value);
        }
        
        return currentNode;
    }
    
    bool search(TreeNode* currentNode, int value)
    {
        if (currentNode == NULL)
        {
            return false;
        }
        
        if (value == currentNode->value)
        {
            return true;
        }
        else if (value <= currentNode->value)
        {
            return search(currentNode->left, value);
        }
        else
        {
            return search(currentNode->right, value);
        }
    }
    
    void inOrderTraversal(TreeNode* currentNode)
    {
        if (currentNode == NULL)
        {
            return;
        }
        
        inOrderTraversal(currentNode->left);
        std::cout << currentNode->value << " ";
        inOrderTraversal(currentNode->right);
    }
    
    void preOrderTraversal(TreeNode* currentNode)
    {
        if (currentNode == NULL)
        {
            return;
        }
        
        std::cout << currentNode->value << " ";
        preOrderTraversal(currentNode->left);
        preOrderTraversal(currentNode->right);
    }
    
    void postOrderTraversal(TreeNode* currentNode)
    {
        if (currentNode == NULL)
        {
            return;
        }
        
        postOrderTraversal(currentNode->left);
        postOrderTraversal(currentNode->right);
        std::cout << currentNode->value << " ";
    }
};



int main(int argc, char **argv)
{
    TreeNode root(50);
    root.addNode(&root, 76);
    root.addNode(&root, 21);
    root.addNode(&root, 4);
    root.addNode(&root, 32);
    root.addNode(&root, 64);
    root.addNode(&root, 15);
    root.addNode(&root, 52);
    root.addNode(&root, 14);
    root.addNode(&root, 100);
    root.addNode(&root, 83);
    root.addNode(&root, 2);
    root.addNode(&root, 3);
    root.addNode(&root, 70);
    root.addNode(&root, 87);
    root.addNode(&root, 80);
    
    root.inOrderTraversal(&root);
    std::cout << std::endl;
    root.preOrderTraversal(&root);
    std::cout << std::endl;
    root.postOrderTraversal(&root);
    std::cout << std::endl;
    std::cout << std::boolalpha << root.search(&root, 14) << std::endl << root.search(&root, 84) << std::endl;
    
    return 0;
}