/*
题目描述
设计一个有 getMin 功能的栈
实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。

输入描述:
第一行输入一个整数N，表示对栈进行的操作总数。
下面N行每行输入一个字符串S，表示操作的种类。
如果S为"push"，则后面还有一个整数X表示向栈里压入整数X。
如果S为"pop"，则表示弹出栈顶操作。
如果S为"getMin"，则表示询问当前栈中的最小元素是多少。

输出描述:
对于每个getMin操作，输出一行表示当前栈中的最小元素是多少。

示例1
输入
6
push 3
push 2
push 1
getMin
pop
getMin

输出
1
2
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> m;
    
    void push(int i) {
        s.push(i);
        if (m.size() == 0)
            m.push(i);
        else if (i > m.top())
            m.push(m.top());
        else
            m.push(i);
    }
    void pop() {
        s.pop();
        m.pop();
    }
    int getMin() {
        return m.top();
    }
};


int main() {
    int n;
    cin >> n;
    MinStack stack;
    while(n--) {
        string s;
        cin >> s;
        if (s == "push"){
            int temp;
            cin >> temp;
            stack.push(temp);
        } else if (s == "pop")
            stack.pop();
        else
            cout << stack.getMin() << endl;
    }
    return 0;
}

