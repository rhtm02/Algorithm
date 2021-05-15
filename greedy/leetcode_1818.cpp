class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s1 = nums1; 
        sort(s1.begin(), s1.end()); 
        
        long ans = 0, bnft = 0; 
        for (int i = 0; i < nums1.size(); ++i) {
            //절대값을 구하고
            long term = abs(nums1[i] - nums2[i]); 
            //값을 더하면서
            ans += term; 
            //lower_bound를 사용하여 처음으로 nums2[i]의 값보다 크거나 같은 값 이터레이터 it 반환
            auto it = lower_bound(s1.begin(), s1.end(), nums2[i]); 
            //it값이 bnft를 최대화 시키는 값이 아님, 단순히 근사한 값 
            //그러므로 end()면 it값, 이전값 비교하여 bnft 값 갱신
            //begin()이면 it값만 확인하여 갱신
            //nums2[i]에서 가장 근사한 값과의 차이(*it - nums2[i]),(nums2[i] - *prev(it)) 
            //term = |nums1[i] - nums2[i]| 둘의 차이가 클수록 전체 총합의 크기는 작아짐
            //그 bnft를 maximaize하는게 목적
            if (it != s1.end())
                bnft = max(bnft, term - (*it - nums2[i]));
            if (s1.begin() != it) 
                bnft = max(bnft, term - (nums2[i] - *prev(it)));
        }
        //ans - bnft는 (그냥 총합 - 바꿈으로서 얻는 이득중 최대값)
        //조건에서 준 modulo 10^9 + 1의 나머지 구함 
        return (ans - bnft) % 1'000'000'007; 
    }
};