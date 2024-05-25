//AVl
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};
int height(struct node *root){
	if(root==NULL){
		return 0;
	}
	return root->height;
}
int max(int a,int b){
	return (a>b)? a : b;
}

//simiar to bst only height assigned
struct node *create(int data){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=newNode->right=0;
	newNode->height=1;
	return newNode;
}
//function to perform right rotation
struct node *rightrotation(struct node *y){
	struct node *x=y->left;
	struct node *t1 = x->right;
	x->right=y;
	y->left=t1;
	x->height=max(height(x->left) , height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return x;
}
struct node *leftrotation(struct node *x){
	struct node *y=x->right;
	struct node *t1 = y->left;
	y->left=x;
	x->right=t1;
	x->height=max(height(x->left) , height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
int balanceFactor(struct node *root){
	if(root==NULL){
		return 0;
	}
	return height(root->left) - height(root->right);
}
struct node *insert(struct node *root,int key){
	if(root==NULL){
		return create(key);
	}
	if(key < root->data){
		root->left=insert(root->left,key);
	}
	else if(key > root->data){
		root->right=insert(root->right,key);
	}
	else{
		
		return root;
	}
	root->height = 1 + max(height(root->left),height(root->right));
	int balance = balanceFactor(root);
//	LL 
	if(balance > 1 && key < root->left->data){
		return rightrotation(root);
	}
	//right right
	if(balance < -1 && key > root->right->data){
		return leftrotation(root);
	}
	//LR
	if(balance > 1 && key > root->left->data){
		root->left=leftrotation(root->left);
		return rightrotation(root);
	}
	//rl
	if(balance < -1 && key < root->right->data){
		root->right=rightrotation(root->right);
		return leftrotation(root);
	}
	return root;
}
void print(struct node *root){
	if(root==NULL){
		return;
	}
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}
void level(struct node *root){
	struct node *current=root;
	struct node *queue[100];
	int rear=0;
	int front=0;
	queue[rear++]=current;
	while(front !=rear){
		current=queue[front++];
		printf("%d ",current->data);
		if(current->left){
			queue[rear++]=current->left;
		}
		if(current->right){
			queue[rear++]=current->right;
		}
	}
}
int main(){
	struct node *root=NULL;
	root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root ,70);
    root = insert(root, 25);
    printf("In-Order Traversal of AVL Tree: ");
    print(root);
    printf("\n");
    printf("Level wise traversal: ");
    level(root);
    printf("\n");
    
}
