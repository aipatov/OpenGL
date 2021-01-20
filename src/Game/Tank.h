#pragma once
#include <memory>
#include <glm/vec2.hpp>

namespace rd {
	class AnimatedSprite;
}

class Tank {
public:
	
	enum class EOrientation {
		Top,
		Bottom,
		Left,
		Right
	};

	Tank(std::shared_ptr<rd::AnimatedSprite> pSprite, float velocity, const glm::vec2& position);

	void render() const;
	void setOrientation(EOrientation eOrientation);
	void move(bool move);
	void update(uint64_t delta);

private:
	EOrientation m_eOrientation;
	std::shared_ptr<rd::AnimatedSprite> m_pSprite;
	bool m_bMove;
	float m_velocity;
	glm::vec2 m_position;
	glm::vec2 m_moveOffset;
};