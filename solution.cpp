// C++ program to count all distinct binary strings without two consecutive 0's

#include <iostream>
#include <math.h>       /* pow */
using namespace std;

long long int mod;	/*  10^9+7  */

long long int countStrings(int n)
{
    long long int a[10], b[10];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i%10] = (a[(i-1)%10] + b[(i-1)%10])%mod;	// modulo 10 is done to save memory
        b[i%10] = a[(i-1)%10]%mod;			// Since these numbers can be very large, so modulo mod(10^9+7) is done
    }
    return a[(n-1)%10] + b[(n-1)%10];
}
 

int main()
{
    int t;
    long long int n;
    mod= pow(10,9)+7;
    cin >> t;
    if(t>=1 && t<=1000)
	{
    	while(t--)
	{
	 cin >> n;
	 if(n<= pow(10,15) && n>=1)
   		 cout << countStrings(n) << endl;
	 else 
		return 0;
	}
	}
    return 0;
}
