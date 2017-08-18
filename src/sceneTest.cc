#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hh"
#include "Scene.hh"
#include <iostream>

int main()
{
  sf::Vector2i screenDimensions(800,600);
  sf::RenderWindow window(sf::VideoMode(800, 600), "Scene!");
  window.setFramerateLimit(60);

  Scene scene;
  scene.setWindow(window);
  scene.createTexture("main")->loadFromFile("player.png");

  SpriteAnimation walkingAnimationDown;
  walkingAnimationDown.setSpriteSheet(scene.getTexture("main"));
  walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
  walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
  walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
  walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

  SpriteAnimation walkingAnimationLeft;
  walkingAnimationLeft.setSpriteSheet(scene.getTexture("main"));
  walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
  walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
  walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
  walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

  SpriteAnimation walkingAnimationRight;
  walkingAnimationRight.setSpriteSheet(scene.getTexture("main"));
  walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
  walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
  walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
  walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

  SpriteAnimation walkingAnimationUp;
  walkingAnimationUp.setSpriteSheet(scene.getTexture("main"));
  walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
  walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
  walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
  walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

  SpriteAnimation* currentAnimation = &walkingAnimationDown;

  // set up AnimatedSprite
  AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
  animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

  scene.addDrawable(animatedSprite);

  sf::Clock frameClock;

  float speed = 80.f;
  bool noKeyWasPressed = true;

  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
          if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
              window.close();
      }

      sf::Time frameTime = frameClock.restart();

      // if a key was pressed set the correct animation and move correctly
      sf::Vector2f movement(0.f, 0.f);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
          currentAnimation = &walkingAnimationUp;
          movement.y -= speed;
          noKeyWasPressed = false;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
          currentAnimation = &walkingAnimationDown;
          movement.y += speed;
          noKeyWasPressed = false;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
          currentAnimation = &walkingAnimationLeft;
          movement.x -= speed;
          noKeyWasPressed = false;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
          currentAnimation = &walkingAnimationRight;
          movement.x += speed;
          noKeyWasPressed = false;
      }
      animatedSprite.play(*currentAnimation);
      animatedSprite.move(movement * frameTime.asSeconds());

      // if no key was pressed stop the animation
      if (noKeyWasPressed)
      {
          animatedSprite.stop();
      }
      noKeyWasPressed = true;

      // update AnimatedSprite
      //animatedSprite.update(frameTime);
      scene.update(frameTime);
      // draw
      window.clear();
      // //window.draw(animatedSprite);
      scene.draw();
      window.display();
  }

  return 0;
}
