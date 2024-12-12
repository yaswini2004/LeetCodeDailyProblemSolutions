class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());

        while (k--) {
            pop_heap(gifts.begin(), gifts.end());

            int maxGift = gifts.back();
            gifts.pop_back();

            gifts.push_back(sqrt(maxGift));
            push_heap(gifts.begin(), gifts.end());
        }

        return accumulate(gifts.begin(), gifts.end(), 0LL);
        
    }
};