#include<stdio.h>
#include<stdlib.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

void printJobScheduling(struct Job job[], int n){
    for (int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i -1; j++){
            if(job[j].profit < job[j+1].profit){
                struct Job temp = job[j];
                job[j] = job[j + 1];
                job[j + 1] = temp;
            }
        }
    }


    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (job[i].deadline > maxDeadline)
        {
            maxDeadline = job[i].deadline;
        }
        
    }
    

    int slot[100];
    for(int i = 0; i < maxDeadline; i++){
        slot[i] = 0;
    }

    int scheduledCount = 0;
    int totalprofit = 0;

    for(int i = 0; i <n; i++){
        for(int j = job[i].deadline - 1; j >= 0; j--){
            if (slot[j] == 0)
            {
                slot[j] = job[i].id;
                scheduledCount++;
                totalprofit += job[i].profit;
                break;
            }
            
        }
    }

    printf("Scheduled Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != 0) {
            printf("%d ", slot[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalprofit);

}



int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job job[n];

    for(int i = 0; i < n; i++){
        printf("Enter the deadline and profit of job %d: ", i + 1);
        scanf("%d %d", &job[i].deadline, &job[i].profit);
        job[i].id = i + 1;
    }

    printJobScheduling(job, n);

    return 0;
}
