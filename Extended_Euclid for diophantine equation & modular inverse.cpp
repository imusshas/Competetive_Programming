#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class EXTENDED_EUCLID {
    // To solve linear equation
    // To find inverse of a number
    public:
    ll x, y, d;
    void extended_euclid (ll a, ll b) {
        if(b==0) {
            x=1;
            y=0;
            d=a;
            return;
        }

        extended_euclid(b, a%b);
        ll x1=y;
        ll y1=x - (a/b)*y;
        x=x1;
        y=y1;
    }

    /// DIOPHANTINE EQUATION

    // ax + by = c

        // Let a & b are integers with d=gcd(a,b)
        // If d|c (d is a factor of c) is not true then no solution 
        // But if d|c is true then the equation has infinitely many solutions
        /* Using extended_euclid we will find (x0, y0) & the rest of solution can be found by
        * x=x0*c, y=y0*c;
        * a*x0*c + b*y0*c = c;
        * xn= x + (b/d)*n, yn= y + (a/d)*n; n=[0, 1, 2, 3, ...]
        * From the equilty x + (b/d)*n>=0 && y + (a/d)*n>=0 find n
        * Now find xn & yn.
        */

    // Find x & y from 25x + 18y = 839

        /*
            a=25, b=18
            From extended_euclid we find x=-5, y=7;

            a * (-5) + b * 7 = gcd (a, b) = d;
            25 * (-5) + 18 * 7 = gcd(25,18) = 1;
            Multiply both sides c/gcd(a,b)
            25 * (x0= (-5) * 839 ) + 18 * (y0= 7 * 839) = 839
            25 * (-4195) + 18 * 5873 = 839
            x= x0 + (b/d)*n , y= y0 - (a/d)*n 

            -4195 + (18/1)*n >=0 && 5873 - (25/1)*n >=0
            4195/18<=n<=5873/25
            n=234
            
            x= -4195 + 18 * 234 = 17, y= 5873 - 25*234 = 13

            Ans:
                x= 17
                y= 13
        */

    pair<ll,ll> diaphantine_euqation (ll a, ll b, ll c) {
        extended_euclid(a, b);
        if(c%d) {
            return {-1, -1};
        }
        ll x0= abs(x*c), y0=abs(y*c), n=y0/a;
        ll ansx=x*c + (b/d)*n, ansy=y*c - (a/d)*n;
        return {ansx, ansy}; 
    }

    /// MODULAR_INVERSE
        /*
        A (cngruence) C%M means A%M == B%M
        M|(A-C) M is a factor of (A-C);
        A*A^-1 = 1
        (A * B^-1)%M = ( (A%M) * ((B^-1)%M) )%M // But this is only possible iff gcd(B,M)=1;
        */

        //Find modular inverse of a with respect to m.
        /*
        x is modular inverse of a if a*x (cogruence) 1%m
        ax + by = gcd (a, b);
        ax + my = gcd (a, m);
        ax + my = 1 
            // taking modulo m on both sides 
        (ax)%m + (my)%m = 1%m
        (ax)%m + 0 = 1%m
        (ax)%m = 1%m 
        */

        // To find modular inverse of A with respect to M call extended_euclid (A, M)
        // -> Then x will be the modular multiplicative inverse of A

        // Use ->
            // (nCr)%p = (n!/(r!*(n-r)!))%p
            //         = ((n!%p)*(r^-1)%p*((n-r)^-1)%p)%p

}; 

int main() {
    EXTENDED_EUCLID exeu;
    // exeu.extended_euclid(25, 18);
    // cout<<exeu.x<<" "<<exeu.y<<"\n";
    pair<ll,ll> p = exeu.diaphantine_euqation(25, 18, 839);
    //cout<<p.first<<" "<<p.second<<"\n";
    exeu.extended_euclid(12, 7);
    cout<<exeu.x<<"\n";
    return 0;
}
