/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#include "math.h"
using namespace itertools;
using std::string;
#define COMMA ,

int main()
{

    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0)
    {

        // BASIC TESTS - DO NOT CHANGE
        range r13{1, 3}, r25{2, 5}, r35{3, 5};
        range rAB('A', 'C'), r09{'0', '9'}, r00{'0', '0'};

        int checkEquals = 1;
        testcase.setname("range");
        for (int i : r13)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }
        checkEquals = 2;

        for (int i : r25)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }
        checkEquals = 3;

        for (int i : r35)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }
        char checkEqualsC = 'A';

        for (int i : rAB)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }
        checkEqualsC = '0';

        for (int i : r09)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }

        for (int i : r00)
        {
            testcase.CHECK_EQUAL(0, 1); // fail , shouldnt return anything
        }

        testcase.setname("chain");
        // BASIC TESTS - DO NOT CHANGE
        chain c13{range{1, 2}, range{2, 4}}, c25{range{2, 3}, range{3, 6}}, c35{range{3, 4}, range{4, 6}};
        chain cST15{std::string("abcd"), range{1, 5}}, cST16_{std::string("1234"), range{5, 7}};
        chain c15ST{range{1, 5}, std::string("abcd")}, cST16{range{1, 5}, std::string("5678")};
        chain cST{std::string("1234"), std::string("5678")};

        checkEquals = 1;
        for (int i : c13)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }
        checkEquals = 2;
        for (int i : c25)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }
        checkEquals = 3;

        for (int i : c35)
        {
            testcase.CHECK_EQUAL(i, checkEquals);
            checkEquals++;
        }
        string input = "";
        string output = "abcd12345";

        for (int i : cST15)
        {
            input += (char)i;
        }
        testcase.CHECK_EQUAL(input, output);

        input = "";
        output = "123456";

        for (int i : cST16_)
        {
            input += (char)i;
        }
        testcase.CHECK_EQUAL(input, output);

        input = "";
        output = "123456";

        for (int i : cST16)
        {
            input += (char)i;
        }
        testcase.CHECK_EQUAL(input, output);

        for (int i : cST)
        {
            input += (char)i;
        }
        testcase.CHECK_EQUAL(input, output);

        testcase.setname("zip");
        int counter = 0;

        for (auto pair : zip{range{1, 2}, string("a")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(1, counter);

        counter = 0;
        for (auto pair : zip{string("a"), range{1, 2}})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(1, counter);

        counter = 0;
        for (auto pair : zip{string("2"), string("a")})
        {
            counter++;
        }

        counter = 0;
        for (auto pair : zip{range{1.1, 2.2}, string("a")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(1, counter);
        testcase.setname("product");
        counter = 0;
        for (auto pair : product{range{1, 2}, string("a")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(1, counter);

        counter = 0;

        for (auto pair : product{string("a"), range{1, 2}})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(1, counter);

        counter = 0;
        for (auto pair : product{string("2"), string("a")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(1, counter);

        counter = 0;
        for (auto pair : product{range{1.1, 2.2}, string("a")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(1, counter);

        testcase.setname("powerset");
        counter = 0;
        for (auto pair : powerset{string("abc")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(counter, pow(2, 3));

        counter = 0;
        for (auto pair : powerset{string("abcde")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(counter, pow(2, 5));

        counter = 0;
        for (auto pair : powerset{string("12345")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(counter, pow(2, 5));

        counter = 0;
        for (auto pair : powerset{string("hello world")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(counter, pow(2, 11));

        counter = 0;
        for (auto pair : powerset{string("hello!@#$")})
        {
            counter++;
        }
        testcase.CHECK_EQUAL(counter, pow(2, 9));

        /*
		in all of this cases threre should be an extion  , case letters in the string , spaces ,tabs and other things
		*/

        grade = testcase.grade();
    }
    else
    {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}
