#pragma once

#include <array>
#include <string>
#include <map>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace CG
{
	class MainScene
	{
	public:
		MainScene();
		~MainScene();

		auto Initialize() -> bool;
		void Update(double dt);
		void Render();

		void OnResize(int width, int height);
		void OnKeyboard(int key, int action);

		void SetMode(int mode);

	private:
		GLenum mode = GL_FILL; // GL_FILL or GL_LINE

		std::array<float, 3> p0c; // Color of P0
		std::array<float, 3> p1c; // Color of P1
		std::array<float, 3> p2c; // Color of P2

		std::array<float, 10> px;
		std::array<float, 10> py;

		float xOffset = 0.0;
		float yOffset = 0.0;

		float rotationSpeed = 0.2;
		float rotation = 0.0;
	};
}

