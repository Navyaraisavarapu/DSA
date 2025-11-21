int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void backtrack(int *nums, int numsSize, int *curr, int curidx, int remainingSum, int **res,
               int *returnSize, int **returnColumnSize, int idx) {
    if (remainingSum < 0) {
        return;
    } else if (remainingSum == 0) {
        res[(*returnSize)] = (int *)malloc(curidx * sizeof(int));
        for (int i = 0; i < curidx; i++) {
            res[(*returnSize)][i] = curr[i];
        }
        (*returnColumnSize)[(*returnSize)] = curidx;
        (*returnSize)++;
        return;
    }
    for (int i = idx; i < numsSize; i++) {
        if (i > idx && nums[i] == nums[i - 1]) continue;
        curr[curidx++] = nums[i];
        backtrack(nums, numsSize, curr, curidx, remainingSum - nums[i], res, returnSize,
                  returnColumnSize, i + 1);
        curidx--;
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize,
                      int **returnColumnSizes) {
    *returnSize = 0;
    int **res = (int **)malloc(1024 * sizeof(int));
    *returnColumnSizes = (int *)malloc(1024 * sizeof(int));
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int *curr = (int *)malloc(128 * sizeof(int));
    backtrack(candidates, candidatesSize, curr, 0, target, res, returnSize, returnColumnSizes, 0);
    return res;
}