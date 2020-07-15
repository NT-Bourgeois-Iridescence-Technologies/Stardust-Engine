#pragma once
#include <string>
#include <GFX/GFXWrapper.h>
#include <glm/glm.hpp>

namespace Stardust::GFX::Render2D {
	class Sprite{
	public:
		Sprite();
		~Sprite();

		Sprite(unsigned int tex, glm::vec2 size);
		Sprite(unsigned int tex, glm::vec2 pos1, glm::vec2 extent); //Cuts stuff

		void setLayer(int i);

		void setPosition(float x, float y);
		void setScale(float x, float y);
		void setColor(float r, float g, float b, float a);
		void setTexture(unsigned int tex);

		void draw();

	private:
		glm::vec2 offset;
		glm::vec2 scaleFactor;
		Mesh mesh;

		Model model;
		unsigned int tex;
	};
}