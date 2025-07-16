// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to check the character
// is an alphabet or no

// Function to check email id is
// valid or not
bool is_valid(string email)
{
   if(!isalpha(email[0])) return false;
   int a = -1, b = -1;
   for(int i=0;i<email.size();i++) {
       if(email[i] == '@') a = i;
       else if(email[i] == '.') b = i;
       else if(email[i] == ' ') return false;
   }
   if(a == -1 || b == -1 || b<a || b == email.size()-1) return false;
   return true;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // to handle newline after reading n

    while (n--) {
        string line;
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end()); // remove all spaces

        if (is_valid(line)) cout << "True\n";
        else cout << "False\n";
    }

    return 0;
}
