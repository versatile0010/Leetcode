
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
        int slow = n; int fast = getNext(n);
        while (fast!=1 && slow!=fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } return fast==1;
    }
};