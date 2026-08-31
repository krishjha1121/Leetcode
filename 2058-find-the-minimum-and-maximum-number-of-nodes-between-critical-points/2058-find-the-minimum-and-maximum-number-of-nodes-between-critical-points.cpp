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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        ListNode* temp = head;
        ListNode* prev = temp;
        temp = temp -> next;
        int cnt = 2;
        while(temp -> next != NULL){
            if(temp -> val > prev -> val && temp -> val > temp -> next -> val){
                criticalPoints.push_back(cnt);
            }else if(temp -> val < prev -> val && temp -> val < temp -> next -> val){
                criticalPoints.push_back(cnt);
            }
            cnt++;
            prev = temp;
            temp = temp -> next;
        }

        if(criticalPoints.size() < 2){
            return {-1, -1};
        }
        ranges::sort(criticalPoints);
        int n = criticalPoints.size();
        int maxi = criticalPoints.back() - criticalPoints[0];
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            mini = min(mini, criticalPoints[i] - criticalPoints[i - 1]);
        }
        return {mini, maxi};
    }
};