#include <iostream>

using namespace std;

bool match(const string & pattern, const string& s){
    int its=0, itp=0;
    for (itp; itp<pattern.length(); ++itp){
        if(pattern[itp]=='*'){
            ++itp;
            while((++its)!=s.length() || s[its]!=pattern[itp]);
        }

        if(pattern[itp]=='?'){
            if (pattern[++itp]==s[its])
                continue;
            else if(pattern[itp]==s[++its]){
                ++itp;
                continue;
            }
        }

        if(pattern[itp]!=s[its])
            return false;

        its++;
    }

    return true;
}

int main()
{
    cout << match("el?wa", "eluwa") << endl;
    return 0;
}
