// Given an array of non-negative integers, count number of unordered pairs of array elements such that their bitwise AND is power of 2
#include <bits/stdc++.h>
using namespace std;

long countPairs(vector<int> arr) {
    int n = arr.size();
    long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] & arr[j]) != 0 && ((arr[i] & arr[j]) & ((arr[i] & arr[j]) - 1)) == 0) {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3};
    cout << countPairs(arr);

    return 0;
}
