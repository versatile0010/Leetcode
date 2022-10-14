class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> hp;
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty()) {
                if (st.top() < nums2[i]) {
                    hp.insert({ st.top(), nums2[i] });
                    st.pop();
                }
                else
                    break;
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (hp.count(nums1[i])) {
                ans[i] = hp[nums1[i]];
            }
            else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};