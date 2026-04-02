# Nox Seekers

> 어둠의 심연 **Nox**로 돌진해 그 핵심을 탈취하고 살아 돌아오라.  
> Charge into the abyss of **Nox**, seize its core, and make it out alive.

**판타지 PvEvP 멀티플레이 익스트랙션 액션RPG** | Fantasy PvEvP Multiplayer Extraction Action RPG

<br>

## 프로젝트 소개 | About

Nox Seekers는 판타지 세계를 잠식하는 어둠의 소용돌이 **Nox**를 배경으로 한 멀티플레이 익스트랙션 액션RPG입니다.

기존 익스트랙션 장르가 밀리터리/SF 총기 기반에 집중된 것과 달리, **판타지 마법 전투 + GAS 기반 클래스 시스템**을 익스트랙션 구조에 접목합니다. 3인칭 TPS 시점을 채택해 캐릭터의 존재감과 주변 위협을 동시에 인지할 수 있으며, 어둠 속에서의 긴장감을 극대화합니다.

> Unlike conventional extraction games built around military/sci-fi gunplay, Nox Seekers combines **fantasy magic combat with a GAS-based class system** in an extraction loop. The third-person shoulder camera maximizes tension in dark, narrow dungeons.

<br>

## 핵심 게임 루프 | Core Loop

```
던전 입장 → 탐색 & Shard 수집 → 선택(탈출 / Relic 쟁탈 / PvP) → 탈출 → 진영 기여도 납부
```

플레이어는 세 진영(봉인자 · 각성자 · 약탈자) 중 하나에 소속되어 Nox 내부에서 자원을 수집하고 탈출합니다. 핵심부의 유물(Relic)을 탈취해 탈출하는 것이 최고 목표이며, 진영별 Relic 탈출 수가 시즌 엔딩을 결정합니다.

<br>

## 기술 스택 | Tech Stack

| 분류 | 기술 |
|------|------|
| Engine | Unreal Engine 5.7 |
| Language | C++ |
| IDE | JetBrains Rider 26.1 |
| Ability System | Gameplay Ability System (GAS) |
| Input | Enhanced Input System |
| UI | UMG + MVVM |
| Network | Listen Server (MVP) → Dedicated Server |
| View | Third-Person Shoulder Camera (TPS) |
| VCS | Git / GitHub |

<br>

## 핵심 구현 포인트 | Key Implementation

### 1. 네트워크 동기화 | Network Synchronization

클라이언트 측 예측(Client-Side Prediction)으로 입력 지연을 최소화하고, 예측 실패 시 보정 로직을 구현합니다.

- Actor Replication — 캐릭터, 몬스터, 아이템 동기화
- RPC 구조 설계 — Server / Client / Multicast
- Client-Side Prediction — 무브먼트 예측 및 Correction 처리
- GAS Network Prediction — 어빌리티 발동 예측
- Lag Compensation — 전투 판정 보정
- Network Relevancy — 다수 액터 최적화

### 2. Data-Driven 직업 시스템 | Data-Driven Job System

새 직업 추가 시 **코드 수정 없이 `UNoxJobDataAsset` 하나만 생성**하면 즉시 플레이 가능한 구조입니다.

| 직업 | 무기 | AnimBP |
|------|------|--------|
| **Mage** | 마법 지팡이 | `ABP_NoxMage` |
| **Warrior** | 검 / 방패 | `ABP_NoxWarrior` |
| **Assassin** | 단검 | `ABP_NoxAssassin` |

```
DA_Job_Mage (UNoxJobDataAsset)
  ├─ CharacterMesh      → External/.../SK_Mage
  ├─ WeaponMesh         → SM_Staff
  ├─ WeaponSocketName   → "weapon_r"
  ├─ AnimBPClass        → ABP_NoxMage      ← 직업별 전용 AnimBP
  ├─ DefaultAbilities   → [GA_Fireball, GA_Blink ...]
  └─ InitAttributeEffect→ GE_Init_Mage
```

직업별로 별도 AnimBP를 사용해 각 직업의 애니메이션을 완전히 독립적으로 관리합니다.

### 3. GAS 기반 어빌리티 시스템 | GAS-Based Ability System

확장 가능한 클래스/스킬 시스템을 DataAsset 기반으로 설계합니다. 클래스 추가 시 코드 수정 없이 DataAsset만으로 확장 가능합니다.

