#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    
    vector<pair<int,int>> nums(n);
    map<int,int> position_num;
    for(int i=0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second = i+1;
        position_num[i+1] = nums[i].first-1;
    }

    sort(nums.begin(),nums.end());

    int rounds =1;
    for(int i=1;i<n;i++){
        if(nums[i].second < nums[i-1].second) rounds++;
    }

    while(m--){
        int a,b;
        cin >> a >> b;

        int num_a = position_num[a], num_b = position_num[b];

        bool sla = false;
        if(num_b <  num_a){
            swap(num_a,num_b);
            sla= true;
        }


        bool flag=false;
        if(num_a-1 >= 0 && nums[num_a-1].second > nums[num_a].second)
        {
            rounds--;
        }
        if(num_a+1 < n && nums[num_a].second > nums[num_a+1].second)
        {
            flag = true;
            rounds--;
        }
        
        if(num_b-1 >= 0 && nums[num_b-1].second > nums[num_b].second)
        {
            flag = true;
            rounds--;
        }
        if(num_b+1 < n && nums[num_b].second > nums[num_b+1].second)
        {
            rounds--;
        }
        
        if(abs(num_a - num_b) == 1 && flag) {
            rounds++;
        } 
        
        swap(nums[num_a].second, nums[num_b].second);

        if(sla) swap(num_a,num_b);
        position_num[a] = num_b;
        position_num[b] = num_a; 
        
        flag = false; 
        if(num_a-1 >= 0 && nums[num_a-1].second > nums[num_a].second) 
        {
            flag = true;
            rounds++;
        }
        if(num_a+1 < n && nums[num_a].second > nums[num_a+1].second) 
        {
            rounds++;
        }
        
        if(num_b-1 >= 0 && nums[num_b-1].second > nums[num_b].second)
        {
            rounds++;
        }
        if(num_b+1 < n && nums[num_b].second > nums[num_b+1].second)
        {
            flag = true;
            rounds++;
        }

        if(abs(num_a - num_b) == 1 && flag){
            flag = false;
            rounds--;
        }

        // for(auto x: nums) cout << x.first << " ";
        // cout << endl;
        // for(auto x: nums) cout << x.second << " ";
        // cout << endl;

        cout << rounds << endl;

    }

    return 0;

}