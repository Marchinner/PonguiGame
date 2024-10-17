#pragma once
#include <string>
#include <glm/glm.hpp>
class Shader
{
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void Use();
	void SetVec3(const std::string& uniform, const glm::vec3& value) const;
	void SetMat4(const std::string& uniform, const glm::mat4& value) const;
private:
	void compile(const std::string& vertexSource, const std::string& fragmentSource);

private:
	unsigned int mID;
};