```
UAbilitySystemComponent (PlayerState)
  ├─ AttributeSet       Health, Mana, AttackPower, Defense, MoveSpeed
  ├─ GameplayAbility    클래스별 스킬 구성
  ├─ GameplayEffect     데미지 / 버프 / 디버프 처리
  └─ GameplayCue        VFX / SFX 분리 관리
```

- AbilityTask로 비동기 어빌리티 흐름 제어
- 멀티플레이 환경에서 GAS Prediction 적용으로 반응성 확보

### 4. 렌더링 최적화 | Rendering Optimization

몬스터 100+ 동시 스폰 시 안정적인 프레임을 유지하는 것이 목표입니다.

- Instanced Static Mesh (ISM) 적용 — Draw Call 수치 before/after 비교
- Hierarchical LOD (HLOD) 설정
- Occlusion Culling 최적화
- Unreal Insights 기반 병목 구간 프로파일링

### 5. 유물 어그로 시스템 | Relic Aggro System

유물 소지자의 위치를 UI로 직접 노출하지 않고, 주변 몬스터의 이동 패턴으로 간접 추리하도록 설계합니다.

- Gameplay Tag 기반 유물 소지 상태 관리
- EQS(Environment Query System)로 주변 몬스터 탐색
- AI Perception 시스템 연동
- 서버 권위(Server Authority) 기반 처리

### 6. 진영 & 협력-배신 시스템 | Faction & Betrayal System

진영 정보 관리, 일시적 협력 판정, 배신자 UI를 서버 권위 기반으로 구현합니다.

- PlayerState에 진영 정보 저장 및 리플리케이션
- Gameplay Tag로 협력 상태 관리
- 배신 감지 시 배신자 타이틀 월드 스페이스 UI 활성화 (Multicast RPC)
- Material Parameter로 진영별 외형 색상 분기

### 7. TPS 카메라 & 긴장감 설계 | TPS Camera & Tension Design

어둡고 좁은 던전에서 긴장감을 극대화하는 카메라 구조를 구현합니다.

- Spring Arm + Camera Component (어깨 너머 시점)
- 좁은 공간 진입 시 카메라 자동 줌인 (충돌 감지)
- 전투/비전투 FOV 전환 (부드러운 보간)
- 캐릭터 실루엣 — 벽에 가려져도 아웃라인으로 인지 가능

<br>

## 프로젝트 구조 | Project Structure

```
NoxSeekers/Source/NoxSeekers/
├─ AbilitySystem/          # GAS — Abilities, AttributeSets, Effects, Cues
├─ Character/
│   ├─ Player/             # 플레이어 캐릭터 (TPS)
│   └─ Monster/            # 몬스터 베이스
├─ Game/                   # GameMode, GameState, PlayerState (ASC + 진영)
├─ Player/Controller/      # PlayerController
├─ AI/                     # AIController, EQS, Perception
├─ Faction/                # 진영 시스템, 협력-배신 판정
├─ Relic/                  # 유물 시스템
├─ Shard/                  # 조각 수집 시스템
├─ Extraction/             # 탈출 포인트 시스템
└─ UI/                     # HUD, WorldSpace UI
```

<br>

## 개발 마일스톤 | Milestones

**MVP (1개월)** — 멀티플레이 + GAS 전투 + 최적화 증명

| Week | 내용 |
|------|------|
| 1 | 프로젝트 세팅, TPS 캐릭터 무브먼트, 기초 애니메이션 |
| 2 | Listen Server, 2인 무브먼트 동기화, Actor Replication |
| 3 | ASC / AttributeSet, 메이지 어빌리티, GE 데미지, 기초 몬스터 AI |
| 4 | 몬스터 100체 스폰 테스트, ISM 최적화 수치 기록, 탈출 포인트, MVP 영상 |

**Phase 2 (3개월)** — 4인 멀티플레이, CSP/Lag Compensation, 클래스 확장, 진영·배신 시스템, Relic 어그로

**Phase 3 (6개월)** — HLOD 최적화, 세계 붕괴 시스템, 시즌 메타, 프로파일링 문서화, 포트폴리오 영상

<br>

## 개발 환경 | Dev Environment

```
Engine    : Unreal Engine 5.7
Language  : C++
IDE       : JetBrains Rider 26.1
OS        : Windows 11
VCS       : Git / GitHub
```

<br>

---

> *"Nox의 심장을 향해 돌진하라. 살아 돌아올 수 있다면."*  
> *"Charge toward the heart of Nox — if you can make it back alive."*
