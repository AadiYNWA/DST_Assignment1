#include <bits/stdc++.h>
using namespace std;
 
// Implement two singly linked lists. Take user input to assign values to them.
// Print the two lists. Traverse through the lists to check for subsets and partial matching. Print its status.

typedef struct Node1 {
    int n1;
    struct Node1 *next1;
}node1;

typedef struct Node2 {
    int n2;
    struct Node2 *next2;
}node2;

void printList1(node1 *l) {   
    printf("\nThe first list is: \n");
    
    while (l != NULL) {
        printf("%d ", l->n1);
        l = l->next1;
    }
    
    printf("\n");
}

void printList2(node2 *l) {   
    printf("\nThe second list is: \n");
    
    while (l != NULL) {
        printf("%d ", l->n2);
        l = l->next2;
    }
    
    printf("\n");
}
 
int main() {   
    int num1,num2;
    
    printf("This program implements two list data structures, checks if one is the subset of the other and for partial matching.\n");

    printf("\nEnter the length of the lists respectively: \n");
    scanf("%d %d", &num1, &num2);
    
   
    node1 *head1, *currentNode1, *temp1;
    node2 *head2, *currentNode2, *temp2;
    
    //List1
    printf("\nInput the elements of the first list.\n");
    for (int i = 0; i < num1; i++) {
        
        currentNode1 = (node1 *)malloc(sizeof(node1));

        printf("Enter element %d : ", (i + 1));
        scanf("%d", &currentNode1->n1);

        if (i == 0) {        
            head1 = temp1 = currentNode1;
        }
        else {
            temp1->next1 = currentNode1;
            temp1 = currentNode1;
        }
    }

    temp1->next1 = NULL;
    temp1 = head1;
    
    //List2
    printf("\nInput the elements of the second list.\n");
    for (int i = 0; i < num2; i++) {
    
        currentNode2 = (node2 *)malloc(sizeof(node2));

        printf("Enter element %d : ", (i + 1));
        scanf("%d", &currentNode2->n2);

        if (i == 0) {
            head2 = temp2 = currentNode2;
        }
        else {
            temp2->next2 = currentNode2;
            temp2 = currentNode2;
        }
    }

    temp2->next2 = NULL;
    temp2 = head2;
    
    int a=0;
    vector<int> v ;
    
    int X = max(num1,num2);
    int Y = min(num1,num2);
    
    if(X == num1) {
        for (struct Node2 *l = head2; l!=NULL; l = l->next2) {
            for (struct Node1 *m = head1; m!=NULL; m = m->next1) {
                if (l->n2 == m->n1) {
                    a++;
                    v.push_back(l->n2);
                }
            }
        }
    }
  
    else {
        for (struct Node1 *m = head1; m!=NULL; m = m->next1) {
            for (struct Node2 *l = head2; l!=NULL; l = l->next2) {
                if (l->n2 == m->n1) {
                    a++;
                    v.push_back(m->n1);
                }
            }
        }
    }
    
    printList1(head1);
    printList2(head2);
    
    printf("\nThe partial matched set is:\n");
    
    for (int i=0; i<v.size(); i++) {
        if (v[i] != 0) printf("%d ", v[i]);
    }
    
    printf("\n");
    
    if (a==Y) printf("\nThe smaller list is a subset of the bigger list.\n");
    else printf ("\nThe smaller list is not a subset of the bigger list.\n");
    
    return 0;
}
