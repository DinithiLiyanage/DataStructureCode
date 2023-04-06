#include<iostream>
using namespace std;

struct Node{
	int value;
	Node *link;
};
struct LinkedList{
	Node *Head = NULL;
};

int isEmpty(LinkedList* L){
	if(L -> Head == NULL){
		return 1;
	}
	return 0;
}
	
void Push(LinkedList* L, int value){
	Node* new_node = new Node();
	new_node -> value = value;
	if(isEmpty(L)){
		new_node -> link = NULL;
	}
	else{
		new_node -> link = L -> Head;
	}
	L -> Head = new_node;
}

int Pop(LinkedList* L){
	if(isEmpty(L)){
		cout<<"Stack underflow"<<endl;
	}
	else{
		int popped_value = L -> Head -> value;
		L -> Head = L -> Head -> link;
		return popped_value;
	}
	return 0;
}

void Display(LinkedList* L){
	Node* temp = L -> Head;
	while(temp != NULL){
		cout<<temp -> value<<endl;
		temp = temp -> link;
	}
}

int main(){
	LinkedList* L = new LinkedList();
	Push(L, 8);
	Push(L, 10);
	Push(L, 5);
	Push(L, 11);
	Push(L, 12);
	
	cout<<"Elements in the stack: "<<endl;
	Display(L);
	
	cout<<"Elements popped out: "<<endl;
	cout<<Pop(L)<<endl;
	cout<<Pop(L)<<endl;
	cout<<Pop(L)<<endl;
	cout<<Pop(L)<<endl;
	
	cout<<"Stack after popping out some elements: "<<endl;
	Display(L);
	
	Push(L, 82);
	Push(L, 120);
	Push(L, 52);
	Push(L, 121);
	Push(L, 122);
	cout<<"Elements in stack after new insertion: "<<endl;
	Display(L);
	
	return 0;
}
	
	
