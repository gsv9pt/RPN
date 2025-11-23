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
    printf("%d", top->num);
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

return 0;

}



int main(){

char input[256];    // creates array for stdin
node *top = NULL;    // sets top pointer
int tokens = 0; // tracks if there is a good token
    
while (fgets(input, sizeof(input), stdin)); // gets the characters


char *cur = input;    // sets another pointer that goes through input

while(*cur != '\0'){     // while string is not nothing check values
    if (isspace(*cur)){    // if there's a space continue on
       cur++;
       continue;
       }
    if (*cur == '\n'){
       cur++;
       continue;
       }

    
    if(isdigit(*cur) || ((*cur=='-') && isdigit(cur[1]))){        // detects numbers and negative numbers
       tokens = 1;
       char *end;                                            // creates a pointer to track the charater after number is made
       long num = strtol(cur, &end, 10);                  // reads chars tracked by cur until number is done, then end points to char after, 10 is the base

       push(&top, (int)num); // push num to stack
       pstack(top,1);        //print
       cur = end;    // cur now starts at end pointer

       continue;
       }

switch (*cur){

case '+':       // if cur is +,-,*,/
case '-':
case '*':
case '/':{

tokens = 1;
    
if(top == NULL || top->next == NULL){  // stack empty or only one num print num
      pstack(top,1); 
      return 0;
      }
    
int b = pop(&top);      // pop twos nums from stack
int a = pop(&top);
int answer = calculate(a, b, *cur);  // preform calc with those nums

push(&top, answer);       // push result on stack 
pstack(top,1);
cur++;
continue;

}

case '\0': // end of good input
break;

    
default:

pstack(top,1); // if unrecognized stop

return 0;

}

cur ++;  // increment cur
}

}   // end of while fgets loop

if (!tokens){
    puts("[]");
    return 0;
}

pstack(top,1);  // answer
return 0;

}

