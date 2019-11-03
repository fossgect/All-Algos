#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
  unsigned capacity;
  char *array;
  int top;
};
typedef struct Stack stack;

stack *createStack(int capacity) {
  stack *stack1;
  stack1 = (stack *)malloc(sizeof(stack));
  stack1->capacity = capacity;
  stack1->array = (char *)malloc(capacity * sizeof(char));
  stack1->top = -1;
  return stack1;
}
char pop(stack *stk) {
  if (stk->top != -1) {
    return (stk->array)[stk->top--];
  }
  return '$';
}
void push(stack *stcki, char ch) {
  if (!(stcki->top == stcki->capacity))
    (stcki->array)[++stcki->top] = ch;
}
void display(stack *stk) {
  int i;
  for (i = 0; i <= stk->top; i++) {
    printf("%c  %d\n", (stk->array)[(stk->top) - i], stk->top - i);
  }
}
int isoperand(char a) {
  if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') ||
      (a >= '0' && a <= '9'))
    return 1;
  else
    return 0;
}
int order(char ch) {
  switch (ch) {
  case ('+'):
  case ('-'):
    return 1;
  case ('*'):
  case ('/'):
    return 2;

  case ('^'):
    return 3;
  }
  return -1;
}
void intopost(char *exp) {
  int i = 0, k = -1;
  char oexp[strlen(exp)];

  stack *mystack;
  mystack = createStack(strlen(exp));
  for (i = 0; exp[i]; i++) {
    if (isoperand(exp[i])) {
      oexp[++k] = exp[i];
    } else if (exp[i] == ')') {
      while (mystack->top != -1 && (mystack->array)[mystack->top] != '(') {
        oexp[++k] = pop(mystack);
      }
      pop(mystack);
    } else if (exp[i] == '(') {
      push(mystack, exp[i]);
    } else {

      while (mystack->top != -1 &&
             order(exp[i]) <= order((mystack->array)[mystack->top]))
        oexp[++k] = pop(mystack);

      push(mystack, exp[i]);
    }
    // printf("The stack is \n");
    // display(mystack);
  }

  while (mystack->top != -1) {
    oexp[++k] = pop(mystack);
  }
  oexp[++k] = '\0';
  i = 0;
  while (oexp[i] != '\0')
    printf("%c", oexp[i]), i++;
}
int main() {
  char a[15];
  printf("Enter the infix expression\n");
  scanf("%s", a);
  intopost(a);
  return 0;
}
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
// struct Stack{
//    unsigned capacity;
//    char* array;
//    int top;
//};
// typedef struct Stack stack;
//
// stack* createStack(int capacity){
//    stack* stack1;
//    stack1=(stack*)malloc(sizeof(stack));
//    stack1->capacity=capacity;
//    stack1->array=(char*)malloc(capacity*sizeof(char));
//    stack1->top=-1;
//    return stack1;
//}
// char pop(stack* stk){
//    if(stk->top!=-1){
//        printf("popped %c\n", (stk->array)[stk->top]);
//        return (stk->array)[stk->top--];
//    }
//      return '$';
//}
// void push(stack* stcki,char ch){
//    if(!(stcki->top==stcki->capacity))
//        (stcki->array)[++stcki->top]=ch;
//    printf("pushed %c into stack\n",ch);
//}
// void display(stack* stk){
//    int i;
//    printf("_______STACK_______\n");
//    for(i=0;i<=stk->top;i++){
//        printf("%c  %d\n",(stk->array)[(stk->top)-i],stk->top-i);
//    }
//    printf("___________________\n");
//}
// int isoperand(char a){
//    if((a>='a' && a<='z')||(a>='A' && a<='Z'))
//        return 1;
//    else
//        return 0;
//}
// int order(char ch){
//    switch(ch){
//        case('+'):
//        case('-'):
//            return 1 ;
//        case('*'):
//        case('/'):
//            return 2;
//
//        case('^'):
//            return 3;
//
//
//    }
//    return -1;
//}
// void intopost(char* exp){
// int i=0,k=-1;
// char oexp[strlen(exp)+1];
// stack* mystack;
// mystack=createStack(strlen(exp));
// printf("infixtopostfix function called.\n");
// for(i=0;exp[i];i++){
//    if(isoperand(exp[i])){
//        printf("operand %c encountered\n",exp[i]);
//        oexp[++k]=exp[i];
//    }
//    else if(exp[i]==')'){
//         printf(") encountered\n");
//        while(mystack->top!=-1&&(mystack->array)[mystack->top]!='('){
//            oexp[++k]=pop(mystack);
//        }
//        pop(mystack);
//    }
//    else if(exp[i]=='('){
//        printf("( encountered\n");
//        push(mystack,exp[i]);
//    }
//   else{
//       printf("operator %c encountered\n",exp[i]);
//       printf("%c:%d
//       %c:%d\n",(mystack->array)[mystack->top],order((mystack->array)[mystack->top]),exp[i],order(exp[i]));
//       while(mystack->top!=-1&&order(exp[i])<=order((mystack->array)[mystack->top]))
//           oexp[++k]=pop(mystack);
//
//        push(mystack,exp[i]);
//
//
//
//}
// printf("The expression is %s\n",oexp);
// printf("The stack is \n");
// display(mystack);
//}
// while(mystack->top!=-1){
// printf("HAHAHAHA\n");
// oexp[++k]=pop(mystack);
// printf("HUHUHU\n");
//}
//
//
//
// printf("%s\n",oexp);
//}
// int main(){
//    char a[]="a+b*(c^d-e)^(f+g*h)-i";
//    printf("Program Execution Begining\n");
//    intopost(a);
//    printf("%d ||| %d\n",order('/'),order('^'));
//    return 0;
//}
