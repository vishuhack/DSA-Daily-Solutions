class Solution {
public:
    bool checkDivisibility(int n) {
        int orgNum = n;
        int sum = 0;
        int prod = 1;
        while(n > 0){
            int temp = n % 10;
            n = n / 10;
            sum += temp;
            prod *= temp;
        }
        sum += prod;
        return orgNum%sum == 0 ? true : false;
    }
};