#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans=INT_MIN,f_prod=1,b_prod=1,i=0;
    while (i<n) {
        if (v[i]==0)f_prod=1;
        if (v[n-i]==0)b_prod=1;
        f_prod*=v[i];
        b_prod*=v[n-i-1];
        ans =max(ans,max(f_prod,b_prod));
        i++;
    }
    cout<<ans<<endl;
    return 0;
}