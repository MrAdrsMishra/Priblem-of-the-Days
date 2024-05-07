class Solution {
public:
   int divide(int dividend, int divisor) {
    // Handle special cases
    if (divisor == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return INT_MAX; // Return a large value indicating an error
    }
    if (dividend == INT_MIN && divisor == -1) {
        std::cerr << "Error: Overflow" << std::endl;
        return INT_MAX; // Return a large value indicating an error
    }

    // Determine the sign of the result
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Make both numbers positive (to handle INT_MIN correctly)
    long long dvd = labs(static_cast<long long>(dividend));
    long long dvs = labs(static_cast<long long>(divisor));

    // Initialize the quotient and result
    long long quotient = 0;
    long long result = 0;

    // Binary search for quotient
    for (int i = 31; i >= 0; --i) {
        if ((result + (dvs << i)) <= dvd) {
            result += (dvs << i);
            quotient |= (1LL << i); // Set ith bit of quotient
        }
    }

    // Apply the sign to the quotient
    return sign * quotient;
}
};
// another method

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0){
            return INT_MAX;
        }
        if(divisor ==1){
            return dividend;
        }
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
    int quotient = 0;
    int sign = ((dividend < 0)^(divisor < 0)) ? -1:1;
            int dvs = abs(divisor);
            int dvd = abs(dividend);
        while(dvd >= dvs){
            int temp = dvs;
            int count = 1;
            while(dvd >= (temp<<1)){
                temp <<= 1;
                count <<= 1;
            }
            dvd -= temp;
            quotient += count; 
        }
        return sign*quotient;
    }
};
