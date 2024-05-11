//GCD iterative
#include <bits/stdc++.h>
using namespace std;

void GCD()
{
	int N1, N2, i, Minimum;
    cout<<"Iterative Approach"<<endl;
	cout << "Enter first numbers: ";
	cin >> N1;
	cout << "Enter second numbers: ";
	cin >> N2;
	Minimum = min(N1, N2);
	for (i = Minimum; i >= 0; i++)
	{
		if (N1 % i == 0 && N2 % i == 0)
		{
			break;
		}
	}
	cout << "GCD of " << N1 << " and " << N2 << " is " << i << endl;
}

int main()
{
	clock_t start, end;
	start = clock();
	GCD();
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
	cout << " sec " << endl;
	return 0;
}
