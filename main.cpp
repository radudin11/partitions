#include <iostream>
using namespace std;

char spaces[]="               ";
//print all partition of a set with n numbers

int solution[20], n, numbrOfSolutions=0, maximum[20];
//initial method
/*int DeterminareMaxim(int k)
{  int maxim=0,i;
    for(i=1;i<=k;i++)
        if (x3[i]>maxim) maxim=x3[i];
    return maxim;
}*/
//using an array to memorize the max
void PrintFor(int maxi)
{
    int i,j;
    cout<<spaces;
    //maxim=DeterminareMaxim(n3);
    for(j=1; j<=maxi; j++)
    {
        cout<<"{";
        for(i=1; i<=n; i++)
            if (solution[i]==j) cout<<i<<" ";
        cout<<"}  ";
    }
    cout<<endl;
    numbrOfSolutions++;
}

void Back(int k)
{
    int i;
    for(i=1; i<=maximum[k-1]+1; i++)
    {
        solution[k]=i;
        maximum[k] = max(maximum[k-1], i);
        if (k==n) PrintFor(maximum[k]);
        else Back(k+1);
    }
}

int main()
{
    cout<<endl<<endl<<spaces<<"Partitions of the set: {1,2,3.....,n}"<<endl;
    cout<<endl<<spaces<<" Give value for n: ";
    cin>>n;
    cout<<endl;
    Back(1);
    cout<<endl<<spaces<<"Number of solutions found: "<<numbrOfSolutions;
    return 0;
}
