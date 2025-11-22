// Blake Tillman
// user ID: gsv9pt

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct node{    // keeps track of number stored, makes pointer to next node in stack

int num;

struct node *next;

}node;

void pstack(node *top, int first) {
    if (!top) { 
        if (first) 
            puts ("[ ]"); 
        return; 
    }
    if (first) 
        printf("[ ");
    printf("%d", top->value);
    if (top->next) {
        printf(", ");
        pstack(top->next, 0);
    } else {
        puts(" ]");
    }
}



void push(node **top, int num){

node *new = malloc(sizeof(node)); // allocate mem for node, makes pointer to new node

new->num = num; // store value in new node

new->next = *top;  // new node points to top

*top = new; // update top

}

int pop(node **top){

node *temp = *top; // temporary storage for first top

int num = temp->num; // gets the value from top

*top = temp->next; // update pointe to next node

free(temp);  // free memory of old top

return num;  // return value

}


int calculate(int a, int b, char o){

if(o == '+'){     // if an operator is read it will return an answer done with that specific math
return a + b;
}

else if(o == '-'){
return a - b;
}

else if(o == '*'){
return a * b;
}

else if(o == '/'){
return a / b;
}


}


}




int main(){

char input[256];    // creates array for stdin

printf("Enter your values");   // promt for user

fgets(input, sizeof(input), stdin); // gets the characters

node *top = NULL;    // sets top pointer
char *cur = input;    // sets another pointer that goes through input

while(*cur != '\0'){    // while string is not nothing check values
     if(isdigit(*cur)){    // check if cur pointer is char is 0-9
     int num = *cur - '0';  // if it is set int num to cur - 0 because of ASCII, this will give actuall value
     push(&top, num);      // call push to put on stack 
     }

switch (*cur){

case '+':       // if cur is +,-,*
case '-':
case '*':
case '/':{

int b = pop(&top);      // pop twos nums from stack
int a = pop(&top);
int answer = calculate(a, b, *cur);  // preform calc with those nums
push(&top, answer);       // push result on stack 
break;

}

case ' ':
break;           // skip whitespace

default:

pstack(top,1); // if unrecognized stop

break;

}

cur += 1;  // increment cur

}
pstack(top,1);  // answer

return 0;

}
