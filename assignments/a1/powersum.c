#include <stdio.h>

/**
 * Depect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n){

    int result = 1;
    int overflow = 0;
    int count = n;

    while (count > 0){
        if (result > 2147483647 / b){
            overflow = 1;
            break;
        }
    
        result = result * b;
        count -= 1;

        }
    
    return overflow;

}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n){
    int count = n; 
    int result = 1;
    while (count > 0){
        if (result > 2147483647 / b){ 
            return 0;
        }
        result = result * b;
        count -= 1;
    }

    return result;

} 


/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n){
    int result = 0;
    int curr = 1;

    for (int i = 0; i <= n; i ++){
        if (result > 2147483647/b){ 
            return 0;
        }
        curr = curr * b;
        result = result + curr;

    }

    return result;


} 
