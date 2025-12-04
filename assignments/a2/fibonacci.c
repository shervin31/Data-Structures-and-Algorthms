/**
 * your program signature
 */ 

#include "fibonacci.h"

/**
 *  add your comment
 */
int recursive_fibonacci(int n){
    if (n <= 0){ 
        return 0;
    }
    else if(n==1){ 
        return 1;
    }

    else{ 
        int f1 = recursive_fibonacci(n-1);
        int f2 = recursive_fibonacci(n-2); 
        if (f1 < 0 || f2 < 0 || f1 + f2 < 0){ 
            return -1;
        }
        else{ 
            return f1 + f2;
        }   
    }
}

/**
 *  add your comment
 */
int iterative_fibonacci(int n){

   if (n <= 1){ 
    return n; 
   }

   int f1 = 0, f2 = 1;
   for (int i = 2; i <= n; i++){
    if (f2 > 2147483647 - f1){
        return -1;
    }
    else{
    int temp = f2;
    f2 = f1 + f2; 
    f1 = temp;
    }
   }

   return f2;

} 

/**
 *  add your comment
 */
int dpbu_fibonacci(int *f, int n) {
    
    if (n <= 1){ 
        return n;
    }
    
    int f[0] = 0;
    int f[1] = 1;

    for (int i = 2; i <= n; i++){
        if (f[i-1] > 2147483647 - f[i-2]){ 
            return -1;
        }
        else{ 
            f[i] = f[i-1] + f[i -2];
        }

    }

    return f[n];


}

/**
 *  add your comment
 */
int dptd_fibonacci(int *f, int n){
    if (n <= 1){ 
        f[n] = n;
        return f[n];
    }

    else{ 
        int f1 = dptd_fibonacci(f, n-1); 
        int f2 = dpbu_fibonacci(f, n-2);
        if (f1 < 0 || f2 < 0 || f1 > 2147483647 - f2){ 
            return -1; 
        }
        else{ 
            f[n] = f1 + f2;
            return f[n]; 
        }
    }

}