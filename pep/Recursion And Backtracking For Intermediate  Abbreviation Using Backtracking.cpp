

// Time Complexity:
// O(2^N)

// Where N = length of the input string. As we are making two calls Yes / No at 
// every index until our pos index is equal to the length of the string, therefore 
// the complexity will be exponential and equal to 2 ^ N.


#include<bits/stdc++.h>
using namespace std;
    void solution(string str, string asf,int count, int pos)
    {
        // write your code here
        if(pos == str.length()){
            if(count==0){
                cout<<asf<<endl;
            }else{
                cout<<asf<<count<<endl;
            }
            return;
        }

if(count>0){
    solution(str,asf+to_string(count)+str[pos],0,pos+1);
}else{
    solution(str,asf+str[pos],0,pos+1);
}
    solution(str,asf,count+1,pos+1);

    }
	int main() {
        string str;
        cin >> str;
        solution(str,"",0,0);
        return 0;
    }