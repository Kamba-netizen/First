#include <iostream>
using namespace std;

void my_sort(int* arr, int size){
    int temp;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int arr_size;
    cout << "array size: ";
    cin >> arr_size;
    int* my_array = new int[arr_size];
    for (int i=0; i<arr_size; i++){
        cin >> my_array[i];
    }
    
    for (int i=0; i<arr_size; i++){
        cout << my_array[i] << " ";
    }
    
    cout << endl;
    my_sort(my_array,arr_size);

    for (int i=0; i<arr_size; i++)
        cout << my_array[i] << " ";
    cout << endl;
    delete[] my_array;
    return 0;
}