#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	window.create(VideoMode(1200, 700), "Main Menu");
	texture.loadFromFile("./Images/m_M.png");
	sprite.setTexture(texture);
}

void MainMenuScreen::render()
{
	RectangleShape button_1(Vector2f(100,100));
	Color rc_1(200, 0, 0);
	button_1.setFillColor(rc_1);
	button_1.setPosition(0, 0);

	RectangleShape button_2(Vector2f(100, 100));
	Color rc_2(0, 200, 0);
	button_2.setFillColor(rc_2);
	button_2.setPosition(0, 100);

	RectangleShape button_3(Vector2f(100, 100));
	Color rc_3(0, 0, 200);
	button_3.setFillColor(rc_3);
	button_3.setPosition(0, 200);


	while (window.isOpen())
	{


		Event e;
		while (window.pollEvent(e))
		{

			if (e.type == Event::Closed)
				window.close();

			if (e.mouseButton.x >= 0 && e.mouseButton.x <= 100 && e.mouseButton.y >= 0 && e.mouseButton.y <= 100)
			{
				if (instructionScreen.getWindow().isOpen())
					instructionScreen.getWindow().close();

				if (highScoreScreen.getWindow().isOpen())
					highScoreScreen.getWindow().close();

				playGame.render();
				//window.close();
				//
				//playGame.create(VideoMode(1200, 700), "Play-Game");
				//while (playGame.isOpen())
				//{
				//	Event ep;
				//	while (playGame.pollEvent(ep))
				//	{
				//		if (ep.type == Event::Closed)
				//			playGame.close();
			
				//	}

				//	instructions.close();
				//	highScore.close();
				//	playGame.display();

				// }
			}

			if (e.mouseButton.x >= 0 && e.mouseButton.x <= 100 && e.mouseButton.y > 100 && e.mouseButton.y <= 200)
			{
				if (playGame.getWindow().isOpen())
					playGame.getWindow().close();

				if (highScoreScreen.getWindow().isOpen())
					highScoreScreen.getWindow().close();

				instructionScreen.render();

			}

			if (e.mouseButton.x >= 0 && e.mouseButton.x <= 100 && e.mouseButton.y > 200 && e.mouseButton.y <= 300)
			{
				if (instructionScreen.getWindow().isOpen())
					instructionScreen.getWindow().close();

				if (playGame.getWindow().isOpen())
					playGame.getWindow().close();


				highScoreScreen.render();

			}



		}
		window.draw(sprite);
		window.draw(button_1);
		window.draw(button_2);
		window.draw(button_3);
		window.display();

	}
}