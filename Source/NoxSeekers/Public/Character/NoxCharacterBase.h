// Copyright smileJiro

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "NoxCharacterBase.generated.h"

class UAbilitySystemComponent;
class UNoxAttributeSet;

/**
 * 모든 캐릭터(플레이어/적)의 공통 베이스.
 *
 * ASC 할당 정책:
 *   - Player  → PlayerState에서 생성 후 이 포인터에 할당 (리스폰 후 속성 유지)
 *   - Enemy   → NoxEnemyCharacter 생성자에서 직접 생성 후 할당
 */
UCLASS(Abstract)
class NOXSEEKERS_API ANoxCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ANoxCharacterBase();

	// IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = "GAS")
	UNoxAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	// ─── GAS ───────────────────────────────────────────────
	// 서브클래스에서 할당. 이 클래스에서는 생성하지 않음.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UNoxAttributeSet> AttributeSet;

	// ─── 무기 ──────────────────────────────────────────────
	// 생성자에서 컴포넌트만 만들고, 소켓 어태치는 InitializeJob에서 처리.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> Weapon;
};
