using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        while(word1.size()!=0 || word2.size()!=0)
        {
            if(word1>=word2)
            {

                merge = merge+word1[0];
                word1.erase(word1.begin()+0);
            }
            else
            {
                merge = merge+word2[0];
                word2.erase(word2.begin()+0);
            }
        }      
        return merge;
    }
};