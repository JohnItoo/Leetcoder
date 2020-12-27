class Solution
{
public:
    struct myComp
    {
        bool operator()(
            pair<int, int> const &a,
            pair<int, int> const &b)
            const noexcept
        {
            if (a.first == b.first)
            {
                return a.second < b.second; //bigger
            }
            return a.first > b.first; //smaller
        }
    };
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        int n = apples.size();
        if (n < 1)
            return n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        int i = 0;
        int eaten = 0;
        while (i < n)
        {
            if (apples[i] != 0)
                pq.push(make_pair(i + 1 + days[i], apples[i]));
            while (!pq.empty() && (pq.top()).first <= i + 1)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                pair<int, int> use = pq.top();
                pq.pop();
                if (use.second - 1 > 0)
                    pq.push(make_pair(use.first, use.second - 1));
                eaten++;
            }
            i++;
        }
        int last = n + 1;
        while (!pq.empty())
        {
            while (!pq.empty() && (pq.top()).first <= last)
            {
                pq.pop();
            }
            if (pq.empty())
                continue;
            int mn = min(pq.top().first - last, pq.top().second);
            last += mn;
            eaten += mn;
        }
        return eaten;
    }
};