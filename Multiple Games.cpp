#include<bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main(){
    int txt;
    cin>>txt;
    while(txt--){
        int num,qnty,mul;
        cin>>num>>qnty>>mul;
        int a[num];
        for(int i=0;i<num;i++){
            cin>>a[i];
        }
        int ran[1000001] = {};
        map<pair<int,int>,int>mp;
        while(qnty--){
            int l,r;
            cin>>l>>r;
            --r;
            --l;
            if(a[l]>mul){
                continue;
            }
            else if(a[l]<=mul && a[r]>mul){
                ran[a[l]]++;
                ran[mul+1]--;
            }
            else if(a[r]<=mul){
                ran[a[l]]++;
                ran[mul+1]--;
                mp[{a[l],a[r]}]++;
            }
        }
        for(auto x:mp){
            int k = x.first.first;
            int p = x.first.second;
            int l = x.second;
            ran[p+k] -= l;
            ran[p+2*k] += l;
            int c = p+2*k;
            while(c+p <= mul){
                c = c + p;
                ran[c] = ran[c] - l;
                ran[c+k] = ran[c+k] + l;
                c = c + k;
            } 
        }   
        int maxi = 0;
        for(int i=1;i<=mul;i++){
            ran[i] = ran[i] + ran[i-1];
            maxi = max(maxi,ran[i]);
        }
        cout<<maxi<<endl;
    }
    return 0;
}