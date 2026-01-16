class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> maxHeap;
        long long totalSum = 0;
        for (int value : target) {
            totalSum += value;
            maxHeap.push(value);
        }
        while (maxHeap.top() != 1) {
            int largest = maxHeap.top();
            maxHeap.pop();
            long long remainingSum = totalSum - largest;
            if (remainingSum <= 0 || largest <= remainingSum) {
                return false;
            }
            int previousValue = largest % remainingSum;
            totalSum = remainingSum + previousValue;
            maxHeap.push(previousValue == 0 ? remainingSum : previousValue);
        }
        return true;
    }
};
