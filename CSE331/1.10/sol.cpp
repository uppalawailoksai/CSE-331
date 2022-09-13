
#include <bits/stdc++.h>
using namespace std;


void main(vector<int>& v)
{


	priority_queue<int> q;


	for (auto x : v) {
		q.push(x);
	}

	int cnt = 0;
	while (q.size() >= 2) {

		
		int ele1 = q.top();
		q.pop();

		
		int ele2 = q.top();
		q.pop();

	
		ele1--;
		ele2--;
		cnt += 2;

		
		if (ele1) {
			q.push(ele1);
		}
		if (ele2) {
			q.push(ele2);
		}
	}

	if (q.size() == 0)
		cout << cnt << endl;
	else
		cout << -1;
}


int main()
{

	vector<int> v = { 5, 3, 4 };
	gfg(v);
}
