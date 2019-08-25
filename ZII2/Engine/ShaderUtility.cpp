#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <GL/glew.h>
#include "ShaderUtility.hpp"

unsigned int ZII2::ShaderUtility::Load(char const * vertexPath, char const * fragmentPath)
{
  // Create the shaders
  GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

  // Read the vertex shader code from the file
  std::string vertexShaderCode;
  std::ifstream vertexShaderStream(vertexPath, std::ios::in);
  
  if (!vertexShaderStream.is_open())
  {
    std::cout << "Unable to open " << vertexPath <<
      ". Are you in the right directory?" << std::endl;
    return 0;
  }

  std::stringstream stream;
  stream << vertexShaderStream.rdbuf();
  vertexShaderCode = stream.str();
  vertexShaderStream.close();

  // Read the fragment shader code from the file
  std::string fragmentShaderCode;
  std::ifstream fragmentShaderStream(fragmentPath, std::ios::in);

  if (fragmentShaderStream.is_open())
  {
    std::stringstream stream;
    stream << fragmentShaderStream.rdbuf();
    fragmentShaderCode = stream.str();
    fragmentShaderStream.close();
  }

  GLint result = GL_FALSE;
  int infoLogLength = 0;

  // Compile the vertex shader
  std::cout << "Compiling vertex shader from " << vertexPath << "...." << std::endl;
  char const * vertexSourcePointer = vertexShaderCode.c_str();
  glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL);
  glCompileShader(vertexShaderID);

  // Check the vertex shader
  glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
  glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

  if (infoLogLength > 0)
  {
    std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
    glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
    std::cout << &vertexShaderErrorMessage[0] << std::endl;
  }

  // Compile the fragment shader
  std::cout << "Compiling fragment shader from " << fragmentPath << "...." << std::endl;
  char const * fragmentSourcePointer = fragmentShaderCode.c_str();
  glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL);
  glCompileShader(fragmentShaderID);

  // Check the fragment shader
  glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
  glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

  if (infoLogLength > 0)
  {
    std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
    glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
    std::cout << &fragmentShaderErrorMessage[0] << std::endl;
  }

  // Link the program
  std::cout << "Linking shader...." << std::endl;
  GLuint programID = glCreateProgram();
  glAttachShader(programID, vertexShaderID);
  glAttachShader(programID, fragmentShaderID);
  glLinkProgram(programID);

  // Check the linked program
  glGetProgramiv(programID, GL_LINK_STATUS, &result);
  glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

  if (infoLogLength > 0)
  {
    std::vector<char> programErrorMessage(infoLogLength + 1);
    glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
    std::cout << &programErrorMessage[0] << std::endl;
  }

  glDetachShader(programID, vertexShaderID);
  glDetachShader(programID, fragmentShaderID);

  glDeleteShader(vertexShaderID);
  glDeleteShader(fragmentShaderID);

  return programID;
}
