#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> count(100, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }

    for (int i = 0; i < 100; i++) {
        while (count[i]--) {
            cout << i << " ";
        }
    }

    return 0;
}
