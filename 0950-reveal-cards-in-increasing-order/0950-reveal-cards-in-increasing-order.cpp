class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Sort the deck in descending order
        sort(rbegin(deck), rend(deck)); 
        
        // Initialize a deque to simulate the card revealing process
        deque<int> dq; 
        int n = deck.size(); 
        
        // Initialize deque with the largest card
        dq.push_front(deck[0]); 
        
        // Simulate the revealing process; start from 1 since deck[0] was in the deque
        for (int i = 1; i < n; i++) {
            // Take the top card from the back of the deque
            int x = dq.back();
            // Remove this card from the deque
            dq.pop_back();
            // Place this revealed card at the front of the deque
            dq.push_front(x);
            // Add the current card from the sorted deck to the front of the deque
            dq.push_front(deck[i]);
        }
        
        // Retrieve the revealed cards in increasing order
        vector<int> res;
        
        while(!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
        }
        
        // Return the ordered deck
        return res;
    }
};