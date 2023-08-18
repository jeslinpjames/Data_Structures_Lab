#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    static int key;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int Data) : data(Data), next(nullptr) {
        key++;  
    }
    Node(int Data, Node* Next) : data(Data), next(Next) {
        key++;
    }
};
int Node::key=0;
class SingleLinkedList{
    public:
    Node* Head;
    Node* Tail;
    int size;
    SingleLinkedList() : size(0), Head(nullptr), Tail(nullptr) {}
    void insertFirst(int val);
    void display();
};
void SingleLinkedList :: insertFirst(int val){
    Node* node = new Node(val);
    node->next=Head;
    Head= node;
    if(Tail==nullptr){
        Tail= Head;
    }
    size++;
}
void SingleLinkedList::display(){
    Node* temp = Head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp= temp->next;
    }    
    cout<<" END"<<endl;
}
int main(){
    SingleLinkedList l1;
    l1.insertFirst(10);
    l1.insertFirst(76);
    l1.insertFirst(86);
    l1.insertFirst(68);
    l1.insertFirst(13);
    l1.insertFirst(121);
    l1.display();
    return 0;
}