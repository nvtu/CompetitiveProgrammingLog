#include <bits/stdc++.h>
using namespace std;

struct Layer {
    long long mmin, mmax, step, gap;
    Layer(){};
    Layer(long long mmin, long long mmax, long long step, long long gap) {
        this->mmin = mmin;
        this->mmax = mmax;
        this->step = step;
        this->gap = gap;
    }
} l[35];

long long L, S, Q, type, k;

long long query(long long k) {
    // Query the value of k-th node in the BST
    long long layerIndex = log2(k);
    long long rem = k % (1 << layerIndex);
    long long ans = l[layerIndex].mmin + rem * l[layerIndex].step;
    return ans;
}

string findNode(long long val) {
    string ans = ""; 
    if (val == l[0].mmin) ans = "root"; // Root case
    else {
	
        long long cur = l[0].mmin;
        for (long long i=0; i<L; i++) {
            // determine the way
            if (val > cur) {
                ans += "r";
                cur += l[i].gap;
                if (i == L-2) cur++;
            }
            else if (val < cur) ans += "l", cur -= l[i].gap;
            else break;
        }
    }
    return ans;
}

void constructBST(long long mmin) {
    long long gap = 0;
    for (long long i=L-1; i>=0; i--) {
        if (i < L-2) gap = 1 << (L-3-i);
        mmin += gap;
        long long step = 1 << (L-1-i);
        long long mmax = (i > 0 ? mmin + step * ((1 << i) - 1) : mmin);
        l[i] = Layer(mmin, mmax, step, gap);
    }
}

bool checkSum() {
	long long ans = 0;
	for (long long i=0; i<L; i++) {
        long long sum = l[i].mmin;
		if (i > 0) sum = (l[i].mmax + l[i].mmin) * ((l[i].mmax - l[i].mmin + l[i].step) / l[i].step) / 2;
        ans += sum;
        if (ans > S) return true;
	}
	return false;
}


long long findMinNode() {
    long long _l = 0, _r = (long long)(1e18)+1, ans = -1;
    while (_l <= _r) {
        long long mid = (_l + _r) >> 1;
        constructBST(mid);
        if (!checkSum()) _l = mid+1;
        else {
            ans = mid;
            _r = mid-1;
        }
    }
    return ans;
}


int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> S >> Q;
    // Construct necessary information for the required BST
    long long mmin = findMinNode();
    constructBST(mmin); 
//    for (long long i=0; i<L; i++) cout << l[i].mmin << " " << l[i].mmax << " " << l[i].step << endl;
    while (Q--) {
        cin >> type >> k;
        if (type == 1) cout << query(k) << endl;
        else cout << findNode(k) << endl;
    }
    return 0;
}

