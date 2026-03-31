#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l;
    cin >> n >> l;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    long long max_gap = 0;

    // internal gaps
    for (int i = 1; i < n; i++) {
        max_gap = max(max_gap, a[i] - a[i - 1]);
    }

    double d = max({
        (double)a[0],
        (double)(l - a[n - 1]),
        max_gap / 2.0
    });

    cout << fixed << setprecision(10) << d << "\n";

    return 0;
}
