#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = int(1e5+5);
const long long MOD = int(1e9+7);

struct Node {
    string val;
    Node* pNode = NULL;

    Node() {
        pNode = NULL;
    }

    Node(string val) {
        this->val = val;
        pNode = NULL;
    }
};

int T;
string ord, s;
Node* root = NULL;

void insert(string s) {
    Node* newNode = new Node(s);
    if (root != NULL) {
        newNode->pNode = root;
    }
    root = newNode;
}

string get() {
    string ans = "empty";
    if (root != NULL) {
        ans = root->val;
        Node* cur = root;
        root = root->pNode;
        delete cur;
    }  
    return ans;
}

string iditarod() {
    string ans = "oopsimcold :(";
    if (root != NULL) {
        Node* cur = root;
        Node* prev = NULL;
        while (cur != NULL) {
            if (cur->val == "snowcoat") {
                ans = "winner winner chicken dinner :)";
                if (cur == root) {
                    root = root->pNode;
                }
                else {
                    prev->pNode = cur->pNode;
                }
                delete cur;
                break;
            }
            prev = cur;
            cur = cur->pNode; 
        }
    }
    return ans;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> ord;
        if (ord == "put") {
            cin >> s;
            insert(s);
        }
        else if (ord == "get") cout << get() << endl;
        else if (ord == "iditarod") cout << iditarod() << endl;
    }
} 


int main() {
    // freopen("input.txt", "r", stdin);

    // Boost C++ IO speed
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
