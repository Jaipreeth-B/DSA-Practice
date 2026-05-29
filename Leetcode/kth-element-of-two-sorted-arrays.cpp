int findKthElement(vector<int> &a, vector<int> &b, int k) {
    // write your code here...
    int n1 = a.size() , n2 = b.size();
   if(n1 > n2) return findKthElement(b,a,k);
   int low = max(0,k-n2) , high = min(k,n1);
   int n = n1 + n2;
   while(low <= high){
    int mid1 = (low + high) / 2;
    int mid2 = k - mid1;
    int l1 = INT_MIN , l2 = INT_MIN;
    int r1 = INT_MAX , r2 = INT_MAX;
    //check boundaries & asssign rights
    if(mid1 < n1) r1 = a[mid1];
    if(mid2 < n2) r2 = b[mid2];

    //assign left
    if( mid1 - 1 >= 0)  l1 = a[mid1 - 1];
    if(mid2 -1 >= 0) l2 = b[mid2 - 1];
    if(l1 <= r2 && l2 <= r1){
        return max(l1,l2);
    }
    else if (l1 > r2) high = mid1 -1 ; //took more elements from arr 1 so reduce high to decrease max val;
    else low = mid1 + 1;
   }
   return 0;
}