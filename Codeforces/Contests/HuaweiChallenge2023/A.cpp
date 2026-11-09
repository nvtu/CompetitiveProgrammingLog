#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;

const int MAX_SIZE = 11;
const long long MOD = int(1e9+7);

struct TenantBufferSize {
    int tenantId;
    int dataSize;
    int priority;
    int minBufferSize, maxBufferSize, baseBufferSize;

    TenantBufferSize() {}
   
};

struct LRUCache {
    int numTenants, cacheSize, remainCacheSize, currentSize;
    int tenantPriority[MAX_SIZE]; // Priority of each tenant
    int capacity[MAX_SIZE]; // Capacity of each tenant's buffer
    int maxCapacity[MAX_SIZE]; // Max capacity of each tenant's buffer
    list<int> lru[MAX_SIZE]; // LRU list of each tenant
    unordered_map<int, list<int>::iterator> cache[MAX_SIZE];  // Cache of each tenant to check if a page is in the buffer (hit/missed)
    unordered_map<int, int> position[MAX_SIZE];

    LRUCache(int numTenants, int cacheSize) {
        this->numTenants = numTenants;
        this->cacheSize = cacheSize;
    }

    void init() {
        capacity[0] = tenantPriority[0] = 0;
        currentSize = 0;
        int totalCacheSize = accumulate(capacity, capacity+numTenants+1, 0);
        remainCacheSize = cacheSize - totalCacheSize;
        int totalPriority = accumulate(tenantPriority, tenantPriority+numTenants+1, 0);
        for (int i=1; i<numTenants+1; i++) {
            lru[i].clear();
            cache[i].clear();
            position[i].clear();
            capacity[i] += tenantPriority[i] * remainCacheSize / totalPriority;
            capacity[i] = min(capacity[i], maxCapacity[i]);     
        }
        totalCacheSize = accumulate(capacity, capacity+numTenants+1, 0);
        remainCacheSize = cacheSize - totalCacheSize;
    }

    int allocateBufferMemory(int tenantId, int pageId, int tenantPriority) {
        if (cache[tenantId].find(pageId) == cache[tenantId].end()) {
            // Missed
            if (lru[tenantId].size() == capacity[tenantId]) {
                // Check if we still can extend the cache size for the tenant
                if (lru[tenantId].size() < maxCapacity[tenantId] 
                    && remainCacheSize > 0) {
                    remainCacheSize--; 
                    position[tenantId][pageId] = ++currentSize;
                    capacity[tenantId]++;
                }
                else {
                    // Remove the least recently used page
                    int lastPageId = lru[tenantId].back();
                    lru[tenantId].pop_back();
                    cache[tenantId].erase(lastPageId);
                    position[tenantId][pageId] = position[tenantId][lastPageId];
                }
            }
            else {
                position[tenantId][pageId] = ++currentSize;
            }
        }
        else {
            // Hit
            lru[tenantId].erase(cache[tenantId][pageId]);
        }
        lru[tenantId].push_front(pageId);
        cache[tenantId][pageId] = lru[tenantId].begin();

        return position[tenantId][pageId];
    }
};
    

int N, Q, M;
TenantBufferSize tenantBufferSizes[MAX_SIZE];
LRUCache* lruCache = NULL;


void input() {
    cin >> N >> Q >> M;
    for (int i=0; i<N; i++) {
        tenantBufferSizes[i].tenantId = i+1;
        cin >> tenantBufferSizes[i].priority;
    }
    for (int i=0; i<N; i++) cin >> tenantBufferSizes[i].dataSize;
    for (int i=0; i<N; i++) {
        cin >> tenantBufferSizes[i].minBufferSize >> tenantBufferSizes[i].baseBufferSize >> tenantBufferSizes[i].maxBufferSize;
    }
}

void init() {
    int totalBufferSize = 0;
    lruCache = new LRUCache(N, Q);
    for (int i=0; i<N; i++) {
        int maxBufferSize = min(tenantBufferSizes[i].maxBufferSize, tenantBufferSizes[i].dataSize);
        int capacity = min(tenantBufferSizes[i].minBufferSize, tenantBufferSizes[i].baseBufferSize);
        lruCache->capacity[i+1] = capacity;
        lruCache->maxCapacity[i+1] = maxBufferSize;
        lruCache->tenantPriority[i+1] = tenantBufferSizes[i].priority;
    } 
    lruCache->init();
}


void solve() {
    input();
    init();
    int tenantId, pageId;
    while (M--) {
        cin >> tenantId >> pageId;
        int tenantPriority = tenantBufferSizes[tenantId-1].priority;
        int bufferId = lruCache->allocateBufferMemory(tenantId, pageId, tenantPriority);
        cout << bufferId << endl;
        cout.flush();
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
