#ifndef FUZZY_SEARCH_H
#define FUZZY_SEARCH_H

// FuzzySearch.h
// The search is meant for finding strings whcih are not
// native latin script but transliterated into one.
// The transliteration gives raise to multiple spellings.
// Here the focus is on Indian spellings.
// eg, take names:
//     Andhra Jyothi (name of a Telugu daily)
// all these spellings are possible:
//    aandhra jyOthi
//    aandhra jyoti
//    andra jyoothi (less common)
//
// It is not possible to search for these in normal way.
// One needs to adapt

// ref: http://www.gotw.ca/gotw/029.htm

#include <string>
#include <iostream>

using namespace std;

// implement char traits for Indian string search (adapted from Sutter's code)
// ignores 'h' while comparing.
struct ign_h__char_traits : public char_traits<char>
    // just inherit all the other functions
    //  that we don't need to override
{
    static bool eq(char c1, char c2)
    {
        return toupper(c1) == toupper(c2);
    }

    static bool ne(char c1, char c2)
    {
        return toupper(c1) != toupper(c2);
    }

    static bool lt(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);
    }

    static int compare(const char* s1, const char* s2, size_t n) {
        const auto s1start = s1;
        const auto s2start = s2;
        char pc1 = '\0'; // prev char in s1
        char pc2 = '\0'; // prev char in s2
        while (*s1 && *s2) {
            char c1 = toupper(*s1);
            char c2 = toupper(*s2);
            // skip chars identical to prev
            if (c1 == pc1 || c1 == ' ') {
                ++s1; continue;
            }
            if (c2 == pc2 || c2 == ' ') {
                ++s2; continue;
            }
            if (c1 == 'H' && s1 != s1start) {
                ++s1; continue; // ignore 'h' in the middle
            }
            if (c2 == 'H' && s2 != s2start) {
                ++s2; continue; // ignore 'h' in the middle
            }
            if (c1 == c2) {
                ++s1; ++s2;
            }
            else {
                // c1 != c2
                return c1 < c2 ? -1 : 1; // NOTE: following latin alphabet ordering as is common
            }
            pc1 = c1; pc2 = c2;
        }
        while (toupper(*s1) == 'H' || *s1 == ' ') ++s1;
        while (toupper(*s2) == 'H' || *s2 == ' ') ++s2;
        if (*s1 == *s2) return 0;
        else return (*s1) ? 1 : -1;
    }

    static const char*
        find(const char* s, int n, char a) {
        while (n-- > 0 && toupper(*s) != toupper(a)) {
            ++s;
        }
        return s;
    }
};

// NOTE: strings must be identical in length for comparison returning equal.
// Thus pad strings with trailing blanks.
// eg: "sampath" and
//     "sampat"  will be returned different
//     "sampath" and 
//     "sampat " will be returned equal
typedef basic_string<char, ign_h__char_traits> ind_string;

#endif