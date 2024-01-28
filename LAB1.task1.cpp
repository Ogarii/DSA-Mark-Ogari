#include <iostream>

using namespace std;

// Function prototypes
int summation(int arr[], int size);
int maximum(int arr[], int size);

int main() {
    int n;

    //get the number of elements in array from the user
    cout<< "enter array length:";
    cin>> n ;

    //declare array
    int num[n];

    for (int i=0 ; i<n ; i++) {
        cin >> num[i];
    }
    // Call functions to calculate sum and maximum
    int summ = summation(num, n);
    int max = maximum(num, n);

    cout << "Sum of elements: " << summ << endl;
    cout << "Maximum element: " << max << endl;

        return 0;
}

int summation(int arr[], int size){
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;

}
int maximum(int arr[], int size){
    int max = arr[0];
    for (int i = 1 ; i < size ;i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;

}