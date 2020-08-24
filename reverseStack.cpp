/*
题目描述
一个栈依次压入1,2,3,4,5，那么从栈顶到栈底分别为5,4,3,2,1。将这个栈转置后，从栈顶到栈底为1,2,3,4,5，也就是实现栈中元素的逆序，但是只能用递归函数来实现，不能用其他数据结构。

输入描述:
输入数据第一行一个整数N为栈中元素的个数。
接下来一行N个整数
表示从栈顶依次到栈底的每个元素。

输出描述:
输出一行表示栈中元素逆序后的每个元素
*/
#include <iostream>
#include <stack>

using namespace std;

int getAndRemoveLastElement(stack<int> &s) {
    int res = s.top();
    s.pop();
    if(s.empty()) {
        return res;
    } else {
        int last = getAndRemoveLastElement(s);
        s.push(res);
        return last;
    }
}

void reverse(stack<int> &s) {
    int i = getAndRemoveLastElement(s);
    if (!s.empty()) {
        reverse(s);
    }
    s.push(i);
}

int main() {
    int n;
    stack<int> s;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        s.push(t);
    }
    reverse(s);
    cout << s.top() << ' ';
    s.pop();
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}