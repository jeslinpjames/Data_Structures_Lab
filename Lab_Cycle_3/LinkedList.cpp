#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(){}
    Node (int Data){
        data = Data;
        next = nullptr;
    }
    Node (int Data, Node* Next){
        data= Data;
        next=Next;
    }
};
class SingleLinkedList{
    public:
    Node* Head;
    Node* Tail;
    int size;
    SingleLinkedList(){
        size=0;
        Head=nullptr;
        Tail=nullptr;
    }
    void insertFirst(int val);
    void display();
};
void SingleLinkedList :: insertFirst(int val){
    Node* node = new Node(val);
    node->next=Head;
    if(Tail==nullptr){
        Tail= node;
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