#include "common.h"
#include <sstream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *createList(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input)
{
    return stoi(input);
}

void printList(ListNode *node)
{
    string result;
    while (node)
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    cout << "链表结果: [" + result.substr(0, result.length() - 2) + "]" << endl;
}

void destoryList(ListNode *node)
{
    ListNode *nextNode;
    while (node)
    {
        nextNode = node->next;
        delete node;
        node = nextNode;
    }
}