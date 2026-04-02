// Copyright smileJiro

#include "Character/NoxCharacterBase.h"

ANoxCharacterBase::ANoxCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	// 컴포넌트 생성만. 소켓 어태치는 InitializeJob에서 JobData 기준으로 처리.
	Weapon = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ANoxCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ANoxCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
