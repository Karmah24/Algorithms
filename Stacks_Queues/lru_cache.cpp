#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        pair<int, int> k_val = *mp[key];
        dll.erase(mp[key]);
        dll.push_front(k_val);
        mp[key] = dll.begin();
        return k_val.second;
    }   
    void set(int key, int value) {
        if (mp.find(key) == mp.end() && dll.size() == cap) {
            pair<int, int> k_val = dll.back();
            dll.pop_back();
            mp.erase(k_val.first);
        }
        else if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    LRUCache cache(3);
    cache.set(1, 10);
    cache.set(2, 20);
    cout << cache.get(1) << ' ';
    cache.set(3, 30);
    cout << cache.get(2) << ' ';
    cache.set(4, 40);
    cache.set(2, 50);
    cout << cache.get(2) << ' ';
    cout << cache.get(4) << ' ';
}