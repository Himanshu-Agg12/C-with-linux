/*
 * Program to print square root of a number upto given precission without using sqrt operator
 *
 * @Himanshu Aggarwal    id-> 1911981022
 * 17/7/2021
 * Assignment -> 1
 */

#include <stdio.h>

float square_root (int n, int p) {
        
        //it stores final answer
        float ans;
        
        //s -> start and e -> end
        int s = 0, e = n;
        
        //Binary search for finding number
        while ( s<=e ) {
                int mid = ( e+s )/2;
                
                //if perect square
                if ( mid * mid == n){
                        ans = mid;
                        break;
                }
                
                //if number become greater then mid^2
                //also we are storing the nearest value if the number is not perfect square.
                else if (mid * mid < n){
                        s = mid+1;
                        ans = mid;
                }
                
                //if number becom less
                else {
                        e = mid-1;
                }
        }
        
        //for finding precission
        float decimal = 0.1;
        for ( int i = 1; i <= p; i++){
                //while ans^2 less then n we increase 0.1 each time
                while ( ans * ans <= n){
                        ans+=decimal;
                }
                //subtracting for removing the extra addition
                ans-=decimal;
                //now it becomes 0.01 and so on till reaches upto p.
                decimal/=10;
        }
        //returning answer
        return ans;
}
int main ( ) {
        //scaning inputs.
        int n, p;
        
        scanf ( "%d %d", &n, &p );
        //here * is for knowing upto what precission we want to print
        //otherwise it will print upto 6 precissionbecause of float.
        printf ( "%.*f\n", p, square_root(n, p) );
        return 0;
}
