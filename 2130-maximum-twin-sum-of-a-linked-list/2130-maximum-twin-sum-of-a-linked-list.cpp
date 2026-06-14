/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nodeValues;
        ListNode* temp = head;
        while(temp){
            nodeValues.push_back(temp -> val);
            temp = temp -> next;
        }
        int maxiSum = 0;
        int currSum = 0;
        int n = nodeValues.size();
        for(int i = 0; i < n / 2; i++){
            currSum = nodeValues[i] + nodeValues[n - 1 - i];
            maxiSum = max(maxiSum, currSum);
        }
        return maxiSum;
    }
};