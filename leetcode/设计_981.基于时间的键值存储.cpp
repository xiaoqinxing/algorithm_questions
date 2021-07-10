/*

*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

class TimeMap2
{
public:
    /** Initialize your data structure here. */
    TimeMap2()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        //注意，一定要是用引用或指针的形式，否则时间会超时！！！！！！！
        auto &tmpm = m[key];
        pair<int, string> p = {timestamp, string({127})};
        auto index = upper_bound(tmpm.begin(), tmpm.end(), p);
        if (index != tmpm.begin())
        {
            // index--;
            return (index - 1)->second;
        }

        return "";
    }

private:
    map<string, vector<pair<int, string>>> m;
};

class TimeMap
{
public:
    /** Initialize your data structure here. */
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        //注意，一定要是用引用或指针的形式，否则时间会超时！！！！！！！
        auto &tmpm = m[key];
        auto index = tmpm.upper_bound(timestamp);
        if (index != tmpm.begin())
        {
            index--;
            return index->second;
        }
        return "";
    }

private:
    unordered_map<string, map<int, string>> m;
};

int main()
{
    PrintTitle(__FILE__);

    TimeMap kv;
    string ret;
    kv.set("foo", "bar", 1);
    ret = kv.get("foo", 1);
    PrintVal(ret);
    ret = kv.get("foo", 3);
    PrintVal(ret);
    kv.set("foo", "bar2", 4);
    ret = kv.get("foo", 4);
    PrintVal(ret);
    ret = kv.get("foo", 5);
    PrintVal(ret);

    return 0;
}