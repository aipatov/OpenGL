#pragma once
#include "Sprite.h"
#include <map>
#include <vector>

typedef std::vector<std::pair<std::string, uint64_t>> TextureDurationV;

namespace rd {

	class AnimatedSprite : public Sprite
	{
	public:
		AnimatedSprite(std::shared_ptr<Texture2D> pTexture,
					   std::shared_ptr<ShaderProgram> pShaderProgram,
					   std::string initialSubTexture = "Default",
					   const glm::vec2& position = glm::vec2(0.f),
					   const glm::vec2& size = glm::vec2(1.f),
					   const float rotation = 0.f);
		
		void insertState(std::string state, TextureDurationV subTexturesDuration);

		void render() const override;

		void setState(const std::string& newState);

		void update(uint64_t delta);
	private:
		std::map<std::string, TextureDurationV> m_statesMap;
		size_t m_currentFrame = 0;
		uint64_t m_currentAnimationTime = 0;
		std::map<std::string, TextureDurationV>::const_iterator m_pCurrentAnimationDurations;
		mutable bool m_dirty = false;
	};
}