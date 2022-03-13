#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int SZ = 1003;

int N, M, A[SZ][SZ], v[4];
long long ans = 0, res = 0, sumRow[SZ], sumCol[SZ];

long long calSumRow(int row, int updatedVal) {
    long long sum = 0;
    for (int i=0; i<M; i++) {
        sum += 1LL * abs(A[row][i] + updatedVal);
    }
    return sum;
}

long long calSumCol(int col, int updatedVal) {
    long long sum = 0;
    for (int i=0; i<N; i++) {
        sum += 1LL * abs(A[i][col] + updatedVal);
    }
    return sum;
}

void updateRow(int row, int val, int replaceVal) {
    long long rowSum = calSumRow(row, 0);
    long long addedSum = ans - rowSum + calSumRow(row, val);
    long long sum = ans;
    long long replacedSum = ans - rowSum + 1LL * abs(replaceVal) * M;
    if (sum >= addedSum && sum >= replacedSum) return;
    else {
        if (replacedSum > addedSum) {
            sumRow[row] = 1LL * abs(replaceVal) * M;
        }
        else {
            sumRow[row] = calSumRow(row, val);
        }
    }
}

void updateColumn(int col, int val, int replaceVal) {
    long long addedSum = ans - sumCol[col] + calSumCol(col, val);
    long long sum = ans;
    long long replacedSum = ans - sumCol[col] + 1LL * abs(replaceVal) * N;
    if (sum >= addedSum && sum >= replacedSum) return;
    else {
        if (replacedSum > addedSum) {
            sumCol[col] = 1LL * abs(replaceVal) * N;
        } 
        else {
            sumCol[col] = calSumCol(col, val);
        }
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
        cin >> A[i][j];
    }
    for (int i=0; i<4; i++) cin >> v[i];
    for (int i=0; i<N; i++) sumRow[i] = calSumRow(i, 0);
    for (int i=0; i<M; i++) sumCol[i] = calSumCol(i, 0);
    for (int i=0; i<N; i++) ans += sumRow[i];
    // Process row first
    for (int i=0; i<N; i++) updateRow(i, v[0], v[1]);
    for (int i=0; i<N; i++) res += sumRow[i];
    //cout << ans << endl;
    // Process column later
    for (int i=0; i<M; i++) updateColumn(i, v[2], v[3]);
    ans = 0;
    for (int i=0; i<M; i++) ans += sumCol[i];
	res = max(res, ans);
    cout << res << endl;
    return 0;
}
