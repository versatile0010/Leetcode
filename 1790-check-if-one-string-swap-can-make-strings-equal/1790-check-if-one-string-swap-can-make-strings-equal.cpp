// O(N)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // check frequency of characters
        vector<int> arr(26); int cnt = 0; // # of mismatched positions
        for (int i = 0; i < s1.length(); i++) {
            arr[s1[i] - 'a']++;
            arr[s2[i] - 'a']--;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) return false;
        }
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        return cnt == 0 || cnt == 2 ? true : false;
    }
};
