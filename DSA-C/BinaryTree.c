#include <stdio.h>
#include <stdlib.h>

//Node creation
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

//inorder traversal
void inorder(struct Node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}

//preoder traversal
void preorder(struct Node* root){
	if(root == NULL)
		return;
	printf("%d->", root->data);
	preorder(root->left);
	preorder(root->right);
}

//postorder traversal
void postorder(struct Node* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d->", root->data);
}

//creating a node function
struct Node* CreateNode(int data){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

//inserting data into left of the node
struct Node* insertLeft(struct Node* root, int data){
	root->left = CreateNode(data);
	return root->left;
}

//inserting data into right of the node
struct Node* insertRight(struct Node* root, int data){
	root->right = CreateNode(data);
	return root->right;
}

//main function
void main(){
	struct Node* root = CreateNode(1);
	insertLeft(root, 2);
	insertRight(root, 3);
	insertLeft(root->left, 5);
    insertRight(root->left, 6);

    printf("Inorder traversal \n");
  	inorder(root);

  	printf("\nPreorder traversal \n");
  	preorder(root);

  	printf("\nPostorder traversal \n");
  	postorder(root);
}
