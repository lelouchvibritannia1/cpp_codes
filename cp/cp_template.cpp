#if !defined __clang__
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _USE_MATH_DEFINES
#endif
#include <cstdio>
#include <cstring>
#include <utility>
#include <functional>
#include <array>
#include <limits>



using namespace __gnu_pbds;

#include <string>
#include <unordered_map>
using namespace std;
//#define MINUS_
#define IO_
//#define PCK_
#define I_ inline
#define T_ template
#define TN_ typename
#define TT_ T_ <TN_ T>
#define HT_ T_ <TN_ H,TN_... T>
#define OP_(t) I_ operator t()
#ifdef IO_
namespace io {
	const size_t s=1<<18;char in[s],*i {},*e {},out[s],*o=out,*f=o+s-1;
	I_ char get(){return i==e?e=(i=in)+fread(in,1,s,stdin),i==e?EOF:*i++:*i++;}
	I_ void flush(){fwrite(out,1,o-out,stdout);o=out;}
	I_ void put(char c){*o++=c;if(o==f)flush();}
	I_ void put_string(char *b, char *e) {
		static char *g {f + 1};
		if (size_t l = e - b, r = g - o; l < r)
			memcpy(o, b, l), o+=l;
		else {
			memcpy(o, b, r), o+=r;
			flush();
			if (l > r)
				put_string(b + r, e);
		}
	};
#ifdef _GLIBCXX_STRING
#define S_
	I_ void put_string(string &str) {
		if (str.size() >= size_t(f - o))
			flush(),fwrite(&str[0], 1, str.size(), stdout);
		else
			memcpy(o, &str[0], str.size()), o+=str.size();
	};
	I_ void get_string(string &str) {
		if (str.size() > size_t(e - i)) {
			for(char &i:str)i=get();
			get();
		} else
			memcpy(&str[0], i, str.size()), i+=str.size(), get();
	};
	I_ string get_string() {
		for (char *j = i; j != e; ++j)
			if (*j == ' ' || *j == '\n')
				return string(exchange(i, j + 1), j);
		string s;for(char c;c=get(),c!=' '&&c!='\n';)s+=c;return s;
	}
#endif
	struct flush_{~flush_(){flush();}} flush__;}
#define gcu io::get
#define pcu io::put
#else
#ifdef __linux
#define _U(s) s##_unlocked
#else
#define _U(s) _##s##_nolock
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
#define gcu _U(getchar)
#define pcu _U(putchar)
#endif
struct in_ {
	I_ operator void *(){char c;do{c=gcu();}while(c!=' '&&c!='\n');return NULL;}
#ifdef S_
	OP_(string){
#ifdef IO_
		return io::get_string();}
#else
		string s;for(char c;c=get(),c!=' '&&c!='\n';)s+=c;return s;}
#endif
	//OP_(string){string s;char c;while(isspace(c = gcu()));do{s+=c;}while(c=gcu(),c!=' '&&c!='\n'&&c!=EOF);return s;}
	I_ string read(int n,char c) {
		string v(n,c);
#ifdef IO_
		io::get_string(v);
#else
		for(char &i:v)i=gcu();gcu();
#endif
		return v;
	}
#endif
	OP_(char){char c=gcu();gcu();return c;}
#ifndef IO_
	OP_(double){double d; scanf("%lf",&d); gcu();return d;}
#endif
	TT_ I_ T RI_(char c){T n{};do{n=10*n+(c-'0'),c=gcu();}while(c>='0'/* &&c<='9' */);return n;}
	TT_ OP_(T){
		char c=gcu();
#ifdef PCK_
		for(;isspace(c);c=gcu());
#endif
#ifdef MINUS_
		return c=='-'?~(RI_<T>(gcu())-1):RI_<T>(c);
#else
		return RI_<T>(c);
#endif
	}
#ifdef _GLIBCXX_VECTOR
#define TI_ T_<TN_ T=vector<int>, TN_ I=TN_ T::value_type>
	TI_ I_ T read(int n) {T v(n);for(I &i:v)i=*this;return v;}
	TI_ I_ T read(int n,function<int(TN_ T::value_type)>f){T v(n);for(I &i:v)i=f(*this);return v;}
	TI_ I_ T read(int n,function<void(TN_ T::value_type&,TN_ T::value_type)>f){T v(n);for(I &i:v)f(i,*this);return v;}
