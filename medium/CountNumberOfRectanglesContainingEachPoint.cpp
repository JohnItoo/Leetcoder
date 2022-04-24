class Solution
{
public:
    vector<int> countRectangles(vector<vector<int> > &rectangles, vector<vector<int> > &points)
    {
        int r = rectangles.size();
        int p = points.size();

        vector<vector<int> > vsi = vector<vector<int> >(105);
        for (int i = 0; i < r; i++)
        {
            int l = rectangles[i][0];
            int h = rectangles[i][1];
            vsi[h].push_back(l);
        }

        for (int i = 1; i <= 100; i++)
        {
            sort(vsi[i].begin(), vsi[i].end());
        }
        vector<int> result;
        for (int i = 0; i < p; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int ans = 0;
            for (int j = y; j <= 100; j++)
            {
                int sz = vsi[j].size();
                if (sz == 0)
                    continue;
                auto it = lower_bound(vsi[j].begin(), vsi[j].end(), x);
                if (it == vsi[j].end())
                    continue;
                int diff = it - vsi[j].begin();
                ans += sz - diff;
            }
            result.push_back(ans);
        }
        return result;
    }
};