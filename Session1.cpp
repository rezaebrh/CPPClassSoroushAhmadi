#include <iostream>

using namespace std;

void reverse_slice(int arr[], unsigned int n, unsigned int start_index, unsigned int end_index) {
    if (end_index >= n)
        return;
    while (start_index < end_index)
        swap(arr[start_index++], arr[end_index--]);
}

int main() {
    cout << "First mention how many numbers do you want to inset: " << endl;	
    int n;
    cin >> n;
    int elements[n];
    cout << "Please insert the numbers: " << endl;
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    cout << elements[0] << " ";
    int my_start = 0;
    for (int i = 1; i < n; i++) {
        if (elements[i - 1] > elements[i]) {
            reverse_slice(elements, n, my_start, i - 1);
            my_start = i;
            cout << endl;
        }
        cout << elements[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    return 0;
}

// 7
// 10 20 3 15 1000 60 16
// 20 10 1000 15 3 60 16
// ascending slice
