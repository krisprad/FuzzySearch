#include "FuzzySearch.h"



bool compare_ind_str(const  ind_string& s1, const ind_string& s2) {
	if (s1 == s2) {
		cout << "'" << s1.c_str() << "' and '" << s2.c_str() << "' are same\n";
		return true;
	}
	else {
		cout << "'" << s1.c_str() << "' and '" << s2.c_str() << "' are not same\n";
		return false;
	}
}


int main(int argc, char** argv) {
	const ind_string s1 = "Andhra Jyothi";
	const ind_string s2 = "Andhra Jyothi";
	const ind_string s3 = "aandhra Jyoti";
	const ind_string s4 = "andra jyoothi";
	compare_ind_str(s1, s2); // match
	compare_ind_str(s1, s3); // match
	compare_ind_str(s1, s4); // match
	compare_ind_str(s3, s4); // match

	compare_ind_str("avatar ", "Avathar");  // match
	compare_ind_str("avatar", "avadar");  // mismatch
	compare_ind_str("sampath", "sampat");  // mismatch
	compare_ind_str("sampath", "sampat ");  // match
}


/* Output
'Andhra Jyothi' and 'Andhra Jyothi' are same
'Andhra Jyothi' and 'aandhra Jyoti' are same
'Andhra Jyothi' and 'andra jyoothi' are same
'aandhra Jyoti' and 'andra jyoothi' are same
'avatar ' and 'Avathar' are same
'avatar' and 'avadar' are not same
'sampath' and 'sampat' are not same
'sampath' and 'sampat ' are same
*/