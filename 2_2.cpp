//insertion sort
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void Display(int A[],int n);
void Insertion_sort(int A[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key = A[i];
        j = i - 1;
        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = key;
    }
    Display(A,n);
}

void Display(int A[],int n)
{
    cout<<"Sorted Array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int N;
    cout<<"Enter array size: ";
    cin>>N;
    int Array[N];
    cout<<"Enter array: ";
    for(int i=0;i<N;i++)
    {
        cin>>Array[i];
    }
    time_t start, end; 
	time(&start); 

	ios_base::sync_with_stdio(false); 

	Insertion_sort(Array,N);

	time(&end);
    double time_taken = double(end - start); 
	cout << endl << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
	cout << " sec " << endl;  
    
    return 0;
}
