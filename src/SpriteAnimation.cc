#include "SpriteAnimation.hh"

SpriteAnimation::SpriteAnimation() : m_texture(NULL)
{

}

void SpriteAnimation::addFrame(sf::IntRect rect)
{
    m_frames.push_back(rect);
}

void SpriteAnimation::setSpriteSheet(sf::Texture* texture)
{
  m_texture = texture;
}

void SpriteAnimation::setSpriteSheet(const sf::Texture& texture)
{
    m_texture = &texture;
}

const sf::Texture* SpriteAnimation::getSpriteSheet() const
{
    return m_texture;
}

std::size_t SpriteAnimation::getSize() const
{
    return m_frames.size();
}

const sf::IntRect& SpriteAnimation::getFrame(std::size_t n) const
{
    return m_frames[n];
}
