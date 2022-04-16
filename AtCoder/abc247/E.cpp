#include <bits/stdc++.h>
using namespace std;
const int SZ = int(2e5+5);

int N, X, Y, A[SZ], L[SZ], R[SZ];
stack<int> l, r;
vector<pair<int, int> > maxB, minB;

bool normalCmp (int x, int y) {
    return x < y;
}

bool greaterCmp(int x, int y) {
    return x > y;
}


void aggregate(vector<pair<int, int> >& v, int Z) {
    for (int i=1; i<=N; i++) {
        if (A[i] == Z) {
            if (!v.empty()) {
                auto b = v.back();
                if (b.second >= L[i] - 1) {
                    v.pop_back();
                    v.push_back({b.first, R[i]});
                }
                else v.push_back({L[i], R[i]});
            }
            else v.push_back({L[i], R[i]});
        }
    }
}


void maxMinIndex(bool (*cmp)(int, int)) {
    L[0] = 0, R[N+1] = N+1;
    for (int i=1; i<=N; i++) {
        while (!l.empty() && cmp(A[l.top()], A[i])) l.pop();
        if (!l.empty()) L[i] = l.top()+1;
        else L[i] = 1;
        l.push(i);

        while (!r.empty() && cmp(A[r.top()], A[N-i+1])) r.pop();
        if (!r.empty()) R[N-i+1] = r.top()-1;
        else R[N-i+1] = N;
        r.push(N-i+1);
    }
    while (!l.empty()) l.pop();
    while (!r.empty()) r.pop();
}


void solve() {
    
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> X >> Y;
    for (int i=1; i<=N; i++) cin >> A[i];
    // Find the index largest j and smallest k that j < i < k and A[i] is maximum in that range
    maxMinIndex(&normalCmp);
    aggregate(maxB, X);
    // Find the index largest j and smallest k that j < i < k and A[i] is minimum in that range
    maxMinIndex(&greaterCmp);
    aggregate(minB, Y);
    for (auto x: maxB) cout << x.first << " " << x.second << endl;
    cout << endl;
    for (auto x: minB) cout << x.first << " " << x.second << endl;
    return 0;
}

