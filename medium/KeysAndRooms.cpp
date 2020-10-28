class Solution {
    int ct = 0;
    map<int, int> visited;

private: void dfs(int curr, vector<vector<int>>& rooms) {
        visited[curr] = 1;
        ct++;
        for (auto it : rooms[curr]) {
            if (visited.find(it) != visited.end()) continue;
            dfs(it, rooms);
        }

    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(0, rooms);
        return ct == rooms.size();

    }
};