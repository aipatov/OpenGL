#pragma once
#include <array>
#include <glm/vec2.hpp>
#include <memory>

class Tank;

class Game {
public:

	enum class EGameState {
		Active,
		Pause
	};

	Game(const glm::vec2& windowSize);
	~Game();

	void render();
	void update(uint64_t delta);
	void setKey(int key, int action);
	bool init();
private:
	std::array<bool, 349> m_keys;
	std::unique_ptr<Tank> m_pTank;
	EGameState m_eCurrentGameState;
	glm::vec2 m_windowSize;
};