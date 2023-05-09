#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
	if(root != NULL){
		traverseInOrder(root->left);
		cout<<root->key<<" ";
		traverseInOrder(root->right);
	}
}

struct node *createNode(int key){
	node* new_node = new node();
	new_node -> key = key;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}



// Insert a node
struct node *insertNode(struct node *node, int key) {
	if(node == NULL){
		return createNode(key);
	}
	if(node -> key > key){
		node -> left = insertNode(node->left, key);
	}
	else if(node -> key < key){
		node -> right = insertNode(node->right, key);
	}
	return node;
}

//Finding maximum
struct node *FindMax(struct node *root){
	node* Max = root;
	node* temp = root;
	while(temp != NULL){
		if(temp->key > Max->key){
			Max = temp;
		}
		temp = temp->right;
	}
	return Max;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key){
	if(root == NULL)
	{
		return root;
	}
	else if(root -> key < key)
	{
		root-> right = deleteNode(root->right, key);
	}
	else if(root -> key > key)
	{
		root-> left = deleteNode(root->left, key);
	}
	else{
		//Leaf Node removal
		if(root->left == NULL && root->right == NULL)
		{
			root = NULL;
			return root;
		}
		//Node has one child
		else if(root->left == NULL)
		{
			root = root -> right;
			return root;
		}
		else if(root->right == NULL)
		{
			root = root -> left;
			return root;
		}
		//Node has 2 children
		else
		{
			node* temp = FindMax(root->right);
			root->key = temp->key;
			temp->key = key;
			root->right =  deleteNode(root->right, key);
		}
	}
	return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
