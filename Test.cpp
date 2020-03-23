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
using namespace phonetic;


TEST_CASE("Test replacement and uppercase-lowercase scenario of v and w"){

    string text = "very lovely evening";
    //case1-(5)
            CHECK(find(text, "very") == string("very"));
            CHECK(find(text, "werI") == string("very"));
            CHECK(find(text, "WeRi") == string("very"));
            CHECK(find(text, "verI") == string("very"));
            CHECK_THROWS(find(text, "be") == string("very")); //should throw an exception

    //case2-(5)
            CHECK(find(text, "lovely") == string("lovely"));
            CHECK_THROWS(find(text, "very lovely") == string("lovely"));//should throw an exception
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
            CHECK_THROWS(find(text, "Love") == string("Weri"));//should throw an exception
            CHECK(find(text, "evening") == string("ewenYng"));
            CHECK(find(text, "eWening") == string("ewenYng"));
            CHECK(find(text, "ewENINj") == string("ewenYng"));
            CHECK(find(text, "evninj") == string("ewenYng"));
            CHECK(find(text, "EVENING") == string("ewenYng"));
            CHECK(find(text, "EwEnYnJ") == string("ewenYng"));

    //total cases 25
}

TEST_CASE("Test replacement and uppercase-lowercase scenario of b and f and p"){

    //case1-(8)
    string text = "boyfriend fulfilling his dest";

            CHECK(find(text, "Boyfriend") == string("boyfriend"));
            CHECK(find(text, "foyPriend") == string("boyfriend"));
            CHECK(find(text, "PoyfrienD") == string("boyfriend"));
            CHECK_THROWS(find(text, "p yfriend") == string("boyfriend"));//should throw an exception
            CHECK(find(text, "FOYpRIENd") == string("boyfriend"));
            CHECK(find(text, "PulBilling") == string("fulfilling"));
            CHECK(find(text, "pUlPiLlInG") == string("fulfilling"));
            CHECK(find(text, "BulPilling") == string("fulfilling"));
    //mixed-(3)
            CHECK(find(text, "BoIpryend") == string("boyfriend"));
            CHECK(find(text, "bulpylling") == string("fulfilling"));
            CHECK_THROWS(find(text, "bulfyllingg") == string("fulfilling"));//should throw an exception

    //case2-(10)
    text = "FoyPriend Pulbilling his dest";

            CHECK(find(text, "Boyfriend") == string("FoyPriend"));
            CHECK(find(text, "poybrienD") == string("FoyPriend"));
            CHECK(find(text, "FoyPriend") == string("FoyPriend"));
            CHECK(find(text, "BOYBRIENd") == string("FoyPriend"));
            CHECK_THROWS(find(text, "l") == string("Pulbilling"));//should throw an exception
            CHECK(find(text, "Fulfilling") == string("Pulbilling"));
            CHECK(find(text, "fulfiLLing") == string("Pulbilling"));
            CHECK(find(text, "BULPillinf") == string("Pulbilling"));
            CHECK_THROWS(find(text, "FoyPriendBULPillinf") == string("Pulbilling"));//should throw an exception
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
            CHECK_THROWS(find(text, "FoyPriend Pulbilling") == string("FoyPriend Pulbilling"));//should throw an exception word cannot be longer then 1 word!

    //total cases 30
}

//-------------------------------------------------------//
//_______________EREL_SEGAL_TESTS________________________//


TEST_CASE("Test replacement of p and b") {

    string text = "xxx happy yyy";

            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";

            CHECK(find(text, "happi") == string("Happi"));
            CHECK(find(text, "Happi") == string("Happi"));
            CHECK(find(text, "HAPPI") == string("Happi"));
            CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here ***********************************************/
}

