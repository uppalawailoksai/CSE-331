

#include <bits/stdc++.h>
using namespace std;

/
bool createTarget(vector<int>& target)
{

	
	int n = target.size();

	
	int sum = 0;


	int lastSum;

	priority_queue<int> maxHeap(target.begin(),
								target.end());

	
	for (int i = 0; i < n; i++) {
		sum = sum + target[i];
	}

	
	while (true) {

		
		lastSum = maxHeap.top();

		
		maxHeap.pop();

	
		sum = sum - lastSum;

		
		if (lastSum == 1 || sum == 1) {

			// Return true
			return true;
		}


		if (lastSum < sum || sum == 0
			|| lastSum - sum == 0) {

			// Return false
			return false;
		}

	
		lastSum = lastSum - sum;


		sum = sum + lastSum;

		maxHeap.push(lastSum);
	}
}


int main()
{
	int N = 2;
	vector<int> target = { 2, 3 };
	bool ans = createTarget(target);
	if (ans)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
