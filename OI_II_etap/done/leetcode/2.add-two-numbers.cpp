/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void iterateLinkListToVector(ListNode *l1, vector<int> &num)
    {
        while (l1 != nullptr)
        {
            num.emplace_back(l1->val);
            l1 = l1->next;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // getting data from linked list
        vector<int> numbers1, numbers2;
        iterateLinkListToVector(l1, numbers1);
        iterateLinkListToVector(l2, numbers2);

        // tests
        // numbers1 = {2, 4, 3};
        // numbers2 = {5, 6, 4};

        // calculating sum
        vector<int> ans;

        ans.resize(max(numbers1.size(), numbers2.size()));

        for (int i = 0; i < numbers1.size(); i++)
            ans[i] = numbers1[i];

        for (int i = 0; i < numbers2.size(); i++)
            ans[i] += numbers2[i];

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] > 9)
            {
                int sum = ans[i] / 10;
                ans[i] %= 10;

                if (i + 1 < ans.size())
                    ans[i + 1] += sum;
                else
                    ans.emplace_back(sum);
            }
        }

        // returning linked list
        ListNode *ansListHead = new ListNode(0);

        for (int i = 0; i < ans.size(); i++)
        {

            ListNode *newNode = new ListNode(ans[i]);

            if (ansListHead->next == nullptr)
                ansListHead->next = newNode;

            else
            {
                auto node = ansListHead;

                while (node->next != nullptr)
                    node = node->next;

                node->next = newNode;
            }
        }

        return ansListHead->next;
    }
};
// @lc code=end

int main()
{

    Solution s;
    auto ptr = s.addTwoNumbers(nullptr, nullptr);

    while (ptr != nullptr)
    {
        cout << ptr->val;
        ptr = ptr->next;
    }

    return 0;
}