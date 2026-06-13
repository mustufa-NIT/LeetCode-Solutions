/* IS QUESTION KO DUBARA KARENGE YA MUJE NAH ATA RECURSION +MEMOIZATION TO KAR DIYA THA PER INKA ACTUAL SOLUTION O(N LONG N) HAI */
class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(),
        [](vector<int>& a, vector<int>& b){

            if(a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        });

        vector<int> LIS;

        for(auto &it : envelopes) {

            int height = it[1];

            auto idx = lower_bound(LIS.begin(), LIS.end(), height);

            if(idx == LIS.end()) {
                LIS.push_back(height);
            }
            else {
                *idx = height;
            }
        }

        return LIS.size();
    }
};
