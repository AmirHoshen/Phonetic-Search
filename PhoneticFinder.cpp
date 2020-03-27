//
// Created by miros on 20/03/2020.
//
/**
 * Phonetic search method definition:
 * this method will get both a sentence and a word (represented by string)
 * @param sentence - a misspelled sentence .
 * @param word - the word we are looking for in the sentence.
 * the letters that may have been replaced mistakenly:
 * v,w
 * b,f,p
 * g,j
 * c,k,q
 * s,z
 * d,t
 * o,u
 * i,y
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include<string>
#include <array>
#include <exception>
#include <iostream>
#include <sstream>


#include"PhoneticFinder.hpp"

using namespace std;


std::string phonetic::find(std::string sentence, std::string word) {
    std::string match = "";
    try{

        bool checkTrueToContinur = check(sentence, word);

        if(!checkTrueToContinur){
            throw string("illegal letter in sentence or word");
        }else{

            int count = numOfWordsInSentence(sentence)+1;
            int index = 0;

            //splitting the sentence to array words
            string words[count];
            //https://stackoverflow.com/questions/16029324/splitting-a-string-into-an-array-in-c-without-using-vector
            int i = 0;
            stringstream ssin(sentence);
            while (ssin.good() && i < count){
                ssin >> words[i];
                ++i;
            }

            //https://en.cppreference.com/w/cpp/algorithm/transform
            //toLowerCase on the word.

            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });

            //toLowerCase on the sentence
            int size_of_words = sizeof(words)/ sizeof(string);

            for (int i = 0; i <size_of_words; i++) {
                std::transform(words[i].begin(), words[i].end(), words[i].begin(),[](unsigned char c) -> unsigned char { return std::tolower(c); });
            }

            //looking for misspelled letters as defined.
            int IndexToMatch = 0;
            index = 0;
            bool MatchesCurrectly = true;

            while ( (MatchesCurrectly) && ((IndexToMatch < size_of_words) && (index < word.length()))) {

                if (words[IndexToMatch].length() != word.length()) {
                    IndexToMatch++;
                    index = 0;
                } else {
                    //word from the sentence and the word were looking for have the same length.
                    //if identical end while.
                    if (words[IndexToMatch].compare(word) == 0) {
                        match = words[IndexToMatch];
                        return match;
                    } else {
                        //not identical compare between each letter and special cases.
                        index = 0;
                        string misspelled = words[IndexToMatch];
                        if (word.at(index) == misspelled.at(index)) {
                            index++;
                        } else if ((word.at(index) == 'v' || word.at(index) == 'w') &&
                                   (misspelled.at(index) == 'v' || misspelled.at(index) == 'w')) {
                            index++;
                        } else if (((word.at(index) == 'b') || (word.at(index) == 'f') || (word.at(index) == 'p')) &&
                                   ((misspelled.at(index) == 'b') || (misspelled.at(index) == 'f') ||
                                    (misspelled.at(index) == 'p'))) {
                            index++;
                        } else if (((word.at(index) == 'g') || (word.at(index) == 'j')) &&
                                   ((misspelled.at(index) == 'g') || (misspelled.at(index) == 'j'))) {
                            index++;
                        } else if (((word.at(index) == 'c') || (word.at(index) == 'k') || (word.at(index) == 'q')) &&
                                   ((misspelled.at(index) == 'c') || (misspelled.at(index) == 'k') ||
                                    (misspelled.at(index) == 'q'))) {
                            index++;
                        } else if (((word.at(index) == 's') || (word.at(index) == 'z')) &&
                                   ((misspelled.at(index) == 's') || (misspelled.at(index) == 'z'))) {
                            index++;
                        } else if (((word.at(index) == 'd') || (word.at(index) == 't')) &&
                                   ((misspelled.at(index) == 'd') || (misspelled.at(index) == 't'))) {
                            index++;
                        } else if (((word.at(index) == 'o') || (word.at(index) == 'u')) &&
                                   ((misspelled.at(index) == 'o') || (misspelled.at(index) == 'u'))) {
                            index++;
                        } else if (((word.at(index) == 'i') || (word.at(index) == 'y')) &&
                                   ((misspelled.at(index) == 'i') || (misspelled.at(index) == 'y'))) {
                            index++;
                        }else if((index == word.length()-1) && (IndexToMatch+1 != size_of_words)){
                            index = 0;
                            IndexToMatch++;
                        }else if((word.at(index<=65)) || (word.at(index)>=91 && word.at(index)<=96) || (word.at(index)>=123)){
                            throw string("ERROR: in find : illegal letter inserted!!!");
                        }

                    }
                    if((IndexToMatch+1 == size_of_words)&&(index == word.length()-1)){
                        match = words[IndexToMatch];
                    }else{
                        if(index< word.length()-1){
                            index++;
                        }else if((IndexToMatch+1 != size_of_words) && index == word.length()-1){
                            IndexToMatch++;
                        }
                    }

                }throw string("there is no similarity as defined!");
            }
            match = words[IndexToMatch];
        }throw string("mismatch letter in the word");
    }catch (string s){
        cout<<"ERROR: caught exception: "<<s<<endl;
    }
    return match;
}

int phonetic::numOfWordsInSentence(string sentence){
    if(sentence.empty()){
        int count = 0;
        return count;
    }
    int index = 0;
    int count = 0;
    while (index < sentence.length()-1) {
        if (sentence.at(index) != ' ' && sentence.at(index + 1) == ' ') {
            index++;
            count++;
        }
        index++;
    }
    return count;
}





/*
std::string phonetic::find(std::string sentence, std::string word) {

        string match = "";
        //value- true if word an sentence contains only letter ((a-b)^(A-B)) and word have no spaces in between(only one word allowed).
        //     - false illegal input inserted in either word or sentence.
        cout<<"Before: checkTrueToContinue "<<endl;
        bool checkTrueToContinue = check(sentence, word);
        cout<<"After: checkTrueToContinue "<<endl;
        //something went wrong - inserted wrong data.
        cout<<"firs if in find"<<endl;
        if (!checkTrueToContinue) {
            throw string("wrong data inserted!!!");
        } else {
            cout<<"firs if "<<endl;
            int count = 0;
            int index = 0;


            cout<<"Before: while"<<endl;
            //counts the number of words in a sentence
            while (index < sentence.length() - 1) {
                if (sentence.at(index) != ' ' && sentence.at(index + 1) == ' ') {
                    index++;
                    count++;
                } else {
                    index++;
                }
            }
            cout<<"After: while"<<endl;
            cout<<"Before: for"<<endl;
            //splitting the sentence into an array in order to find similarity over each word in the array that matches the word we are looking for.
            index = 0;
            string tmpWord = "";
            string words[count];
            for (auto x: sentence) {

                if (x != ' ') {
                    tmpWord += x;
                }
                if (x == ' ' && !tmpWord.empty()) {
                    words[index] = tmpWord;
                    index++;
                    tmpWord = "";
                }
            }
            cout<<"After: for"<<endl;
            //find the matching index in the array
            //words at (index) contains the word we need to return-inVariable
            //lower case.
            //while on words
            //look for mismatches as defined
            ///TO LOWER CASE - HOW TO
            https://en.cppreference.com/w/cpp/algorithm/transform
            //toLowerCase on the word.
            std::transform(word.begin(), word.end(), word.begin(),
                           [](unsigned char c) -> unsigned char { return std::tolower(c); });

            //toLowerCase on the sentence
            int size_of_words = sizeof(words)/ sizeof(string);
            cout<<"size_of_word: "<<size_of_words<<endl;

            for (int i = 0; i <size_of_words ; i++) {
                std::transform(words[i].begin(), words[i].end(), words[i].begin(),
                               [](unsigned char c) -> unsigned char { return std::tolower(c); });
                cout<<"words are: "<<words[i]<<" "<<endl;
            }

            cout<<"for ended success"<<endl;

}
*/


