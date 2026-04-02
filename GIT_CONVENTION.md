# Git Commit Convention — NoxSeekers

## 기본 형식

```
<type>(<scope>): <subject>

[body - 선택]
```

---

## Type

| type | 용도 |
|------|------|
| `feat` | 새 기능/시스템 추가 |
| `fix` | 버그 수정 |
| `refactor` | 동작 변경 없는 코드 구조 변경 |
| `perf` | 성능 최적화 |
| `chore` | 빌드 설정, .uproject, Build.cs 등 |
| `asset` | UE 에셋 변경 (맵, BP, DataAsset 등) |
| `docs` | 주석, README, 문서 |

---

## Scope

| scope | 대상 |
|-------|------|
| `character` | 캐릭터 클래스 |
| `gas` | GAS 관련 (AttributeSet, Ability, Effect) |
| `job` | 직업 시스템 / DataAsset |
| `network` | 리플리케이션, RPC |
| `ai` | AI, EQS, BehaviorTree |
| `faction` | 진영/배신 시스템 |
| `relic` | 유물 시스템 |
| `ui` | UMG, HUD, WorldSpace UI |
| `input` | Enhanced Input |
| `map` | 맵/레벨 |
| `config` | 프로젝트 설정 |

---

## 예시

```
feat(job): add NoxJobDataAsset and InitializeJob to NoxCharacter

fix(gas): apply InitAttributeEffect spec validity check before apply

refactor(character): remove weapon socket attachment from base constructor

chore(config): add GameplayAbilities module to Build.cs

asset(job): create DA_Job_Sorceress with mesh and ability references

perf(network): limit actor relevancy range for distant enemies
```

---

## 규칙

- `subject`는 **영어 소문자**, 현재형 동사로 시작 (`add`, `fix`, `remove`)
- 마침표 없음
- 50자 이내 권장
- body는 **왜** 변경했는지 필요할 때만 작성
