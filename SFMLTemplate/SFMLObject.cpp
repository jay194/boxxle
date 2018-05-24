#include <cassert>
#include "SFMLGame.h"
#include "SFMLObject.h"
#include "SFMLRoom.h"
#include "SFMLTextureManager.h"

SFMLObject::SFMLObject(const std::string & resourceName,
	float x,
	float y,
	int HorizontalFrames,
	int VerticalFrames)
	: Sprite(new sf::Sprite()),
	FramesHorizontally(HorizontalFrames),
	FramesVertically(VerticalFrames),
	ImageIndex(0),
	ImageSpeed(0),
	Depth(0),
	Visible(true),
	PreviousPosition(x, y),
	StartPosition(x, y),
	Velocity(0, 0),
	Acceleration(0, 0),
	Friction(0),
	Alarms(12, -1)
{
	sf::Texture * Texture = SFMLTextureManager::GetInstance()->GetTexture(resourceName);
	assert(Texture != nullptr);
	Sprite->setTexture(*Texture);
	Sprite->setPosition(x, y);
}

SFMLObject::~SFMLObject()
{
	delete Sprite;
}

void SFMLObject::Update()
{
	PreviousPosition = GetSprite()->getPosition();
	SetImageIndex(GetImageIndex() + GetImageSpeed());
	GetSprite()->setPosition(GetSprite()->getPosition() + Velocity);
	Velocity += Acceleration;
	if (Friction != 0)
	{
		float newSpeed = GetSpeed() - GetFriction();
		SetSpeed(std::max<float>(0, newSpeed));
	}
	ModifyAlarms();
}

void SFMLObject::Draw()
{
	if (Visible == true)
	{
		sf::Sprite * s = GetSprite();
		int Index = static_cast<int>(GetImageIndex());
		int Horizontal = Index % FramesHorizontally;
		int Vertical = Index / FramesHorizontally;
		s->setTextureRect(sf::IntRect(Horizontal * s->getTexture()->getSize().x / FramesHorizontally,
			Vertical * s->getTexture()->getSize().y / FramesVertically,
			s->getTexture()->getSize().x / FramesHorizontally,
			s->getTexture()->getSize().y / FramesVertically));
		SFMLGame::GetInstance()->GetWindow()->draw(*s);
	}
}

sf::Sprite * SFMLObject::GetSprite()
{
	return Sprite;
}

float SFMLObject::GetImageIndex()
{
	return ImageIndex;
}

float SFMLObject::GetImageSpeed()
{
	return ImageSpeed;
}

void SFMLObject::SetImageIndex(float Value)
{
	ImageIndex = static_cast<float>(fmod(Value, GetImageNumber()));
	if (ImageIndex < 0)
	{
		ImageIndex += GetImageNumber();
	}
}

void SFMLObject::SetImageSpeed(float Value)
{
	ImageSpeed = Value;
}

int SFMLObject::GetImageNumber()
{
	return FramesHorizontally * FramesVertically;
}

bool SFMLObject::GetVisible()
{
	return Visible;
}

void SFMLObject::SetVisible(bool value)
{
	Visible = value;
}

float SFMLObject::GetDepth()
{
	return Depth;
}

void SFMLObject::SetDepth(float value)
{
	Depth = value;
}

int SFMLObject::GetSpriteWidth()
{
	return GetSprite()->getTexture()->getSize().x / FramesHorizontally;
}

int SFMLObject::GetSpriteHeight()
{
	return GetSprite()->getTexture()->getSize().y / FramesVertically;
}

float SFMLObject::GetSpriteXOffset()
{
	return GetSprite()->getOrigin().x;
}

float SFMLObject::GetSpriteYOffset()
{
	return GetSprite()->getOrigin().y;
}

void SFMLObject::SetSpriteXOffset(float value)
{
	sf::Vector2f v = GetSprite()->getOrigin();
	GetSprite()->setOrigin(value, v.y);
}

void SFMLObject::SetSpriteYOffset(float value)
{
	sf::Vector2f v = GetSprite()->getOrigin();
	GetSprite()->setOrigin(v.x, value);
}

float SFMLObject::GetSpriteXScale()
{
	return GetSprite()->getScale().x;
}

float SFMLObject::GetSpriteYScale()
{
	return GetSprite()->getScale().y;
}

void SFMLObject::SetSpriteXScale(float value)
{
	sf::Vector2f v = GetSprite()->getScale();
	GetSprite()->setScale(value, v.y);
}

void SFMLObject::SetSpriteYScale(float value)
{
	sf::Vector2f v = GetSprite()->getScale();
	GetSprite()->setScale(v.x, value);
}

float SFMLObject::GetImageAngle()
{
	return -GetSprite()->getRotation();
}

void SFMLObject::SetImageAngle(float value)
{
	GetSprite()->setRotation(-value);
}

unsigned char SFMLObject::GetImageAlpha()
{
	return GetSprite()->getColor().a;
}

void SFMLObject::SetImageAlpha(unsigned char value)
{
	sf::Color c = GetSprite()->getColor();
	c.a = value;
	GetSprite()->setColor(c);
}

sf::Color SFMLObject::GetImageBlend()
{
	return GetSprite()->getColor();
}

