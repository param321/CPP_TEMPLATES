void compute_automaton(string s, vector<vector<ll>>& aut) {
    s+='#';
    ll n =s.size();
    vector<int> pi =prefix_function(s);
    aut.assign(n, vector<ll>(26));
    for (ll i = 0; i < n; i++) {
        for (ll c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}