//Queue 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* Next;
};

class Queue {
    private:
    Node* Front;
    Node* Rear;
    int count;

    public:
    Queue() : Front(NULL), Rear(NULL), count(0) {}
    ~Queue() {
        while(!empty())
            Pop();
    }
    void Push(int item);
    int Pop();
    int Size() const {
        return count;
    }
    bool empty() const {
        return (count == 0);
    }
    int front() const {
        if (!empty())
            return Front->data;
        else
            return -1;
    }
    int back() const {
        if (!empty())
            return Rear->data;
        else
            return -1;
    }
};

void Queue::Push(int item) {
    Node* newnode = new Node;
    newnode->data = item;
    newnode->Next = NULL;
    if (!empty()) {
        Rear->Next = newnode;
        Rear = newnode;
    } else 
        Front = Rear = newnode;
    count++;
}
int Queue::Pop() {
    if (empty()) {
        return -1;
    } else {
        Node* tmp = Front;
        int val = tmp->data;

        Front = Front->Next;
        delete tmp;
        count--;

        if (Front == NULL)
            Rear == NULL;

        return val;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, val;
    string s;
    Queue Q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> val;
            Q.Push(val);
        }
        else if (s == "pop") 
            cout << Q.Pop() << endl;
        
        else if (s == "size")
            cout << Q.Size() << endl;
        else if (s == "front")
            cout << Q.front() << endl;
        else if (s == "back")
            cout << Q.back() << endl;
        else if (s == "empty")
            cout << Q.empty() << endl;
        else
            cout << "잘못된 입력\n";
    }
    return 0;
}