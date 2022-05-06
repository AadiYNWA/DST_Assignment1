#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *prev;
};

struct node*top=NULL;

void push(int num){
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));

    if (!new_node){
        printf("Stack Overflow.\n");
        exit(0);
    }

    new_node->data=num;
    new_node->prev=top;
    top=new_node;
}

int isEmpty(){
    if (top==NULL){
        return 1;
    }
    else
        return 0;
}

int pop(){
    struct node *temp;
    if(isEmpty(top)){
        printf("Stack Underflow!!\n");
        return 0;
    }
    else{
        temp=top;
        top=temp->prev;
        return temp->data; 
        free(temp);      
    }
}

int peek(){
    if(isEmpty(top)){
        printf("Stack Underflow!!\n");
        return 1;
    }
    else
        return top->data;
}

void display(){
    if(isEmpty(top)){
        printf("Stack Underflow!!\n");
        exit(0);
    }
    else{
        struct node *temp;
        temp->prev=top->prev;
        temp->data=top->data;
        while(temp!=NULL){
            printf("%d ->",temp->data);
            temp=temp->prev;
        }
        printf("\n");
    }
}
int main(){
    char ans[4]="y";
    while (!strcmp(ans,"y")){
        printf("Enter your Choice fron the below Menu\n1. Push\n2. Pop\n3. Display Stack\n4. Peek\n5. Is Empty\n");
        printf("Enter your choice:");
        int ch;
        scanf("%d",&ch);

        if (ch==1){
            printf("Enter Number to Push:");
            int dat_push;
            scanf("%d",&dat_push);
            push(dat_push);
        }
        
        else if(ch==2){
            int dat_pop;
            dat_pop=pop();
            if (dat_pop)
                printf("Popped Element: %d\n",dat_pop);
        }

        else if (ch==3)
            display();
        
        else if (ch==4){
            int top_data=peek();
            if (top_data)
                printf("Data at TOP : %d\n",top_data);
        }

        else if (ch==5){
            if (isEmpty())
                printf("Empty Stack.\n");
            else
                printf("Stack not Empty.\n");
        }

        else{
            printf("Incorrect Entry. TRY AGAIN.\n");
        }
        printf("Do you want to continue? (Y/N)");
        fflush(stdin);
        scanf("%s",ans);
        fflush(stdin);
        continue;
    } 
}