TEST_CASE("Test replacement and uppercase lower case p and f"){

    string text = " powerful fire loop";
            //case1-(12)
            CHECK(find(text,"powerpul") == string("powerful"));
            CHECK_THROWS(find(text,"powerPull") == string("powerful"));//should throw exception
            CHECK(find(text,"PowerPul") == string("powerful"));
            CHECK(find(text,"FOWERPUL") == string("powerful"));
            CHECK(find(text,"foweful") == string("powerful"));
            CHECK_THROWS(find(text,"fowerful fire ") == string("powerful"));
            CHECK(find(text,"PIRE") == string("fire"));
            CHECK_THROWS(find(text," Pire ") == string("fire"));
            CHECK_THROWS(find(text,"l fire") == string("fire"));
            CHECK(find(text,"loop") == string("loop"));
            CHECK(find(text,"looF") == string("loop"));
            CHECK_THROWS(find(text,"e Loof ") == string("loop"));

            //mixed cases-(8)
            CHECK_THROWS(find(text,"Fowerfull") == string("powerful"));
            CHECK(find(text,"fuverPol") == string("powerful"));
            CHECK(find(text,"PoverPOL") == string("powerful"));
            CHECK_THROWS(find(text,"POVERgoll") == string("powerful"));
            CHECK(find(text,"Fyre") == string("fire"));
            CHECK(find(text,"Pyre") == string("fire"));
            CHECK_THROWS(find(text,"PYyre") == string("fire"));
            CHECK(find(text,"p!re") == string("fire"));
            CHECK(find(text,"lOuf") == string("loop"));
            CHECK(find(text,"L0uF") == string("loop"));
            CHECK(find(text," lUUf") == string("loop"));
            CHECK(find(text,"lUop") == string("loop"));
            CHECK_THROWS(find(text,"lUOPp") == string("loop"));

    //25 cases
}

