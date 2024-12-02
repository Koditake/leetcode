impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let words: Vec<&str> = sentence.split_whitespace().collect();
        
        for (i, word) in words.iter().enumerate() {
            if word.starts_with(&search_word) {
                return (i + 1) as i32;  // Return 1-based index
            }
        }
        
        -1
    }
}