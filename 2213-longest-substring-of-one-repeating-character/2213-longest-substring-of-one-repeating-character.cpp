class Solution {
    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;

        Node() {
            len = pref = suff = best = 0;
            leftChar = rightChar = '\0';
        }
        Node(char c) {
            len = pref = suff = best = 1;
            leftChar = rightChar = c;
        }
    };

    vector<Node> seg;
    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        if (a.pref == a.len && a.rightChar == b.leftChar) {
            res.pref = a.len + b.pref;
        }

        res.suff = b.suff;
        if (b.suff == b.len && a.rightChar == b.leftChar) {
            res.suff = b.len + a.suff;
        }

        res.best = max(a.best, b.best);
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);
        }
        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            seg[idx] = Node(s[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx] = Node(c);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * idx, l, mid, pos, c);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, c);
        }
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

public:
    vector<int> longestRepeating(string s,string queryCharacters,vector<int>& queryIndices) {
        int n = s.size();
        int q = queryIndices.size();

        seg.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> res;
        for (int i = 0; i < q; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            res.push_back(seg[1].best);
        }
        return res;
    }
};