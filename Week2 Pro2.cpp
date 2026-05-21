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

        bool found = false;

        // Taking every element as arr[k]
        for (int k = 0; k < n; k++) {

            int i = 0;
            int j = k - 1;

            while (i < j) {

                int sum = arr[i] + arr[j];

                if (sum == arr[k]) {

                    cout << i + 1 << ","
                         << j + 1 << ","
                         << k + 1 << endl;

                    found = true;
                    break;
                }
                else if (sum < arr[k]) {
                    i++;
                }
                else {
                    j--;
                }
            }

            if (found) {
                break;
            }
        }

        if (!found) {
            cout << "No sequence found" << endl;
        }
    }

    return 0;
}