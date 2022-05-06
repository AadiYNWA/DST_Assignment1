#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int arr[SIZE];
int front = 0;
int rear = -1;
void eenqueue(){
	if(rear!=-1 &&((rear+1)%SIZE==front)){
		printf("Queue Overflow!!\n");
		return;
	}
	else{
		rear = (rear+1)%SIZE;
	}
	printf("Enter number that has to be inserted into the array\n");
	int temp;
	scanf("%d",&temp);
	arr[rear] = temp;
}
void ddequeue(){
	if((rear==-1)||(front==rear)){
		printf("Queue Underflow!!\n");
		return;
	}
	arr[front]=0;
	front = (front+1)%SIZE;
}
void display(){
	for(int i=1;i<=SIZE;i++){
		if(arr[front]!=0){
			printf("%d\n",arr[front]);
		}
	if(arr[front]==0){
		printf("Position empty\n");
		continue;
	}
	front  = (front+1)%SIZE;
	}
}
void peek(){
	int tempp;
	printf("Enter the position at which you would like to check element\n");
		scanf("%d",&tempp);
	tempp = tempp-1;
	tempp = (tempp+front)%SIZE;
	if(arr[tempp]==0){
		printf("Position Empty\n");
	}
	else{
		printf("%d\n",arr[tempp]);
	}
} 
struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
  
int main()
{
    int check;
	printf("Enter 1 if you want to implement queue using circular array. Enter 0 if you want to implement queue using linked list\n");
	scanf("%d",&check);
	if(check==1){
		for(int i=0;i<SIZE;i++){
		arr[i] = 0;
	}
	int i;
	do{
		int temp;
		printf("Enter the number you want to choose\n");
		printf("1-Enqueue\n");
		printf("2-Dequeue\n");
		printf("3-Display\n");
		printf("4-Peek\n");
		scanf("%d",&temp);
		switch(temp){
			case 1 :
				eenqueue();
				break;
			case 2:
				ddequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			default:
			printf("Wrong choice!!\n");
		}
		printf("If you want to choose any other directory press 1 otherwise press 0\n");
		scanf("%d",&i);
	}while(i==1);
	}
	else{
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
  
    linkedListTraversal(f);
}
    return 0;
}