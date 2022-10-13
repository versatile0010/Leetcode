class Solution {
public:
    string swap_string(string &s, int x, int y) {
        char temp_char; string temp = s;
        temp_char = temp[x];
        temp[x] = temp[y];
        temp[y] = temp_char;
        return temp;
 }

    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        string temp = ""; bool ans = false;
        for (int i = 0; i < s1.length()-1; i++) {
            temp.clear();
            for (int j = i+1; j < s1.length(); j++) {
                temp = swap_string(s2, i, j);
                if (temp == s1) {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
};