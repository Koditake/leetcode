function tribonacci(n: number): number {
    if (n == 0) return 0;
        if (n < 3) return 1;
        let arr = [0,1,1];

        for (let i = 3; i <= n; i++) {
            arr[i % 3] = arr[0] + arr[1] +arr[2];
        }

        return arr[n % 3];
};