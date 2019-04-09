#include <iostream>
#include <string>

using namespace std;

bool match(const string & pattern, const string & s){

    if( s.size()==1 )
    if (( pattern.size() == 1 && pattern.front()==s.front() ) || ( pattern.front()=='*' || pattern.front()=='?') )
        return true;
        else return false;

	else if(pattern.front()=='?'){
		return match(pattern.substr(1), s.substr(1));
	}

	else if(pattern.front()=='*'){
		if(pattern.front()!=s.front() || !match(pattern.substr(1), s.substr(1)))
			return match(pattern, s.substr(1));
	}

    return match(pattern.substr(1), s.substr(1));

}

int main(){
	cout << match("i??yi*?*", "inzyieria kwantowa") << endl;
}
