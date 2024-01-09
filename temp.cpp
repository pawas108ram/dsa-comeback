#include<iostream>
using namespace std;

class ll_node{
    public:
    int data;
    ll_node*next;

    ll_node(int data){
        this -> data =data;
        this -> next =NULL;
    }

    //this part is known as destructor
    ~ll_node(){
        int value=this->data;//current object

        if(this->next!=NULL){
            delete this->next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;

    }

};

//created a funcn to insert data at head
void inser_athead(ll_node* &head , int data){

    //new mode for new data

    ll_node* temp= new ll_node(data); //new node temp created
    temp->next=head;//temp ki next value pointed to head
    head=temp;
}

void inser_atpos(ll_node* &head , int position , int data){

    //case ,if u need to insert at head
    if(position==1){
        inser_athead(head,data);
        return;
    }

    ll_node*temp=head;

    int cnt=1;

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    

    ll_node* nodetoinsert=new ll_node(data);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

void inser_attail(ll_node* &tail,int data ){
    ll_node* temp=new ll_node(data);
    tail ->next =temp;
    tail= temp;
}


//funcn to traverse a ll
void pri_node(ll_node* &head){//yhn pr head a ref lia taki new copy na creae ho jaye
    ll_node *temp=head;//Create a new pointer 'temp' and make it point to the same location as 'head'

    while(temp!=NULL){
        cout<<temp->data<<""<<endl;
        temp=temp -> next;//temp ko aage bdh dia

    }
    cout<<endl;
}

//deletion of a node
void del_node(int position,ll_node* &head){
    if(head==NULL){
        ///for cases when ll is empty
        return;
    }
    
    if(position==1){
        ll_node* temp=head;
        head = head->next;//head ko ek position aage bdha dia
        temp->next=NULL;
        //memory free
        delete temp;

    }
    
    else{
        //deleting any middle or any node
        ll_node* curr=head;
        ll_node* prev=NULL;

        int cnt=1;
        
        while(cnt<=position && curr!=NULL){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        if(curr==NULL){
            return;
        }
        else{
        
        
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;}
    }

}
int main(){

    ll_node* node_01= new ll_node(10); //a new node created for addin data
    // cout<< node_01 -> data<<endl;
    // cout<< node_01 -> next<<endl;

    ll_node* head=node_01;
    ll_node* tail=node_01; //head pointed to node_01
    
    inser_athead(head, 20);
    inser_athead(head, 30);
    inser_athead(head, 40);
    pri_node(head);

    del_node(3, head);
    pri_node(head);

    return 0;
}