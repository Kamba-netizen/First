#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main() {
    int n;
    string ans;
    stack<char> st;
    stack<char> st2;

    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        getline(cin, ans);
        string temp = ans;
        for (int j = 0; j < ans.size(); j++) {
            
            if (ans[j] == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else
                st.push(ans[j]);
        }
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}