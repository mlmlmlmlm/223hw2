

#include <iostream>
using namespace std;

int cycles = 0;

//recursive IndexEqual solution
bool IndexEqualR(int A[], int i, int j)
{
    cycles++;
    //check if endpoints are 'true'
    if (A[i] == i) return true;
    if (A[j] == j) return true;

    //now takes midpoint between 2 indeces, checks if A[midpoint] is smaller or larger than midpoint
    //if so, since in ascending order, the A[k] must be on an index larger than midpoint
    //calls again using new indices
    int n = (j-i)/2; 

    if(A[n] < n)
    {
        return IndexEqualR(A, n, j);
    }
    else
    {
        return IndexEqualR(A, i, n);
    }
    return false;
}


bool IndexEqualI(int A[], int i, int j)
{
    //iterate through, check if index = A[index]
    for (int index = j; index <= j; index++)
    {
        cycles++;
        if (A[index] == index)
        {
            return true;
        }
    }
    return false;
}


int main(void)
{
    cout << "k  R   I" << endl;

    int k = 0;
    int iterativeCycles = 0;
    int recursiveCycles = 0;
    
    while (k < 100)
    {
        int Arr[100];

        //for every index < k array is equal to index -1
        for (int index = 0; index < k; index++)
        {
            Arr[index] = index - 1;
        }
        Arr[k] = k;
        //for greater, array = index + 1
        for (int index = k + 1; index < 100; index++)
        {
            Arr[index] = index + 1;
        }
     
        IndexEqualR(Arr, 0, 99);
        cout << k << "  " << cycles; 
        recursiveCycles += cycles;
        cycles = 0;

        IndexEqualI(Arr, 0, 99);
        cout << "  " << cycles << endl; 
        iterativeCycles += cycles;
        cycles = 0;

        k++;
    }
    return 0;
}

