#pragma once
#include <string>
#include <memory>
#include <map>
#include <vector>

namespace rd
{
	class ShaderProgram;
	class Texture2D;
	class Sprite;
	class AnimatedSprite;
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

	std::shared_ptr<rd::Texture2D> loadTexture(const std::string& textureName, const std::string& texturePath);
	std::shared_ptr<rd::Texture2D> getTexture(const std::string& textureName);

	std::shared_ptr<rd::Sprite> loadSprite(const std::string& spriteName,
															const std::string& textureName,
															const std::string& shaderName,
															unsigned int spriteWidth,
															unsigned int spriteHeight,
															const std::string& subTextureName = "Default");
	std::shared_ptr<rd::Sprite> getSprite(const std::string& spriteName);

	std::shared_ptr<rd::AnimatedSprite> getAnimatedSprite(const std::string& spriteName);
	std::shared_ptr<rd::AnimatedSprite> loadAnimatedSprite(const std::string& spriteName,
															const std::string& textureName,
															const std::string& shaderName,
															unsigned int spriteWidth,
															unsigned int spriteHeight,
															const std::string& subTextureName = "Default");


	std::shared_ptr<rd::Texture2D> loadTextureAtlas(std::string textureName,
																	 std::string texturePath,
																	 std::vector<std::string> subTextures,
																	 unsigned int subTextureWidth,
																	 unsigned int subTextureHeight);
private:
	std::string getFileString(const std::string& relativeFilePath) const;

	typedef std::map<const std::string, std::shared_ptr<rd::ShaderProgram>> ShaderProgramsMap;
	ShaderProgramsMap m_shaderPrograms;

	typedef std::map <const std::string, std::shared_ptr<rd::Texture2D>> TexturesMap;
	TexturesMap m_textures;

	typedef std::map <const std::string, std::shared_ptr<rd::Sprite>> SpritesMap;
	SpritesMap m_sprites;

	typedef std::map <const std::string, std::shared_ptr<rd::AnimatedSprite>> AnimatedSpritesMap;
	AnimatedSpritesMap m_AnimatedSprites;

	std::string m_path;
};