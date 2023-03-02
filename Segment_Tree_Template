class Segment_Tree {

    vector<ll> seg;
public:
    Segment_Tree(ll n) {
        seg.resize(4*n+1);
    }
    
    void build (ll ind, ll low, ll high, vector<ll> &a) {
    if(low==high) {
        seg[ind]=a[low];
        return;
    }
    ll mid=(low+high)/2;
    ll left=ind*2+1, right=left+1;
    build(left, low, mid, a);
    build(right, mid+1, high, a);
    seg[ind]=min(seg[left], seg[right]); // Range_Minimum
    //seg[ind]=max(seg[left], seg[right]); // Range_Maximum
    //seg[ind]=seg[left]+seg[right]; //Range_Sum
    }

    ll query(ll ind, ll low, ll high, ll ql, ll qh) {
    // No_Overlap
    if(high<ql || low>qh) {
    return LLONG_MAX; // Range_Minimum
    //return LLONG_MIN; //Range_Maximum
    //return 0; // Range_Sum
    }

    // Complete_Overlap
    if(ql<=low && qh>=high) return seg[ind];

    //Partial_Overlap
    ll mid=(low+high)/2;
    ll left=ind*2+1, right=left+1;
    ll lans=query(left, low, mid, ql, qh);
    ll rans=query(right, mid+1, high, ql, qh);
    return min(lans,rans); //Range_Minimum
    //return max(lans, rans); //Range_Maximum
    //return lans+rans; //Range_Sum
    }

    void update(ll ind, ll low, ll high, ll i, ll val) {
    if(low==high) {
    seg[ind]=val;
    return;
    }
    ll mid=(low+high)/2;
    ll left=ind*2+1;
    ll right=ind*2+2;
    if(i<=mid) update(left, low, mid, i, val);
    else update(right, mid+1, high, i, val);
    seg[ind]=min(seg[left], seg[right]); //Range_Minimum
    // seg[ind]=max(seg[left],seg[right]); //Range_Maximum
    //seg[ind]=seg[left]+seg[right]; //Range_Sum
    }
};
