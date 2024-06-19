class Solution {
public:
    int flip(int n){
        auto str = to_string(n);
        std::reverse(str.begin(), str.end());
        return atoi(str.c_str());
    }
       
    bool isInteger(double v){
        double tmp;
        return std::modf(v, &tmp) == 0.0;
    }
    
    int largestPalindrome(int n) {
        
        if (n == 1) return 9;
        
        const long max = pow(10, n);
        
        for (int z = 2; z < max -1; z++){
            const long left = max -z;
            const long right = flip(left);
            const double sqrt_term = z*z - 4*right;

            if (sqrt_term < 0.0){ continue; }
            
            const double root1 = 0.5*(z + sqrt(sqrt_term));
            const double root2 = 0.5*(z - sqrt(sqrt_term));
            
            if (isInteger(root1) || isInteger(root2)){
                return (max*left + right) % 1337;
            }
        }
        return -1;
    }
};
