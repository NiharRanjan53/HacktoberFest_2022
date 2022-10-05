class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int start = 0; start < board.size(); ++start)
            for(int end = 0; end < board[i].size(); ++end)
                
                if(board[start][end] != '.')
                {
                    int num = board[start][end] - '0' - 1;
                    int k = start / 3 * 3 + end / 3;
                    if(used1[start][num] || used2[end][num] || used3[k][num])
                        return false;
                    
                    used1[start][num] = used2[end][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};