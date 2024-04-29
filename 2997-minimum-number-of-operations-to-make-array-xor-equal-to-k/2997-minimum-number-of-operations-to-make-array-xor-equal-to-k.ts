function minOperations(nums: number[], k: number): number {
    return (nums.reduce((acc, c) => acc ^ c, 0) ^ k).toString(2).split('').filter(x => x === '1').length
};