#include<stdio.h>
#include <math.h>
float square_root(int n, int p) {
        float ans;
        int s = 0, e = n;
        while(s<=e){
                int mid = (e+s)/2;
                if (mid * mid == n){
                        ans = mid;
                        break;
                }
                else if (mid * mid < n){
                        ans = mid;
                        s = mid+1;
                }
                else{
                        e = mid-1;
                }
        }
        float decimal = 0.1,mul=1;
        for(int i=1;i<=p;i++){
                while(ans * ans <= n){
                        ans+=decimal;
                }
                mul = mul*10;
                ans-=decimal;
                decimal/=10;
        }
        float val = round(ans*mul)/mul;
    return val;
}
int main ( void ) {
        int n, p;
        scanf ("%d %d", &n, &p);
        printf("%g", square_root(n, p));
        return 0;
}
