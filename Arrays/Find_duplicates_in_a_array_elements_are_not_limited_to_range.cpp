/* Find duplicates in a given array when elements are not limited to a range*/

#include <bits/stdc++.h>
using namespace std;
void findDuplicates(int arr[], int len)
{
	bool ifPresent = false;
	vector<int> al;
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = i + 1; j < len; j++)
		{
			if (arr[i] == arr[j])
			{auto it = std::find(al.begin(),al.end(), arr[i]);
									
				if (it != al.end())
				{
					break;
				}
				else
				{
					al.push_back(arr[i]);
					ifPresent = true;
				}
			}
		}
	}
	if (ifPresent == true)
	{
		cout << "[" << al[0] << ", ";
		for(int i = 1; i < al.size() - 1; i++)
		{
			cout << al[i] << ", ";
		}
		
		cout << al[al.size() - 1] << "]";
	}
	else
	{
		cout << "No duplicates present in arrays";
	}
}
int main()
{
	int arr[] = { 12, 11, 40, 12,5, 6, 5, 12, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findDuplicates(arr, n);
	return 0;
}
