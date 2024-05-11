//factorial recursive
#include <bits/stdc++.h>
using namespace std;

int Factorial(int N)
{
    if(N==0 || N==1)
    {
        return 1;
    }
    else
    {
        return N*Factorial(N-1);
    }
}

int main()
{
	clock_t start, end;
	start = clock();
      int Num,fact;
      cout << "Enter a number: ";
      cin>>Num;
	fact=Factorial(Num);
      cout<<"Factorial of "<<Num<<" through recursive approach is "<<fact<<endl;
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(5);
	cout << " sec " << endl;
	return 0;
}