/**
 * this method checks for illegal input that may have been inserted to either the given sentence or the word we want to find in that sentence.
 * using ASCII value to match the legal pattern to be (a-z)(A-Z)(spaces- where their legal)
 * @param temp given sentence from the user.
 * @param word which similarity as defined ABOVE to find in the sentence.
 * @return true if sentence is legal and word is legal(contain words), false otherwise.
 */
bool phonetic::check(std::string sentence, std::string word) {
        if(sentence.empty() || word.empty()){
            if(word.empty())
                throw string("ERROR: empty word");
            else if(sentence.empty())
                throw string("ERROR: empty sentence");
        }else{
                int i = 0;

                //check the sentence for illegal content
                while ( (i < sentence.length()-1) &&((
                        ((sentence.at(i) >= 65 && sentence.at(i) <= 90))) || ((i < sentence.length()) &&(sentence.at(i) == 32)) || ((i < sentence.length()) &&
                         (sentence.at(i) >= 97 && sentence.at(i) <= 122))) ){
                    i++;
                }

                int j = 0;
                //check the word for illegal content
                //remove spaces from the word
                string tmp = "";
                for(auto x: word){
                    if(x!=' '){
                        tmp += x;
                    }
                }
                word = tmp;
                while ( (j<word.length()-1)&&((((word.at(j) >= 65 && word.at(j) <= 90))) || ((j < word.length()) &&
                       (word.at(j) >= 97 && word.at(j) <= 122)) || ((j == word.length()- 1) && (word.at(j) == 32))) ) {
                                            j++;

                }
                //one letter in the sentence is illegal or spaces may have been appeared in the word or it might be illegal letter in word
                //return false stop looking for the word in the sentence
//                cout<<"i value is: "<<i<<" sentence length -1 is: "<<sentence.length()-1<<endl;
//                cout<<"j value is: "<<j<<" word length -1 is: "<<word.length()-1<<endl;
                if (i == sentence.length()-1 &&  j == word.length()-1)return true;
        }
    return false;
}