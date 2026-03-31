#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> nums(n);
    for (auto &x : nums) cin >> x;

    long long target;
    cin >> target;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;

        for (int j = i; j < n; j++) {
            if (nums[j] == target) sum += 1;
            else sum -= 1;

            if (sum > 0) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
