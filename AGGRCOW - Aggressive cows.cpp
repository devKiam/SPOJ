#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


bool isPossible(ll mid, vector<ll> &v, ll cows)
{
    ll cowsStalled = 1, lastCowStalledAt = v[0]; // cow stalled at first position
    for(int i=1; i<v.size(); i++){
        if((v[i] - lastCowStalledAt) >= mid){
            lastCowStalledAt = v[i];
            cowsStalled++;
            if(cowsStalled == cows) return true;
        }
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int testCase; cin>>testCase;
    while(testCase--){
        int n, cows; cin>>n>>cows;
        vector<ll> v;
        for(int i=0; i<n; i++){
            int vectorInput; cin>>vectorInput; v.push_back(vectorInput);
        }
        sort(v.begin(), v.end());
        ll lo = 1, hi = v[v.size()-1], mid;

        while(lo < hi){
            mid = (lo + hi + 1) / 2;
            if(isPossible(mid, v, cows))
            {
                lo = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        cout<<lo<<endl;
    }

}
