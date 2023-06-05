#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

int compareItems(const void* a, const void* b) {
    struct Item* itemA = (struct Item*)a;
    struct Item* itemB = (struct Item*)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    if (ratioA < ratioB) {
        return 1;  // Sort in descending order of ratio
    } else if (ratioA > ratioB) {
        return -1;
    } else {
        return 0;
    }
}

double fractionalKnapsack(int n, struct Item items[], int capacity) {
    qsort(items, n, sizeof(struct Item), compareItems);

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(n, items, capacity);

    printf("The maximum value that can be obtained is: %f\n", maxValue);

    return 0;
}
