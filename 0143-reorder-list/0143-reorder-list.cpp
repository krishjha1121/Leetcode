class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        stack<ListNode*> st;
        int cnt = 0;

        ListNode* temp = head;
        while (temp) {
            st.push(temp);
            cnt++;
            temp = temp->next;
        }

        ListNode* curr = head;

        for (int i = 0; i < cnt / 2; i++) {
            ListNode* back = st.top();
            st.pop();

            ListNode* nxt = curr->next;

            curr->next = back;
            back->next = nxt;

            curr = nxt;
        }

        curr->next = nullptr;   
    }
};