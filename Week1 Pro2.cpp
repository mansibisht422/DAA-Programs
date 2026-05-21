#include <iostream>
using namespace std;

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

        int start = 0;
        int end = n - 1;

        int comparisons = 0;
        bool found = false;

        // Binary Search
        while (start <= end) {

            int mid = (start + end) / 2;
            comparisons++;

            if (arr[mid] == key) {
                found = true;
                break;
            }
            else if (key < arr[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        if (found) {
            cout << "Present " << comparisons << endl;
        } else {
            cout << "Not Present " << comparisons << endl;
        }
    }

    return 0;
}