void SFMLObject::SetImageBlend(unsigned char RED, unsigned char GREEN, unsigned char BLUE, unsigned char ALPHA)
{
	GetSprite()->setColor(sf::Color(RED, GREEN, BLUE, ALPHA));
}

void SFMLObject::SetX(float value)
{
	GetSprite()->setPosition(value, GetSprite()->getPosition().y);
}

void SFMLObject::SetY(float value)
{
	GetSprite()->setPosition(GetSprite()->getPosition().x, value);
}

float SFMLObject::GetX()
{
	return GetSprite()->getPosition().x;
}

float SFMLObject::GetY()
{
	return GetSprite()->getPosition().y;
}

void SFMLObject::SetXPrevious(float value)
{
	PreviousPosition.x = value;
}

void SFMLObject::SetYPrevious(float value)
{
	PreviousPosition.y = value;
}

void SFMLObject::SetXStart(float value)
{
	StartPosition.x = value;
}

void SFMLObject::SetYStart(float value)
{
	StartPosition.y = value;
}

float SFMLObject::GetXPrevious()
{
	return PreviousPosition.x;
}

float SFMLObject::GetYPrevious()
{
	return PreviousPosition.y;
}

float SFMLObject::GetXStart()
{
	return StartPosition.x;
}

float SFMLObject::GetYStart()
{
	return StartPosition.y;
}

float SFMLObject::GetDirection()
{
	return atan2(-Velocity.y, Velocity.x) * 180.0f / 3.14159265359f;
}

float SFMLObject::GetHSpeed()
{
	return Velocity.x;
}

float SFMLObject::GetVSpeed()
{
	return Velocity.y;
}

float SFMLObject::GetSpeed()
{
	return sqrt((Velocity.x * Velocity.x) + (Velocity.y * Velocity.y));
}

void SFMLObject::SetDirection(float valueInDegrees)
{
	float radians = valueInDegrees * 3.14159265359f / 180.0f;
	float speed = GetSpeed();
	Velocity.x = speed * cos(radians);
	Velocity.y = -speed * sin(radians);
}

void SFMLObject::SetHSpeed(float value)
{
	Velocity.x = value;
}

void SFMLObject::SetVSpeed(float value)
{
	Velocity.y = value;
}

void SFMLObject::SetSpeed(float value)
{
	if (value == 0)
	{
		Velocity = sf::Vector2f(0, 0);
	}
	else
	{
		float speed = GetSpeed();
		if (speed != 0)
		{
			float speedMultiplier = value / speed;
			Velocity *= speedMultiplier;
		}
		else
		{
			Velocity = sf::Vector2f(value, 0);
		}
	}
}

// ------

float SFMLObject::GetAccelerationDirection()
{
	return atan2(-Acceleration.y, Acceleration.x) * 180.0f / 3.14159265359f;
}

float SFMLObject::GetAccelerationHSpeed()
{
	return Acceleration.x;
}

float SFMLObject::GetAccelerationVSpeed()
{
	return Acceleration.y;
}

float SFMLObject::GetAccelerationSpeed()
{
	return sqrt((Acceleration.x * Acceleration.x) + (Acceleration.y * Acceleration.y));
}

void SFMLObject::SetAccelerationDirection(float valueInDegrees)
{
	float radians = valueInDegrees * 3.14159265359f / 180.0f;
	float speed = GetAccelerationSpeed();
	Acceleration.x = speed * cos(radians);
	Acceleration.y = -speed * sin(radians);
}

void SFMLObject::SetAccelerationHSpeed(float value)
{
	Acceleration.x = value;
}

void SFMLObject::SetAccelerationVSpeed(float value)
{
	Acceleration.y = value;
}

void SFMLObject::SetAccelerationSpeed(float value)
{
	if (value == 0)
	{
		Acceleration = sf::Vector2f(0, 0);
	}
	else
	{
		float speed = GetAccelerationSpeed();
		if (speed != 0)
		{
			float speedMultiplier = value / speed;
			Acceleration *= speedMultiplier;
		}
		else
		{
			Acceleration = sf::Vector2f(value, 0);
		}
	}
}

float SFMLObject::GetFriction()
{
	return Friction;
}

void SFMLObject::SetFriction(float value)
{
	Friction = value;
}

void SFMLObject::MotionSet(float directionInDegrees, float speed)
{
	float radians = directionInDegrees * 3.14159265359f / 180.0f;
	Velocity.x = speed * cos(radians);
	Velocity.y = -speed * sin(radians);
}

void SFMLObject::MotionAdd(float directionInDegrees, float speed)
{
	float radians = directionInDegrees * 3.14159265359f / 180.0f;
	Velocity.x += (speed * cos(radians));
	Velocity.y += (-speed * sin(radians));
}

void SFMLObject::ModifyAlarms()
{
	for (std::size_t i = 0; i < Alarms.size(); ++i)
	{
		Alarms[i] = std::max(Alarms[i] - 1, -1);
		if (Alarms[i] == 0)
		{
			OnAlarm(i);
		}
	}
}

void SFMLObject::OnAlarm(int alarm)
{
	// Do nothing...
}

void SFMLObject::SetAlarm(int alarm, int value)
{
	Alarms.at(alarm) = value;
}

sf::Rect<float> SFMLObject::GetBoundingBox()
{
	return sf::Rect<float>(GetX(),
		GetY(),
		GetSpriteWidth(),
		GetSpriteHeight());
}