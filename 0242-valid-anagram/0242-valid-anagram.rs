impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut char_counts = [0; 26]; // Initialize array for character counts

        for c in s.chars() {
            char_counts[c as usize - 97] += 1; // Increment count for current char
        }

        for c in t.chars() {
            char_counts[c as usize - 97] -= 1; // Decrement count for characters in t
            if char_counts[c as usize - 97] < 0 {
                return false;
            }
        }

        true
    }
}