/*
题目描述
用两个栈实现队列，支持队列的基本操作。

输入描述:
第一行输入一个整数N，表示对队列进行的操作总数。
下面N行每行输入一个字符串S，表示操作的种类。
如果S为"add"，则后面还有一个整数X表示向队列尾部加入整数X。
如果S为"poll"，则表示弹出队列头部操作。
如果S为"peek"，则表示询问当前队列中头部元素是多少。

输出描述:
对于每一个为"peek"的操作，输出一行表示当前队列中头部元素是多少。

示例
输入
6
add 1
add 2
add 3
peek
poll
peek
输出
1
2
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Queue {
public:
    stack<int> q1;
    stack<int> q2;
    
    void add(int x) {
        q1.push(x);
    }
    void poll() {
        if (q2.empty()) {
            while(!q1.empty()) {
                q2.push(q1.top());
                q1.pop();
            }
        }
        if (!q2.empty())
            q2.pop();
    }
    int peek() {
        if (q2.empty()) {
            while(!q1.empty()) {
                q2.push(q1.top());
                q1.pop();
            }
        }
        if (!q2.empty())
            return q2.top();
        return -1;
    }
};

int main() {
    Queue q;
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if (s == "add") {
            int t;
            cin >> t;
            q.add(t);
        } else if (s == "poll")
            q.poll();
        else if (s == "peek")
            cout << q.peek() <<endl;
    }
    return 0;
}