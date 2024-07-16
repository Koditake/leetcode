// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long    l = 0,
            r = n;
    while (l < r) {
        int m = l + (r - l)/2;
        
        if (isBadVersion(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}