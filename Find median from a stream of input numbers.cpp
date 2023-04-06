#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<double> arr;
	while(true){
		double num, Median;
		cin>>num;
		//Adding the input value to the vector
		arr.push_back(num);
		int len = arr.size();
		//If vector has only one value, return value
		if(len == 0){
			Median = arr[0];
		}
		else{
			//insertion sort
			double value = arr[len-1];
			int hole = len-1;
			for(int i=len-2; i>=0; i--){
				if(arr[i] > value){
					arr[i+1] = arr[i];
					hole = i;
				}
				else{
					break;
				}
			}
			arr[hole] = num;
			//Find median
			if(len % 2 == 1){
				Median = (arr[len/2])/ 1.0;
			}
			else{
				Median = (arr[(len/2)-1] + arr[(len/2)])/2.0;
			}
		}
		cout<<Median;
	}
	return 0;
}
