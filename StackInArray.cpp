#include<iostream>
using namespace std;

class Stack{
	int top;
	int size;
	int arr[];
	
	public:
		Stack(int size);
		int isEmpty();
		int isFull();
		int getTop();
		void Display();
		void Push(int value);
		int Pop();
		int stackTop();
};
Stack::Stack(int sizeIn){
	size = sizeIn;
	top = -1;
	int arr[size];
}
int Stack::isEmpty(){
	if(this->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}
int Stack::isFull(){
	if(top >= size){
		return 1;
	}
	else{
		return 0;
	}
}
void Stack::Push(int value){
	top += 1;
	if(this -> isFull()){
		cout<<"Stack overflow"<<endl;
	}
	else{
		arr[top] = value;
		//cout<<top<<endl;
	}
}
int Stack::Pop(){
	if(this -> isEmpty()){
		cout<<"Stack underflow"<<endl;
		return 0;
	}
	else{
		top = top -1;
		return arr[top+1];
	}
}
int Stack::stackTop(){
	return arr[top];
}

void Stack::Display(){
	for(int i=top; i>=0; i--){
		cout<<arr[i]<<endl;
	}
}

int main(){
	int size;
	cin>> size;
	Stack s(size);
	
	s.Push(8);
	s.Push(10);
	s.Push(5);
	s.Push(11);
	s.Push(12);
	
	cout<<"Elements in the stack: "<<endl;
	s.Display();
	
	cout<<"Elements popped out: "<<endl;
	cout<<s.Pop()<<endl; 
	cout<<s.Pop()<<endl; 
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
	
	cout<<"Stack after popping out some elements: "<<endl;
	s.Display();
	
	s.Push(1);
	s.Push(11);
	s.Push(51);
	s.Push(111);
	s.Push(121);
	
	cout<<"Elements in stack after new insertion: "<<endl;
	s.Display();
	return 0;
}
