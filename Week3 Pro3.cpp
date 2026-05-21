#include <iostream>
#include <algorithm>
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

        // Sorting array
        sort(arr, arr + n);

        bool duplicate = false;

        // Checking adjacent elements
        for (int i = 0; i < n - 1; i++) {

            if (arr[i] == arr[i + 1]) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}