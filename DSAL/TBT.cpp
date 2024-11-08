#include<iostream>
using namespace std;

class node{
	public:
		node*left;
		node*right;
		int data;
		bool lpoint;
		bool rpoint;
		
		node(){
			data=0;
			left=NULL;
			right=NULL;
			lpoint=rpoint=0;
		}
		
		node(int key){
			data=key;
			left=NULL;
			right=NULL;
			lpoint=rpoint=0;
		}
};

class TBT{
	public:
	node*dummy=NULL;
	node*root=NULL;
	
	TBT(){
		dummy=new node(999);
		dummy->left=dummy;
		dummy->right=dummy;
	}
	void insert(int key);
	void inorder(node*root,node*dummy);
	void preorder(node*root,node*dummy);
};

void TBT::insert(int key){
	if(root==NULL){
		root=new node(key);
		root->left=dummy;
		root->right=dummy;
		dummy->left=root;
		dummy->lpoint=1;
		
	}
	else{
		node*temp=root;
		while(temp!=dummy){
			node*p=new node(key);
			if(key<temp->data){
				if(temp->lpoint==0){
				p->left=temp->left;
				p->right=temp;
				temp->left=p;
				temp->lpoint=1;
				return;
				}
				else{
					temp=temp->left;
			    }
		}
		else if(key>temp->data){
			if(temp->rpoint==0){
				p->right=temp->right;
				p->left=temp;
				temp->right=p;
				temp->rpoint=1;
				return;
			}
			else{
				temp=temp->right;
			}
		}
	}
  }
}

void TBT:: inorder(node*root,node*dummy) { 
	node*current=root;
 	while (current != dummy) { 
 	while (current->lpoint == 1) { 
 		current = current->left; 
	 } 
 	cout << current->data << " "; 
 	while (current->rpoint == 0 && current->right != dummy) { 
 		current = current->right; 
 		cout << current->data << " "; 
 	} 
 	current = current->right; 
 	} 
 } 
 
void TBT::preorder(node* root, node* dummy) {
    node* current = root;
    while (current != dummy) {
        while (current->lpoint == 1) {
            cout << current->data << " ";
            current = current->left;
        }
        cout << current->data << " ";        
            while (current->rpoint == 0 && current->right != dummy) {
                current = current->right;
            }
            current = current->right;
        }
    }
 
 int main() {
    TBT tbt;
    int choice;

    do {
        cout << "Select a choice :" << endl;
        cout << "1. Insert an element" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
			int n;
			cout<<"Enter the number of nodes: ";
			cin>>n;
			for(int i=0;i<n;i++){
				int element;
            	cout << "Enter an element to insert : ";
            	cin >> element;
            	tbt.insert(element);
			}
            
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tbt.inorder(tbt.root, tbt.dummy);
            cout << endl;
            break;

        case 3:
            cout << "Preorder Traversal: ";
            tbt.preorder(tbt.root, tbt.dummy);
            cout << endl;
            break;

        case 4:
            cout << "Program Terminated" << endl;
            exit(0);
        }
    } while (choice != 4);

    return 0;
}

