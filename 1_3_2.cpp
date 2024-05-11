//GCD recursive
#include <bits/stdc++.h>
using namespace std;

int GCD(int n1, int n2)
{
    if (n2 != 0)
        return GCD(n2, n1 % n2);
    else
        return n1;
}
int main()
{
    clock_t start, end;
    start = clock();
    int N1, N2, gcd;
    cout<<"Recursive Approach"<<endl;
    cout << "Enter First Number: ";
    cin >> N1;
    cout << "Enter Second Number: ";
    cin >> N2;
    gcd = GCD(N1, N2);
    cout << "GCD of " << N1 << " and " << N2 << " is " << gcd << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
