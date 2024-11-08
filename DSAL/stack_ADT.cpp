#include<iostream>
#include<string>
using namespace std;

template <class T>
class node{
    public:
        T data;
        node<T> * next;
};

template <class T>
class stack{
    public:
        node<T> *top=NULL;

        int isempty();
        void push(T item);
        T pop();
        T peek();
        void display();
};

template <class T>
int stack<T>::isempty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

template <class T>
void stack<T>::push(T item){
    node<T> * p=new node<T>;
    p->data=item;
    p->next=top;
    top=p;
}

template <class T>
T stack<T>::pop(){
    T temp=top->data;
    node<T>* temp1=top;
    top=top->next;
    delete temp1;
    return temp;
}

template <class T>
T stack<T>::peek(){
	return top->data;
}

template <class T>
void stack<T>::display(){
    node<T> * n=top;
    while(n!=NULL){
        cout<<n->data<<endl;
        n=n->next;
    }
}

class conversion{
    public:
        int precedence(char c);
        string infixtopostfix(string );
        string reverse(string );
        string infixtoprefix(string );
        int evalpost(string );
        int evalpre(string );
};

int conversion::precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string conversion::infixtopostfix(string inf){
	stack<char> ob;
	string postfix;
	for(int i=0;i<inf.length();i++){
		char c=inf[i];
		if(c=='('){
			ob.push(c);
		}
		else if(c==')'){
			while(ob.peek()!='('){
				postfix+=ob.peek();
				ob.pop();
			}
			ob.pop();//poping the opening paranthesis
		}
		else if(isalpha(c)){
			postfix+=c;
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
			while(!ob.isempty() && ob.peek()!='(' && precedence(c)<=precedence(ob.peek())){
					postfix+=ob.pop();
			}
			ob.push(c);
		}
   	}
			while(!ob.isempty()){
			postfix+=ob.pop();
	}
	return postfix;
}

string conversion::reverse(string inf){
    stack<char> sb;
    string rev;

    for(int i=0;i<inf.length();i++){
        char c=inf[i];
        if(c=='('){
            sb.push(')');
        }
        else if(c==')'){
            sb.push('(');
        }
        else{
            sb.push(c);
        }
    }

    while(!sb.isempty()){
        rev+=sb.pop();
    }

    return rev;
}

string conversion::infixtoprefix(string inf){
    return reverse(infixtopostfix(reverse(inf)));
}

int conversion::evalpost(string exp){
	stack<int> ob;
	for(int i=0;i<exp.length();i++){
	
		if(isdigit(exp[i])){
			ob.push(exp[i]-'0');
		}
		else{
			int val1=ob.peek();
			ob.pop();
			int val2=ob.peek();
			ob.pop();
			switch(exp[i]){
				case '+':
					ob.push(val2+val1);
					break;
				case '-':
					ob.push(val2-val1);
					break;
				case '*':
					ob.push(val2*val1);
					break;
				case '/':
					ob.push(val2/val1);
			}
		}
	}
	return ob.peek();
}

int conversion::evalpre(string s){
    stack<int> ob;
	for(int i=s.length()-1;i>=0;i--){
	
		if(isdigit(s[i])){
			ob.push(s[i]-'0');
		}
		else{
			int val1=ob.peek();
			ob.pop();
			int val2=ob.peek();
			ob.pop();
			switch(s[i]){
				case '+':
					ob.push(val2+val1);
					break;
				case '-':
					ob.push(val2-val1);
					break;
				case '*':
					ob.push(val2*val1);
					break;
				case '/':
					ob.push(val2/val1);
			}
		}
	}
	return ob.peek();
}


int main(){
    conversion obj;
    string temp;
    int choice;
    int flag=1;
    string input;
    
    do{
        cout<<"Menu:"<<endl;
        cout<<"1 Infix to Postfix Conversion"<<endl;
        cout<<"2 Infix to Prefix Conversion"<<endl;
        cout<<"3 Evaluation of postfix "<<endl;
        cout<<"4 Evaluation of prefix"<<endl;
        cout<<"5 Exit"<<endl;
        cout<<endl;
        cout<<"Enter the choice:"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the infix expression: ";
                cin>>input;
                temp=obj.infixtopostfix(input);
                cout<<temp;
                break;
            case 2:
                cout<<"Enter the infix expression: ";
                cin>>input;
                temp=obj.infixtoprefix(input);
                cout<<temp;
                break;
            case 3:
                cout<<"Enter the expression: ";
                cin>>input;
                cout<<obj.evalpost(input);
                break;
            case 4:
                cout<<"Enter the expression: ";
                cin>>input;
                cout<<obj.evalpre(input);
            case 5:
                flag=0;
                exit(0);
                break;
            default:
                cout<<"Case not found"<<endl;
                break;

        }
    }while(flag!=0);
}
