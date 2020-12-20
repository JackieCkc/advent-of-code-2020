#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
	bool fst = 1; str res = "{";
	F0R(i,sz(v)) {
		if (!fst) res += ", ";
		fst = 0; res += ts(v[i]);
	}
	res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class T> str ts(T v) {
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

vector<string> split(string s, char dim) {
    vector<string> res;
    stringstream ss(s);
    string item;
    while (getline(ss, item, dim)) res.push_back(item);
	if (s[s.size() - 1] == dim) res.push_back("");
    return res;
}

long ans = 0;
int c = 0;
vector<int> nums;
void dfs(vector<int>& curr, int j) {
	if (curr.back() == nums.back()) {
		ans += 1;
		if (ans > pow(10, c)) {
			ps(ans);
			c += 1;
		}
		return;
	}
	for (int k = 1; k <= 3; k++) {
		for (int i = j; i < nums.size(); i++) {
			if (nums[i] == curr.back() + k) {
				curr.push_back(nums[i]);
				dfs(curr, i + 1);
				curr.pop_back();
			}
		}
	}
}

long inv(long a, long m) 
{ 
    long m0 = m, t, q; 
    long x0 = 0, x1 = 1; 
  
    if (m == 1) 
       return 0; 
  
    // Apply extended Euclid Algorithm 
    while (a > 1) 
    { 
        // q is quotient 
        q = a / m; 
  
        t = m; 
  
        // m is remainder now, process same as 
        // euclid's algo 
        m = a % m, a = t; 
  
        t = x0; 
  
        x0 = x1 - q * x0; 
  
        x1 = t; 
    } 
  
    // Make x1 positive 
    if (x1 < 0) 
       x1 += m0; 
  
    return x1; 
} 

long long mul_inv(long long a, long long b)
{
	long long b0{ b }, t{ 0 }, q{ 0 };
	long long x0{ 0 }, x1{ 1 };

	if (b == 1)
	{
		return 1;
	}
	while (a > 1) 
	{
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0)
	{
		x1 += b0;
	}

	return x1;
}

long long chinese_remainder(const std::vector<long long>& n, const std::vector<long long>& a, const long long lenght) {
	long long p{ 0 }, i{ 0 }, prod{ 1 }, sum{ 0 };

	for (i = 0; i < lenght; i++) {
		prod *= n[i];
	}

	for (i = 0; i < lenght; i++) 
	{
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}

	return sum % prod;
}

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<string> flip1(vector<string>& mat) {
	vector<string> res = mat;
	reverse(res.begin(), res.end());
	return res;
}

vector<string> flip2(vector<string>& mat) {
	vector<string> res = mat;
	for (auto& row : res) {
		reverse(row.begin(), row.end());
	}
	return res;
}

vector<string> rotate(vector<string>& mat) {
	vector<string> res = mat;
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		for (int j = i + 1; j < res.size(); j++) {
			swap(res[i][j], res[j][i]);
		}
	}
	return res;
}
vector<pair<int, int>> dir = {{1, 1}, {1, 4}, {0, 5}, {0, 6}, {1, 7}, {1, 10}, {0, 11}, {0, 12}, {1, 13}, {1, 16}, {0, 17}, {0, 18}, {0, 19}, {-1, 18}};

int check(vector<string>& mat) {
	int num = 0;
	int m = mat.size(), n = mat[0].size();
	int t = 0;
	set<pair<int, int>> as;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == '#') t += 1;
			if (i - 1 < 0 || i + 1 >= m || j + 19 >= n) continue;

			if (mat[i][j] == '#') {
				bool ok = true;
				set<pair<int, int>> ts = {{i, j}};
				for (auto& d : dir) {
					int ii = i + d.first, jj = j + d.second;
					ts.insert({ii, jj});
					if (mat[ii][jj] != '#') {
						ok = false;
						break;
					}
				}
				if (ok) {
					num += 1;
					for (auto& v : ts) as.insert(v);
				}
			}
		}
	}
	if (!as.empty()) ps("P2 Ans:", t - as.size());
	return num;
}

