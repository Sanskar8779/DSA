//Basic Implementation of Stack using an array

#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int size;
    int top;
    int *S;
};
void push(struct Stack *st, int x){
    if(st->top == st->size - 1){
        cout << "StackOverFlow"<< endl;
    }else{
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(struct Stack *st){
    int x = -1;
    if(st->top == -1){
        cout << "Stack Under Flow"<< endl;
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
int peek(struct Stack st, int pos){
    int x = -1;
    if(st.top - pos + 1  < 0){
        cout << "Invalid position" << endl;
    }else{
        x = st.S[st.top - pos + 1];
    }
    return x;
}
bool isEmpty(struct Stack st){
    if(st.top == -1){
        return true;
    }
    return false;
}
bool isFull(struct Stack st){
    if(st.top == st.size - 1){
        return true;
    }
    return false;
}
int StackTop(struct Stack st){
    if(st.top == -1){
        return -1;
    }
    else{
        return st.S[st.top];
    }
}
int main(){
    struct Stack st;
    cout << "Enter the size of the stack: ";
    cin >> st.size;
    st.S = new int[st.size];
    st.top = -1;
    cout << "Enter the array: "<< endl;
    for(int i=0; i<st.size; i++){
        int x;
        cin >> x;
        push(&st, x); 
    }
    
    int value_deleted = pop(&st);
    cout << "The deleted value is: "<< value_deleted<< endl;
    int peek_value = peek(st, 4);
    cout << peek_value;
    return 0;
}