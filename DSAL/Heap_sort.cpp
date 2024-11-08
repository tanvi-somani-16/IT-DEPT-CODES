#include<iostream>
using namespace std;

void heapifymax(int a[], int n , int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && a[l]>a[largest]){
		largest=l;
	}
	if(r<n && a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		int temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		
		heapifymax(a,n,largest);
	}
}

void create_maxheap(int a[], int n){
	for(int i=n/2;i>=0;i--){
		heapifymax(a,n,i);
	}
}

void heap_sort_max(int a[], int n){
	for(int i=n-1;i>=0;i--){
		int t=a[0];
		a[0]=a[i];
		a[i]=t;
		
		heapifymax(a,i,0);
	}
}

void heapifymin(int a[], int n , int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && a[l]<a[largest]){
		largest=l;
	}
	if(r<n && a[r]<a[largest]){
		largest=r;
	}
	if(largest!=i){
		int temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		
		heapifymin(a,n,largest);
	}
}

void create_minheap(int a[], int n){
	for(int i=n/2;i>=0;i--){
		heapifymin(a,n,i);
	}
}

void heap_sort_min(int a[], int n){
	for(int i=n-1;i>=0;i--){
		int t=a[0];
		a[0]=a[i];
		a[i]=t;
		
		heapifymin(a,i,0);
	}
}

void display(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	int n;
	cout<<"Enter the size of array :";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of array "<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int choice;
do{
	cout<<endl;
	cout<<"1 for creating max heap"<<endl;
	cout<<"2 for heap sort of max heap "<<endl;
	cout<<"3 for creating min heap "<<endl;
	cout<<"4 for heap sort of min heap "<<endl;
	cout<<"5 for exit "<<endl;
	
	cout<<"Enter choice "<<endl;
	cin>>choice;
	switch(choice){
	
	case 1:
		create_maxheap(a,n);
		display(a,n);
		break;
		
	case 2:
		heap_sort_max(a,n);
		display(a,n);
		break;
		
	case 3:
		create_minheap(a,n);
		display(a,n);
		break;
		
	case 4:
		heap_sort_min(a,n);
		display(a,n);
		break;
		
	case 5:
		cout<<"Program Terminated "<<endl;
		exit(0);
	}
}while(choice!=5);
	return 0;
}
