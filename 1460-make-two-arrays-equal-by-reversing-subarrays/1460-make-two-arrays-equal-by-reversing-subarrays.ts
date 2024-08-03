function canBeEqual(target: number[], arr: number[]): boolean {
    target.sort()
    arr.sort()
    for (let i = 0; i < arr.length; i++) {
        if (target[i] != arr[i]) return false
    }
    
    return true
};