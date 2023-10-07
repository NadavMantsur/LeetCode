#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store name and height
struct Person {
    char* name;
    int height;
};

// Helper function to compare two persons by height
int compareByHeight(const void* a, const void* b) {
    return ((struct Person*)b)->height - ((struct Person*)a)->height;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // Create an array of Person structures
    struct Person* people = (struct Person*)malloc(namesSize * sizeof(struct Person));
    for (int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    // Sort the people array in descending order by height
    qsort(people, namesSize, sizeof(struct Person), compareByHeight);

    // Allocate memory for the result array
    char** res = (char**)malloc(namesSize * sizeof(char*));

    // Copy the sorted names into the result array
    for (int i = 0; i < namesSize; i++) {
        res[i] = people[i].name;
    }

    // Set the return size
    *returnSize = namesSize;

    // Free the dynamically allocated memory for the Person array
    free(people);

    return res;
}

int main() {
    char* names[] = {"John", "Alice", "Bob", "Eve"};
    int heights[] = {180, 165, 175, 160};
    int namesSize = sizeof(names) / sizeof(names[0]);
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int returnSize;

    char** sortedNames = sortPeople(names, namesSize, heights, heightsSize, &returnSize);

    printf("Sorted Names by Height:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", sortedNames[i]);
    }

    free(sortedNames);

    return 0;
}
