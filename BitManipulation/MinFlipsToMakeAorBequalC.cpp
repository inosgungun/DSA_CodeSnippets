/*

Right most bit = (num & 1)
eg. a = 1001  a & 1 = (1001 & 0001) = 1

Right shift = (a >>= 1)
a = 1001 --> 0100

*/

// Leetcode 1318
// Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;

        while(a != 0 || b != 0 || c != 0){
            if((c & 1) == 1){
               if((a & 1) == 0 && (b & 1) == 0){
                    flip++;
                }
            }
            if((c & 1) == 0){
                if((a & 1) == 1){
                    flip++;
                }
                if((b & 1) == 1){
                    flip++;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flip;
    }
};
