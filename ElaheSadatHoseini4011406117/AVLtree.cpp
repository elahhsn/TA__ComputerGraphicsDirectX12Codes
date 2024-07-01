#include <bits/stdc++.h>
using namespace std;
class NODE{
	public:
		int key;
		NODE* left;
		NODE* right;
		int height;
};
//function to get the height 
int height(NODE* N){
	if(N==NULL)
		return 0;
	return N->height+1;	
}

//function to get maximum of two integers
int max(int a , int b){
	return (a>b)?a:b;
}
//a function that allocates a new node with the given key and NULL left and right pointer
NODE *newNode(int key){
	NODE *node=new NODE();
	node->key=key;
	node->height=1;
	node->left=NULL;
	node->right=NULL;
	return node;
	
}

//a utility function to right rotate subtree rooted with y
NODE* rightrotate(NODE* y){
	
	NODE* x=y->left;
	NODE* T2=x->right;
	
	x->right=y;
	y->left=T2;
	
	//UPDATE HEIGHTS
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	//return new root
	return x;
	
}

NODE* leftRotate(NODE* x){
	NODE *y=x->right;
	NODE *T2=y->left;
	
	y->left=x;
	x->right=T2;
	x->height=max(height(x->left), height(x->right))+1;
	y->height=max(height(y->left), height(y->right))+1;
	
	//return new root
	return y;
}
int GetBalance(NODE* N){
	if(N==NULL)
		return 0;
	return height(N->left)-height(N->right);	
}
//recursive function to insert a key in the subtree rooted with node
//and returns the new root of the subtree.
NODE* insert(NODE* node , int key){
	//1.perform the normal bst insertion
	if(node ==NULL){
		return (newNode(key));
		
	}
	if(key<node->key)
		node->left=insert(node->left,key);
		
	else if(key>node->key)
		node->right=insert(node->right, key);
	else//equal keys are not allowed in BST
		return node;		
		
	//2.update the height of this ancestor node
	node->height=max(height(node->left),height(node->right));
	
	//3.get the balance factor of this ancestor node to check whether 
	//this node became unbalanced
	int balance=getBalance(node);
	//if this node beacme unbalanced then there are 4 cases
	//left left case
	if(balance>1 && key<node->left->key)
		return rightrotate(node);
	//right right case
	if(balance<-1 && key>node->right->key)
		return leftRotate(node);
		//left right case
	if(balance>1 && key>node->left->key){
		node->left=leftRotate(node->left);
		return rightrotate(node);
		
	}	
	//right left case
	if(balance<-1 && kry<node->right->key){
		node->right=rightrotate(node->right);
		return leftRotate(node);
	}	
	//return the unchanged node
	return node;
		
}
//functio to print the preorder traversal and the height of every node
void preOrder(NODE *root){
	if(root!=NULL){
		cout<<root->key<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
/* Given a non-empty binary search tree, 
return the node with minimum key value 
found in that tree. Note that the entire 
tree does not need to be searched. */
Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
 
    return current; 
} 
 
// Recursive function to delete a node 
// with given key from subtree with 
// given root. It returns root of the 
// modified subtree. 
Node* deleteNode(Node* root, int key) 
{ 
     
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL) 
        return root; 
 
    // If the key to be deleted is smaller 
    // than the root's key, then it lies
    // in left subtree 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
 
    // If the key to be deleted is greater 
    // than the root's key, then it lies 
    // in right subtree 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
 
    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) ||
            (root->right == NULL) ) 
        { 
            Node *temp = root->left ? 
                         root->left : 
                         root->right; 
 
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
            *root = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            Node* temp = minValueNode(root->right); 
 
            // Copy the inorder successor's 
            // data to this node 
            root->key = temp->key; 
 
            // Delete the inorder successor 
            root->right = deleteNode(root->right, 
                                     temp->key); 
        } 
    } 
 
    // If the tree had only one node
    // then return 
    if (root == NULL) 
    return root; 
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
 
    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = getBalance(root); 
 
    // If this node becomes unbalanced, 
    // then there are 4 cases 
 
    // Left Left Case 
    if (balance > 1 && 
        getBalance(root->left) >= 0) 
        return rightRotate(root); 
 
    // Left Right Case 
    if (balance > 1 && 
        getBalance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && 
        getBalance(root->right) <= 0) 
        return leftRotate(root); 
 
    // Right Left Case 
    if (balance < -1 && 
        getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
 
    return root; 
} 

int main(){
	NODE *root=NULL;
	
	root=insert(root, 10);
	root=insert(root, 12);
	root=insert(root, 3);
	root=insert(root, 40);
	root=insert(root, 8);
	root=insert(root, 30);
	preOrder(root);
	return 0;
	
}
