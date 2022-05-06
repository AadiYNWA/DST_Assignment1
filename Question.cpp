//We need to implement a basic priority queue using stack data structure

#include <bits/stdc++.h>
using namespace std;

int A[50];
int size = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int left_Child(int i) {
    return ((2 * i) + 1);
}

int right_Child(int i) {
    return ((2 * i) + 2);
}

void shift_Up(int i){
    while (i > 0 && A[parent(i)] < A[i]) {
        swap(A[parent(i)], A[i]); 
        i = parent(i);
    }
}

void shift_Down(int i){
    int max_Index = i;
    int l = left_Child(i);
    if (l <= size && A[l] > A[max_Index])
        max_Index = l;

    int r = right_Child(i);

    if (r <= size && A[r] > A[max_Index])
        max_Index = r;

    if (i != max_Index) {
        swap(A[i], A[max_Index]);
        shift_Down(max_Index);
    }
} 

void insert(int p){
    size = size + 1;
    A[size] = p;
    shift_Up(size);
}

int extract_Max(){
    int result = A[0];
    A[0] = A[size];
    size = size - 1;
    shift_Down(0);
    return result;
}

void change_Priority(int i, int p){
    int oldp = A[i];
    A[i] = p;

    if (p > oldp)
        shift_Up(i);
    else
        shift_Down(i);
}

int get_Max(){
    return A[0];
}

void remove(int i){
    A[i] = get_Max() + 1;
    shift_Up(i);
    extract_Max();
}

int main(){
    insert(415);
    insert(228);
    insert(149);
    insert(12);
    insert(310);
    insert(74);
    insert(11);
    insert(131);
    insert(7);

    int i = 0;
    cout << "Priority Queue : ";

    while (i <= size) { 
        cout << A[i] << " ";
        i++;
    } 

    cout << "\n"; 
    cout << "Node with maximum priority : " << extract_Max() << "\n";
    cout << "Priority queue after "<< "extracting maximum : ";

    int j = 0;

    while (j <= size) {
        cout << A[j] << " ";
        j++;
    }

    cout << "\n"; 

    change_Priority(7, 49);
    cout << "Priority queue after "<< "priority change : ";

    int k = 0;

    while (k <= size) {
        cout << A[k] << " ";
        k++;
    }

    cout << "\n"; 
    remove(11);
    cout << "Priority queue after " << "removing the element : ";
    int l = 0;
    while (l <= size) { 
        cout << A[l] << " ";
        l++;
    }
}
