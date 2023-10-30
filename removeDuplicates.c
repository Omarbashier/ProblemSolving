#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i, j = 0;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }

    return j + 1;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newSize = removeDuplicates(nums, numsSize);

    printf("New array after removing duplicates:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}