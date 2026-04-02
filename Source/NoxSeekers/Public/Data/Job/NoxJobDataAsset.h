// Copyright smileJiro

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NoxJobDataAsset.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class UAnimInstance;

/**
 * 직업(Job) 정의 DataAsset.
 * 새 직업 추가 시 이 에셋 하나만 생성하면 됩니다.
 *
 * [사용 흐름]
 *   Content/Game/Characters/Player/Data/DA_Job_Mage 생성
 *     → 각 필드 채우기
 *     → BP_NoxPlayerCharacter의 JobData에 할당
 *     → BeginPlay 시 InitializeJob()이 자동 적용
 *
 * NOTE: 무기가 여럿 필요한 클래스(워리어/어새신)는 Phase 2에서
 *       TArray<FNoxWeaponData> 구조로 확장 예정.
 */
UCLASS(BlueprintType)
class NOXSEEKERS_API UNoxJobDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// ─── 기본 정보 ─────────────────────────────────────────
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Job|Info")
	FName JobName;

	// ─── 외형 ─────────────────────────────────────────────
	/** 직업별 스켈레탈 메시 (External 폴더 에셋 참조) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Job|Appearance")
	TObjectPtr<USkeletalMesh> CharacterMesh;

	/** 직업별 무기 스태틱 메시 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Job|Appearance")
	TObjectPtr<UStaticMesh> WeaponMesh;

	/** 무기를 붙일 소켓 이름 — 스켈레탈 메시마다 다를 수 있음 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Job|Appearance")
	FName WeaponSocketName = FName("weapon_r");

	// ─── 애니메이션 ────────────────────────────────────────
	/**
	 * Job 타입에 맞는 AnimBP 클래스
	 * 메이지 → ABP_NoxMage
	 * 워리어 → ABP_NoxWarrior
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Job|Animation")
	TSubclassOf<UAnimInstance> AnimBPClass;

	// ─── GAS ───────────────────────────────────────────────
	/** BeginPlay 시 자동으로 부여할 어빌리티 목록 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Job|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	/**
	 * 속성 초기값 설정용 GameplayEffect.
	 * GE_Init_Mage 처럼 직업별 Health/Mana/AttackPower 초기값을
	 * Modifier로 지정해두면 됩니다.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Job|Abilities")
	TSubclassOf<UGameplayEffect> InitAttributeEffect;
};
