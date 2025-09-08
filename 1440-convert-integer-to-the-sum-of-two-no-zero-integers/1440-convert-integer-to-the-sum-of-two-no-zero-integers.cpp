class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        if(n < 10){
            return {1, n - 1};
        }

        for(int i = 1; i <= n; i++){
            string a = to_string(i);
            string b = to_string(n - i);

            cout << a << ' ' << b << endl;
            bool zero = false;
            for(char it : a){
                if(it == '0'){
                    zero = true;
                }
            }
            for(char it : b){
                if(it == '0'){
                    zero = true;
                }
            }

            cout << zero << endl;
            if(!zero){
                return {stoi(a), stoi(b)};
            }
        }

        return {0, 0};
    }
};