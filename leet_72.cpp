class Solution {
public:
    int ED[501][501];
    int done[501][501];
    int minDistance(string word1, string word2) {
        //recursive formulation
        //ED[i,j] = if word1[i] == word2[j] then ED[i-1][j-1]
        //          else min{ED[i-1][j] + 1, ED[i][j-1] + 1, ED[i-1][j-1] + 1}
        //basecase ED[0,0] = 0
        
        int s1 = word1.length();
        int s2 = word2.length();
        
        if(s1 == 0) return s2;
        if(s2 == 0) return s1;
        fill(&ED[0][0], &ED[s1][s2], 0);
        fill(&done[0][0], &done[s1][s2], 0);
        
        dp(word1, word2, s1, s2);
        return ED[s1][s2];
    }
    //ED : minedit until ith, jth string
    void dp(string word1, string word2, int i, int j){
        if(i == 0){
            ED[i][j] = j;
            done[i][j] = 1;
            return;
        }
        if(j == 0){
            ED[i][j] = i;
            done[i][j] = 1;
            return;
        }
        
        if(word1[i-1] == word2[j-1]){
            if(!done[i-1][j-1]) dp(word1, word2, i-1, j-1);
            ED[i][j] = ED[i-1][j-1];
            done[i][j] = 1;
        }
        else{
            if(!done[i-1][j-1]) dp(word1, word2, i-1, j-1);
            if(!done[i][j-1]) dp(word1, word2, i, j-1);
            if(!done[i-1][j]) dp(word1, word2, i-1, j);
            ED[i][j] = min(min(ED[i-1][j], ED[i][j-1]), ED[i-1][j-1]) + 1;
            done[i][j] = 1;
        }
    }
};
