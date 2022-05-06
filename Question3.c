//Simple Array Implementation

#include<stdio.h>
#include<conio.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack[SIZE], top = -1;
int main(){
 int value, choice;
 //clrscr();
 while(1){
    printf("\n\n***** MENU *****\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
       case 1: printf("Enter the value to be insert: ");
       scanf("%d",&value);
       push(value);
       break;
       case 2: pop();
       break;
       case 3: display();
       break;
       default: printf("\nWrong selection!!! Try again!!!");
    }
  }
  
  return 0;
}
void push(int value){
   if(top == SIZE-1)
   printf("\nStack is Full!!! Insertion is not possible!!!");
   else{
   top++;
   stack[top] = value;
   printf("\nInsertion success!!!");
   }
}
void pop(){
   if(top == -1)
   printf("\nStack is Empty!!! Deletion is not possible!!!");
   else{
   printf("\nDeleted : %d", stack[top]);
   top--;
   }
}
void display(){
   if(top == -1)
   printf("\nStack is Empty!!!");
   else{
     int i;
     printf("\nStack elements are:\n");
     for(i=top; i>=0; i--)
     printf("%d\n",stack[i]);
    }
}

//Two Ended Array Implementation

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int* arr;
    int size;
    int top1, top2;
};



void push1(struct stack *ptr,int x){
        if (ptr->top1 > 0) {
            ptr->top1--;
            ptr->arr[ptr->top1] = x;
            return;
        }
        else {
            printf( "Stack Overflow!\n");
            return; 
        }
    }

void push2(struct stack*s,int x){
        if (s->top2 < s->size - 1) {
            s->top2++;
            s->arr[s->top2] = x;
        }
        else {
            printf("Stack Overflow!\n");
        }
    }

int pop1(struct stack *s)
    {
        if (s->top1 <= s->size / 2) {
            int x = s->arr[s->top1];
            s->top1++;
            return x;
        }
        else {
            printf("Stack UnderFlow!\n");
        }
    }

int pop2(struct stack *s)
    {
        if (s->top2 >= s->size / 2 + 1) {
            int x = s->arr[s->top2];
            s->top2--;
            return x;
        }
        else {
            printf( "Stack UnderFlow!\n");
        }
    }

int main(){
    struct stack *s  =(struct stack*)malloc(sizeof(struct stack));
    printf("Enter the size of stack:");
    scanf("%d",&(s->size));
    s->top1 = s->size/2 + 1;
    s->top2 = s->size/2;

    s->arr = (int *)malloc(s->size*(sizeof(int)));
    int n;
    
    while(1){
    printf("MENU:\n");
    printf("1.Push an element into array:\n");
    printf("2.Pop an element from array:\n");
    printf("3.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&n);

    
    if(n==1){
        int p;
        int val;
        printf("Enter the value to push:");
        scanf("%d",&val);
        printf("Enter which stack you want to input into(1 or 2):");
        scanf("%d",&p);

        if(p==1){

            push1(s,val);
        }
        else{
            push2(s,val);
        }
    }
    else if(n==2){
        int p;
        printf("Enter which stack you want to pop from(1 or 2):");
        scanf("%d",&p);

        if(p==1){

            printf("Element popped:%d\n",pop1(s));
        }
        else{
            printf("Element popped:%d\n",pop2(s));
        }
    }
    else if(n==3){
        break;
    }


    }
}
