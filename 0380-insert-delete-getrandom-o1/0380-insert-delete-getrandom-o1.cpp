class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        bool present = 0;
        if(st.count(val)){
            present = 1;
        }

        st.insert(val);
        return present == 0;
    }
    
    bool remove(int val) {
        bool present = 0;
        if(st.count(val)){
            present = 1;
        }

        st.erase(val);
        return present;
    }
    
    int getRandom() {
        int r = rand() % st.size();
        auto it = st.begin();
        advance(it, r);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */