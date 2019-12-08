#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack1, stack2;   
        void push(int x) {
            stack1.push(x);
        }

        void pop() {
            // if(stack1.empty() && stack2.empty()){
            //     return;
            // }
            if(stack2.empty()){
                while(!stack1.empty()){
                    int temp = stack1.top();
                    stack1.pop();
                    stack2.push(temp);
                }
            }
            stack2.pop();
        }

        int front() {
            // if(stack1.empty() && stack2.empty()){
            //     return;
            // }
            if(stack2.empty()){
                while(!stack1.empty()){
                    int temp = stack1.top();
                    stack1.pop();
                    stack2.push(temp);
                }
            }
            return stack2.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}