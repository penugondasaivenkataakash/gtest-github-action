#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(string_calculator_add_when_passed_a_single_number,returns_0_for_empty_string){
 //Arrange
  StringCalculator calculator;
  string input="";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_a_single_number,returns_0_for_zero){
 //Arrange
  StringCalculator calculator;
  string input="0";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_a_single_number,returns_1_for_one){
 //Arrange
  StringCalculator calculator;
  string input="1";
  int expectedsum=1;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_two_comma_delimited_numbers,returns_their_sum){
 //Arrange
  StringCalculator calculator;
  string input="1,2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_multiple_comma_delimited_numbers,returns_their_sum){
 //Arrange
  StringCalculator calculator;
  string input="1,2,3";
  int expectedsum=6;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_delimited_with_newline_and_comma,returns_their_sum){
 //Arrange
  StringCalculator calculator;
  string input="1\n2,3";
  int expectedsum=6;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_a_delimiter,returns_the_sum_based_on_that_delimiter){
 //Arrange
  StringCalculator calculator;
  string input="//;\n1;2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_negative_numbers,throws_an_exception_listing_invalid_values){
  StringCalculator calculator;
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

TEST(string_calculator_add_when_passed_numbers_over_1000,ignores_them){
 //Arrange
  StringCalculator calculator;
  string input="42,1001,3";
  int expectedsum=45;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

