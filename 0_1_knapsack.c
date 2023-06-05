#include<stdio.h>
int max(int a, int b) {
   if(a>b){
      return a;
   } else {
      return b;
   }
}
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main() {
     int n;
     printf("Enter the size of Knapsack\n");
    scanf("%d",&n);
    int val[n];
    int W=50;
    int wt[50];
    printf("Enter Values\n");
    for(int i=1;i<=n;i++){
        printf("Enter Value no. %d\n",i);
        scanf("%d",&val[i]);
        printf("Enter Weight for corresponding value\n");
        scanf("%d",&wt[i]);
    }
   printf("The solution is : %d", knapsack(W, wt, val, n));
   return 0;
}
