#include <iostream>
#include <string>

using namespace std;

bool match(const string & pattern, const string &s ){
	int itp=0, its=0;

	if(pattern.size() == 0 && s.size() == 0)
		return true;
	
	else if(pattern[0]=='*')
		if(match(pattern.substr(1), s.substr(1)))
			return true;
		else
			match(pattern, s.substr(1));

	else if (pattern[0] == '?' || pattern[0]==pattern[0])
		match(pattern.substr(1), s.substr(1));

	else if(pattern.size()==0 || s.size()==0 || pattern[0]!=s[0])
		return false;
	
}

int main(){
	cout << match("Inzy*wan?owa", "Inzynieria Kwantowa");
}
