#ifndef ANIMATEDSPRITE_INCLUDE
#define ANIMATEDSPRITE_INCLUDE

#include <cstdlib> //Included for Mac g++ compiler compatibility 

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>

#include "SpriteAnimation.hh"

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
    explicit AnimatedSprite(sf::Time frameTime = sf::seconds(0.2f),
                            bool paused = false, bool looped = true);

    void update(sf::Time deltaTime);
    void setAnimation(const SpriteAnimation&);
    void setFrameTime(sf::Time time);
    void play();
    void play(const SpriteAnimation&);
    void pause();
    void stop();
    void setLooped(bool looped);
    void setColor(const sf::Color& color);
    const SpriteAnimation* getAnimation() const;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;
    bool isLooped() const;
    bool isPlaying() const;
    sf::Time getFrameTime() const;
    void setFrame(std::size_t newFrame, bool resetTime = true);

private:
    const SpriteAnimation* m_animation;
    sf::Time m_frameTime;
    sf::Time m_currentTime;
    std::size_t m_currentFrame;
    bool m_isPaused;
    bool m_isLooped;
    const sf::Texture* m_texture;
    sf::Vertex m_vertices[4];

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // ANIMATEDSPRITE_INCLUDE
