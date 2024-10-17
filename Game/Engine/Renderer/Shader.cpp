#include "Shader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) :
	mID{ }
{
	// Stores vertex and fragment code
	std::string vertexCode;
	std::string fragmentCode;

	// Vertex and fragment file readers
	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	// Ensure ifstream objects can throw exceptions
	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		// Open vertex shader file
		vertexShaderFile.open(vertexPath);
		// Vertex shader string stream
		std::stringstream vertexShaderStream;
		// Read vertex shader file's buffer contents into stream
		vertexShaderStream << vertexShaderFile.rdbuf();
		// Close vertex file reader
		vertexShaderFile.close();
		// Convert vertex string stream into string
		vertexCode = vertexShaderStream.str();

		// Open fragment shader file
		fragmentShaderFile.open(fragmentPath);
		// Fragment shader string stream
		std::stringstream fragmentShaderStream;
		// Read fragment shader file's buffer contents into stream
		fragmentShaderStream << fragmentShaderFile.rdbuf();
		// Close fragment file reader
		fragmentShaderFile.close();
		// Convert fragment string stream into string
		fragmentCode = fragmentShaderStream.str();

		compile(vertexCode, fragmentCode);
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
}

Shader::~Shader()
{
	glDeleteProgram(mID);
}

void Shader::Use()
{
	glUseProgram(mID);
}

void Shader::SetVec3(const std::string& uniform, glm::vec3 value)
{
	glUniform3f(glGetUniformLocation(mID, uniform.c_str()), value.x, value.y, value.z);
}

void Shader::compile(const std::string& vertexSource, const std::string& fragmentSource)
{
	// Vertex Shader
	const char* vertexCode = vertexSource.c_str();
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexCode, NULL);
	glCompileShader(vertexShader);
	// Check for compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Fragment Shader
	const char* fragmentCode = fragmentSource.c_str();
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
	glCompileShader(fragmentShader);
	// Check for compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Link Shader Program
	mID = glCreateProgram();
	glAttachShader(mID, vertexShader);
	glAttachShader(mID, fragmentShader);
	glLinkProgram(mID);
	// Check for linking errors
	glGetProgramiv(mID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(mID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// Delete vertex and fragment shader
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
