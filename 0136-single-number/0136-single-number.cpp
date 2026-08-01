class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR of all elements.
        // XOR Properties:
        // 1. x ^ x = 0  (same numbers cancel each other)
        // 2. x ^ 0 = x  (0 does not affect the result)
        // 3. XOR is commutative and associative:
        //    a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b

        int xorr = 0;

        for(int i = 0; i < nums.size(); i++) {
            // Keep XOR-ing every element.
            // Duplicate numbers become 0 and disappear.
            // The element appearing only once remains.
            xorr ^= nums[i];
        }

        // Only the unique element is left.
        return xorr;
    }
};