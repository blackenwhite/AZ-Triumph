#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int maxsize = 0;
    list<ii> order;
    unordered_map<int, list<ii>::iterator> cache;

public:
    LRUCache(int capacity)
    {
        // Complete function
        maxsize = capacity;
        order.clear();
        cache.clear();
    }

    int get(int key)
    {
        // Complete function
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        auto it = cache.find(key);
        // int key = it->first;
        int res = (*cache[key]).second;
        order.erase(it->second);
        order.push_front({key, res});
        cache[key] = order.begin();
        return res;
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            order.erase(it->second);
            order.push_front({key, value});
            cache[key] = order.begin();
        }
        else
        {
            order.push_front({key, value});
            cache[key] = order.begin();
        }
        if (order.size() > maxsize)
        {
            int key = order.rbegin()->first;
            order.pop_back();
            cache.erase(key);
        }
    }
};
