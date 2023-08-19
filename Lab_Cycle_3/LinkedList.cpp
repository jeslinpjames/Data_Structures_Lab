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
    void insert_pos(int val,int k);
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
int SingleLinkedList :: search(int val){
    int position = 0;
    int final_pos=-1;
    bool found = false;
    Node* temp = Head;
    int* arr = new int[size];
    int t=0;
    while(temp!=nullptr){
        if(temp->data==val){
            found=true;
            arr[t++]=position;
            final_pos=position;
        }
        position++;
        temp=temp->next;
    }
    if(!found){
        cout<<"NOT FOUND"<<endl;
        return -1;
    }else{
        cout<<"Key of the element "<<val<<" in Linked list :";
        for(int i=0;i<t;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return final_pos;
}
int SingleLinkedList:: count_duplicates(int val){
    int position =0;
    int count=-1;
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
        cout<<"NO DUPLICATES"<<endl;
    }else {
        cout << "Number of duplicates for key " << val << ": " << count << endl;
    }
    return count;
}
void SingleLinkedList::remove_duplicates(int val){
    bool first_occured = false;
    Node* prev = nullptr;
    Node* current = Head;
    while(current!=nullptr){
        if(current->data==val){
            if(first_occured){
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
                first_occured=true;
                prev=current;
                current=current->next;
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

    cout<<"Enter the number of Elements in the Linked List : ";
    int n=0;
    cin>> n;
    cout<<"Enter the Elements of the List seperated by space : ";
    int val;
    SingleLinkedList Lst;
    for(int i=0;i<n;i++){
        cin>>val;
        Lst.insertLast(val);
    }
    char ch;
     int ele, x;
    do{
        cout<<"Enter s to search for Elements,\n";
        cout<<"Enter c to Print the number of times key is duplicated in the List,\n";
        cout<<"Enter r to Delete Duplicate entries of Key in the List,\n";
        cout<<"Enter i to Insert an element to a specific position in the List,\n";
        cout<<"Enter d to Display the List,\n";
        cout<<"Enter e to Exit the Program.\n";
        cout<<"Enter your Choice : ";
        cin>>ch;
        switch (ch)
        {
        case 's':
            int ele;
            cout<<"Enter the Element to Search : ";
            cin>>ele;
            cout<<endl;
            x = Lst.search(ele);
            break;
        case 'c':
            cout<<"Enter the Element to find the count of Duplicates : ";
            cin>>ele;
            cout<<endl;
            x = Lst.count_duplicates(ele);
            break;
        case 'r':
            cout<<"Enter the Element to Delete the duplicates of : ";
            cin>>ele;
            cout<<endl;
            Lst.remove_duplicates(ele);
            break;
        case 'i':
            int pos;
            cout<<"Enter the Element to be inserted : ";
            cin>>ele;
            cout<<"Enter the position to be inserted : ";
            cin>>pos;
            cout<<endl;
            Lst.insert_pos(ele,pos);
            break;
        case 'd':
            cout<<endl;
            cout<<"The Linked List is : ";
            Lst.display();
            break;
        case 'e':
            break;        
        default:
            cout<<"Wrong choice!"<<endl;
        }
        cout<<endl<<endl;
    }while(ch!='e');
    cout<<"Thank You!"<<endl;
    return 0;
}