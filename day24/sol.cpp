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

long inv(long a, long m) { 
  long m0 = m, t, q; 
  long x0 = 0, x1 = 1; 

  if (m == 1) return 0; 

  // Apply extended Euclid Algorithm 
  while (a > 1) { 
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
  if (x1 < 0) x1 += m0; 

  return x1; 
} 

long long mul_inv(long long a, long long b){
	long long b0{ b }, t{ 0 }, q{ 0 };
	long long x0{ 0 }, x1{ 1 };

	if (b == 1) {
		return 1;
	}

	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}

	if (x1 < 0) {
		x1 += b0;
	}

	return x1;
}

long long chinese_remainder(const std::vector<long long>& n, const std::vector<long long>& a, const long long lenght) {
	long long p{ 0 }, i{ 0 }, prod{ 1 }, sum{ 0 };

	for (i = 0; i < lenght; i++) {
		prod *= n[i];
	}

	for (i = 0; i < lenght; i++) {
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}

	return sum % prod;
}

string trim(const string& str) {
  size_t first = str.find_first_not_of(' ');
  if (string::npos == first) {
    return str;
  }
  size_t last = str.find_last_not_of(' ');
  return str.substr(first, (last - first + 1));
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	string s;
	vector<pair<int, int>> dir = {{0, -2}, {0, 2}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	vector<int> nums;
	vector<string> sen;
	unordered_set<long> numSet;
	unordered_set<long> ssSet;
	unordered_map<long, string> ls;
	unordered_map<string, long> sl;

	map<pair<int, int>, int> mp;
	while (getline(cin, s)) {
    sen.push_back(s);
		int i = 0;
		int j = 0, k = 0;
		while (i < s.size()) {
			char c = s[i];
			if (c == 'e') {
				k += 2;
				i += 1;
			} else if (c == 's') {
				char c2 = s[i + 1];
				if (c2 == 'e') {
					j += 1;
					k += 1;
				} else {
					j += 1;
					k -= 1;
				}
				i += 2;
			} else if (c == 'w') {
				k -= 2;
				i += 1;
			} else if (c == 'n') {
				char c2 = s[i + 1];
				if (c2 == 'w') {
					j -= 1;
					k -= 1;
				} else {
					j -= 1;
					k += 1;
				}
				i += 2;
			}
		}
		mp[{j, k}] = mp[{j, k}] == 0 ? 1 : 0;
	}

	long res = 0;
	for (int i = 0; i < 100; i++) {
		map<pair<int, int>, int> mp2;
		for (auto& e : mp) {
			if (e.second == 1) {
				int j = e.first.first, k = e.first.second;
				for (auto& d : dir) {
					if (!mp.count({j + d.first, k + d.second})) {
						mp[{j + d.first, k + d.second}] = 0;
					}
				}
			}
		}

		for (auto& e : mp) {
			int j = e.first.first, k = e.first.second;
			int c = 0;
			for (auto& d : dir) {
				if (mp.count({j + d.first, k + d.second}) && mp[{j + d.first, k + d.second}] == 1) {
					c += 1;
				}		
			}
			if (e.second == 1) {
				if (c == 0 || c > 2) {
					mp2[{j, k}] = 0;
				} else {
					mp2[{j, k}] = 1;
				}
			} else {
				if (c == 2) {
					mp2[{j, k}] = 1;
				} else {
					mp2[{j, k}] = 0;
				}
			}
		}
		mp = mp2;
	}
	int c = 0;
	for (auto& e : mp) {
		if (e.second == 1) {
			c += 1;
		}
	}
	ps(c);
  
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	ps("time in seconds:", microseconds / (float)1e6);
}

// g++ -std=c++11 sol.cpp -o sol.out && ./sol.out < sol.in