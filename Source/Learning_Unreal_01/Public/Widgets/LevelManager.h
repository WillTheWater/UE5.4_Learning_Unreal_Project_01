#pragma once
#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Kismet/GameplayStatics.h"

UENUM(BlueprintType)
enum class ELevels : uint8
{
	LevelOne,
	LevelTwo,
	LevelThree,
	Credits,
	MainMenu
};

class LevelManager
{
public:
	LevelManager()
	{
		LevelMap.Add(ELevels::LevelOne, "LevelOne");
		LevelMap.Add(ELevels::LevelTwo, "LevelTwo");
		LevelMap.Add(ELevels::LevelThree, "LevelThree");
		LevelMap.Add(ELevels::Credits, "Credits");
		LevelMap.Add(ELevels::MainMenu, "MainMenu");
	}

	FName GetLevelName(ELevels Level) const
	{
		const FName* LevelName = LevelMap.Find(Level);
		return LevelName ? *LevelName : FName("MainMenu");
	}

	ELevels GetNextLevel(ELevels CurrentLevel) const
	{
		switch (CurrentLevel)
		{
		case ELevels::LevelOne: return ELevels::LevelTwo;
		case ELevels::LevelTwo: return ELevels::LevelThree;
		case ELevels::LevelThree: return ELevels::Credits;
		case ELevels::Credits: return ELevels::MainMenu;
		default: return ELevels::LevelOne;
		}
	}

	void SetLevel(ELevels Level, UObject* World) const
	{
		FName LevelName = GetLevelName(Level);
		if (!LevelName.IsNone()) { UGameplayStatics::OpenLevel(World, LevelName); }
	}

private:
	TMap<ELevels, FName> LevelMap;
};
