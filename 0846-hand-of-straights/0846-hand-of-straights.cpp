class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        multiset<int> st(hand.begin(), hand.end());
        while(!st.empty()) {
            int curr = *st.begin();
            for (int i = 0; i < groupSize; i++) {
                auto it = st.find(curr);
                if (it == st.end()) return false;
                st.erase(it);  
                curr++;
            }
        }

        return true;
    }
};