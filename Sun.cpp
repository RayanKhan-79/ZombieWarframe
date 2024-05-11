#include "Sun.h"

Sun::Sun() {
   
}

Sun::Sun(float interval) {
    Total_Animation_Time = 0;
    this->interval = interval;
    score = 0;
    health = 1;
    texture.loadFromFile("./Images/Sun.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(offset * 92, 0, 92, 90));
    sprite.setPosition(Pos.x, Pos.y);

}

void Sun::UpdateAnimation(float deltaTime, float switchTime) {
    Total_Animation_Time += deltaTime;
    if (Total_Animation_Time >= switchTime)
    {
        Total_Animation_Time -= switchTime;
        offset++;

        if (offset == 2)
            offset = 0;
    }
    sprite.setTextureRect(IntRect(offset * 92, 0, 92, 90));
}

void Sun::spawnSun() {
    
    int fieldWidth = 855; 
    int fieldHeight = 590; 

   
    int randomX = rand() % fieldWidth + Pos.x;
    int randomY = rand() % fieldHeight + Pos.y;

    sprite.setPosition(randomX, randomY);
    health = 1;
}


void Sun::scoreDisplay(sf::RenderWindow& window, sf::Font& font) {
    // Create a text object to display the score
    sf::Text scoreText;
    scoreText.setFont(font); // Set the font
    scoreText.setCharacterSize(24); // Set the character size
    scoreText.setFillColor(sf::Color::White); // Set the fill color
    scoreText.setPosition(10, 10); // Position the text at the top left corner
    scoreText.setString("Score: " + std::to_string(score)); // Set the text string

    // Draw the text on the window
    window.draw(scoreText);
}
void Sun::isClick(sf::Event& event) {
    // Check if the sun is clicked
    // Assuming you have access to the event system of your game

    // Assuming 'event' is the SFML event object
    if (event.type == sf::Event::MouseButtonPressed) {
        // Check if the left mouse button is pressed
        if (event.mouseButton.button == sf::Mouse::Left) {
            // Get the position of the mouse click
            int mouseX = event.mouseButton.x;
            int mouseY = event.mouseButton.y;

            // Get the bounding box of the sun sprite
            sf::FloatRect spriteBounds = sprite.getGlobalBounds();

            // Check if the mouse click is within the bounds of the sun sprite
            if (mouseX >= spriteBounds.left && mouseX <= spriteBounds.left + spriteBounds.width &&
                mouseY >= spriteBounds.top && mouseY <= spriteBounds.top + spriteBounds.height) {
                // If the sun is clicked, add 25 points to the score
                score += 25;
                // Update the health of the sun
                health = 0;
                // Remove the sun from the screen if health is zero
                if (health == 0) {
                    // Set the sprite's color alpha to 0 for transparency
                    sf::Color color = sprite.getColor();
                    color.a = 0;
                    sprite.setColor(color);
                }
            }
        }
    }
}

