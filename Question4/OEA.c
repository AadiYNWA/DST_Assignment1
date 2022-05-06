#include<stdio.h>
#include<string.h>

int top=-1;

void push(int *arr,int size){
    if (top>=size)
        printf("Stack Overflow!!");
    else{
        int a;
        printf("Enter Element to Push: ");
        scanf("%d",&a);
        arr[++top]=a;
        printf("Element Pushed: %d\n",a);
    }
}

int pop(int *arr){
    if (top<0){
        printf("Stack is Empty!!\n");
        return 0;
    }
    else
        return arr[top--];
}

int isEmpty(){
    if (top<=0)
        return 1;
    else
        return 0;
}

int main(){
    char ans[4]="y";
    int stk[100];

    while (!strcmp(ans,"y")){
        printf("Enter your Choice fron the below Menu\n1. Push\n2. Pop\n3. Display Stack\n4. Peek\n5. Is Empty\n");
        printf("Enter your choice:");
        int ch;
        scanf("%d",&ch);

        if (ch==1){
            push(stk,100);
        }
        
        else if(ch==2){
            int dat_pop;
            dat_pop=pop(stk);
            if (dat_pop)
                printf("Popped Element: %d\n",dat_pop);
        }

        else if (ch==3){
            for(int i=0;i<=top;i++)
                printf("%d ",stk[i]);
            printf("\n");
        }
        
        else if (ch==4)
            printf("Data at TOP : %d\n",stk[top]);
        
        else if (ch==5){
            if (isEmpty())
                printf("Empty Stack.\n");
            else
                printf("Stack not Empty.\n");
        }

        else{
            printf("Incorrect Entry. TRY AGAIN.");
        }
        printf("Do you want to continue? (Y/N) ");
        fflush(stdin);
        scanf("%s",ans);
        continue;
    } 
}
