//
// Created by miros on 20/03/2020.
//

/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <string>
using namespace std;


TEST_CASE("Test replacement and uppercase-lowercase scenario of v and w"){

    string text = "very lovely evening";
    //case1-(5)
    CHECK(find(text, "very") == string("very"));
    CHECK(find(text, "werI") == string("very"));
    CHECK(find(text, "WeRi") == string("very"));
    CHECK(find(text, "verI") == string("very"));
    CHECK(find(text, "be") == string("very")); //should throw an exception

    //case2-(5)
    CHECK(find(text, "lovely") == string("lovely"));
    CHECK(find(text, "very lovely") == string("lovely"));//should throw an exception
    CHECK(find(text, "lUvely") == string("lovely"));
    CHECK(find(text, "luvelI") == string("lovely"));
    CHECK(find(text, "loWely") == string("lovely"));

    //case3-(15)
    text = "Weri lUwely ewenYng";

    CHECK(find(text, "werI") == string("Weri"));
    CHECK(find(text, "WerY") == string("Weri"));
    CHECK(find(text, "VeRi") == string("Weri"));
    CHECK(find(text, "Very") == string("Weri"));
    CHECK(find(text, "very") == string("Weri"));
    CHECK(find(text, "LoVeLy") == string("lUwely"));
    CHECK(find(text, "luvelI") == string("lUwely"));
    CHECK(find(text, "LOVELi") == string("lUwely"));
    CHECK(find(text, "Love") == string("Weri"));//should throw an exception
    CHECK(find(text, "evening") == string("ewenYng"));
    CHECK(find(text, "eWening") == string("ewenYng"));
    CHECK(find(text, "ewENINj") == string("ewenYng"));
    CHECK(find(text, "evninj") == string("ewenYng"));
    CHECK(find(text, "EVENING") == string("ewenYng"));
    CHECK(find(text, "EwEnYnJ") == string("ewenYng"));

    //total cases 25
}

TEST_CASE("Test replacement and uppercase-lowercase scenario of b and f and p"){

    //case1-(11)
    string text = "boyfriend fulfilling his dest";

    CHECK(find(text, "Boyfriend") == string("boyfriend"));
    CHECK(find(text, "foyPriend") == string("boyfriend"));
    CHECK(find(text, "PoyfrienD") == string("boyfriend"));
    CHECK(find(text, "p yfriend") == string("boyfriend"));//should throw an exception
    CHECK(find(text, "FOYpRIENd") == string("boyfriend"));
    CHECK(find(text, "PulBilling") == string("fulfilling"));
    CHECK(find(text, "pUlPiLlInG") == string("fulfilling"));
    CHECK(find(text, "BulPilling") == string("fulfilling"));
    //mixed
    CHECK(find(text, "BoIpryend") == string("boyfriend"));
    CHECK(find(text, "bulpylling") == string("fulfilling"));
    CHECK(find(text, "bulfyllingg") == string("fulfilling"));//should throw an exception

    //case2-(10)
    text = "FoyPriend Pulbilling his dest";

    CHECK(find(text, "Boyfriend") == string("FoyPriend"));
    CHECK(find(text, "poybrienD") == string("FoyPriend"));
    CHECK(find(text, "FoyPriend") == string("FoyPriend"));
    CHECK(find(text, "BOYBRIENd") == string("FoyPriend"));
    CHECK(find(text, "l") == string("Pulbilling"));//should throw an exception
    CHECK(find(text, "Fulfilling") == string("Pulbilling"));
    CHECK(find(text, "fulfiLLing") == string("Pulbilling"));
    CHECK(find(text, "BULPillinf") == string("Pulbilling"));
    CHECK(find(text, "FoyPriendBULPillinf") == string("Pulbilling"));//should throw an exception
    CHECK(find(text, "FULPILLINF") == string("Pulbilling"));

    //case3-mixed misspelled-(9)
    CHECK(find(text, "Puibryent") == string("FoyPriend"));
    CHECK(find(text, "boyfriend") == string("FoyPriend"));
    CHECK(find(text, "boiBRYent") == string("FoyPriend"));
    CHECK(find(text, "Poi2rint") == string("FoyPriend"));//shouldn't work!! if return expected algorithm should be fixed.
    CHECK(find(text, "goyPriend") == string("FoyPriend"));//shouldn't work!! if return expected algorithm should be fixed.
    CHECK(find(text, "fulfilling") == string("Pulbilling"));
    CHECK(find(text, "folPYlling") == string("Pulbilling"));
    CHECK(find(text, "BolpyLLynj") == string("Pulbilling"));
    CHECK(find(text, "FoyPriend Pulbilling") == string("FoyPriend Pulbilling"));//should throw an exception word cannot be longer then 1 word!

    //total cases 30
}

TEST_CASE("Test replacement and uppercase lower case of p and b"){

}

TEST_CASE("Test replacement and uppercase lower case p and f"){

}

TEST_CASE("Test replacement and uppercase lower case of b and f"){

}

TEST_CASE("Test replacement and uppercase-lowercase scenario of g and j"){

    string text = " ";
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
    CHECK(find(text," ") == string(""));
}

TEST_CASE("Test replacement and uppercase lower case of c and k"){

}

TEST_CASE("Test replacement and uppercase lower case of c and q"){

}

TEST_CASE("Test replacement and uppercase lower case of k and q"){

}

TEST_CASE("Test replacement and uppercase-lowercase scenario of c and k and q"){

    string text = " ";
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
}

TEST_CASE("Test replacement and uppercase-lowercase scenario of s and z"){

    string text = " ";
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
}

TEST_CASE("Test replacement and uppercase-lowercase scenario of d and t"){

    string text = " ";
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
}

TEST_CASE("Test replacement and uppercase-lowercase scenario of o and u"){

    string text = " ";
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
}

TEST_CASE("Test replacement and uppercase-lowercase scenario of i and y"){

    string text = " ";
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
}

//-------------------------------------------------------//
//_______________EREL_SEGAL_TESTS________________________//


TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
            CHECK(find(text, "happi") == string("Happi"));
            CHECK(find(text, "Happi") == string("Happi"));
            CHECK(find(text, "HAPPI") == string("Happi"));
            CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}

/* Add more test cases here */
