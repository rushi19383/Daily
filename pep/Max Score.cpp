// Time Complexity:
// The time complexity for the above solution is O(2n) where n is the number of input words.
//  This is because we have n words and every word has two choices i.e. to be included in the subset or not to be.
//  You might be thinking what about the validation that we applied? We are not generating 2n subsets, rather only
//  the valid ones. Actually, this is not completely true. Backtracking generates all the possible subsets and we
//  select the valid subsets from them. So, we are creating 2n subsets and hence the time complexity becomes 2n.

// Space Complexity:
// The space complexity of the above solution is O(h) where h is the height of the recursion stack and 
// O(1) without considering the recursion space as we have not used any extra memory other than recursion.


#include<bits/stdc++.h>
using namespace std;
int solve(vector<string> &words,vector<int> &freq,vector<int> &score,int idx){
  // base case...
    if(idx==words.size()){
        return 0;
    }
  // i m not including...
    int sno=solve(words,freq,score,idx+1);
    int syes=0,sword=0;
    bool flag=true;
  
    string word=words[idx];
    for(int i=0;i<word.size();i++){
        if(freq[word[i]-'a']==0){
            flag=false;
        }
        freq[word[i]-'a']--;
        sword+=score[word[i]-'a'];
    }
  
    if(flag){
        syes=sword+solve(words,freq,score,idx+1);
    }
  // for maintain frequency...
    for(int i=0;i<word.length();i++){
        freq[word[i]-'a']++;
    }
  // return max value...
    return max(syes,sno);
}
int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    int m;
    cin>>m;
    vector<char> letters(m);
    for(int i=0;i<m;i++){
        cin>>letters[i];
    }
    vector<int> score(26);
    for(int i=0;i<score.size();i++){
        cin>>score[i];
    }
    vector<int> freq(26);
    for(auto ch:letters){
        freq[ch-'a']++;
    }
    cout<<solve(words,freq,score,0);
    return 0;
}
