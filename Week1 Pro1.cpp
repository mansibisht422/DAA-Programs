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

        int comparisons = 0;
        bool found = false;

        // Linear Search
        for (int i = 0; i < n; i++) {
            comparisons++;

            if (arr[i] == key) {
                found = true;
                break;
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