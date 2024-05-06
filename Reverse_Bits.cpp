class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result =0;
        int i =0;
        while(i<32){
           int lsb = n&1;
            int Rlsb = lsb << (31-i);
            result |=Rlsb;
            n >>=1; 
            i++;
        }
        return result;
    }
};
