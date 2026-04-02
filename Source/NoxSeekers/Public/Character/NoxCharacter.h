// Copyright smileJiro

#pragma once

#include "CoreMinimal.h"
#include "Character/NoxCharacterBase.h"
#include "NoxCharacter.generated.h"

class UNoxJobDataAsset;

/**
 * 플레이어 캐릭터.
 * ASC는 PlayerState에서 할당받고, JobDataAsset 기반으로 직업을 초기화합니다.
 *
 * [직업 추가 방법]
 *   1. Content/Game/Characters/Player/Data/ 에 DA_Job_XXX 생성
 *   2. CharacterMesh / WeaponSocketName / AnimLayerClass / DefaultAbilities 설정
 *   3. BP_NoxPlayerCharacter의 JobData 슬롯에 할당
 *   → 코드 수정 없이 새 직업 즉시 플레이 가능
 */
UCLASS()
class NOXSEEKERS_API ANoxCharacter : public ANoxCharacterBase
{
	GENERATED_BODY()

public:
	ANoxCharacter();

	/**
	 * 직업 초기화 — 메시 / 소켓 어태치 / 애님 레이어 / 어빌리티를 JobData 기준으로 적용.
	 * BeginPlay에서 자동 호출. 런타임 직업 변경 시에도 재호출 가능.
	 */
	UFUNCTION(BlueprintCallable, Category = "Job")
	void InitializeJob();

	/** 런타임 직업 변경이 필요한 경우 사용 */
	UFUNCTION(BlueprintCallable, Category = "Job")
	void SetJobData(UNoxJobDataAsset* NewJobData);

protected:
	virtual void BeginPlay() override;

	/** 에디터 / BP에서 직업 DataAsset 할당 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Job")
	TObjectPtr<UNoxJobDataAsset> JobData;
};
