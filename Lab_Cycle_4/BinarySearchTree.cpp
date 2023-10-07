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
            if(currentNode != nullptr){
                inorder(currentNode->left);
                cout<<currentNode->data<<" ";
                inorder(currentNode->right);
            }
        }
        void preorder(Node* currentNode){
            if(currentNode != nullptr){
                cout<<currentNode->data<<" ";
                preorder(currentNode->left);
                preorder(currentNode->right);
            }
        }
        void postorder(Node* currentNode){
            if(currentNode != nullptr){
                postorder(currentNode->left);
                postorder(currentNode->right);
                cout<<currentNode->data<<" ";
            }
        }
        void display(Node* currentNode, int depth) {
        if (currentNode == nullptr) {
            return;
        }

        // Increase the depth for better spacing
        depth += 5;

        // Right child first
        display(currentNode->right, depth);

        // Print the current node with proper indentation
        cout << endl;
        for (int i = 5; i < depth; i++) {
            cout << " ";
        }
        cout << currentNode->data << endl;

        // Left child
        display(currentNode->left, depth);
    }
    public:
        BST(){
            root= nullptr;
        }
        void insert(int element){
            root = insert(root, element);
        }
        bool search(int element){
            return search(root, element);
        }
        void deleteNode(int element){
            root = deleteNode(root, element);
        }
        void inorder()
        {
            inorder(root);
            cout<<endl;
        }
        void preorder()
        {
            preorder(root);
            cout<<endl;
        }
        void postorder()
        {
            postorder(root);
            cout<<endl;
        }
        void display() {
            display(root, 0);
        }
};
int main() {
    BST tree;

    int choice, key;
    while (true) {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Preorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> key;
                tree.insert(key);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> key;
                if (tree.search(key)==true) {
                    cout << key << " found in the tree." << endl;
                } else {
                    cout << key << " not found in the tree." << endl;
                }
                break;
            case 3:
                cout << "Enter element to delete: ";
                cin >> key;
                tree.deleteNode(key);
                break;
            case 4:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 5:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 6:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 7:
                cout << "Displaying tree:" << endl;
                tree.display();
                break;
            case 8:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}



