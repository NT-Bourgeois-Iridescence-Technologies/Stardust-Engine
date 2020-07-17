#include <Platform/Platform.h>
#include <GFX/RenderCore.h>
#include <Platform/PC/Window.h>
#include <GFX/GFXWrapper.h>
#include <GFX/2D/SpriteAnimated.h>
using namespace Stardust;

int main() {
	Platform::initPlatform();

	float r = 0.0f;

	unsigned int myTex = GFX::g_TextureManager->loadTex("fire_0.png", GFX_FILTER_NEAREST, GFX_FILTER_NEAREST, true);
	GFX::Render2D::SpriteAnimated* sprite = new GFX::Render2D::SpriteAnimated(myTex, { 256, 256 }, 32);

	sprite->setPosition(240, 136);
	GFX::Render2D::PointLight light = { 240, 136, 255, 255, 255, 255, 100.0f, 1.0f };

	while (true) {
		GFX::g_RenderCore->beginFrame();

		r += 0.005f;
		if (r >= 1.0f) {
			r = 0.0f;

			light.intensity = 1.0f;
			light.range = 50.0f;
			light.x += 2;


			sprite->clearPointLights();
			sprite->addPointLight(light);
			sprite->calculateLighting();
			sprite->tickPhase();
		}



		GFX::g_RenderCore->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		GFX::g_RenderCore->clear();

		//Main loop
		sprite->draw();

		Platform::platformUpdate();
		GFX::g_RenderCore->endFrame();
	}

	Platform::exitPlatform();
	return 0;
}