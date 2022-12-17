#ifndef UNITARY_TEST_HPP
#define UNITARY_TEST_HPP

#include <YT/Command.hpp>
#include <YT/Field.hpp>
#include <YT/Other.hpp>
#include <cassert>
#include <iostream>
#include<YT/Flag.hpp>
#include <cstring>
#include <cctype> 
#include <algorithm>
#define assertErr(msg , str) ((msg + str).c_str)


void UT_Field();
void UT_Command();
void UT_Other();
void UT_Flag();

#endif