#include "SFMLObject.h"
#include "SFMLRoom.h"
#include "Box.h"
#include "Goal.h"
#include "MainMenuRoom.h"
#include "NextLevelRoom.h"
#include "SFMLFont.h"

SFMLRoom::SFMLRoom()
	: Objects()
{
	// Nothing here...
}

SFMLRoom::~SFMLRoom()
{
	for (SFMLObject * Object : Objects)
	{
		delete Object;
	}
	Objects.clear();
}

void SFMLRoom::Update()
{
	//check for won game
	std::vector<SFMLObject *> boxes = GetAllObjectsOfType<Box*>();
	std::vector<SFMLObject *> goals = GetAllObjectsOfType<Goal*>();
	int count = 0;
	if(boxes.size() > 0){
		for (SFMLObject * boxer : boxes)
		{
			for (SFMLObject * goaler : goals)
			{
				if (boxer->GetBoundingBox() == goaler->GetBoundingBox())
				{
					++count;
				}
			}
		}
		if (count >= boxes.size()) // winner
		{
			sf::sleep(sf::seconds(1));
			SFMLGame::GetInstance()->ChangeCurrentRoom(new NextLevelRoom);
		}
	}

	for (SFMLObject * Object : Objects)
	{
		Object->Update();
	}
}

bool SortObjectsByDepth(SFMLObject * LHS, SFMLObject * RHS)
{
	return LHS->GetDepth() < RHS->GetDepth();
}

void SFMLRoom::Draw()
{
	std::sort(Objects.begin(), Objects.end(), SortObjectsByDepth);

	for (SFMLObject * Object : Objects)
	{
		Object->Draw();
	}
}

void SFMLRoom::InstanceCreate(SFMLObject * Instance)
{
	Objects.push_back(Instance);
}

