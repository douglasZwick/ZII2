#include <iostream>
#include <iomanip>
#include <string>
#include <ZII2/Engine/Engine.hpp>
#include <ZII2/Math/Matrix.hpp>
#include <ZII2/Math/Pixit.hpp>

int main(int argc, char *argv[])
{
  using ZII2::Matrix3x3;
  using ZII2::Pixit;

  //ZII2::Engine engine;

  Matrix3x3<Pixit> lhs(
    Pixit(3, 9),  Pixit(-5, 0), Pixit(-1, 1),
    Pixit(2.25f), Pixit(0),     Pixit(2, 8),
    Pixit(1, 1),  Pixit(-7, 7), Pixit(0, 15));
  Matrix3x3<Pixit> rhs(
    Pixit(3, 9), Pixit(-5, 0), Pixit(-1, 1),
    Pixit(2.25f), Pixit(0), Pixit(2, 8),
    Pixit(1, 1), Pixit(-7, 7), Pixit(0, 15));
  Matrix3x3<Pixit> sum = lhs - lhs;
  //Matrix3x3<int> lhs(
  //  1, 2, 3,
  //  4, 5, 6,
  //  7, 8, 9);
  //Matrix3x3<int> rhs(
  //  1, 2, 3,
  //  4, 5, 6,
  //  7, 8, 9);
  //Matrix3x3<int> sum = lhs + rhs;

  std::cout << std::setw(8);
  std::cout << sum(0, 0);
  std::cout << std::setw(8);
  std::cout << sum(1, 0);
  std::cout << std::setw(8);
  std::cout << sum(2, 0) << std::endl;
  std::cout << std::setw(8);
  std::cout << sum(0, 1);
  std::cout << std::setw(8);
  std::cout << sum(1, 1);
  std::cout << std::setw(8);
  std::cout << sum(2, 1) << std::endl;
  std::cout << std::setw(8);
  std::cout << sum(0, 2);
  std::cout << std::setw(8);
  std::cout << sum(1, 2);
  std::cout << std::setw(8);
  std::cout << sum(2, 2) << std::endl;

  int status = 0;// engine.RunSDL();

  return status;
}
