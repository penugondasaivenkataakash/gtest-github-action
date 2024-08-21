#include <gtest/gtest.h>
#include "StringCalculator.h"
class string_calculator_add_Fixture:public testing::Test{
  protected:
  StringCalculator calculator;

};
class string_calculator_add_Parameter_Fixture:
                                 public string_calculator_add_Fixture, 
                                 public testing::WithParamInterface<std::tuple<std::string,int>>{
  protected:
  StringCalculator calculator;

};
INSTANTIATE_TEST_SUITE_P(SingleNumerParameter,
                         string_calculator_add_Parameter_Fixture,
                         testing::Values(
                                        std::make_tuple("1", 1),
                                        std::make_tuple("1,2",3)
  ));

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

TEST_F(string_calculator_add_Fixture,when_passed_a_single_number_returns_0_for_zero){
 //Arrange
  string input="0";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST_P(string_calculator_add_Parameter_Fixture,when_passed_a_single_Or_Multiple_Number_with_Delimiters_returns_Sum){
 //Arrange
  string input=std::get<0>(GetParam());
  int expectedsum=std::get<1>(GetParam());
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
