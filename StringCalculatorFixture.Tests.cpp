#include "StringCalculator.h"
#include <gtest/gtest.h>

class  StringCalculatorAddTestFixture:public testing::Test {
  // Here we can have a common reusable code and Hook Callbacks

  protected:
    StringCalculator calculator;
};

TEST_F(StringCalculatorAddTestFixture,when_passed_a_single_number_returns_0_for_empty_string) {
  string input="";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_a_single_number_returns_0_for_zero) {
  string input="";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_a_single_number_returns_1_for_one){
  string input="1";
  int expectedsum=1;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_two_comma_delimited_numbers_returns_their_sum){
  string input="1,2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_multiple_comma_delimited_numbers_returns_their_sum){
  string input="1,2,3";
  int expectedsum=6;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_delimited_with_newline_and_comma_returns_their_sum){
  string input="1\n2,3";
  int expectedsum=6;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_a_delimiter_returns_the_sum_based_on_that_delimiter){
  string input="//;\n1;2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_negative_numbers_throws_an_exception_listing_invalid_values){
  string input="1,-2,-4,5";
  int expectedsum=3;
    try {
        calculator.Add(input);
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument& e) {
        EXPECT_EQ(std::string(e.what()), "Negatives not allowed: -2,-4");
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST_F(StringCalculatorAddTestFixture,when_passed_numbers_over_1000_ignores_them){
  string input="42,1001,3";
  int expectedsum=45;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}


TEST_F(StringCalculatorAddTestFixture,when_passed_multicharacter_delimiter_uses_that_delimiter_to_sum_values){
  string input="//[***]\n8***2***3";
  int expectedsum=13;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_multiple_delimiters_sums_on_each_delimiter){
  string input="//[*][%]\n4*2%3";
  int expectedsum=9;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_F(StringCalculatorAddTestFixture,when_passed_multiple_multicharacter_delimiters_sums_on_each_delimiter){
  string input="//[**][%^]\n4**1%^9";
  int expectedsum=14;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
