// MERGE DLL


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createnode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> prev = NULL;
    newnode -> next = NULL;
    return newnode;
}


struct node *insert(struct node **head, int data){
    struct node *newnode = createnode(data);
    if(*head == NULL){
        *head = newnode;
    }
    else{
        struct node *temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
    }
}

struct node *mergeList(struct node *list1, struct node *list2){
    struct node *result = NULL;
    struct node *tail = NULL;
    
    while(list1 != NULL && list2 != NULL){
        if(list1 -> data <= list2 -> data){
            if(result == NULL){
// If result is NULL, it means this is the first node being added to the merged list.
//In this case, we set both result and tail to point to this node.
                result = list1;
                tail = list1;
            }
            else{
                tail -> next = list1;
                list1 -> prev = tail;
                tail = list1;
            }
            list1 = list1 -> next;
        }
        else{
            if(list1 -> data > list2 -> data){
                if(result == NULL){
                    result = list2;
                    tail = list2;
                }
                else{
                    tail -> next = list2;
                    list2 -> prev = tail;
                    tail = list2;
                }
                list2 = list2 -> next;
            }
        }
    }
    
    if(list1 != NULL){
        tail -> next = list1;
        list1 -> prev = tail;
    }
    if(list2 != NULL){
        tail -> next = list2;
        list2 -> prev = tail;
    }
    
    return result;
}

void printlist(struct node *head){
    struct node *temp = head;
    
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
}

int main()
{
    struct node *head = NULL;
    
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    
    insert(&list1, 2);
    insert(&list1, 4);
    insert(&list1, 6);
    insert(&list1, 8);
    
    insert(&list2, 1);
    insert(&list2, 3);
    insert(&list2, 5);
    insert(&list2, 7);
    insert(&list2, 9);
    
    printf("List1: ");
    printlist(list1);
    printf("\nList2: ");
    printlist(list2);
    
    struct node *merge = mergeList(list1, list2);
    printf("\nMerged List: ");
    printlist(merge);

    return 0;
}
