//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
    
    
    void merge(long long arr[] ,int s, int mid,int e,long long int &count){
        int size1= mid -s  +1;
        int size2= e - mid;
        
        long long int left[size1];
        long long int right[size2];
        
         for (int i = 0; i < size1; i++) {
        left[i] = arr[s + i];
    }

    for (int j = 0; j < size2; j++) {
        right[j] = arr[mid + 1 + j];
    }
        int i=s;
        int j=0;
        int k=0;
        while(i<=e && j<size1 && k<size2 ){
            if(left[j] <= right[k] ){
                arr[i]=left[j];
                i++;
                j++;
            }    
            else {
                arr[i] = right[k];
                i++;
                k++;
                count += (size1 - j); // Count inversions when right element is smaller
            }
                
                
        }
        
        
        while(j<size1 && i<=e){
            arr[i]=left[j];
            i++;
            j++;
        }
        
        
        while(k<size2 && i<=e){
            arr[i]=right[k];
            i++;
            k++;
        }
        
    }
    
    void mergeSort(long long arr[], int s,int e, long long int &count){
        
        if(s<e){
            long long int cp=0;
        int mid = s + (e-s)/2;
        mergeSort(arr,s,mid,count);
        mergeSort(arr,mid+1,e,count);
        
        merge(arr,s,mid,e,cp);
        count+=cp;
        }        
        
        
        
    }
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        
        //using brute force t.c - O(n^2)
        // long long int count=0;
        // for(int i=0;i<N;i++){
        //     for(int j=i;j<N;j++){
        //         if(arr[i]>arr[j])count++;
        //     }
        // }
        
        // return count;

        
        //using approach 2
        //merge sort

        long long int count =0;
        int s=0;
        int e=N-1;
        mergeSort(arr,s,e,count);
    
        // for(int i=0;i<N;i++)cout<<arr[i]<<" ";
        // cout<<endl;
        return count;
        
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends