class Solution {
public:
    int passThePillow(int n, int time) {
        /*
            Since the pillow goes from one side of the array to the other,
            with n as the "oscillation"
            If 
                time/n = (2^n).x -> it is in the "positive" oscialltion direction
                time/n = (2^n + 1).x -> it is in the "negative" oscillation direction
            We find the position relative to the last known boundary.
        */
        
        time = time % ((n - 1) * 2) + 1;
        return min(time, n * 2 - time);
    }
};