TEST_CASE("Test replacement and uppercase lower case of b and f"){

    string text = "butterfly big buffer ";

    //case1-(7)
            CHECK(find(text,"butterfly") == string("butterfly"));
            CHECK(find(text,"butterFlY") == string("butterfly"));
            CHECK_THROWS(find(text,"BuTT3rfly") == string("butterfly"));//should throw an exception.
            CHECK(find(text,"futterFly") == string("butterfly"));
            CHECK(find(text,"f0tt3RFLY") == string("butterfly"));
            CHECK(find(text,"butterfl$") == string("butterfly"));//should throw an exception.
            CHECK_THROWS(find(text,"Futt3rflyy") == string("butterfly"));//should throw an exception.

    //case2-(5)
            CHECK(find(text,"big") == string("big"));
            CHECK(find(text,"bIg") == string("big"));
            CHECK_THROWS(find(text,"Figg") == string("big"));//should throw an exception.
            CHECK_THROWS(find(text,"F1g") == string("big"));//should throw an exception.
            CHECK(find(text," fig") == string("big"));

    //case3-(9)
            CHECK(find(text,"bufber") == string("buffer"));
            CHECK(find(text,"bubfer") == string("buffer"));
            CHECK(find(text,"buBBer") == string("buffer"));
            CHECK(find(text,"FuBBeR") == string("buffer"));
            CHECK(find(text,"fufber") == string("buffer"));
            CHECK(find(text,"fubFEr") == string("buffer"));
            CHECK(find(text,"fuFFer") == string("buffer"));
            CHECK_THROWS(find(text,"fuFFerR") == string("buffer"));//should throw an exception.
            CHECK(find(text,"fu3ber") == string("buffer"));

    //mixed cases-(40)
            text = "Futterbly Fig fuBBer ";

            CHECK(find(text,"Futterbly") == string("Futterbly"));
            CHECK(find(text,"futterfly") == string("Futterbly"));
            CHECK(find(text,"futterPly") == string("Futterbly"));
            CHECK(find(text,"FuDterbly") == string("Futterbly"));
            CHECK(find(text,"Futderbly") == string("Futterbly"));
            CHECK(find(text,"Fudderbly") == string("Futterbly"));
            CHECK(find(text,"Putterbly") == string("Futterbly"));
            CHECK(find(text,"pudterbly") == string("Futterbly"));
            CHECK(find(text,"Putderbly") == string("Futterbly"));
            CHECK(find(text,"pudderfly") == string("Futterbly"));
            CHECK(find(text,"Podterfli") == string("Futterbly"));
            CHECK(find(text,"Futterpli") == string("Futterbly"));
            CHECK(find(text,"Futderbli") == string("Futterbly"));
            CHECK(find(text,"Fodterbli") == string("Futterbly"));
            CHECK_THROWS(find(text,"F{tterpli") == string("Futterbly"));//should throw an exception.
            CHECK(find(text,"Fig") == string("Fig"));
            CHECK(find(text,"fyg") == string("Fig"));
            CHECK(find(text,"fyj") == string("Fig"));
            CHECK(find(text,"fij") == string("Fig"));
            CHECK(find(text,"Pig") == string("Fig"));
            CHECK(find(text,"pYg") == string("Fig"));
            CHECK(find(text,"pYj") == string("Fig"));
            CHECK(find(text,"pIj") == string("Fig"));
            CHECK_THROWS(find(text,"p1g") == string("Fig"));//should throw an exception.
            CHECK_THROWS(find(text," ") == string("Fig"));//should throw an exception.
            CHECK(find(text,"Fubber") == string("fuBBer"));
            CHECK(find(text,"fubper") == string("fuBBer"));
            CHECK(find(text,"fupber") == string("fuBBer"));
            CHECK(find(text,"fubfer") == string("fuBBer"));
            CHECK(find(text,"fufber") == string("fuBBer"));
            CHECK(find(text,"fupper") == string("fuBBer"));
            CHECK(find(text,"fuffer") == string("fuBBer"));
            CHECK(find(text,"puffer") == string("fuBBer"));
            CHECK(find(text,"pubber") == string("fuBBer"));
            CHECK(find(text,"pufber") == string("fuBBer"));
            CHECK(find(text,"bubfer") == string("fuBBer"));
            CHECK(find(text,"buffer") == string("fuBBer"));
            CHECK(find(text,"bufbeR") == string("fuBBer"));
            CHECK_THROWS(find(text,"") == string("fuBBer"));//should throw an exception.
            CHECK_THROWS(find(text,"7@BBer") == string("fuBBer"));//should throw an exception.
            CHECK_THROWS(find(text,"fuubber") == string("fuBBer"));//should throw an exception.

    //61 cases
}