void processMat(vector<string>& mat) {
	set<vector<string>> arr;
	for (int i = 0; i < 4; i++) {
		vector<string> nm = rotate(mat);
		vector<string> nm1 = flip1(nm);
		vector<string> nm2 = flip2(nm);
		arr.insert(nm);
		arr.insert(nm1);
		arr.insert(nm2);
		mat = nm;
	}
	for (auto a : arr) {
		check(a);
	}
}

string s1(vector<string>& mat) {
	int m = mat.size(), n = mat[0].size();
	string res = "";
	for (int i = 0; i < m; i++) {
		res += mat[i][n - 1];
	}
	return res;
}

string s3(vector<string>& mat) {
	int m = mat.size(), n = mat[0].size();
	string res = "";
	for (int i = 0; i < m; i++) {
		res += mat[i][0];
	}
	return res;
}

int k = 12;
bool found = false;
vector<vector<int>> ids(k, vector<int>(k, 0));
unordered_map<int, vector<vector<string>>> tileVariations;
unordered_map<int, vector<string>> tiles;
unordered_set<int> used;
vector<vector<vector<string>>> res(k, vector<vector<string>>(k, vector<string>()));

void dfs(int i, int j) {
	if (found) return;
	if (i == k) {
		found = true;

		for (int i = 0; i < k; i++) {
			ps(ids[i]);
		}

		vector<string> mat;
		for (int i = 0; i < k; i++) {
			vector<vector<string>> arr;
			for (int j = 0; j < k; j++) {
				auto& m = res[i][j];
				arr.push_back(m);
			}
			for (int j = 1; j < arr[0].size() - 1; j++) {
				string row = "";
				for (int l = 0; l < k; l++) {
					row += arr[l][j].substr(1, 8);
				}
				mat.push_back(row);
			}
		}
		processMat(mat);
		return;
	}
	for (auto& t : tiles) {
		int id = t.first;
		if (used.count(id)) continue;
		auto tile = t.second;

		for (auto& item : tileVariations[id]) {
			bool ok = true;
			if (i > 0) {
				auto& r = res[i - 1][j];
				if (r.back() != item[0]) ok = false;
			}
			if (j > 0) {
				auto& r = res[i][j - 1];
				if (s1(r) != s3(item)) ok = false;
			}
			if (ok) {
				res[i][j] = item;
				int ii = i, jj = j + 1;
				if (jj == k) {
					ii += 1, jj = 0;
				} 
				ids[i][j] = id;
				used.insert(id);
				dfs(ii, jj);
				used.erase(id);
			}

			tile = rotate(tile);
		}
	}
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	string s;
	vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {1, 1}, {-2, 1}};
	vector<int> nums;
	vector<string> sen;
	unordered_set<long> numSet;
	unordered_set<long> ssSet;
	unordered_map<long, string> ls;
	unordered_map<string, long> sl;
	
	vector<string> tile;
	int id;
	while (getline(cin, s)) {
		if (s[0] == 'T') {
			id = stoi(s.substr(5));
		} else if (s.empty()) {
			tiles[id] = tile;
			tile = {};
		} else {
			tile.push_back(s);
		}
	}
	for (auto& t : tiles) {
		auto& tile = t.second;
		int id = t.first;
		set<vector<string>> arr;
		for (int l = 0; l < 4; l++) {
			auto f1 = flip1(tile);
			auto f2 = flip2(tile);
			arr.insert(tile);
			arr.insert(f1);
			arr.insert(f2);
			tile = rotate(tile);
		}
		tileVariations[id] = vector<vector<string>>(arr.begin(), arr.end());
	}
	dfs(0, 0);

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	ps("time in seconds:", microseconds / (float)1e6);
}

// g++ -std=c++11 sol.cpp -o sol.out && ./sol.out < sol.in