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

        int k;
        cin >> k;

        // Sorting array
        sort(arr, arr + n);

        // Checking validity of K
        if (k > 0 && k <= n) {
            cout << arr[k - 1] << endl;
        }
        else {
            cout << "not present" << endl;
        }
    }

    return 0;
}