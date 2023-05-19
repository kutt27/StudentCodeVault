#include <stdio.h>
#include <stdlib.h>

//structure of the node
struct node{
	int data;
	struct node *right;
	struct node *left;
};

//creation of the node
struct node *newNode(int item) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

//traversal (inorder)
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ->", root->data);
		inorder(root->right);
	}
}

//Insert a node
struct node *insert(struct node *root, int data){
	if(root == NULL){
		return newNode(data);
	}

	if(data < root->data){
		root->left = insert(root->left, data);
	}
	else
		root->right = insert(root->right, data);

	return root;
}

//finding the minimum value
struct node *minValueNode(struct node *node){
	struct node *current = node;

	while(current && current->left != NULL)
		current = current->left;
	return current;
}

//Deleting a node
struct node *deleteNode(struct node *root, int data){
	if(root == NULL)
		return root;
	 if(data < root->data){
	 	root->left = deleteNode(root->left, data);
	 }
	 else if(data > root->data){
	 	root->right = deleteNode(root->right, data);
	 }
	 else{
	 	//if the node have one child or no child
	 	if(root->left == NULL){
	 		struct node *temp = root->right;
	 		free(root);
	 		return temp;
	 	}
	 	else if(root->right == NULL){
	 		struct node *temp = root->left;
	 		free(root);
	 		return temp;
	 	}
	 	//if the node have two children
	 	struct node *temp = minValueNode(root->right);
	 	root->data = temp->data;
	 	root->right = deleteNode(root->right, temp->data);
	 }
	return root;
}

//main function
void main(){
	struct node *root = NULL;
	root = insert(root, 8);
  	root = insert(root, 3);
  	root = insert(root, 1);
  	root = insert(root, 6);
 	root = insert(root, 7);
  	root = insert(root, 10);
  	root = insert(root, 14);
  	root = insert(root, 4);
  	root = insert(root, 2);
  	root = insert(root, 5);
  	root = insert(root, 9);

  	printf("Inorder traversal: ");
  	inorder(root);

  	printf("\nAfter deleting node 10");
  	deleteNode(root, 10);

  	printf("\nInorder traversal: ");
    inorder(root);
}