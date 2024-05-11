//binary searcch
#include <bits/stdc++.h> 
using namespace std; 
int Binary_Search(int *A,int U,int M,int L,int N) 
{ 
    int flag = 0;
	while(L<U)
    {
        if(A[M]>N)
        {
            U=M+1;
            M=(L+U)/2;
        }
        else if(A[M]==N)
        {
            flag=1;
            break;
        }
        else
        {
            L=M-1;
            M=(L+U)/2;
        }
    }
    if(flag==0)
    {
        cout<<"Number is not present"<<endl;
    }
    return M;
} 

int main() 
{ 
    int N;
    cout<<"Enter array size: ";
    cin>>N;
    int A[N];
    cout<<"Enter Array6: ";
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    int Upper=N-1,Lower=0,Mid=(Upper+Lower)/2;
    int Num,index;
    cout<<"Enter the number to be searched: ";
    cin>>Num;
	time_t start, end; 
	time(&start); 
	ios_base::sync_with_stdio(false); 

	index=Binary_Search(A,Upper,Mid,Lower,Num); 
    cout<<Num<<" is at index number "<<index<<endl;
	time(&end); 
    double time_taken = double(end - start); 
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
	cout << " sec " << endl; 
	return 0; 
}
