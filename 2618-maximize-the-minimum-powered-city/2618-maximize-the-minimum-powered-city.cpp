class Solution {
private:
    bool isPossible(long long mid, vector<long long> &diff,
    int r, int k, int n){
        vector<long long> tempDiff = diff;
        long long cumSum = 0;
        for(int i = 0; i < n; i++){
            cumSum += tempDiff[i];
            if(cumSum < mid){
                long long need = mid - cumSum;
                if(need > k) return false;
                k -= need;
                cumSum += need;
                if(i + 2 * r + 1 < n) tempDiff[i + 2 * r + 1] -= need;
            }
        }
        return true;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> diff(n, 0);
        for(int i = 0; i < n; i++){
            diff[max(0, i - r)] += stations[i];
            if(i + r + 1 < n){
                diff[i + r + 1] -= stations[i];
            }
        }
        long long low = *min_element(stations.begin(), stations.end());
        long long high = accumulate(stations.begin(), stations.end(), 0LL) + k;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isPossible(mid, diff, r, k, n)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};