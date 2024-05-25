// TREE CODES


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct stack{
    struct node *data;
    struct stack *next;
};

void push(struct stack **top, struct node *n){
    struct stack *newstack = (struct stack *)malloc(sizeof(struct stack));
    newstack -> data = n;
    newstack -> next = *top;
    *top = newstack;
}

struct node *pop(struct stack **newtop){
    struct stack *top = *newtop;
    struct node *item = top -> data;
    *newtop = top -> next;
    free(top);
    return item;
}

struct node *peek(struct stack *top){
    if(top == NULL){
        return NULL;
    }    
    else{
        return top -> data;
    }
}

int emptystack(struct stack *top){
    if(top == NULL){
        return 1;
    }    
    else{
        return 0;
    }
}

struct node *createnode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct node* insertnode(struct node* root,int data){
	struct node* newnode = createnode(data);
	if(root==NULL)
		return newnode;
	struct node* current=root;
	while(1){
		if(current->data > data){
			if(current->left==NULL){
				current->left=newnode;
				break;
			}else{
				current=current->left;
			}
		}
		else if(current->data < data){
			if(current->right == NULL){
				current->right=newnode;
				break;
			}
			else{
				current=current->right;
			}
		}
		else if (current->data==data){
			free(newnode);
			break;
		}
	}
	return root;
}

void preorder(struct node *root){
    struct node *temp = root;
    struct stack *s = NULL;
     while(temp != NULL || !emptystack(s)){
         if(temp != NULL){
             printf("%d ",temp -> data);
             push(&s, temp);
             temp = temp -> left;
         }
         else{
             temp = pop(&s);
             temp = temp -> right;
         }
     }
}

void inorder(struct node *root){
    struct node *temp = root;
    struct stack *s = NULL;
     while(temp != NULL || !emptystack(s)){
         if(temp != NULL){
             push(&s, temp);
             temp = temp -> left;
         }
         else{
             temp = pop(&s);
             printf("%d ",temp -> data);
             temp = temp -> right;
         }
     }
}

void postorder(struct node *root){
    struct node *temp = root;
    struct node *previous = NULL;
    struct stack *s = NULL;
    
    do{
        while(temp != NULL){
            push(&s,temp);
            temp = temp -> left;
        }
        while(temp == NULL && !emptystack(s)){
            temp = peek(s);
            if(temp -> right == NULL || temp -> right == previous){
                printf("%d ",temp -> data);
                temp = pop(&s);
                previous = temp;
                temp = NULL;
            }
            else{
                temp = temp -> right;
            }
        }
    }while(!emptystack(s));
}

void leafnode(struct node *root){
    struct node *temp = root;
    struct stack *s = NULL;
     while(temp != NULL || !emptystack(s)){
         if(temp != NULL){
             push(&s, temp);
             temp = temp -> left;
         }
         else{
             temp = pop(&s);
             if(temp -> left == NULL && temp -> right == NULL){
                 printf("%d ",temp -> data);
             }
             temp = temp -> right;
         }
     }
}

int maxi(int num1, int num2){
    return(num1 > num2) ? num1 : num2;    
}

int height1(struct node *root){
    struct node *temp = root;
    struct stack *s = NULL;
    
    int count = 0;
    int max = 0;
    
    while(temp != NULL || !emptystack(s)){
        if(temp != NULL){
            count++;
            max = maxi(count, max);
            push(&s, temp);
            temp = temp -> left;
        }
        else{
            temp = pop(&s);
            count--;
            max = maxi(count, max);
            temp = temp -> right;
        }
    }
    return max;
}

int height2(struct node *root){
    struct node *temp = root;
    if(temp == NULL){
        return 0;
    }
    else{
        int lheight = height2(temp -> left);
        int rheight = height2(temp -> right);
        return maxi(lheight, rheight) + 1;
    }
}

void mirror(struct node *root){
    struct node *current = root;
    struct stack *s = NULL;
    push(&s,current);
    while(!emptystack(s)){
        current = pop(&s);
        struct node *temp = current -> left;
        current -> left = current -> right;
        current -> right = temp;
        if(current -> left != NULL){
            push(&s, current -> left);
        }
        if(current -> right != NULL){
            push(&s, current -> right);
        }
    }
}

int total_nodes(struct node *root){
    struct node *temp = root;
    struct stack *s = NULL;
    int counter = 0;
    
    while(temp != NULL || !emptystack(s)){
        if(temp != NULL){
            counter++;
            push(&s, temp);
            temp = temp -> left;
        }
        else{
            temp = pop(&s);
            temp = temp -> right;
        }
    }
    return counter;
}

void level_order(struct node *root) {
    if(root == NULL){
        return;
    }
    struct stack *s1 = NULL;
    struct stack *s2 = NULL;
    
    push(&s1,root);
    
    while(!emptystack(s1)){
        struct node *current = pop(&s1);
        printf("%d ",current -> data);
        
        if(current -> left != NULL){
            push(&s2, current -> left);
        }
        
        if(current -> right != NULL){
            push(&s2, current -> right);
        }
        
        if(emptystack(s1)){
            while(!emptystack(s2)){
                push(&s1, pop(&s2));
            }
        }
    }
}

int countLeafNodes(struct node *root){
    int c = 0;
    struct node *temp = root;
    struct stack *s = NULL;
     while(temp != NULL || !emptystack(s)){
         if(temp != NULL){
             push(&s, temp);
             temp = temp -> left;
         }
         else{
             temp = pop(&s);
             if(temp -> left == NULL && temp -> right == NULL){
                 c++;
             }
             temp = temp -> right;
         }
     }
     return c;
}

int main()
{
    struct node *root = NULL;
    root = insertnode(root, 50);
    root = insertnode(root, 40);
    root = insertnode(root, 70);
    root = insertnode(root, 30);
    root = insertnode(root, 45);
    root = insertnode(root, 65);
    root = insertnode(root, 75);
    printf("preorder Traversal: ");
    preorder(root);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\npostorder Traversal: ");
    postorder(root);
    printf("\nLeaf Nodes: ");
    leafnode(root);
    int total = countLeafNodes(root);
    printf("\nTotal Leaf Nodes: %d",total);
    int height_tree1 = height1(root);
    printf("\nHeight of tree (non recursive): %d",height_tree1);
    int height_tree2 = height2(root);
    printf("\nHeight of tree (recursive): %d",height_tree2);
    mirror(root);
    printf("\nMirror Image: ");
    preorder(root);
    int Tnodes = total_nodes(root);
    printf("\nTotal Nodes: %d",Tnodes);
    printf("\nLevel-order Traversal: ");
    level_order(root);
    return 0;
}


/*
Certainly! The insertnode function inserts a new node with a given data value into a binary search tree (BST) in such a way that the BST property is preserved:

If the tree is empty (root is NULL), it simply sets the new node as the root.
Otherwise, it iterates through the tree:
If the data is less than the current node's data, it moves to the left subtree.
If the left child is NULL, it inserts the new node as the left child.
Otherwise, it continues the traversal to the left.
If the data is greater than the current node's data, it moves to the right subtree.
If the right child is NULL, it inserts the new node as the right child.
Otherwise, it continues the traversal to the right.
If the data is equal to the current node's data, it means the data is already in the tree, so it avoids duplication.
After insertion, it returns the root of the modified tree.
*/