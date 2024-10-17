#pragma once
#include <string>
#include <glm/ext/vector_float3.hpp>
class Shader
{
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void Use();
	void SetVec3(const std::string& uniform, glm::vec3 value);
private:
	void compile(const std::string& vertexSource, const std::string& fragmentSource);

private:
	unsigned int mID;
};

