#include <iostream>
#include <string>

using namespace std;

bool match(const string & pattern, const string & s){
	if(pattern.front()=='?'){
		match(pattern.substr(1), s.substr(1));
	}

	if(pattern.front()=='*'){
		if(pattern.front()!=s.front() || !match(pattern.substr(1), s.substr(1)))
			match(pattern, s.substr(1));
	}

	if(pattern.front() != s.front())
		return false;

	return true;
}

int main(){
	cout << match("?l*", "eluwa") << endl;
}
