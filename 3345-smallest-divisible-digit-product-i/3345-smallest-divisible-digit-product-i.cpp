class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp =   n;
        int num = 1;
        while(true){
            while(n > 0){
                num*= n%10;
                n = n / 10;
            }
            if(num % t == 0) return temp;
            temp++;
            n = temp;
            num = 1;
        }
        return num;
    }
};