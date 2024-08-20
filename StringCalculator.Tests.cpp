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
  string input1="1";
  string input2="2"
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input1,input2);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
