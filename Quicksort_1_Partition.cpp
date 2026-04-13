#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> arr) {
    int pivot = arr[0];
    vector<int> left, equal, right;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < pivot) left.push_back(arr[i]);
        else if (arr[i] == pivot) equal.push_back(arr[i]);
        else right.push_back(arr[i]);
    }

    vector<int> result;

    for (int x : left) result.push_back(x);
    for (int x : equal) result.push_back(x);
    for (int x : right) result.push_back(x);

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> res = quickSort(arr);

    for (int x : res) cout << x << " ";

    return 0;
}
