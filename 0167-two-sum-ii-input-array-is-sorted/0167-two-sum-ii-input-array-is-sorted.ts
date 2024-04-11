function twoSum(numbers: number[], target: number): number[] {
    let left = 0, right = numbers.length - 1;
    
    while (left < right) {
        let temp = numbers[left] + numbers[right] - target
        if (temp == 0)
            return [left + 1, right + 1];
        else if (temp > 0)
            right--;
        else 
            left++;
    }
    
    return [0, 0];
};