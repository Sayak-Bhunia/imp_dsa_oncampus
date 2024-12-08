string bintooct(string bin) {
    while(bin.length()%3 != 0) bin = "0" + bin;
    string oct = "";
    for(int i=0;i<bin.length();i+=3) {
        int dec = (bin[i] - '0')*4 + (bin[i+1] - '0')*2 + (bin[i+2] - '0');
        oct += to_string(dec);
    }
    return oct;
}

string octtobin(string oct) {
    string bin = "";
    for(int i=0;i<oct.length();i++) {
        int octdigit = oct[i] - '0';
        string s = "";
        for(int j=2;j>=0;j--) s += to_string((octdigit>>j)&1);
        bin += s;
    }
    while(bin.length() > 1 && bin[0] == '0') bin.erase(0, 1);
    return bin;
}
