//With ExtraSpace.
class Solution {
    set<vector<int>> result;
    vector<int> mCandidates;
    int mTarget = 0;

    void backtrack(int curr, vector<int> vcurr) {
        if (curr >= mTarget) {
            if (curr == mTarget) {
                sort(vcurr.begin(), vcurr.end());
                result.insert(vcurr);
            }
            return;
        }


        for (int i = 0; i < mCandidates.size(); i++) {
            vcurr.push_back(mCandidates[i]);
            backtrack(curr + mCandidates[i], vcurr);
            vcurr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        mTarget = target;
        mCandidates = candidates;
        vector<int> vcurr;
        backtrack(0, vcurr);
        vector<vector<int>> solution;
        for (vector<int> vii : result) {
            solution.push_back(vii);
        }
        return solution;

    }
};

//

class Solution {
    int mTarget = 0;

    void backtrack(int curr, vector<int> vcurr, int start, vector<int> &candidates, vector<vector<int>> &result) {
        if (curr >= mTarget) {
            if (curr == mTarget) {
                result.push_back(vcurr);
            }
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            vcurr.push_back(candidates[i]);
            backtrack(curr + candidates[i], vcurr, i, candidates, result);
            vcurr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        mTarget = target;
        vector<int> vcurr;
        vector<vector<int>> result;

        backtrack(0, vcurr, 0, candidates, result);
        return result;

    }
};