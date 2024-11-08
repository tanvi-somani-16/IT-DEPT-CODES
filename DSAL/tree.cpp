#include"tree.h"
#include<iostream>
using namespace std;
template <class T>
node<T>::node(){
	next=NULL;
}

template <class T>
bool stack<T>::isempty(){
	if(top==NULL){
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void stack<T>::push(T data){
	node<T>*new1=new node<T>;
	new1->info=data;
	new1->next=top;
	top=new1;
}

template <class T>
T stack<T>::pop(){
	T temp=top->info;
	node<T>* temp2=top;
	top=top->next;
	delete temp2;
	return temp;
}

template <class T>
T stack<T>::peek(){
	return top->info;
}

tree::tree(){
	left=NULL;
	right=NULL;
}
