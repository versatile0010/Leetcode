class Solution {
public:
    int arraySign(vector<int>& nums) {
        int positive_cnt = 0; int negative_cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) return 0;
            else if (nums[i] > 1) positive_cnt++;
            else if (nums[i] < 0) negative_cnt++;
        }
        if (negative_cnt % 2 == 1) return -1;
        else return 1;
    }
};