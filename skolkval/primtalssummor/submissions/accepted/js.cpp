#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool isprime[1000];
vector<int> primes;

bool ok(int a, int b, int c){
	vector<bool> d(10);
	while(a) d[a%10] = true, a /= 10;
	while(b) d[b%10] = true, b /= 10;
	while(c) d[c%10] = true, c /= 10;
	return d[0] == false && count(d.begin(), d.end(), true) == 9;
}

int main(){
	for(int i = 2; i < 1000; i++) isprime[i] = true;
	for(int i = 2; i < 1000; i++){
		if(isprime[i]){
			for(int j = i*i; j < 1000; j+=i) isprime[j] = false;
			if(i >= 100) primes.push_back(i);
		}
	}
	int ans = 0, lo = 1000000, hi = 0;
	for(int i = 0; i < primes.size(); ++i)
		for(int j = i+1; j < primes.size(); ++j)
			for(int k = j+1; k < primes.size(); ++k)
				if(ok(primes[i], primes[j], primes[k])){
					ans++;
					lo = min(lo, primes[i] + primes[j] + primes[k]);
					hi = max(hi, primes[i] + primes[j] + primes[k]);
				}
	printf("%d %d %d\n", ans, lo, hi);
}
