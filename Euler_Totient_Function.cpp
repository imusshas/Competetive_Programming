
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class TOTIENT {
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

	// Euler Totient Function to calculate the number of co_primes of 'Num'
	ll eulerPhi(ll Num) {
		ll i=0, ans=Num;
		 for(i=0; i<primes.size() && primes[i]*primes[i]<=Num; i++) {
			if(Num%primes[i]==0) {
				ans-=ans/primes[i];
				while(Num%primes[i]==0) Num/=primes[i];
			}
		}
		if(Num!=1) ans-=ans/Num;
		return ans;
	}
};

int main() {
	TOTIENT co_primes;
	co_primes.sieve();
	cout<<co_primes.primes.size()<<"\n";
	ll ans=co_primes.eulerPhi(36);
	cout<<ans<<"\n";
	return 0;
}
