# NoxSeekers — CLAUDE.md

## 소통 언어

한국어로 소통한다.

---

## Git 컨벤션

`GIT_CONVENTION.md` 참고. 요약:

```
<type>(<scope>): <subject>
```

- **type**: `feat` / `fix` / `refactor` / `perf` / `chore` / `asset` / `docs`
- **scope**: `character` / `gas` / `job` / `network` / `ai` / `faction` / `relic` / `ui` / `input` / `map` / `config`
- **subject**: 영어 소문자 현재형 동사, 마침표 없음, 50자 이내

---

## 코딩 컨벤션

### 에셋 네이밍

| 종류 | 접두사 | 예시 |
|------|--------|------|
| Blueprint | `BP_` | `BP_NoxPlayerCharacter` |
| DataAsset | `DA_` | `DA_Job_Mage` |
| AnimBlueprint | `ABP_` | `ABP_NoxMage` |
| GameplayAbility | `GA_` | `GA_Fireball` |
| GameplayEffect | `GE_` | `GE_Init_Mage` |
| GameplayCue | `GC_` | `GC_HitEffect` |

### 직업(Job) 이름 표준

| 직업 | 표준 영문 |
|------|-----------|
| 메이지 | `Mage` |
| 워리어 | `Warrior` |
| 어새신 | `Assassin` |
