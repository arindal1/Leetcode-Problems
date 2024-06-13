class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rn = 0;
        for (int i = 0; i < 32; ++i)
            if (n >> i & 1)
                rn |= 1 << 31 - i;
        return rn;
    }
};
