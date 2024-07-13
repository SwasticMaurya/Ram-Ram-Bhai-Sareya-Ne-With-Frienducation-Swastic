class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> game(n * n);
        int ind = 0;
        bool flag = true;
        for (int i = n - 1; i >= 0; i--) {
            if (flag) {
                for (int j = 0; j < n; j++) {
                    game[ind++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    game[ind++] = board[i][j];
                }
            }
            flag = !flag;
        }
        vector<int> dis(n * n, -1);
        queue<int> q;
        q.push(0);
        dis[0] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == n * n - 1) {
                return dis[cur];
            }
            for (int i = 1; i <= 6; i++) {
                int next = cur + i;
                if (next >= n * n) {
                    continue;
                }
                if (game[next] != -1) {
                    next = game[next] - 1;
                }
                if (dis[next] == -1) {
                    dis[next] = dis[cur] + 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};