#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define sqr(x) (x) * (x)
using namespace std;

const int MAX_SIZE = int(1e5 + 5);
const long long MOD = int(1e9 + 7);
const double EPS = 1e-6;

struct State {
    int x, y, num_candies, mask;
    State(int x, int y, int num_candies, int mask) : x(x), y(y), num_candies(num_candies), mask(mask) {}
};

int n, m;
vector<string> c;
map<pair<int, int>, int> positions;
pair<int, int> start_pos, end_pos;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool visited[105][105][8][256];
queue<pair<State, int> > q;
int ans = MOD;

void solve() {
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    int candy_id = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c.push_back(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'S') {
                start_pos = {i, j};
            } else if (s[j] == 'E') {
                end_pos = make_pair(i, j);
            } else if (s[j] == 'C') {
                positions[make_pair(i, j)] = candy_id++;
            }
        }
    }

    q.push(make_pair(State(start_pos.first, start_pos.second, 0, 0), 0));
    visited[start_pos.first][start_pos.second][0][0] = true;
    while (!q.empty()) {
        pair<State, int> cur = q.front();
        q.pop();
        State state = cur.first;
        int time = cur.second;
        if (state.x == end_pos.first && state.y == end_pos.second) {
            ans = min(ans, time);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = state.x + dx[i], ny = state.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            char cell = c[nx][ny];
            int new_bitmask = state.mask;
            int new_num_candies = state.num_candies;

            if (cell == 'P')
                continue;
            else if (cell == 'J') {
                if (state.num_candies > 0) {
                    new_num_candies--;
                } else {
                    continue;
                }
            } else if (cell == 'C') {
                int candy_index = positions[make_pair(nx, ny)];
                if ((state.mask & (1 << candy_index)) == 0) {
                    new_bitmask |= (1 << candy_index);
                    new_num_candies++;
                }
            }

            State new_state = State(nx, ny, new_num_candies, new_bitmask);
            if (!visited[nx][ny][new_num_candies][new_bitmask]) {
                visited[nx][ny][new_num_candies][new_bitmask] = true;
                q.push(make_pair(new_state, time + 1));
            }
        }
    }
    if (ans == MOD) {
        cout << "SPOOKED!" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    // freopen("inp.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}