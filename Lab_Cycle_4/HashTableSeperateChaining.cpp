// Implement a hash table using Linked List with separate chaining with the following
// operations : INSERT(key), DELETE(key), SEARCH(key).
#include<iostream>
using namespace std;
const int TABLE_SIZE = 10;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
class HashTable{
    private:
        Node **table;
        int size;
    public:
        HashTable(){
            table = new Node*[TABLE_SIZE]();
        }
        ~HashTable(){
            for(int i =0;i<TABLE_SIZE;i++){
                Node *temp = table[i];
                while(temp){
                    Node *prev = temp;
                    temp = temp->next;
                    delete prev;
                }
            }
            delete[] table;
        }
        int hash(int key){
            return key%TABLE_SIZE;
        }
        void insert(int key){
            int index = hash(key);
            Node* newNode = new Node(key);
            newNode->next = table[index];
            table[index]= newNode;
        }
        void remove(int key){
            int index = hash(key);
            Node *current = table[index];
            Node *prev = NULL;
            while(current!=nullptr){
                if(current->data==key){
                    if(prev!= nullptr){
                        prev->next=current->next;
                    }else{
                        table[index]=current->next;
                    }
                    delete current;
                    return;
                }
                prev=current;
                current=current->next;
            }
        }
        bool search(int key){
            int index = hash(key);
            Node *current = table[index];
            while(current!=nullptr){
                if(current->data==key)
                    return true;
                current= current->next;
            }
            return false;
        }
        void display(){
            for(int i=0;i<TABLE_SIZE;i++){
                Node* current = table[i];
                cout<<"Bucket "<<i<<" : ";
                while(current!=nullptr){
                    cout<<current->data<<" ";
                    current= current->next;
                }
                cout<<endl;
            }
        }
};

int main() {
    HashTable hashTable;

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(6);    
    hashTable.insert(16);   
    hashTable.insert(7);
    hashTable.insert(69);
    hashTable.insert(5);
    hashTable.insert(65);
    hashTable.insert(1);
    hashTable.insert(2);
    hashTable.insert(3);
    hashTable.insert(4);
    hashTable.insert(5);
    hashTable.insert(6);
    hashTable.insert(7);
    hashTable.insert(8);
    hashTable.insert(9);
    hashTable.insert(10);
    hashTable.insert(11);
    hashTable.insert(12);
    hashTable.insert(13);
    hashTable.insert(14);
    hashTable.insert(16);
    hashTable.insert(17);
    hashTable.insert(18);
    
    cout << "HashTable contents:" << endl;
    hashTable.display();

    cout << "Searching for key 15: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for key 20: " << (hashTable.search(20) ? "Found" : "Not Found") << endl;

    hashTable.remove(15);
    hashTable.remove(20); // This key is not in the table

    cout << "HashTable contents after removal:" << endl;
    hashTable.display();

    return 0;
}



// HashTable contents:
// Bucket 0 : 10
// Bucket 1 : 11 1
// Bucket 2 : 12 2
// Bucket 3 : 13 3
// Bucket 4 : 14 4
// Bucket 5 : 5 65 5 35 25 15 5
// Bucket 6 : 16 6 16 6
// Bucket 7 : 17 7 7
// Bucket 8 : 18 8
// Bucket 9 : 9 69
// Searching for key 15: Found
// Searching for key 20: Not Found
// HashTable contents after removal:
// Bucket 0 : 10
// Bucket 1 : 11 1
// Bucket 2 : 12 2
// Bucket 3 : 13 3
// Bucket 4 : 14 4
// Bucket 5 : 5 65 5 35 25 5
// Bucket 6 : 16 6 16 6
// Bucket 7 : 17 7 7
// Bucket 8 : 18 8 
// Bucket 9 : 9 69