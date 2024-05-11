//fibonacci recursive
#include <bits/stdc++.h>
using namespace std;

int Fib(int N) {
    if (N <2) {
        return N;
    }
     else
    {
        return Fib(N - 1) + Fib(N - 2);
    }
}

int main() {
    clock_t start, end;
    start = clock();
    int N;
    cout<<"Recursive approach"<<endl;
    cout << "Enter total numbers you want in Fibonacci series: ";
    cin >> N;
    cout << "Fibonacci Series is ";
    for (int i = 0; i < N; i++) {
        cout << Fib(i) << " ";
    }
    cout << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : "<< fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
