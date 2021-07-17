/*
 * Program to print square root of a number upto given precission without using sqrt operator
 *
 * @Himanshu Aggarwal    id-> 1911981022
 * 17/7/2021
 * Assignment -> 1
 * (Resource - gfg)
 */

#include <stdio.h>

float square_root (int n, int p) {
        float ans;
        int s = 0, e = n;
        while ( s<=e ) {
                int mid = ( e+s )/2;
                if ( mid * mid == n){
                        ans = mid;
                        break;
                }
                else if (mid * mid < n){
                        s = mid+1;
                        ans = mid;
                }
                else {
                        e = mid-1;
                }
        }
        float decimal = 0.1;
        for ( int i=1;i<=p;i++ ){
                while ( ans * ans <= n){
                        ans+=decimal;
                }
                ans-=decimal;
                decimal/=10;
        }
        return ans;
}
int main ( ) {
        int n, p;
        scanf ( "%d %d", &n, &p );
        printf ( "%.*f\n", p, square_root(n, p) );
        return 0;
}
