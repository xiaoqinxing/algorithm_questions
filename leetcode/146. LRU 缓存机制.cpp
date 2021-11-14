/*
146. LRU 缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 105
最多调用 2 * 105 次 get 和 put
*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

// 方法一
class LRUCache1
{
public:
    LRUCache1(int capacity)
    {
        maxUsedSize = capacity;
    }

    int get(int key)
    {
        auto it = mLRU.find(key);
        if (it != mLRU.end())
        {
            usedOrder.erase(usedMap[key]);
            usedOrder.push_back(it);
            usedMap[key] = prev(usedOrder.end());
            return it->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = mLRU.find(key);
        // if exists, update history record
        if (it != mLRU.end())
        {
            usedOrder.erase(usedMap[key]);
            it->second = value;
            usedOrder.push_back(it);
            usedMap[key] = prev(usedOrder.end());
            return;
        }
        // if not exist, check usedOrder size
        if (usedOrder.size() >= maxUsedSize)
        {
            mLRU.erase(*usedOrder.begin());
            usedOrder.pop_front();
        }
        mLRU[key] = value;
        usedOrder.push_back(mLRU.find(key));
        usedMap[key] = prev(usedOrder.end());
        return;
    }

private:
    map<int, int> mLRU;
    list<map<int, int>::iterator> usedOrder;
    map<int, list<map<int, int>::iterator>::iterator> usedMap;
    int maxUsedSize;
};

// 方法二 list里面尽可能的多存储信息，然后在map进行索引
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        maxUsedSize = capacity;
    }

    int get(int key)
    {
        auto it = mLRU.find(key);
        if (it != mLRU.end())
        {
            usedOrder.emplace_front(make_pair(key, it->second->second));
            usedOrder.erase(it->second);
            mLRU[key] = usedOrder.begin();
            return usedOrder.front().second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = mLRU.find(key);
        // if exists, update history record
        if (it != mLRU.end())
        {
            usedOrder.emplace_front(make_pair(key, value));
            usedOrder.erase(it->second);
            mLRU[key] = usedOrder.begin();
            return;
        }
        // if not exist, check usedOrder size
        if (usedOrder.size() >= maxUsedSize)
        {
            mLRU.erase(usedOrder.back().first);
            usedOrder.pop_back();
        }
        usedOrder.emplace_front(make_pair(key, value));
        mLRU[key] = usedOrder.begin();
        return;
    }

private:
    using LRUListType = list<pair<int, int>>;
    LRUListType usedOrder;
    unordered_map<int, LRUListType::iterator> mLRU;
    int maxUsedSize;
};

int main()
{
    PrintTitle(__FILE__);
    LRUCache lRUCache{2};
    lRUCache.put(1, 1);     // 缓存是 {1=1}
    lRUCache.put(2, 2);     // 缓存是 {1=1, 2=2}
    PRINT(lRUCache.get(1)); // 返回 1
    lRUCache.put(3, 3);     // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    PRINT(lRUCache.get(2)); // 返回 -1 (未找到)
    lRUCache.put(4, 4);     // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    PRINT(lRUCache.get(1)); // 返回 -1 (未找到)
    PRINT(lRUCache.get(3)); // 返回 3
    PRINT(lRUCache.get(4)); // 返回 4

    return 0;
}