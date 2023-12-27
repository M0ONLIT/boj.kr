#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1000000];
int result[1000000];

vector<int> v;

int binary_search(int target)
{
    int low = 0;
    int high = v.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;

        if(target == v[mid]) return mid;
        else if(target > mid) low = mid+1;
        else if(target < mid) high =mid-1;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    //fill(result, result+n, 0);

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];

        if(v.empty()) v.push_back(arr[i]);
        else{
            bool flag = true;
            for(int j = 0; j<v.size(); j++) if(binary_search(arr[i]) != 0) flag = false;
            if(flag) v.push_back(arr[i]);
        }
    }


    sort(v.begin(), v.end());

    for(int i = 0; i<n; i++)
        result[i] = binary_search(arr[i]);

    for(int i = 0; i<n; i++) cout<<result[i]<<' ';
    cout<<'\n';

    return 0;
}
