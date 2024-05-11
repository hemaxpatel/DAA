//fibonacci iterative
#include <bits/stdc++.h>
using namespace std;

void Fib()
{
    int N1 = 0, N2 = 1, sum, N;
    sum = N1 + N2;
    cout<<"Iterative approach"<<endl;
    cout << "Enter total numbers you want in Fibonacci series: ";
    cin >> N;
    if (N == 1)
    {
        cout << "Fibonacci Series is " << N1;
    }
    else if (N == 2)
    {
        cout << "Fibonacci Series is " << N1 << " " << N2;
    }
    else
    {
        cout << "Fibonacci Series is " << N1 << " " << N2 << " " << sum << " ";
        for (int i = 3; i < N; i++)
        {
            N1 = N2;
            N2 = sum;
            sum = N1 + N2;
            cout << sum << " ";
        }
        cout << endl;
    }
}

int main()
{
    clock_t start, end;
    start = clock();
    Fib();
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
