#include<vector>
#include<iostream>
#include<map>
#include<string>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int len = s.length();
		vector<vector<int> > pre(len, vector<int>(26, 0)), suf(len, vector<int>(26, 0));
		map<int, int> mp1, mp2, mp3;
		for (int i = 0; i<len; i++) {
			for (int j = 1; j<26; j++) {
				pre[i][j] = pre[i][j - 1] + mp1[j - 1];
			}
			mp1[s[i] - 'a']++;
		}
		for (int i = len - 1; i >= 0; i--) {
			for (int j = 24; j >= 0; j--) {
				suf[i][j] = suf[i][j + 1] + mp2[j + 1];
			}
			mp2[s[i] - 'a']++;
		}

		int mx = -342412;
		int temp, idx, c;
		for (int i = 0; i<len; i++) {
			for (int j = 0; j<26; j++) {
				temp = (pre[i][s[i] - 'a'] + suf[i][s[i] - 'a']) - (pre[i][j] + suf[i][j] + abs(j - (s[i] - 'a')));
				if (temp>mx) {
					mx = temp;
					idx = i;
					c = j;
				}
			}
		}
		ll ans = pre[idx][c] + suf[idx][c] + abs(c - (s[idx] - 'a'));
		s[idx] = ('a' + c);
		vector<int> prefix(len), suffix(len);
		for (int i = len - 1; i >= 0; i--) {
			if (i != idx) {
				for (int j = (s[i] - 'a' + 1); j<26; j++) {
					ans += mp3[j];
				}
				mp3[(s[i] - 'a')]++;
			}

		}
		cout << ans << "\n";
	}
	return 0;
}