impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        match word.split_once(ch) {
            Some((pre, post)) => {
                ch.to_string() +
                &pre.chars().rev().collect::<String>() +
                post
            }
            None => word
        }
    }
}