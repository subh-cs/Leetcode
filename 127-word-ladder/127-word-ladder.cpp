class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //all elements from wordlist now in set, which increases our checking efficiency
        unordered_set<string>dt(begin(wordList),end(wordList));
        int count=1;queue<string>q;
        q.push(beginWord);
        //
        while(!q.empty()){
            int n = q.size();
            for(int k=0;k<n;k++){
            string top = q.front();q.pop();
            dt.erase(top);
            if(top==endWord) return count;
            //search for each elements of the array
            for(int i=0;i<top.size();++i){
                char temp = top[i];
                //check for each alphabet
                for(int j=0;j<26;++j){
                    top[i]='a'+j;
                    if(dt.count(top)==1)
                        q.push(top);
                }
                top[i]=temp;
                }
            }
        count++;
        }
    return 0;
    }
};