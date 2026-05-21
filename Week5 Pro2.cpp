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

        int key;
        cin >> key;

        // Sorting array
        sort(arr, arr + n);

        int left = 0;
        int right = n - 1;

        bool found = false;

        while (left < right) {

            int sum = arr[left] + arr[right];

            if (sum == key) {

                cout << arr[left] << " " << arr[right] << endl;
                found = true;
                break;
            }
            else if (sum < key) {
                left++;
            }
            else {
                right--;
            }
        }

        if (!found) {
            cout << "No Such Element Exist" << endl;
        }
    }

    return 0;
}