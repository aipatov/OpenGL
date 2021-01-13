#pragma once
#include <string>
#include <memory>
#include <map>

namespace rd
{
	class ShaderProgram;
}

class ResourceManager {
public:
	ResourceManager(const std::string& execPath);
	~ResourceManager() = default;

	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;

	std::shared_ptr<rd::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
	std::shared_ptr<rd::ShaderProgram> getShaderProgram(const std::string& shaderName);
private:
	std::string getFileString(const std::string& relativeFilePath) const;

	typedef std::map<const std::string, std::shared_ptr<rd::ShaderProgram>> ShaderProgramsMap;
	ShaderProgramsMap m_shaderPrograms;
	std::string m_path;
};