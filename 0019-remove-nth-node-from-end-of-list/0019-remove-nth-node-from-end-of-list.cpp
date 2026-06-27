class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        int pos = len - n;  

        if (pos == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};