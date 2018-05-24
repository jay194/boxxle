#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "SFMLGame.h"
#include "SFMLRoom.h"

class SFMLObject
{
public:
	SFMLObject(const std::string & resourceName,
		float x,
		float y,
		int HorizontalFrames = 1,
		int VerticalFrames = 1);

	virtual ~SFMLObject();

	virtual void Update();
	virtual void Draw();

	sf::Sprite * GetSprite();

	float GetImageIndex();
	float GetImageSpeed();

	void SetImageIndex(float Value);
	void SetImageSpeed(float Value);

	int GetImageNumber();

	bool GetVisible();
	void SetVisible(bool value);

	float GetDepth();
	void SetDepth(float value);

	int GetSpriteWidth();
	int GetSpriteHeight();

	float GetSpriteXOffset();
	float GetSpriteYOffset();

	void SetSpriteXOffset(float value);
	void SetSpriteYOffset(float value);

	float GetSpriteXScale();
	float GetSpriteYScale();

	void SetSpriteXScale(float value);
	void SetSpriteYScale(float value);

	float GetImageAngle();
	void SetImageAngle(float value);

	unsigned char GetImageAlpha();
	void SetImageAlpha(unsigned char value);

	sf::Color GetImageBlend();
	void SetImageBlend(unsigned char RED, unsigned char GREEN, unsigned char BLUE, unsigned char ALPHA = 255);

	void SetX(float value);
	void SetY(float value);

	float GetX();
	float GetY();

	void SetXPrevious(float value);
	void SetYPrevious(float value);
	void SetXStart(float value);
	void SetYStart(float value);

	float GetXPrevious();
	float GetYPrevious();
	float GetXStart();
	float GetYStart();

	void SetDirection(float value);
	void SetHSpeed(float value);
	void SetVSpeed(float value);
	void SetSpeed(float value);

	float GetDirection();
	float GetHSpeed();
	float GetVSpeed();
	float GetSpeed();

	float GetAccelerationDirection();
	float GetAccelerationHSpeed();
	float GetAccelerationVSpeed();
	float GetAccelerationSpeed();

	void SetAccelerationDirection(float value);
	void SetAccelerationHSpeed(float value);
	void SetAccelerationVSpeed(float value);
	void SetAccelerationSpeed(float value);

	float GetFriction();
	void SetFriction(float value);

	void MotionSet(float directionInDegrees, float speed);
	void MotionAdd(float directionInDegrees, float speed);

	void SetAlarm(int alarm, int value);
	virtual void OnAlarm(int alarm);

	sf::Rect<float> GetBoundingBox();

	template<typename T>
	bool PlaceMeeting(int X, int Y);

	template<typename T>
	SFMLObject * InstancePlace(int X, int Y);

	int steps = 0;

private:
	sf::Sprite * Sprite;
	int FramesHorizontally;
	int FramesVertically;
	float ImageIndex;
	float ImageSpeed;
	float Depth;
	bool Visible;
	sf::Vector2f PreviousPosition;
	sf::Vector2f StartPosition;
	sf::Vector2f Velocity;
	sf::Vector2f Acceleration;
	float Friction;
	std::vector<int> Alarms;

	void ModifyAlarms();
};

template<typename T>
bool SFMLObject::PlaceMeeting(int X, int Y)
{
	sf::Rect<float> Box(X, Y, GetSpriteWidth(), GetSpriteHeight());
	return SFMLGame::GetInstance()->GetCurrentRoom()->PlaceMeeting<T>(this, Box);
}

template<typename T>
SFMLObject * SFMLObject::InstancePlace(int X, int Y)
{
	sf::Rect<float> Box(X, Y, GetSpriteWidth(), GetSpriteHeight());
	return SFMLGame::GetInstance()->GetCurrentRoom()->InstancePlace<T>(this, Box);
}