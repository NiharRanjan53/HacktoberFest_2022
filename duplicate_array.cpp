#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Result {
    Result() : output1() {};
    int output1[100];
};
Result duplicatearrya(int input, int input1[]) {
	unordered_map<int, int> mp;
    Result res;
	for (int i = 0; i < input; i++) {
		mp[input1[i]]++;
	}
    int j = 0;
	for (auto &it : mp) {
		if (it.second > 1) {
			res.output1[j++] = it.first;
		}
	}
	return res;
}

int main() {
	int input;
	cin >> input;
	int input1[input];
	for (int i = 0; i < input; i++) {
		cin >> input1[i];
	}
	Result res = duplicatearrya(input, input1);

	for (int i = 0; i< input;i++) {
        cout << res.output1[i] << " ";
    }

	return 0;
}