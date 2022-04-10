#include <bits/stdc++.h>
using namespace std;

int N, Q;
string s = "";

char ask(char x, char y) {
    char ans;
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    cin >> ans;
    return ans;
}


void merge(int l, int mid, int r) {
    string t = "";
    int p = l, q = mid+1;
    for (int i=l; i<=r; i++) {
        if (p > mid) t += s[q++];
        else if (q > r) t += s[p++];
        else {
            char ans = ask(s[p], s[q]);
            if (ans == '<') t += s[p++];
            else t += s[q++];
        }
    }
    for (int i=0; i<r-l+1; i++) s[l+i] = t[i];
}


void query_for_five() {
    char ans;
    ans = ask(s[0], s[1]); // Ask A and B
    if (ans == '<') swap(s[0], s[1]); // Swap A and B
    ans = ask(s[2], s[3]); // Ask C and D
    if (ans == '<') swap(s[2], s[3]); // Swap C and D
    ans = ask(s[0], s[2]); 
    if (ans == '<') {
        swap(s[0], s[2]); // Swap A and C
        swap(s[1], s[3]); // Swap B and D
    }
    ans = ask(s[4], s[2]);
    if (ans == '<') {
        ans = ask(s[4], s[3]); 
        if (ans == '>') swap(s[4], s[3]); // Swap D and E
    }
    else {
        ans = ask(s[4], s[0]);
        if (ans == '<') {
            swap(s[2], s[4]); // Swap C and E
            swap(s[3], s[4]); // Swap D and C
        }
        else {
            swap(s[0], s[4]); // Swap A and E
            swap(s[2], s[4]); // Swap A and C
            swap(s[3], s[4]); // Swap D and C
        }
    }
    ans = ask(s[1], s[3]);
    if (ans == '<') {
        ans = ask(s[1], s[4]);
        if (ans == '<') s = string(1, s[1]) + string(1, s[4]) + string(1, s[3]) + string(1, s[2]) + string(1, s[0]);
        else s = string(1, s[4]) + string(1, s[1]) + string(1, s[3]) + string(1, s[2]) + string(1, s[0]);
    }
    else {
        ans = ask(s[1], s[2]);
        if (ans == '<') s = string(1, s[4]) + string(1, s[3]) + string(1, s[1]) + string(1, s[2]) + string(1, s[0]);
        else s = string(1, s[4]) + string(1, s[3]) + string(1, s[2]) + string(1, s[1]) + string(1, s[0]);
    }
}


void query(int l, int r) {
    if (l < r) {
        int mid = (l+r)>>1;
        query(l, mid);
        query(mid+1, r);
        merge(l, mid, r);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> N >> Q;
    for (int i=0; i<N; i++) s += char('A' + i);
    if (N == 5) query_for_five();
    else query(0, N-1);
    cout << "! " << s << endl;
    return 0;
}

