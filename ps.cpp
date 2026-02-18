#include <iostream>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
    delete arr[];
    return 0;
}