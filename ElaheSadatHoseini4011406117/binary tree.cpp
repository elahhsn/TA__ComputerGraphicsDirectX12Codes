#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* Front;
    Node* rear;

public:
    Queue() : Front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void push(T value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            Front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = Front;
        Front = Front->next;
        delete temp;
        if (Front == nullptr) {
            rear = nullptr;
        }
    }

    T front() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return Front->data;
    }

    bool isEmpty() {
        return Front == nullptr;
    }

    void display() {
        Node* current = Front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};



//node class to define the structure of the node
class NODEE{
	public:
		int data;
		NODEE *left , *right;
		
		NODEE(int value){
			data=value;
			left=right=NULL;
			
		}
};

//insert node
NODEE* insert(NODEE* root , int data){
	//if tree is empty
	if(root==NULL){
		root=new NODEE(data);
		return root;
	}
	
	//queue to traverse the tree and find the position to insert the node
	queue<*NODEE> Q;
	Q.push(root);
	while(!Q.empty()){
		NODEE* tmp=Q.front();
		Q.pop();
		//insert node as the left child of the node if empty
		if(tmp->left==NULL){
			tmp->left=new NODEE(data);
			break;
		}
		//if the left child of the node is not null push it to the queue
		else
			Q.push(tmp->left);
			
		//insert node as the right child if null
		if(tmp->right==NULL){
			tmp->right=new NODEE(data);
			break;
		}	
		
		//if right child is null push it to queue
		else
			Q.push(tmp->right);
	}
	return root;
	
	
}
//function to delete the given deepest node 
void deletedeepest(NODEE *root , NODEE* d_node){
	queue<NODEE*> Q;
	Q.push(root);
	//level traversal until last node
	NODEE* temp;
	while(!Q.empty()){
		temp=Q.front();
		Q.pop();
		if(temp==d_node){
			temp=NULL;
			delete (d_node);
			return;
		}
		if(temp->right){
			if(temp->right==d_node){
				temp->right=NULL;
				delete (d_node);
				return;
			}
			else{
				Q.push(temp->right);
			}
			
		}
		if(temp->left){
			if(temp->left==d_node){
				temp->left=NULL;
				delete (d_node);
				return;
			}
			else{
				Q.push(temp->left);
			}
		}
	}
	
	//function to delete element
	NODEE* deletion(NODEE* root , int key){
		if(!root){
			return NULL;
			
		}
		if(root->left==NULL && root->right==NULL){
			if(root->data == key)
				return NULL;
			else
				return root;	
		}
		queue<*NODEE> Q;
		Q.push(root);
		NODEE* tmp;
		NODEE* key_node=NULL;
		//level traversal to find deepest 
		//node(tmp) and the node to be deleted (key_node)
		while(!Q.empty()){
			tmp=Q.front();
			Q.pop();
			if(tmp->data==key)
				key_node=tmp;
			if(tmp->left)
				Q.push(tmp->left);
			if(tmp->right)
				Q.push(tmp->right);		
		}
		if(key_node!=NULL){
			int x=tmp->data;
			key_node->data=x;
			deletedeepest(root,tmp);
			
		}
		return root;
	}
	
	
}
//inorder traversal(left-root-right)
void inorderTraversal(NODEE* root){
	if(!root)
		return;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);	
}

//preorder traversal(root-left-right)
void preorderTraversal(NODEE* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
//postorder traversal (left-right-root)
void postorderTraversal(NODEE* root){
	if(!root)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data<<" ";	
}
//levelorder traversal
void levelorderTRAVERSAL(NODEE* root){
	queue<*NODEE> Q;
	Q.push(root);
	while(!Q.empty()){
		NODEE* temp;
		temp=Q.front();
		Q.pop();
		cout<<temp->data<<" ";
		if(temp->left){
			Q.push(temp->left);
			
		}
		if(temp->right){
			Q.push(temp->right);
		}
		
	}
}



int main(){
	NODEE* root=NULL;
	root=insert(root,10);
	root=insert(root,30);
	root=insert(root,60);
	cout<<"postorder traversal:"<<endl;
	postorderTraversal(root);
	root=deletion(root,10);
	cout<<"inorder traversal:"<<endl;
	inorderTraversal(root);
}


