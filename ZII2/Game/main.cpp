//#include <iostream>
//#include <iomanip>
//#include <string>
#include <ZII2/Engine/Engine.hpp>
//#include <ZII2/Math/Matrix.hpp>
//#include <ZII2/Math/Pixit.hpp>
//#include <ZII2/Math/Vec2.hpp>
//#include "ZII2/Engine/Types.hpp"

int main(int argc, char *argv[])
{
  //using ZII2::Matrix3x3;
  //using ZII2::Pixit;
  //using ZII2::Vec2;
  //using ZII2::Float2;

  //typedef Vec2<Pixit> Pixit2;

  ZII2::Engine engine;

  //Pixit2 lhs(Pixit(3, 9), -Pixit(1, 1));
  //Pixit2 rhs(-Pixit(2, 11), Pixit(-2.5f));
  //Pixit scalar = Pixit(1.1f);
  //Pixit divisor = scalar;
  //Pixit2 sum = lhs + rhs;
  //Pixit2 difference = lhs - rhs;
  //Pixit2 reverseDifference = rhs - lhs;
  //Pixit2 product = lhs * rhs;
  //Pixit2 quotient = lhs / rhs;
  //Pixit2 inverseQuotient = rhs / lhs;
  //Pixit2 lhsScaled = lhs * scalar;
  //Pixit2 lhsDivided = lhs / divisor;
  //Pixit2 rhsScaled = rhs.Scale(scalar);
  //Pixit2 rhsDivided = rhs.Divide(divisor);

  //std::cout << "LHS: " << lhs << std::endl;
  //std::cout << "RHS: " << rhs << std::endl;
  //std::cout << "Scalar: " << scalar << std::endl;
  //std::cout << "Divisor: " << divisor << std::endl;
  //std::cout << std::endl;
  //std::cout << "Sum: " << sum << std::endl;
  //std::cout << "Difference: " << difference << std::endl;
  //std::cout << "Reverse Difference: " << reverseDifference << std::endl;
  //std::cout << "Product: " << product << std::endl;
  //std::cout << "Quotient: " << quotient << std::endl;
  //std::cout << "Inverse Quotient: " << inverseQuotient << std::endl;
  //std::cout << "LHS Scaled: " << lhsScaled << std::endl;
  //std::cout << "LHS Divided: " << lhsDivided << std::endl;
  //std::cout << "RHS Scaled: " << rhsScaled << std::endl;
  //std::cout << "RHS Divided: " << rhsDivided << std::endl;

  int status = engine.RunOpenGL();
  //int status = 0;

  return status;
}
