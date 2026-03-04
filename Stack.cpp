#include <iostream>
#include <cstring>
using namespace std;

class Node {
    public:
    int data;
    Node* Next;
    Node() :data(0), Next(NULL){}

};

class Stack {
    private:
    Node* Top;
    public:
    Stack() : Top(NULL) {}
    ~Stack() {
        delete Top;
    }
    void push(int item);
    int pop();
    int size() const;
    bool empty();
    int top();
};
void Stack::push(int item) {
    Node* newTop = new Node;
    newTop->data = item;
    newTop->Next = Top;
    Top = newTop;
}
int Stack::pop() {
    if (empty())
        return -1;
    Node* temp = Top;
    int val = temp->data;
    Top = Top->Next;
    delete temp;
    return val;
}
int Stack:: size() const {
    int cnt = 0;
    Node* temp = Top;
    while(temp) {
        cnt++;
        temp = temp->Next;
    }
    delete temp;
    return cnt;
}
bool Stack::empty() {
    if(Top == NULL)
        return true;
    else
        return false;
}
int Stack::top() {
    if (empty())
        return -1;
    else
        return Top->data;
}
int main() {
    int n, num;
    Stack s;
    cin >> n;
    string ans;

    for (int i = 0; i < n; i++) {
        cin >> ans;

        if (ans == "push") {
            cin >> num;
            s.push(num);
        }
        else if (ans == "pop") 
            cout << s.pop() << "\n";
        else if (ans == "size")
            cout << s.size() << "\n";
        else if (ans == "empty")
            cout << s.empty() << "\n";
        else if (ans == "top")
            cout << s.top() << "\n";
    }

    return 0;
}