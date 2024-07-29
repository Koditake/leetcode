class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        // Tables for increasing and decreasing sequences
        vector<vector<int>> increasingTeams(n, vector<int>(4, 0));
        vector<vector<int>> decreasingTeams(n, vector<int>(4, 0));

        // Fill the base cases. (Each soldier is a sequence of length 1)
        for (int i = 0; i < n; i++) {
            increasingTeams[i][1] = 1;
            decreasingTeams[i][1] = 1;
        }

        // Fill the tables
        for (int count = 2; count <= 3; count++) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (rating[j] > rating[i]) {
                        increasingTeams[j][count] +=
                            increasingTeams[i][count - 1];
                    }
                    if (rating[j] < rating[i]) {
                        decreasingTeams[j][count] +=
                            decreasingTeams[i][count - 1];
                    }
                }
            }
        }

        // Sum up the results (All sequences of length 3)
        for (int i = 0; i < n; i++) {
            teams += increasingTeams[i][3] + decreasingTeams[i][3];
        }

        return teams;
    }
};