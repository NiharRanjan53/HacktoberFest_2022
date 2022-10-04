#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num, rev = 0, m, temp;
	cout << "Enter the Number: ";
	cin >> num;
	temp = num;
	while (temp > 0)
	{
		m = temp % 10;
		rev = (rev * 10) + m;
		temp = temp / 10;
	}
	if (rev == num)
		cout << "It is a Palindrome." << endl;
	else
		cout << "It is not a Palindrome." << endl;
	return 0;
}
