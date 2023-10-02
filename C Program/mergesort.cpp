
void merge(vector<int>& arr, int s, int mid, int e){
    int left = s;
    int right = mid+1;
    vector<int> temp;
    while(left<= mid && right <= e){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left<= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= e){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=s; i<=e; i++){
        arr[i] = temp[i-s];
    }
}


void mymergesort(vector<int>& arr, int l, int r){
    if(l>=r) return;
    int mid = (l+r)/2;
    mymergesort(arr, l, mid);
    mymergesort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

void mergeSort(vector<int>& arr, int l, int r) {
    // Write Your Code Here
    mymergesort(arr, l, r);
}