#include <bits/stdc++.h>
using namespace std;

struct myComp
{
    bool operator()(
        pair<int, int> a,
        pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
bool canReach(string from, string to)
{
    if (from.length() != to.length() || from == to)
        return false;
    int len = from.length();
    for (int i = 0; i < len; i++)
    {
        string fr = from;
        fr[i] = to[i];
        if (fr == to)
            return true;
    }
    return false;
}

int shortestEditPath(vector<string> words, string source, string target)
{
    vector<vector<int> > adj(words.size() + 1, vector<int>());
    int idx = -1;
    for (int i = 0; i < words.size(); i++)
    {

        if (words[i] == target)
        {
            idx = i;
            continue;
        }
        if (canReach(source, words[i]))
        {
            adj[0].push_back(i + 1);
            adj[i + 1].push_back(0);
        }
    }
  
    if (idx == -1)
    {
        return idx;
    }
    int INF = 1e9 + 8;
    vector<int> distance(words.size() + 1, INF);
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (i == j)
                continue;
            if (canReach(words[i], words[j]))
            {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }
      for(int i = 0; i <= words.size(); i++) {
        for(int xx: adj[i]) {
            cout << xx << " ";
        }
        cout << endl;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, myComp> q;
    q.push(make_pair(0, 0)); // {distance, vertex}
    distance[0] = 0;
    map<int, int> visited;
    while (!q.empty())
    {
        pair<int, int> next = q.top();
        q.pop();
        int dist = next.first;
        int vertex = next.second;
        if (visited.find(vertex) != visited.end())
            continue;
        visited[vertex] = 1;

        for (int child : adj[vertex])
        {
            if (distance[vertex] + 1 >= distance[child])
                continue;
            distance[child] = distance[vertex] + 1;
            q.push(make_pair(distance[child], child));
        }
    }
    if (distance[idx] == INF)
        return -1;
    return distance[idx];
}

int main()
{
    string source;
    cin >> source;
    string target;
    cin >> target;
    vector<string> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
    }
    cout << shortestEditPath(words, source, target);
}