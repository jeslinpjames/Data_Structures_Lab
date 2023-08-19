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
    void insertLast(int val);
    void insert(int val,int k);
    int search(int val);
    int count_duplicates(int val);
    void remove_duplicates(int val);
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
void SingleLinkedList:: insert(int val, int k){
    if(k==0){
        insertFirst(val);
        return;
    }
    if(k==size){
        insertLast(val);
        return;
    }
    if(k>size){
        cout<<"Key is greater than the size of the Linked List!"<<endl;
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
int SingleLinkedList :: search(int val){
    int position = 0;
    bool found = false;
    Node* temp = Head;
    while(temp!=nullptr){
        if(temp->data==val){
            found=true;
            break;
        }
        position++;
        temp=temp->next;
    }
    if(!found){
        cout<<"NOT FOUND"<<endl;
        return -1;
    }
    return position;
}
int SingleLinkedList:: count_duplicates(int val){
    int position =0;
    int count=0;
    bool not_found=true;
    Node* temp = Head;
    while(temp!=nullptr){
        if(temp->data==val){
            count++;
            not_found=false;
        }
        position++;
        temp=temp->next;
    }
    if(not_found){
        cout<<"Key not in the Linked List"<<endl;
    }else {
        cout << "Number of duplicates for key " << val << ": " << count << endl;
    }
    return count;
}
void SingleLinkedList::remove_duplicates(int val){
    bool not_found =true;
    Node* prev = nullptr;
    Node* current = Head;
    while(current!=nullptr){
        if(current->data==val){
            if(prev!=nullptr){
                prev->next=current->next;
                delete current;
                current=prev->next;
                size--;
            }else{
                Node* temp = current;
                current = current->next;
                Head = current;
                delete temp;
                size--;
            }
        }else{
            prev=current;
            current=current->next;
        }
    }
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
    l1.insertLast(69);
    l1.insertLast(96);
    l1.insert(11,7);
    l1.insertFirst(69);
    l1.display();
    int x= l1.search(76);
    if(x!=-1){
        cout<<"The Position of the element is "<<x<<endl;
    }
    int x1=l1.count_duplicates(69);
    l1.remove_duplicates(69);
    l1.display();
    return 0;
}