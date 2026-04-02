// Copyright smileJiro

#include "Character/NoxCharacter.h"
#include "Data/Job/NoxJobDataAsset.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"

ANoxCharacter::ANoxCharacter()
{
}

void ANoxCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializeJob();
}

void ANoxCharacter::SetJobData(UNoxJobDataAsset* NewJobData)
{
	JobData = NewJobData;
	InitializeJob();
}

void ANoxCharacter::InitializeJob()
{
	if (!JobData)
	{
		return;
	}

	// 1. 스켈레탈 메시 교체
	if (JobData->CharacterMesh)
	{
		GetMesh()->SetSkeletalMesh(JobData->CharacterMesh);
	}

	// 2. 무기 메시 + 소켓 어태치
	if (JobData->WeaponMesh)
	{
		Weapon->SetStaticMesh(JobData->WeaponMesh);
		Weapon->AttachToComponent(
			GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			JobData->WeaponSocketName
		);
	}

	// 3. AnimBP 연결 (Job 타입별 기본 애니메이션)
	if (JobData->AnimBPClass)
	{
		GetMesh()->SetAnimInstanceClass(JobData->AnimBPClass);
	}

	// 4. 속성 초기값 GE 적용
	if (AbilitySystemComponent && JobData->InitAttributeEffect)
	{
		FGameplayEffectContextHandle Context = AbilitySystemComponent->MakeEffectContext();
		FGameplayEffectSpecHandle Spec = AbilitySystemComponent->MakeOutgoingSpec(
			JobData->InitAttributeEffect, 1.f, Context);

		if (Spec.IsValid())
		{
			AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*Spec.Data.Get());
		}
	}

	// 5. 어빌리티 부여 (서버 권위)
	if (AbilitySystemComponent && HasAuthority())
	{
		for (const TSubclassOf<UGameplayAbility>& Ability : JobData->DefaultAbilities)
		{
			if (Ability)
			{
				AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1));
			}
		}
	}
}
