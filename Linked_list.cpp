//연결리스트 - string

#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    string data;
    Node* Next;
};

class List {
    private:
    Node* Head;
    int count;

    public:
    List();
    ~List();
    void Insert(int position, string item);
    void Delete(int Position);
    bool IsEmpty() const {return (count == 0);}
    int Length() const {return count;}
    void PrintAll() const {
        const Node* prev = Head;
        while(prev != NULL) {
            cout << prev->data << " ";
            prev = prev->Next;
        }
        cout << endl;
    }
    void Print(int position) const {
        if (position < 0 || position > count - 1) {
            cout << "잘못된 위치\n";
            return;
        }

        const Node* cur = Head;
        for (int i = 0; i < position; i++) {
            cur = cur->Next;
        }
        cout << cur->data << endl;
    }
};
List::List() {
    Head = NULL;
    count = 0;
}
void List::Insert(int position, string item) {
    if (position < 0 || position > count) {
        cout << "잘못된 위치\n";
        return;
    }

    Node* newnode = new Node;
    newnode->data = item;
    newnode->Next = NULL;

    if (position == 0) {
        newnode->Next = Head;
        Head = newnode;
    } else {
        Node* prev = Head;
        for (int i = 0; i < position-1; i++) 
            prev = prev->Next;
        newnode->Next = prev->Next;
        prev->Next = newnode;
    }
    count++;
}
void List::Delete(int position) {
    if (position < 0 || position > count - 1){
        cout << "잘못된 위치\n";
        return;
    }
    Node* p;
    if (position == 0) {
        p = Head;
        Head = Head->Next;
    } else {
        Node* prev = Head;
        for (int i = 0; i < position - 1; i++) 
            prev = prev->Next;
        p = prev->Next;
        prev->Next = p->Next;
    }
    count--;
    delete p;
}
List::~List() {
    while(!IsEmpty())
        Delete(0);
}
int main() {
    int n, m, num;
    string val;
    bool running = true;
    List l;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        l.Insert(i,val);
    }
    l.PrintAll();
    cout << "1. 삽입\n2. 삭제\n3. 출력\n4. 종료\n";
    while(running) {
        cin >> m;
        switch(m) {
            case(1):
                cin >> num >> val;
                l.Insert(num, val);
                break;
            case 2:
                cin >> num;
                l.Delete(num);
                break;

            case 3:
                l.PrintAll();
                break;

            case 4:
                cout << "프로그램 종료\n";
                running = false;
                break;
            default:
                cout << "잘못된 선택\n";
        }
    }
    return 0;
}