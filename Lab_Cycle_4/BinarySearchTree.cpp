// 1. Create a Binary Search Tree which supports the following operations:
// ◦ insert(tree, element) – adds the node specified by element (which contains the data)
// into the BST specified by tree.
// ◦ search(tree, key) – searches for the data specified by key in the BST specified by
// tree.
// ◦ delete(tree, element) – removes the node specified by element from the BST
// specified by
// ◦ tree.
// ◦ inorder(tree) – To do a recursive inorder traversal of the BST.
// ◦ preorder(tree) – To do a recursive preorder traversal of the BST.
// ◦ postorder(tree) – To do a recursive postorder traversal of the BST.
// Write a menu driven program to demonstrate these operations.
#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node * left;
        Node * right;   
        Node (int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
class BST{
    private:
        Node * root;    
        Node* insert(Node* currentNode, int element){
            if (currentNode==nullptr){
                return new Node(element);
            }
            if(element<currentNode->data){
                currentNode->left = insert(currentNode->left, element);
            }else if(element>currentNode->data){
                currentNode->right = insert(currentNode->right, element);
            }
            return currentNode;
        }
        void insert(int element){
            root = insert(root, element);
        }
        bool search(Node* currentNode,int key){
            if (currentNode==nullptr){
                return false;
            }
            if (currentNode->data==key){
                return true;
            }
            else if(key<currentNode->data){
                return search(currentNode->left, key);
            }else{
                return search(currentNode->right,key);
            }
        }
        Node* findMin(Node* currentNode){
            while(currentNode->left!= nullptr){
                currentNode = currentNode->left;
            }
            return currentNode;
        }
        Node* deleteNode(Node* currentNode, int key){
            if(currentNode==nullptr){
                return currentNode;
            }
            if(key<currentNode->data){
                currentNode->left = deleteNode(currentNode->left,key);
            }else if (key>currentNode->data){
                currentNode->right= deleteNode(currentNode->right,key);
            }else{
                if(currentNode->left==nullptr){
                    Node* temp = currentNode->right;
                    delete currentNode;
                    return temp;
                }
                else if (currentNode->right==nullptr)
                {
                    Node* temp = currentNode->left;
                    delete currentNode;
                    return temp;
                }
                Node* temp = findMin(currentNode->right);
                currentNode->data = temp->data;
                currentNode->right =deleteNode(currentNode->right,temp->data);                
            }
            return currentNode;
        }
        void inorder(Node* currentNode){
            if(currentNode == nullptr){
                inorder(currentNode->left);
                cout<<currentNode->data<<" ";
                inorder(currentNode->right);
            }
        }
        void preorder(Node* currentNode){
            if(currentNode == nullptr){
                cout<<currentNode->data<<" ";
                preorder(currentNode->left);
                preorder(currentNode->right);
            }
        }
        void postorder(Node* currentNode){
            if(currentNode == nullptr){
                postorder(currentNode->left);
                postorder(currentNode->right);
                cout<<currentNode->data<<" ";
            }
        }
};

