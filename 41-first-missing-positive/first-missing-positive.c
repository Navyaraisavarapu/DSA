int firstMissingPositive(int* nums, int numsSize) {
    //Step 1: replacing negitive values in the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 1) {
            nums[i] = numsSize + 1;
        }
    }
    // Step 2: Use indices to mark the presence of numbers

    for (int i = 0; i < numsSize; i++) {
        int val = abs(nums[i]);
        if (val >= 1 && val <= numsSize) {
            nums[val - 1] = -abs(nums[val - 1]);
        }
    }
    //Step 3: checking for the first elements missing
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    //No elemnet is missing so were returning len(nums)+1
    return numsSize + 1;
}