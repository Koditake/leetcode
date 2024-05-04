impl Solution {
    #[allow(dead_code)]
    #[cold]
    pub fn num_rescue_boats(people: Vec<i32>, limit: i32) -> i32 {
        if people.is_empty() {
            return 0;
        }

        let mut people = people.clone();
        people.sort_unstable();

        let (mut i, mut j, mut ans) = (people.len() - 1, 0, 0);
        while i >= j {
            ans += 1;
            if people[i] + people[j] <= limit {
                j += 1;
            }
            if i == 0 {
                break;
            }
            i -= 1;
        }

        ans
    }
}