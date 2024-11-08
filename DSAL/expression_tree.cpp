#include<iostream>
#include"tree.h"
#include"tree.cpp"
#include<string>
using namespace std;

class expression_tree{
	string postfix;
	tree*root;
	public:
		void input();
		tree* create_tree();
		void inorder_recursive(tree* temp);
		void preorder_recursive(tree* temp);
		void postorder_recursive(tree* temp);
		void inorder(tree* root);
		void preorder(tree* root);
		void postorder(tree* root);
};

void expression_tree::input(){
	cout<<"Enter the postfix expression : ";
	cin>>postfix;
}

tree* expression_tree::create_tree(){
	stack<tree*> st;
	for(int i=0;i<postfix.length();i++){
		tree* tnode=new tree();
		tnode->data=postfix[i];
		if(isalpha(postfix[i])){
			st.push(tnode);
		}
		else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'){
			tnode->right=st.peek();
			st.pop();
			tnode->left=st.peek();
			st.pop();
			st.push(tnode);
		}
	}
	root=st.peek();
	return st.peek();
}

void expression_tree::inorder_recursive(tree* temp){
	if(temp!=NULL){
		inorder_recursive(temp->left);
		cout<<temp->data<<" ";
		inorder_recursive(temp->right);
	}
}

void expression_tree::preorder_recursive(tree* temp){
	if(temp!=NULL){
		cout<<temp->data<<" ";
		preorder_recursive(temp->left);
		preorder_recursive(temp->right);
	}
}

void expression_tree::postorder_recursive(tree* temp){
	if(temp!=NULL){
		postorder_recursive(temp->left);
		postorder_recursive(temp->right);
		cout<<temp->data<<" ";
	}
}

void expression_tree::inorder(tree* root){
	stack<tree*> st;
	tree* temp;
	temp=root;
	if(temp==NULL){
		cout<<"Empty";
		return;
	}
	while(temp!=NULL||!st.isempty()){
		while(temp!=NULL){
			st.push(temp);
			temp=temp->left;
		}
		temp=st.peek();
		st.pop();
		cout<<temp->data;
		temp=temp->right;
		}
}

void expression_tree::preorder(tree* root){
	stack<tree*> st;
	tree*temp=root;
	if(temp==NULL){
		cout<<"Empty";
		return;
	}
	while(temp!=NULL||!st.isempty()){
		while(temp!=NULL){
			cout<<temp->data;
			st.push(temp);
			temp=temp->left;
		}
		temp=st.peek();
		st.pop();
		temp=temp->right;
		}
}

void expression_tree::postorder(tree* root){
    stack<tree*> st;
    tree* current = root;
    tree* prev = nullptr;
    if(current == nullptr){
        cout << "Empty";
        return;
    }
    do{
        while(current != nullptr){
            st.push(current);
            current = current->left;
        }
        while(current == nullptr && !st.isempty()){
            current = st.peek();
            if(current->right == nullptr || current->right == prev){
                cout << current->data << " ";
                st.pop();
                prev = current;
                current = nullptr;
            } else {
                current = current->right;
            }
        }
    } while(!st.isempty());
}

// void expression_tree::postorder(tree* root){
// 	stack<tree*> s1,s2;
// 	s1.push(root);
// 	tree* nod;
// 	while(!s1.isempty()){
// 		nod=s1.peek();
// 		s1.pop();
// 		s2.push(nod);
// 		if(nod->left){
// 			s1.push(nod->left);
// 		}
// 		if(nod->right){
// 			s1.push(nod->right);
// 		}
// 	}
// 	while(!s2.isempty()){
// 		nod=s2.peek();
// 		s2.pop();
// 		cout<<nod->data;
// 	}
// }

int main(){
	expression_tree t;
	int flag=1;
	t.input ();
	
	do{
		cout<<endl;
		cout<<"Main menu :"<<endl;
		cout<<"1 for inorder recursive traversal"<<endl;
		cout<<"2 for preorder recursive traversal"<<endl;
		cout<<"3 for postorder recursive traversal"<<endl;
		cout<<"4 for inorder non-recursive traversal"<<endl;
		cout<<"5 for preorder non-recursive traversal"<<endl;
		cout<<"6 for postorder non-recursive traversal"<<endl;
		cout<<"7 for exit"<<endl;
		
		cout<<"Enter the choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				t.inorder_recursive(t.create_tree());
				break;
			case 2:
				t.preorder_recursive(t.create_tree());
				break;
			case 3:
				t.postorder_recursive(t.create_tree());
				break;
			case 4:
				t.inorder(t.create_tree());
				break;
			case 5:
				t.preorder(t.create_tree());
				break;
			case 6:
				t.postorder(t.create_tree());
				break;
			case 7:
				cout<<"Program Terminated";
				flag=0;
				break;
			default:
				cout<<"Invalid choice";
				break;
		}
		// cout<<"Do u want to continur or not?";
		// char c;
		// cin>>c;
		// if(c=='n')
		// break;
	}while(flag!=0);
	return 0;
}
