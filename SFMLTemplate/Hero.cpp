#include "Hero.h"
#include "SFMLKeyboard.h"
#include "Wall.h"
#include "Box.h"
#include <iostream>
#include "SFMLTextureManager.h"
#include "SFMLRoom.h"

Hero::Hero(float x, float y)
	: SFMLObject("Hero_Right", x, y, 2, 1)
{
	this->SetDepth(3);
	SetImageBlend(255,0,0,255);
}

void Hero::Update()
{
	SFMLObject::Update();
	if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Right))
	{
		GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Right"));
		if ((PlaceMeeting<Box*>(GetX() + 40, GetY()) == true) && (PlaceMeeting<Wall*>(GetX() + 80, GetY()) == false) && (withBOX == false))
		{
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Right_Box"));
			SetImageIndex(GetImageIndex() + 1);
			withBOX = true;
			InstancePlace<Box*>(GetX() + 40, GetY())->SetHSpeed(2);
			SetHSpeed(2);
			SetAlarm(0, 20);
			++steps;
		}
		else if (PlaceMeeting<Wall*>(GetX() + 40, GetY()) == false && (withBOX == false))
		{
			SetImageIndex(GetImageIndex() + 1);
			SetHSpeed(4);
			SetAlarm(0,10);
			++steps;
		}
	}
	else if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Left))
	{
		GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Left"));
		if ((PlaceMeeting<Box*>(GetX() - 40, GetY()) == true) && (PlaceMeeting<Wall*>(GetX() - 80, GetY()) == false) && (withBOX == false))
		{
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Left_Box"));
			SetImageIndex(GetImageIndex() + 1);
			withBOX = true;
			InstancePlace<Box*>(GetX() - 40, GetY())->SetHSpeed(-2);
			SetHSpeed(-2);
			SetAlarm(0, 20);
			++steps;
		}
		else if (PlaceMeeting<Wall*>(GetX() - 40, GetY()) == false && (withBOX == false))
		{
			SetImageIndex(GetImageIndex() + 1);
			SetHSpeed(-4);
			SetAlarm(0, 10);
			++steps;
		}
	}
	else if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Up))
	{
		GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Up"));
		if ((PlaceMeeting<Box*>(GetX(), GetY() - 40) == true) && (PlaceMeeting<Wall*>(GetX(), GetY() - 80) == false) && (withBOX == false))
		{
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Up_Box"));
			SetImageIndex(GetImageIndex() + 1);
			withBOX = true;
			InstancePlace<Box*>(GetX(), GetY() - 40)->SetVSpeed(-2);
			SetVSpeed(-2);
			SetAlarm(0, 20);
			++steps;
		}
		else if (PlaceMeeting<Wall*>(GetX(), GetY() - 40) == false && (withBOX == false))
		{
			SetImageIndex(GetImageIndex() + 1);
			SetVSpeed(-4);
			SetAlarm(0, 10);
			++steps;
		}
	}
	else if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Down))
	{
		GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Down"));
		if ((PlaceMeeting<Box*>(GetX(), GetY() + 40) == true) && (PlaceMeeting<Wall*>(GetX(), GetY() + 80) == false) && (withBOX == false))
		{
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("Hero_Down_Box"));
			SetImageIndex(GetImageIndex() + 1);
			withBOX = true;
			InstancePlace<Box*>(GetX(), GetY() + 40)->SetVSpeed(2);
			SetVSpeed(2);
			SetAlarm(0, 20);
			++steps;
		}
		else if (PlaceMeeting<Wall*>(GetX(), GetY() + 40) == false && (withBOX == false))
		{
			SetImageIndex(GetImageIndex() + 1);
			SetVSpeed(4);
			SetAlarm(0, 10);
			++steps;
		}
	}
}

int Hero::GetSteps()
{
	return steps;
}


Hero::~Hero()
{
}

void Hero::OnAlarm(int alarm)
{
	SetSpeed(0);
	if (withBOX == true)
	{
		std::vector<SFMLObject *> boxes = SFMLGame::GetInstance()->GetCurrentRoom()->GetAllObjectsOfType<Box*>();
		for (SFMLObject * boxer : boxes)
		{
			boxer->SetSpeed(0);
		}
		withBOX = false;
	}
	SetImageIndex(GetImageIndex() + 1);
}