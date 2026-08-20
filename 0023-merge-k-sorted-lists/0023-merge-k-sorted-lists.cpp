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
class comp{
public:
    bool operator()(ListNode* a , ListNode* b){
        return a -> val > b -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;

        priority_queue<ListNode* , vector<ListNode*> , comp> pq;

        for(int i = 0 ; i < n ; i++){
            if(lists[i]) pq.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();

            if(temp -> next != NULL){
                pq.push(temp -> next);
            }   

            if(head == NULL){
                head = tail = temp;
            }
            else{
                tail -> next = temp;
                tail = temp;
            }
        }
        return head;
    }
};