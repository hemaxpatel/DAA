//factorial iterative
#include <bits/stdc++.h>
using namespace std;

void factorial()
{
    int Num, fact = 1;
    cout << "Enter a number: ";
    cin >> Num;
    if (Num == 0 || Num == 1)
    {
        cout << "Factorial of " << Num << "through iterative approach is " << fact << endl;
    }
    else
    {
        for (int i = Num; i > 0; i--)
        {
            fact = fact * i;
        }
        cout << "Factorial of " << Num << " is " << fact << endl;
    }
}
int main()
{
    clock_t start, end;
    start = clock();
    factorial();
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
