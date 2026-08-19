/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* temp = head;
        map<Node*, Node*> mpp;
        while(temp){
            Node* newNode = new Node(temp -> val);
            mpp[temp] = newNode;
            temp = temp -> next;
        }

        temp = head;
        while(temp){
            Node* newNode = mpp[temp];
            newNode -> next = mpp[temp -> next];
            newNode -> random = mpp[temp -> random];
            temp = temp -> next;
        }
        return mpp[head];
    }
};