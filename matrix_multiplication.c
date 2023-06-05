#include<stdio.h>
#include<limits.h>

int matrixChain(int arr[], int i, int j){
    if (i == j)
    {
        return 0;
    }
    int k;
    int min = INT_MAX;
    int count;
    for(k = i; k < j; k++){
        count = matrixChain(arr,i,k) + matrixChain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if (count< min)
        {
            min = count;
        }
        
    }

    return min;
    
}

int main(){
    int n, i;
    printf("Enter the size of Array: ");
    scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("minimum no of multiplication is %d",matrixChain(arr,1,n-1));
    getchar();


}
