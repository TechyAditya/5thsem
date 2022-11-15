int findMaximumGreatness(vector<int> arr) {
    vector<int> vec = arr;
    sort(vec.begin(), vec.end());
    int ret = 0;
    
    for(auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;
    for(auto i : vec) {
        cout << i << ' ';
    }
    
    int ptr1 = 0, ptr2 = arr.size() - 1;
    while(ptr2<ptr1) {
        if(vec[ptr1] < vec[ptr2]) {
           ret++;
           ptr1++;
           ptr2--;
        }
        else {
            ptr2--;
        }
    }
    cout << endl;
        for(auto i : vec) {
        cout << i << ' ';
    }
    
    return ret;
}