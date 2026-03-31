#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }


    sort(movies.begin(), movies.end(), [](auto a, auto b) {
        return a.second < b.second;
    });

    int count = 0;
    int last_end = 0;

    for (auto movie : movies) {
        if (movie.first >= last_end) {
            count++;
            last_end = movie.second;
        }
    }

    cout << count << endl;
    return 0;
}