#endif
	T_ <int N, TN_ T=int> array<T, N> read(){array<T, N>a;for(T &i:a)i=*this;return a;}
} in;
T_ <TN_ T=int> struct ist {
	int n; ist(int _n) : n(_n) {};
	struct it { int p; it(int _p) : p(_p) {}; I_ T operator *() const {return T(in);};
		I_ bool operator !=(const it& v) {return p != v.p;}; I_ it & operator ++() {++p; return *this;}; };
	I_ it begin() {return {0};}; I_ it end() {return {n};};
};
#define DEF_(r, n, ...) I_ r n(__VA_ARGS__)
#define OUT_(...) DEF_(void,out,__VA_ARGS__)
#define OUTL_(...) DEF_(void,outl,__VA_ARGS__)
OUT_(bool b){pcu('0'+b);}
OUT_(const char *s){while(*s)pcu(*s++);}
OUT_(char c){pcu(c);}
#ifdef S_
OUT_(string &s){
#ifdef IO_
	io::put_string(s);
#else
	for(char c:s)pcu(c);
#endif
}
//OUT_(string s){for(char c:s)pcu(c);}
#endif
//TT_ DEF_(void,OUTX_,T n){if(n<10)pcu(n+'0');else OUTX_(n/10),pcu(n%10+'0');}
TT_ OUT_(T n){
#ifdef MINUS_
	if(n<0)pcu('-'),n=-n;
#endif
	static char b[20], *a=b+20;
	char *p=a;
	if(n)while(n)*--p=n%10+'0',n/=10;else*--p='0';
#ifdef IO_
	io::put_string(p, a);
#else
	while(p!=a)pcu(*p++);
#endif
	//OUTX_(n);
}
TT_ OUT_(initializer_list<T> v){for(auto i{begin(v)};i!=end(v);++i)out(i==begin(v)?"":" "),out(*i);}
#ifdef _GLIBCXX_VECTOR
TT_ OUT_(vector<T> &v){if(auto i{begin(v)},e{end(v)};i!=e){out(*i++);for(;i!=e;++i)out(' '),out(*i);}}
#endif
HT_ OUT_(H &&h,T... t){out(h);out(t...);}
OUTL_(){out('\n');}
T_ <TN_... T> OUTL_(T... t){out(t...);outl();}
T_ <TN_ I,TN_... T> OUTL_(initializer_list<I> v,T... t){for(auto i{begin(v)};i!=end(v);++i)out(i==begin(v)?"":" "),out(*i);outl(t...);}
T_ <TN_ T=int> struct range{
	T e,b=0,s=1;range(T b,T e,T s):e(e),b(b),s(s){} range(T b,T e): e(e), b(b){} range(T e):e(e){}
	struct it{T v,s; it(T v,T s):v(v),s(s){} operator T()const{return v;} I_ operator T&(){return v;}T operator*()const{return v;}
		I_ it& operator++(){v+=s;return *this;}}; it begin(){return {b,s};} it end(){return {e,s};}};
#define Range(b,...)for([[maybe_unused]] auto b:range<int>((int) __VA_ARGS__))
#define Test Range(testcase__, in)
#define dbg(...)fprintf(stderr,__VA_ARGS__)
using LL=long long;
#define tee(s,v)({dbg(s,v);v;})
#define TAPP(t,s)t tapp(t v){return tee(s, v);}
TAPP(char,"%c") TAPP(int,"%d") TAPP(LL,"%lld") TAPP(const char *, "%s") TAPP(bool, "%d")
#ifdef S_
string tapp(string s) {return tee("%s",s.c_str());}
#endif
TT_ T tapp(T v){for (auto i: v){tapp(i);dbg(" ");}return v;}
TT_ T tapl(T v){tapp(v);dbg("\n");return v;}

#ifdef _GLIBCXX_IOSTREAM
void fast_io() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#endif
#ifdef _FUNCTIONAL_HASH_H
#include <chrono>
struct custom_hash{size_t operator()(size_t x)const{static const size_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); x += 0x9e3779b97f4a7c15 + FIXED_RANDOM; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } };
#endif
TT_ constexpr T inf {numeric_limits<T>::max()};
TT_ T sign(T a) {return (a > 0) - (a < 0);}
I_ int bsign(bool b){return b - !b;}
TT_ T eucdiv(T a, T b) {T t = a / b; return a % b < 0 ? t - 1: t;}
TT_ T eucmod(T a, T b) {T t = a % b; return t < 0 ? t + abs(b) : t;}
TT_ I_ T ceil(T a, T b) {return (a + b - 1) / b;}
T_ <TN_ P, TN_ O> I_ constexpr int len(P &p, O o) {return distance(begin(p), o);}
TT_ I_ constexpr int len(T p) {return size(p);}

#define ly(x) __builtin_expect(x, 1)
#define un(x) __builtin_expect(x, 0)

using P = pair<int, int>;
P z = {0, 0};

int main() {
	Test {
		gcu();
		int n {in}, k {in};
		gp_hash_table<int, P, custom_hash> m;
		Range (i, 1, n + 1) {
			int u {in};
			if (m[u] == z)
				m[u] = {i, i};
			else
				m[u].second = i;
		}
		Range (i, k) {
			int a {in}, b {in};
			outl(m[a] != z && m[b] != z && m[a].first < m[b].second ? string("YES") : string("NO"));
		}
	}
}