TEST_CASE("Test replacement and uppercase-lowercase scenario of g and j"){

    string text = "garbage geeking programing";

            //case1-(8)
            CHECK(find(text,"garbage ") == string("garbage"));
            CHECK(find(text,"garbaje") == string("garbage"));
            CHECK(find(text," garBAJE") == string("garbage"));
            CHECK(find(text,"Jarbage") == string("garbage"));
            CHECK(find(text,"JarbaJe") == string("garbage"));
            CHECK_THROWS(find(text,"Parbaje") == string("garbage"));//should throw an exception.
            CHECK_THROWS(find(text,"Parbage") == string("garbage"));//should throw an exception.
            CHECK_THROWS(find(text," ") == string("garbage"));//should throw an exception.

            //case2-(8)
            CHECK(find(text,"geeking") == string("geeking"));
            CHECK(find(text," geeking") == string("geeking"));
            CHECK(find(text,"geeking ") == string("geeking"));
            CHECK(find(text,"geekinJ") == string("geeking"));
            CHECK(find(text,"JeekinJ") == string("geeking"));
            CHECK(find(text,"Jeeking") == string("geeking"));
            CHECK_THROWS(find(text,"Jeekingg") == string("geeking"));//should throw an exception.
            CHECK_THROWS(find(text,"JeekiIng") == string("geeking"));//should throw an exception.

            //case3-(7)
            CHECK(find(text,"programing") == string("programing"));
            CHECK(find(text,"programinJ") == string("programing"));
            CHECK(find(text,"proJraming") == string("programing"));
            CHECK(find(text,"PROJraminj") == string("programing"));
            CHECK_THROWS(find(text,"!23$%") == string("programing"));//should throw an exception.
            CHECK_THROWS(find(text,"!@#%$%%^&^%$") == string("programing"));//should throw an exception.
            CHECK_THROWS(find(text,"!") == string("programing"));//should throw an exception.

            text = "gaggage jegIinJ FrogGraminj";

            //mixed cases-(40)
            CHECK(find(text,"GAGGAGE") == string("gaggage"));
            CHECK(find(text,"gaggaje") == string("gaggage"));
            CHECK(find(text,"gagjage") == string("gaggage"));
            CHECK(find(text,"gagjaje") == string("gaggage"));
            CHECK(find(text,"gajjage") == string("gaggage"));
            CHECK(find(text,"gajjaje") == string("gaggage"));
            CHECK(find(text,"jaggage") == string("gaggage"));
            CHECK(find(text,"jaggaje") == string("gaggage"));
            CHECK(find(text,"jagjage") == string("gaggage"));
            CHECK(find(text,"jajgage") == string("gaggage"));
            CHECK(find(text,"jagjaje") == string("gaggage"));
            CHECK(find(text,"jajgaje") == string("gaggage"));
            CHECK_THROWS(find(text,"gaggagee") == string("gaggage"));//should throw an exception.
            CHECK_THROWS(find(text,"ra") == string("gaggage"));//should throw an exception.
            CHECK_THROWS(find(text,"") == string("gaggage"));//should throw an exception.
            CHECK_THROWS(find(text," ") == string("gaggage"));//should throw an exception.


            CHECK(find(text,"jegIynj") == string("jegIinJ"));
            CHECK(find(text,"jegIYng") == string("jegIinJ"));
            CHECK(find(text,"jejIynj") == string("jegIinJ"));
            CHECK(find(text,"jejIyng") == string("jegIinJ"));
            CHECK(find(text,"gegIynj") == string("jegIinJ"));
            CHECK(find(text,"gegiinj") == string("jegIinJ"));
            CHECK(find(text,"gegIyng") == string("jegIinJ"));
            CHECK(find(text,"gegYYnj") == string("jegIinJ"));
            CHECK(find(text,"jegIinj1") == string("jegIinJ"));//should throw an exception.
            CHECK(find(text,"gejYYn&") == string("jegIinJ"));//should throw an exception.
            CHECK(find(text,"!@#$$%$") == string("jegIinJ"));//should throw an exception.
            CHECK(find(text," ") == string("jegIinJ"));//should throw an exception.

            CHECK(find(text,"FrogGraminj") == string("FrogGraminj"));
            CHECK(find(text,"FrogGraming") == string("FrogGraminj"));
            CHECK(find(text,"FrogjraMinj") == string("FrogGraminj"));
            CHECK(find(text,"FrojGraminj") == string("FrogGraminj"));
            CHECK(find(text,"FrogJraming") == string("FrogGraminj"));
            CHECK(find(text,"FroJgraming") == string("FrogGraminj"));
            CHECK(find(text,"proJGraming") == string("FrogGraminj"));
            CHECK(find(text,"brogGraminj") == string("FrogGraminj"));
            CHECK(find(text,"bruJGraminj") == string("FrogGraminj"));
            CHECK(find(text,"ProJJramYnG") == string("FrogGraminj"));
            CHECK(find(text,"broJJraminj") == string("FrogGraminj"));
            CHECK(find(text,"broJjraming") == string("FrogGraminj"));

    //63 cases
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
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));

    //20 cases
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
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));

    //20 cases
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
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));

    //20 cases
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
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));

    //20 cases
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
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));
            CHECK(find(text," ") == string(""));

    //20 cases
}

    //TOTAL number of tests executed is:


