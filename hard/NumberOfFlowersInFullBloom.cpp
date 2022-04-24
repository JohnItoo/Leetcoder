class Solution
{
    using ll = long long;

public:
    vector<int> fullBloomFlowers(vector<vector<int> > &flowers, vector<int> &persons)
    {
        set<int> times;
        map<int, int> timesVals, resVals;

        int n = flowers.size();
        for (int i = 0; i < n; i++)
        {
            int from = flowers[i][0];
            int to = flowers[i][1];
            times.insert(from);
            times.insert(to + 1);
            timesVals[from]++;
            timesVals[to + 1]--;
        }
        ll sol = 0;
        for (auto &[k, v] : timesVals)
        {
            sol += v;
            resVals[k] = sol;
        }

        vector<int> res;
        for (auto &person : persons)
        {
            auto it = times.lower_bound(person);
            if (it == times.end())
            {
                res.push_back(sol);
            }
            else
            {
                if (*it == person)
                {
                    res.push_back(resVals[person]);
                }
                else
                {
                    if (it == times.begin())
                    {
                        res.push_back(0);
                    }
                    else
                    {
                        --it;
                        res.push_back(resVals[*it]);
                    }
                }
            }
        }
        return res;
    }
};