use std::collections::VecDeque;

impl Solution {
    pub fn is_n_straight_hand(mut hand: Vec<i32>, group_size: i32) -> bool {
        hand.sort_unstable();
        
        let mut p = 0;
        let mut v: VecDeque<(i32, bool)> = VecDeque::new();

        for n in hand {
            if n != p {
                if p > 0 && n > p + 1 && !v.is_empty() {
                    return false;
                } else {
                    for i in 0..v.len() {
                        if !v[i].1 {
                            return false;
                        }

                        v[i].1 = false;
                    }
                }
                
                p = n;               
            } 

            let mut f = false;
            
            if !v.is_empty() {
                for i in 0..v.len() {
                    if !v[i].1 {
                        v[i].1 = true;
                        v[i].0 += 1;

                        f = true;
                        break;
                    }
                }

                if v[0].0 == group_size {
                    v.pop_front();
                }
            }

            if !f {
                if group_size > 1 {
                    v.push_back((1, true));
                }
            }
        }        

        v.is_empty()
    }
}