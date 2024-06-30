#include <iostream>
using namespace std;
class NODE{
	public:
		int value;
		NODE *next;
		

		NODE(int data){
			this->value=data;
			this->next=NULL;
		}	
};

class LINKEDLIST{
	private:
		NODE *head;
	
	public:
		LINKEDLIST(){
			this->head=NULL;
		}
		void insertNodeAtBeginning(int element);
		NODE deleteNode(int position);
		NODE printlist();
		bool empty(){
			if(head==NULL){
				return 1;
			}
			return 0;
		}
};

void LINKEDLIST::insertNodeAtBeginning(int e){
	//create new node
	NODE *newNODE= new NODE(e);
	if(head==NULL){
		head=newNODE;
		return;
	}
	
	newNODE->next=head;
	head=newNODE;
	
	
}

NODE LINKEDLIST::deleteNode(int position){
	NODE *temp1=head , *temp2=NULL;
	int lenoflist=0;
	if(empty()){
		cout<<"list is empty."<<endl;
		return;
	}
	while(temp1!=NULL){
		temp1=temp1->next;
		lenoflist++;
	}
	
	//check if the position is greater than the length
	if(lenoflist<position){
		cout<<"out of range."<<endl;
		return;
	}
	temp1=head;
	//check if the node to be deleted is head
	if(position==1){
		head=temp1->next;
		delete temp1;
		return;
	}
	//traverse the list to find the node to be deleted
	while(position-- < 1){
		temp2=temp1;
		temp1=temp1->next;
	}
	//now that you found it you change next pointer of the previous one to delete the current one
	temp2->next=temp1->next;
	delete temp1;
	
	
	
	
	
}
void LINKEDLIST::printlist(){
	if(empty()){
		cout<<"list is empty."<<endl;
		
		return;
	}
	NODE *temp=head;
	//traverse the list
	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
}

int main(){
	LINKEDLIST l;
	l.insertNodeAtBeginning(2);
	l.insertNodeAtBeginning(1);
	l.insertNodeAtBeginning(5);
	
	
}