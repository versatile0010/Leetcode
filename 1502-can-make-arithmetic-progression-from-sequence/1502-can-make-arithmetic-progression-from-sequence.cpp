class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = 0; int check = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++) {
            diff = arr[i] - arr[i - 1];
            if (check != diff) return false;
        } return true;
    }
};