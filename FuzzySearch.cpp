#include "FuzzySearch.h"


template<typename T>
bool compare_str(const  T& s1, const T& s2) {
	if (s1 == s2) {
		cout << "'" << s1.c_str() << "' and '" << s2.c_str() << "'\t\t are same\n";
		return true;
	}
	else {
		cout << "'" << s1.c_str() << "' and '" << s2.c_str() << "'\t\t are not same\n";
		return false;
	}
}

template<typename T>
void compare_strings() {
	const T s1 = "Andhra Jyothi";
	const T s2 = "Andhra Jyothi";
	const T s3 = "aandhra Jyoti";
	const T s4 = "andra jyoothi";
	compare_str(s1, s2); // match
	compare_str(s1, s3); // match
	compare_str(s1, s4); // match
	compare_str(s3, s4); // match

	compare_str(T("avatar "), T("Avathar"));  // match
	compare_str(T("avatar"), T("avadar"));  // mismatch
	compare_str(T("sampath"), T("sampat"));  // mismatch
	compare_str(T("sampath"), T("sampat "));  // match
	compare_str(T("Srinivas "), T("Sreenivas"));  // mismatch for ind_string but match for syl_string
	compare_str(T("Srinivaas "), T("Sreenivass"));  // mismatch for ind_string but match for syl_string because of 'ee' vs 'i'
	compare_str(T("Udeep "), T("Uddeep"));  // match for ind_string but mismatch for syl_string. because of 'dd' vs 'd'
}

int main(int argc, char** argv) {
	cout << "\n----- ind_string comparision -------\n";
	compare_strings<ind_string>();
	cout << "\n----- syl_string comparision -------\n";
	compare_strings<syl_string>();
}

/* Output
----- ind_string comparision -------
'Andhra Jyothi' and 'Andhra Jyothi'              are same
'Andhra Jyothi' and 'aandhra Jyoti'              are same
'Andhra Jyothi' and 'andra jyoothi'              are same
'aandhra Jyoti' and 'andra jyoothi'              are same
'avatar ' and 'Avathar'          are same
'avatar' and 'avadar'            are not same
'sampath' and 'sampat'           are not same
'sampath' and 'sampat '          are same
'Srinivas ' and 'Sreenivas'              are not same
'Srinivaas ' and 'Sreenivass'            are not same
'Udeep ' and 'Uddeep'            are same

----- syl_string comparision -------
'Andhra Jyothi' and 'Andhra Jyothi'              are same
'Andhra Jyothi' and 'aandhra Jyoti'              are same
'Andhra Jyothi' and 'andra jyoothi'              are same
'aandhra Jyoti' and 'andra jyoothi'              are same
'avatar ' and 'Avathar'          are same
'avatar' and 'avadar'            are not same
'sampath' and 'sampat'           are not same
'sampath' and 'sampat '          are same
'Srinivas ' and 'Sreenivas'              are same
'Srinivaas ' and 'Sreenivass'            are not same
'Udeep ' and 'Uddeep'            are not same
*/