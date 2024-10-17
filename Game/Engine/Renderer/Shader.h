#pragma once
#include <string>
class Shader
{
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void Use();

private:
	void compile(const std::string& vertexSource, const std::string& fragmentSource);

private:
	unsigned int mID;
};

