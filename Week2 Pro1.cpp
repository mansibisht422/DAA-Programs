#include <iostream>
using namespace std;

// Function to find first occurrence
int firstOccurrence(int arr[], int n, int key) {

    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end) {

        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1;   // move left
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

// Function to find last occurrence
int lastOccurrence(int arr[], int n, int key) {

    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end) {

        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            ans = mid;
            start = mid + 1;   // move right
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int first = firstOccurrence(arr, n, key);

        if (first == -1) {
            cout << "Key not present" << endl;
        }
        else {

            int last = lastOccurrence(arr, n, key);

            int count = last - first + 1;

            cout << key << " - " << count << endl;
        }
    }

    return 0;
}