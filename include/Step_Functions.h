//
// Created by blackberry on 27.07.2020.
//

#ifndef PRIMEROOT_STEP_FUNCTIONS_H
#define PRIMEROOT_STEP_FUNCTIONS_H

#endif //PRIMEROOT_STEP_FUNCTIONS_H

#include <boost/multiprecision/gmp.hpp>

#define MAX_N_SIZE 1024
#define MAX_XY_SIZE MAX_N_SIZE / 2 + 1

using namespace boost::multiprecision;

///Constant variables
enum BranchType{
    equalLeft       = 0b11100, ///flipped: 0b00011, offloaded: 0b01100
    equalRight      = 0b10011, ///flipped: 0b01100, offloaded: 0b00011
    oppositeLeft    = 0b11001, ///flipped: 0b00110, offloaded: 0b01001
    oppositeRight   = 0b10110  ///flipped: 0b01001, offloaded: 0b00110

//    equalLeft       = 0b100, ///flipped: 0b011, offloaded: 0b000
//    equalRight      = 0b111, ///flipped: 0b000, offloaded: 0b011
//    oppositeLeft    = 0b101, ///flipped: 0b010, offloaded: 0b001
//    oppositeRight   = 0b110  ///flipped: 0b001, offloaded: 0b010
};

enum StrategyType{
    equalLeft_oppositeLeft      = 0b1110011001,
    equalRight_oppositeLeft     = 0b1001111001,
    equalLeft_oppositeRight     = 0b1110010110,
    equalRight_oppositeRight    = 0b1001110110
};

///Single functions
void         getNodeType(const mpz_t& number, const mpz_t& result, unsigned int position, unsigned int branches[MAX_N_SIZE]);
void         makeResult (mpz_t& result, const mpz_t& previousResult, unsigned int position, unsigned int branchType, mpz_t& x, mpz_t& y, mpz_t& diff);

///Composite functions
void         setXY      (mpz_t& x, mpz_t& y, unsigned int position, unsigned int branchType);
void         resetXY    (mpz_t& x, mpz_t& y, unsigned int position);

/////Test functions
//unsigned int test_getNodeType(mpz_int number, mpz_int result, bool verbose);
//unsigned int test_setXY(mpz_int x, mpz_int y, bool verbose);
//unsigned int test_resetXY(mpz_int x,mpz_int y, bool verbose);
//unsigned int test_makeResult(mpz_int result, mpz_int previousResult, mpz_int x, mpz_int y, bool verbose);
