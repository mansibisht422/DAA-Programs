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

        int k;
        cin >> k;

        int count = 0;

        // Checking all pairs
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int diff = arr[j] - arr[i];

                if (diff == k || diff == -k) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}