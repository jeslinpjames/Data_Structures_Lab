#include<iostream>
using namespace std;
class Node{
    public :
        int data;
        static int key;
        Node* next;
        Node* prev;
        Node() : data(0), next(nullptr) {}
        Node(int Data) : data(Data), next(nullptr) {
            key++;  
        }
        Node(int Data, Node* Next) : data(Data), next(Next) {
            key++;
        }
};
class BaseList {
public:
    virtual void display() = 0; 
    virtual void insertFirst(int val) = 0;
    virtual void insertLast(int val) = 0;
    virtual void insert_pos(int val, int k) = 0;
};
int Node::key=0;
class SingleLinkedList:public BaseList{
    public :
        Node* Head;
        Node* Tail;
        int size;
        SingleLinkedList():size(0),Head(nullptr),Tail(nullptr){}
        void insertFirst(int val);
        void insertLast(int val);
        void insert_pos(int val,int k);
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
void SingleLinkedList::insertLast(int val){
    if (Tail==nullptr){
        insertFirst(val);
        return;
    }
    Node* node = new Node(val);
    Tail->next=node;
    Tail= node;
    size++;
}
void SingleLinkedList:: insert_pos(int val, int k){
    if(k==0){
        insertFirst(val);
        return;
    }
    if(k==size){
        insertLast(val);
        return;
    }
    if(k>size){
        cout<<"LIST TOO SMALL"<<endl;
        return;
    }
    Node* temp = Head;
    for(int i=1;i<k;i++){
        temp=temp->next;
    }
    Node* node = new Node(val,temp->next);
    temp->next=node;
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
class DoubleLinkedList:public BaseList{
    public :
        Node* Head;
        Node* Tail;
        int size;
        DoubleLinkedList():size(0),Head(nullptr),Tail(nullptr){}
        void insertFirst(int val);
        void insertLast(int val);
        void insert_pos(int val,int k);
        void display();
        void displayFromLast();
        void insertExisting(Node* exist);
}; 
void DoubleLinkedList :: insertFirst(int val){
    Node* node = new Node(val);
    node->next=Head;
    node->prev=nullptr;
    if(Head!=nullptr){
        Head->prev=node;
    } 
    Head= node;
    if(Tail==nullptr){
        Tail= Head;
    }
    size++;
}
void DoubleLinkedList::insertLast(int val){
    if (Tail==nullptr){
        insertFirst(val);
        return;
    }
    Node* node = new Node(val);
    node->prev=Tail;
    Tail->next=node;
    Tail= node;
    size++;
}
void DoubleLinkedList:: insert_pos(int val, int k){
    if(k==0){
        insertFirst(val);
        return;
    }
    if(k==size){
        insertLast(val);
        return;
    }
    if(k>size){
        cout<<"LIST TOO SMALL"<<endl;
        return;
    }
    Node* temp = Head;
    for(int i=1;i<k;i++){
        temp=temp->next;
    }
    Node* node = new Node(val,temp->next);
    node->prev=temp;
    temp->next=node;
    size++;
}
void DoubleLinkedList::display(){
    Node* temp = Head;
    while(temp!=nullptr){
        cout<<temp->data<<"<->";
        temp= temp->next;
    }    
    cout<<" END"<<endl;
}
void DoubleLinkedList::displayFromLast(){
    Node* temp = Tail;
    while(temp!=nullptr){
        cout<<temp->data<<"<->";
        temp= temp->prev;
    }    
    cout<<" END"<<endl;
}
void DoubleLinkedList::insertExisting(Node* exist){
    if(Tail==nullptr){
        insertFirst(exist->data);
        return;
    }
    exist->prev=Tail;
    Tail->next=exist;
    Tail=exist;
    size++;
}
class convert{
    public:
    void  convertToDLL(const SingleLinkedList& Lst,DoubleLinkedList& DLL){
        Node* node = Lst.Head;
        while(node!=nullptr){
            DLL.insertExisting(node);
            node= node->next;
        }
    }
};

int main(){
    cout<<"Enter the number of Elements in the Single Linked List : ";
    int n=0;
    cin>> n;
    cout<<"Enter the Elements of the List seperated by space : ";
    int val;
    SingleLinkedList Lst;
    for(int i=0;i<n;i++){
        cin>>val;
        Lst.insertLast(val);
    }
    DoubleLinkedList DLL;
    convert Obj ;
    Obj.convertToDLL(Lst,DLL);
    cout<<"The Single Linked List converted into Double Linked List."<<endl;
    cout<<"The Double Linked list from Head to Tail : ";
    DLL.display();
    cout<<"The Double Linked List from Tail to Head : ";
    DLL.displayFromLast();
    return 0;
}




// OUTPUT 
// Enter the number of Elements in the Single Linked List : 9
// Enter the Elements of the List seperated by space :  6 4 10 13 1 7 88 10 5
// The Single Linked List converted into Double Linked List.
// The Double Linked list from Head to Tail : 6<->4<->10<->13<->1<->7<->88<->10<->5<-> END
// The Double Linked List from Tail to Head : 5<->10<->88<->7<->1<->13<->10<->4<->6<-> END