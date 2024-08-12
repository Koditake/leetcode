func characterReplacement(s string, k int) int {
    l := 0
    w_l := 0
    w_c := 0
    veca := [26]int{};
    
    for r := 0; r < len(s); r++ {
        veca[s[r] - 'A']++;
        w_c = max(w_c, veca[s[r] - 'A']);
        if (r - l + 1 - w_c > k) {
            veca[s[l] - 'A']--;
            l++;
        }
        w_l = max(w_l, r - l + 1);
    } 
    return w_l;
}