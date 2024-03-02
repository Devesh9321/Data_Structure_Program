#include <bits/stdc++.h>
using namespace std;

// 9 3
// 1 2 3 1 4 5 2 3 6

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> output;
        for(int i = 0; i < n-(n/k)+1; ++i ){
            int max = arr[i];
            for( int j = i; j < i+k ; ++j ){
                if(max < arr[j]){
                    max = arr[j];
                }
            }
            output.push_back(max);
        }
        return output;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}