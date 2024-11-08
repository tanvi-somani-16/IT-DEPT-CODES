#ifndef TREE_H_
#define TREE_H_
template<class T>
class stack;//Forward declaration

template<class T>
class node{
	private:
		T info;
		node<T>*next;
	public:
		node();
	    friend class stack<T>;
};

template<class T>
class stack{
	private:
		node<T>*top;
	public:
		bool isempty();
		void push(T data);
		T pop();
		void display();
		T peek();
		Stack();	
};

class expression_Tree;
class tree{	
	public:
		char data;
		tree*left,*right;
		tree();
		friend class Expression_Tree;
};

#endif
