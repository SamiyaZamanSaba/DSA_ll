#include <bits/stdc++.h>
using namespace std;

struct Basket {
    int count;
    int index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    double mid = (m + 1) / 2.0;

    // custom comparator
    auto cmp = [&](Basket a, Basket b) {
        if (a.count != b.count) return a.count > b.count;

        double da = abs(a.index - mid);
        double db = abs(b.index - mid);

        if (da != db) return da > db;

        return a.index > b.index;
    };

    priority_queue<Basket, vector<Basket>, decltype(cmp)> pq(cmp);

    // initially all baskets empty
    for (int i = 1; i <= m; i++) {
        pq.push({0, i});
    }

    for (int i = 1; i <= n; i++) {
        auto top = pq.top();
        pq.pop();

        cout << top.index << '\n';

        top.count++;
        pq.push(top);
    }
}
