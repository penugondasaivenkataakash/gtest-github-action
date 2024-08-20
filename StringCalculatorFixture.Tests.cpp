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
