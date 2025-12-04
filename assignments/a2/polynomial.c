#define EPSILON 1e-6
#define MAX_ITER 100
/**
 * Compute and return the value of a polynomial of degree (n-1):
 *   p(x) = p[0]*x^{n-1} + p[1]*x^{n-2} + ... + p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm (see: https://en.wikipedia.org/wiki/Horner%27s_method).
 *
 * @param p Pointer to the array of coefficients (length n).
 * @param n Number of coefficients (degree + 1).
 * @param x Value at which to evaluate the polynomial.
 * @return The computed value p(x).
 */
float horner(float *p, int n, float x){

    
    float result = 0;
    for (int i = 0; i < n; i++){
        result = result * x +  p[i];
    }

    return result; 
}

/**
 * Compute the derivative of a polynomial of degree (n-1):
 *   p(x) = p[0]*x^{n-1} + p[1]*x^{n-2} + ... + p[n-2]*x^1 + p[n-1]*x^0
 * and store the coefficients of the derivative polynomial in array d.
 * The derivative is:
 *   p'(x) = (n-1)*p[0]*x^{n-2} + (n-2)*p[1]*x^{n-3} + ... + p[n-2]*x^0
 *
 * @param p Pointer to the array of input polynomial coefficients (length n).
 * @param d Pointer to the array for output derivative coefficients (length n-1).
 * @param n Number of coefficients in the input polynomial.
 */
void derivative(float *p, float *d, int n){
    for (int i = 0; i < n -1; i++){
        d[i] = p[i] * (n - 1 - i); 
      }

}

/**
 * Compute an approximate real root x of polynomial p(x) using Newton's method
 * (see: https://en.wikipedia.org/wiki/Newton%27s_method).
 * Uses a tolerance of 1e-6 and a maximum of 100 iterations.
 *
 * @param p Pointer to the array of input polynomial coefficients (length n).
 * @param n Number of coefficients in the input polynomial.
 * @param x0 Initial guess for the root.
 * @return The computed root if found; otherwise, returns x0.
 */
float newton(float *p, int n, float x0){
    float x = x0;
    float x_prev;
    float deriv[n-1];
    
    derivative(p, deriv, n);
    
    for (int i = 0; i < 100; i++){

        float curr = horner(p, n, x); 
        float curr_deriv = horner(deriv, n-1, x);

        if (fabs(curr_deriv) < EPSILON){
            break;
        }
        else{
            x_prev = x;
            x = x - curr/curr_deriv;

        if (fabs(curr) < EPSILON || fabs(x - x_prev) < EPSILON){ 
            break;
        }

        }
    
    }
    
    return x;
    
    

}