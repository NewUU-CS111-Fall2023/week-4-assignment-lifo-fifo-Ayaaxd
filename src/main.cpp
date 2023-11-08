/*
 * Date: 08/11/2023
 * Name: Sitora Aslonova
 */

#include <iostream>
#include "task_1.h"

int main() {
    std::cout << "Task 1" << std::endl;
    // call for task 1
    std::cout << "Task 2" << std::endl;

    // call for task 2
    std::cout << "Task 3" << std::endl;
    // call for task 3
    std::cout << "Task 4" << std::endl;
    // call for task 4
    std::cout << "Task 5" << std::endl;
    // call for task 5
    return 0;
}

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
int main() {

    int N;
    cin >> N;
    deque<int> train_order;
    for(int i=0;i<N;i++) {
        int m;
        cin>>m;
        train_order.push_front(m);
    }

    deque<int> dead_end_queue;
    deque<int> track_2;

    int k=1;
    int l=1;
    bool flag= true;
    int count_in=0;
    int count_out=0;
    while(flag){
             if(k==train_order.front()){
                 count_in++;
                 k++;
             }

             dead_end_queue.push_front(train_order.front());
             train_order.pop_front();
             if(train_order.empty()){
                 flag= false;
             }
        if(dead_end_queue.back()==l){
                    track_2.push_back(dead_end_queue.back());
                   dead_end_queue.pop_back();
                   count_out++;
                   l++;
        }
      }

cout<<track_2.back();

    }


    while (!dead_end_queue.empty()) {
      cout << "2 1" << endl;
        dead_end_queue.pop();
    }


#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define length 100

struct stack
{
    int top;
    double items[length];
};

int stack[length];
int counter = 0;
void push(int value);
int pop();
void intopost(char *infix, char *postfix);

double eva(char str[]);
void epush(struct stack *ps, double x);
double epop(struct stack *ps);
double oper(int symb, double op1, double op2);

int main()
{
    char infix_str[200];
    char postfix_str[200];
    printf("Enter infix  : ");
    gets(infix_str);
    intopost(infix_str, postfix_str);
    printf("Postfix is  : %s\n", postfix_str);
    printf("Value is  : %.2f\n",eva(postfix_str));
}

void intopost(char *infix, char *postfix)
{
    int  st;
    push('(');
    while (*infix != '\0')
    {
        if (isspace(*infix)) ;
        else if (isalpha(*infix)  isdigit(*infix)) *postfix++ = *infix;
                  else if (*infix == '(') push('(');
        else if (*infix == ')')
        {
            while ((st = pop()) != '(')
                *postfix++ = st;
        }
        else if (*infix == '*'  *infix == '/')
        {
            while (1)
            {
                if ((st = pop()) == '('  st == '+'  st == '-')
                {
                    push(st);
                    break;
                }
                *postfix++ = st;
            }
            push(*infix);
        }
        else if (*infix == '+' || *infix == '-')
        {
            while (1)
            {
                if ((st = pop()) == '(')
                              {
                    push(st);
                    break;
                }
                *postfix++ = st;
            }
            push(*infix);
        }
        else printf("Undefined character %c\n", *infix);
        ++infix;
        continue;
                  }
    while ((st = pop()) != '(') *postfix++ = st;
   *postfix = '\0';
}

void push(int value)
{
    stack[counter++] = value;
}

int pop()
{
    if (counter == 0) return 0;
    return stack[--counter];
}

double eva(char str[])
{
    int c,i;
    double opnd1,opnd2,value;
    struct stack opndstk;
    opndstk.top=-1;
    for(i=0;(c=str[i])!='\0';i++)
    {
        if(isdigit(c)) epush(&opndstk,(double) (c-'0'));
        else
        {
            opnd2=epop(&opndstk);
            opnd1=epop(&opndstk);
            value=oper(c,opnd1,opnd2);
            epush(&opndstk,value);
        }
    }
    return (epop(&opndstk));
}

void epush(struct stack *ps, double x)
{
    ps->items[++(ps->top)]=x;
}

double epop(struct stack *ps)
{
    return(ps->items[ps->top--]);
}

double oper(int symb, double op1, double op2)
{
    switch(symb)
    {
        case '+':return(op1+op2);
      case '-':return(op1-op2);
        case '*':return(op1*op2);
        case '/':return(op1/op2);
    }
}


#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

    vector<vector<int>> stacks(n);
    for (int i = 0; i < n; ++i) {
      int ki;
        cin >> ki;

        for (int j = 0; j < ki; ++j) {
            int type;
            cin >> type;

            stacks[i].push_back(type);
        }
    }

  bool isInitiallyProper = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < stacks[i].size(); ++j) {
            if (stacks[i][j] != i) {
                isInitiallyProper = false;
                break;
            }
       }
    }
  
    if (isInitiallyProper) {
       
    } else {
        // Containers need to be rearranged
        while (true) {
            bool hasMovedContainers = false;

            for (int i = 0; i < n; ++i) {
                if (stacks[i].empty()) {
                    continue;
                }

                int topType = stacks[i].back();
                if (topType != i) {

                    int targetStack = topType;

                    if (!stacks[targetStack].empty()) {
                        
                        if (stacks[targetStack].back() == topType) {
                          
                           continue;
                        }
                    }

                    int fromStack = i;

                    cout << fromStack + 1 << " " << targetStack + 1 << endl;
                    int container = stacks[fromStack].back();
                    stacks[fromStack].pop_back();
                    stacks[targetStack].push_back(container);

                    hasMovedContainers = true;
                    break;
               }
            }

            if (!hasMovedContainers) {
                cout << 0 << endl;
                break;
            }
        }
    }
  return 0;
}


problem 5

#include <iostream>
using namespace std;
int towerOfHanoi(int n) {
    if (n == 1) {
return 1;
    }
return 2 * towerOfHanoi(n - 1) + 1;
}
int main() {
   int n = 8;
   int minMoves = towerOfHanoi(n);
   cout << minMoves << endl;
   return 0;
}

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {

    int N;
    cin >> N;
    deque<int> train_order;
    for(int i=0;i<N;i++) {
        int m;
        cin>>m;
        train_order.push_front(m);
    }

    deque<int> dead_end_queue;
    deque<int> track_2;

    int k=1;
    int l=1;
    bool flag= true;
    int count_in=0;
    int count_out=0;
    while(flag){
             if(k==train_order.front()){
                 count_in++;
                 k++;
             }

             dead_end_queue.push_front(train_order.front());
             train_order.pop_front();
             if(train_order.empty()){
                 flag= false;
             }
        if(dead_end_queue.back()==l){
                    track_2.push_back(dead_end_queue.back());
                   dead_end_queue.pop_back();
                   count_out++;
                   l++;
        }

      }


cout<<track_2.back();

    }
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {

    int N;
    cin >> N;
    deque<int> train_order;
    for(int i=0;i<N;i++) {
        int m;
        cin>>m;
        train_order.push_front(m);
    }

    deque<int> dead_end_queue;
    deque<int> track_2;

    int k=1;
    int l=1;
    bool flag= true;
    int count_in=0;
    int count_out=0;
    while(flag){
             if(k==train_order.front()){
                 count_in++;
                 k++;
             }

             dead_end_queue.push_front(train_order.front());
             train_order.pop_front();
             if(train_order.empty()){
                 flag= false;
             }
        if(dead_end_queue.back()==l){
                    track_2.push_back(dead_end_queue.back());
                   dead_end_queue.pop_back();
                   count_out++;
                   l++;
        }

      }
if(dead_end_queue.empty()){
    cout<<"possible";
} else{
    cout<<"not possible";
}

    }
