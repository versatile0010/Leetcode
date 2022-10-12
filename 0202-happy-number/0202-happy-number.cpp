
class Solution {
private:
    int getNext(int n) {
        int next_num = 0;
        while (n > 0) {
            next_num += (n % 10) * (n % 10);
            n /= 10;
        }
        return next_num;
    }

public:
    bool isHappy(int n) {
        set<int> hmap;
        hmap.insert(n); int next_num = 0;
        while (n != 1) {
            next_num = getNext(n);
            if (hmap.count(next_num)) return false;
            hmap.insert(next_num);
            n = next_num;
        } return true;
    }
};