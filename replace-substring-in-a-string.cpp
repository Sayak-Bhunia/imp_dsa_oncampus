string replaceSubstring(string s, const string &t, const string &r) {
    size_t pos = s.find(t); 
    while(pos != string::npos) {
        s.replace(pos, t.length(), r); 
        pos = s.find(t, pos + r.length()); 
    }
    return s;
}
