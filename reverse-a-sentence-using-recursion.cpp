void reverse(string s) {
    if(s.empty()) return; 
    cout << s.back();
    reverse(s.substr(0, s.size() - 1));
}
