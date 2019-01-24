/* 
    Assume input is a/b
    Convert both a and b to positive. Keep track
    how many were negative before.
    Start from largest bit and check if shifting the
    divisor additional i bits left is less than or equal to
    a (if it is greater that cannot divide more). Keep track of 
    how much we shift on b and upate the quotient. Assign what sign
    that we decided in the beginning. When returning, check for 
    the bounds. 
*/

int divide(int dividend, int divisor) {
    
    long long a = dividend;
    long long b = divisor;
    long long q = 0;
    long long k = 1;
    unsigned int count = 0;
    
    
    /* 0 is pos, 1 is neg */
    int is_neg_a = 0;
    int is_neg_b = 0;
    int is_neg_all = 0;
    
    /* check initial signs */
    if (a < 0){
        is_neg_a = 1;
        is_neg_all = 1;
        a = -a;
    }
    if (b < 0){
        is_neg_b = 1;
        is_neg_all = 1;
        b = -b;
    }
    if (is_neg_a == 1 && is_neg_b == 1){
        is_neg_all = 0;
    }
    
    /* assuming 32-bit signed integers */
    for (int i = 31; i > -1; i--){
         /* check if can shift left. Should be less than dividend */
        if ( (count + (b << i)) <= a){
            count += (b << i);
            q |= (k << i);
        }
    }
    
    /* check for sign */
    if (is_neg_all == 1){
        q = -q;
    }
    
    /* check for overflow */
    return (q >= INT_MAX || q < INT_MIN) ? INT_MAX : q;
        
    
}
