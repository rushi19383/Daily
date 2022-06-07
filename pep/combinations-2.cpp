#include<bits/stdc++.h>
using namespace std;
int nboxes;
void combinations(bool boxes[],int ci,int ti,int llb){
    if(ci>ti){
        for(int i=0;i<nboxes;i++){
            if(boxes[i]==true){
                cout<<"i";
            }else{
                cout<<"-";
            }
        }
        cout<<endl;
        return;
    }
    for(int b=llb+1;b<nboxes;b++){
        if(boxes[b]==false){
            boxes[b]=true;
            combinations(boxes,ci+1,ti,b);
            boxes[b]=false;
        }
    }
}

int main(){
    
    cin>>nboxes;
    int ritems;
    cin>>ritems;
    
    
    bool arr[nboxes];
    memset(arr,false,sizeof(arr));
    combinations(arr,1,ritems,-1);
}