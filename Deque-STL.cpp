/*
    Company Tags    : Google, Zenefits, Microsoft, Zoho, Flipkart, Amazon, Directi, SAP Labs
    Hackerrank Link : https://www.hackerrank.com/challenges/deque-stl/problem
*/

#include<bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> deq;
    
    for(int i = 0; i<k; i++) {
        while(!deq.empty() && arr[deq.back()] <= arr[i])
            deq.pop_back();
        
        deq.push_back(i);
    }
    vector<int> result;
    
    for(int i = k; i<n; i++) {
        result.push_back(arr[deq.front()]);
        //frist remove out of window elements which are max
        while(!deq.empty() && deq.front() <= i-k)
            deq.pop_front();
            
        //now, remove the elements which are smaller than arr[i]
        while(!deq.empty() && arr[deq.back()] <= arr[i])
            deq.pop_back();
        
        deq.push_back(i);
    }
    result.push_back(arr[deq.front()]);
    
    for(int x:result)
        cout << x << " ";
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t--) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
  	}
  	return 0;
}
