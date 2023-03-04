#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class PRIMES {
	private:
	static const ll N=2e6+13;
	bool siv[N+1]={false};
	public:
	vector<ll> primes;
	void sieve() {
		ll i, j;
		for(i=3; i*i<=N; i+=2) {
			if(!siv[i]) {
				for(j=i*i; j<=N; j+=i+i) {
					siv[j]=1;
				}
			}
		}

		primes.push_back(2);
		for(i=3; i<=N; i+=2)
		if(!siv[i]) primes.push_back(i);
		return;
	}

 
  public: 
	vector<ll> segmented_sieve(ll left, ll right) { 
    vector<ll> segmented_primes;
		ll L=left, R=right;
		bool dummy[R-L+1]={false};
		ll i, j, firstmultiple, increment;
		
		for(i=1; i<primes.size() && primes[i]*primes[i]<=R; i++) {
			
			firstmultiple=L/primes[i];
			firstmultiple*=primes[i];
			if(firstmultiple<L) firstmultiple+=primes[i];
			if(firstmultiple%2==0) firstmultiple+=primes[i];
			increment=max(firstmultiple, primes[i]*primes[i]);
			
				for(j=increment; j<=R; j+=primes[i]+primes[i]) {
					dummy[j-L]=1;
				}
		}
		
		j=L;
		if(L%2==0) j++;
		for(i=j; i<=R; i+=2) {
			if(!dummy[i-L]) segmented_primes.push_back(i);
		}
		return segmented_primes;
	}

	public:
	vector<ll> prime_factor(ll N) {
  vector<ll> pf;
		ll i=0;
		for(i=0; i<primes.size() && primes[i]*primes[i]<=N; i++) {
			while(N%primes[i]==0) {
				pf.push_back(primes[i]);
				N/=primes[i];
			}
		
		}
		if(N!=1) pf.push_back(N);
		return pf;
	}

};

int main() 
{
	ll L=1e12, R=1e12+1e6;
	PRIMES segsiv;
	segsiv.sieve();
	vector<ll> ans, pfactors;
	ans=segsiv.segmented_sieve(L, R);
	pfactors=segsiv.prime_factor(36);
  for(auto it:
	for(auto it: pfactors) cout<<it<<" ";
	cout<<"\n";
}
