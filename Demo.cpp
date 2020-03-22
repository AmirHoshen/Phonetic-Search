/**
 * Demo program for Gimatriya calculation.
 * 
 * Date: 2020-02
 */

#include "PhoneticFinder.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	string text = "Dond vorri be haffy";
	cout << PhonticFinder::find(text, "dont") << endl;   // should print "Dond"
	cout << PhonticFinder::find(text, "worry") << endl;   // should print "vorri"
	cout << PhonticFinder::find(text, "Be") << endl;   // should print "be"
	cout << PhonticFinder::find(text, "happy") << endl;   // should print "haffy"
	try {
		cout << PhoneticFinder::find(text, "happ") << endl;   // should throw an exception - "happ" is not a full word in the sentence
	} catch (exception ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'happ' in the text"
	}
}
