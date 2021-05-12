#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    list<int> vec;
    unordered_map<int, pair<int, list<int>::iterator>> map;
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if (map.count(key) == 0) return -1;
        int val = map[key].first;
        auto ptr = map[key].second;
        vec.erase(ptr);
        vec.push_front(key);
        map[key].second = vec.begin();
        return val;
    }
     
    void put(int key, int value) {
        if (vec.size() == capacity && map.count(key) == 0) {
            int bKey = vec.back();
            map.erase(bKey);
            vec.pop_back();
        }
        else if (map.count(key) != 0) {
            auto ptr = map[key].second;
            vec.erase(ptr);
        }
        vec.push_front(key);
        map[key] = {value, vec.begin()};
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << ' ';
    cache.put(3, 3);
    cout << cache.get(2) << ' ';
    cache.put(4, 4);
    cout << cache.get(1) << ' ';
    cout << cache.get(3) << ' ';
    cout << cache.get(4) << ' ';
}