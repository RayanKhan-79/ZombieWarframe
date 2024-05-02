#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() 
	: playgameIcon("Play",coordinates(456,130)), InstructionIcon("Instructions", coordinates(465, 280)), highScoreIcon("High Score", coordinates(465, 430)), Quit("Quit", coordinates(910, 540))
{
	Texture texture_1;
	texture_1.loadFromFile("./Images/button.png");
	playgameIcon.setTexture(texture_1, 56, 27);
	InstructionIcon.setTexture(texture_1, 149, 25);
	highScoreIcon.setTexture(texture_1, 137, 31);
	Quit.setTexture(texture_1, 58, 29);

	texture.loadFromFile("./Images/main_back.png");
	sprite.setTexture(texture);

}

void MainMenuScreen::drawIcons()
{
	
	playgameIcon.draw(window);
	InstructionIcon.draw(window);
	highScoreIcon.draw(window);
	Quit.draw(window);


}

void MainMenuScreen::render()
{
	window.create(VideoMode(1200, 700), "Main Menu");
	window.setPosition(Vector2i(100, 100));

	while (window.isOpen())
	{
		
		
		Event e;
		while (window.pollEvent(e))
		{

			if (e.type == Event::Closed || Quit.isClicked(e))
				window.close();


			// For Testing
			if (e.type == Event::MouseButtonReleased)
			{
				std::cout << "x: " << Mouse::getPosition(window).x << " y: " << Mouse::getPosition(window).y << "\n";
			}
			// ==========

			if (InstructionIcon.isClicked(e))
			{
//				this->getWindow().close();
				playGame.getWindow().close();

				highScoreScreen.getWindow().close();
				
				instructionScreen.render();
			}

			if (playgameIcon.isClicked(e))
			{
//				this->getWindow().close();
				highScoreScreen.getWindow().close();
				
				instructionScreen.getWindow().close();
				
				playGame.render();
			}

			if (highScoreIcon.isClicked(e))
			{
//				this->getWindow().close();
				playGame.getWindow().close();
				
				instructionScreen.getWindow().close();
				
				highScoreScreen.render();
			}



		}



		window.draw(sprite);

		drawIcons();

		window.display();

	}
}