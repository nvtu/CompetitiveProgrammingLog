#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = int(1e5+5);

int n, a[MAX_SIZE], x, y;
vector<int> pathx, pathy;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node() {
        left = NULL;
        right = NULL;
    }
    Node(int val) {
        this->val = val; 
        left = NULL;
        right = NULL;
    }
};

void insert(Node*& root, int val) {
    Node* cur = root;
    while (true) {
        if (val > cur->val) {
            if (cur->right == NULL) {
                cur->right = new Node(val);
                return;
            }
            else cur = cur->right;
        }
        else {
            if (cur->left == NULL) {
                cur->left = new Node(val);
                return;
            }
            else cur = cur->left;
        }
    }
}

void search(Node* root, int val, vector<int>& path) {
    Node* cur = root;
    while (cur != NULL) {
        path.push_back(cur->val);
        if (val > cur->val) cur = cur->right;
        else if (val < cur->val) cur = cur->left;
        else return;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    Node* root = new Node(a[0]);
    for (int i=1; i<n; i++) insert(root, a[i]);
    cin >> x >> y;
    search(root, x, pathx);
    search(root, y, pathy);
    int ans = 0, msz = min(pathx.size(), pathy.size()), k = 0;
    for (int i=0; i<msz; i++) {
        if (pathx[i] == pathy[i]) k = i;
    }
    for (int i=k; i<pathx.size(); i++) ans = max(ans, pathx[i]);
    for (int i=k; i<pathy.size(); i++) ans = max(ans, pathy[i]);
    cout << ans << endl;
    return 0;
}

