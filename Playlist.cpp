#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    unordered_map<long long, int> last_pos;

    int l = 0;
    int best = 0;

    for (int r = 0; r < n; r++) {
        if (last_pos.count(a[r]) && last_pos[a[r]] >= l) {
            l = last_pos[a[r]] + 1;
        }

        last_pos[a[r]] = r;

        best = max(best, r - l + 1);
    }

    cout << best << "\n";
    return 0;
}
