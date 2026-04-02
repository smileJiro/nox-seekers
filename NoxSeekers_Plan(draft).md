# noxseekers
UE5 C++ multiplayer PvEvP extraction RPG with Gameplay Ability System and network optimization


# Nox Seekers

> 어둠의 심연 **Nox**로 돌진해 그 핵심을 탈취하고 살아 돌아오라.  
> 판타지 세계관 기반 **PvEvP 멀티플레이 익스트랙션 액션RPG**

<br>

---

## 목차

- [개요](#개요)
- [세계관](#세계관)
- [진영 시스템](#진영-시스템)
- [핵심 게임 루프](#핵심-게임-루프)
- [Nox 시스템](#nox-시스템)
- [보상 & 리스크 구조](#보상--리스크-구조)
- [유물(Relic) 쟁탈 시스템](#유물relic-쟁탈-시스템)
- [세계 붕괴 & 시즌 메타](#세계-붕괴--시즌-메타)
- [클래스 시스템](#클래스-시스템)
- [기술 스택 & 구현 포인트](#기술-스택--구현-포인트)
- [프로젝트 구조](#프로젝트-구조)
- [개발 마일스톤](#개발-마일스톤)

<br>

---

## 개요

**Nox Seekers**는 판타지 세계를 잠식하는 어둠의 소용돌이 **Nox**를 배경으로 한  
멀티플레이 익스트랙션 액션RPG입니다.

기존 익스트랙션 장르가 **밀리터리/SF 총기 기반**에 집중된 것과 달리,  
Nox Seekers는 **판타지 마법 전투 + GAS 기반 클래스 시스템**을 익스트랙션 구조에 접목합니다.

**3인칭 TPS 시점**을 채택해 캐릭터의 존재감과 주변 위협을 동시에 인지할 수 있으며,  
좁은 통로와 어둠 속에서의 긴장감을 극대화합니다.

모든 플레이어는 **각자의 진영 이념을 위해** Nox의 심연으로 침투해  
균열 조각(Shard)을 수집하고 탈출해야 합니다.  
Nox의 핵심부에는 강력한 유물(Relic)이 존재하며, 이를 탈취해 탈출하는 것이 최고의 목표입니다.

<br>

---

## 세계관

수백 년 전, 세계의 심층부에서 균열이 발생했습니다.  
그 균열에서 흘러나온 어둠의 에너지는 점점 응축되어 **Nox** — 어둠의 소용돌이를 형성했습니다.

Nox는 살아있는 생명체처럼 주변의 마력을 흡수하며 세계를 잠식합니다.  
세계의 현자들은 Nox의 심연에서 흘러나오는 **균열 조각(Shard)**을 수집해  
봉인 제단에 납부하면 Nox의 팽창을 억제할 수 있다는 사실을 발견했습니다.

그러나 **Nox가 재앙인지, 변화인지, 혹은 기회인지**에 대한 해석은 세력마다 다릅니다.  
그 해석의 차이가 세 진영을 만들었고, 그들 모두는 같은 장소를 향해 돌진합니다. **Nox의 심장.**

<br>

---

## 진영 시스템

> **플레이어 1인 = 진영 1개. 모든 타 플레이어는 잠재적 적입니다.**

진영은 단순한 팀 구분이 아니라, 플레이어가 세계를 바라보는 **이념**입니다.  
선악의 구분 없이 세 진영은 각자의 논리로 Relic을 원하며,  
누가 옳은지는 시즌 결말이 판가름합니다.

<br>

### ⬜ 봉인자 — The Wardens

> *"Nox는 반드시 봉인되어야 한다. 그것이 세계를 지키는 유일한 길이다."*

세계의 현자들과 기사단이 주축이 된 세력.  
Relic을 봉인 제단에 납부해 Nox의 팽창을 억제하는 것이 목표.  
가장 명분이 뚜렷하고 조직적이지만, 자신들이 봉인하는 것이 정말 재앙인지 의심하지 않는다는 맹점이 있다.

- **시즌 우세 시** → Nox 봉인 진행, 세계 안정화 엔딩

<br>

### 🔴 각성자 — The Awakened

> *"Nox는 파괴가 아니라 변화다. 봉인은 세계를 서서히 죽이는 행위다."*

Nox를 연구하다 깨달음을 얻은 학자, 이단자, 방랑자들의 세력.  
Relic을 통해 Nox의 에너지를 이해하고 세계와 공존하거나 재편하려 한다.  
위험해 보이지만 틀렸다고 단언할 수 없다.

- **시즌 우세 시** → Nox와의 공존 시대 개막, 세계관 급변 엔딩

<br>

### ⚫ 약탈자 — The Reavers

> *"봉인이든 각성이든, Relic을 손에 쥔 자가 다음 세계를 설계한다."*

세력가, 용병, 추방자들의 집합체.  
진영 이념 없이 Relic 자체를 목적으로 하며, 그 힘으로 다음 세계의 주도권을 쥐려 한다.  
가장 실리적이고 예측 불가능한 세력.

- **시즌 우세 시** → 권력 공백과 혼돈, 다음 시즌 불안정 상태로 시작

<br>

### 삼각 구도 — 필드 역학

```
봉인자 ──── "약탈자보다는 각성자가 덜 나쁘다" ──── 각성자
   │                                               │
   │  "명분 없는 약탈자는 최악의 적"         "이용당하기 싫다"
   │                                               │
   └──────────────── ⚫ 약탈자 ◄───────────────────┘
                  "누가 이기든 나는 이용한다"
```

세 진영은 **고정 적대 관계**지만, 필드의 상황이 일시적 협력을 만듭니다.

<br>

### 일시적 협력 & 배신

| 구분 | 내용 |
|------|------|
| **협력 발생 조건** | 강력한 몬스터/보스 출현 시 — 혼자 처리 불가능한 상황에서 자연스럽게 발생. 시스템이 강요하지 않음. |
| **협력 신호** | 비언어적 제스처 또는 무기를 내리는 동작. 상대 수락 시 일정 시간 아군 판정. |
| **배신 타이밍** | 보스 처치 직후 — Relic이 드롭되는 순간. 협력이 자동으로 배신의 유혹을 만드는 구조. |
| **배신 패널티** | **배신자 타이틀 UI 활성화** — 던전 내 모든 플레이어에게 배신자 표시 노출. 즉각적인 공공의 적이 되는 구조. |
| **설계 의도** | 배신이 항상 이득이면 협력이 사라짐. 배신자 낙인이 생존을 위협하도록 설계해 협력의 무게를 유지. |

<br>

### 진영 선택 & 고착

- **시즌 단위 고정** — 시즌 시작 시 진영 선택, 시즌 종료 후 변경 가능
- **외형 차별화** — 같은 클래스라도 진영에 따라 색상 계열이 달라져 시각적 식별 가능
- **진영 간 관계** — 모든 진영이 서로 적. 아군 없음. 협력은 오직 상황에 의해 발생.

<br>

---

## 핵심 게임 루프

```
① 던전 입장
   └─ 진영 확인 (시즌 고정)
   └─ 클래스 선택 (소서리스, 워리어, 어새신 등)

② 탐색 & 수집
   └─ 외곽부터 중앙으로 갈수록 강해지는 몬스터
   └─ 균열 조각(Shard) 수집 — 많이 가질수록 PVP 표적
   └─ 탈출 포인트는 던전 곳곳에 분산 배치

③ 선택의 기로
   └─ [안전]   외곽에서 조각 수집 후 탈출
   └─ [도전]   중앙으로 돌진 → 유물(Relic) 쟁탈 → 탈출
   └─ [협력]   강력한 보스 앞에서 타 진영과 일시적 협력
   └─ [배신]   협력 후 보스 처치 순간 Relic 선취 — 단, 배신자 타이틀 노출
   └─ [PVP]    다른 플레이어의 조각/유물 탈취 시도

④ 탈출
   └─ 탈출 포인트 채널링 후 이탈 (방해 가능)
   └─ 사망 시 보유 Shard 전량 드롭
   └─ 탈출 성공 시 진영 기여도 납부

⑤ 결과
   └─ 진영별 Relic 탈출 수 집계 → 시즌 승리 진영 결정
   └─ 재화 및 보상 지급
   └─ 다음 사이클 진행
```

<br>

---

## Nox 시스템

Nox 내부는 **중앙으로 갈수록 위험하고, 보상이 크며, 탈출이 어렵습니다.**

```
[ 외곽 구역 ]  ──────────────────────────────────
  몬스터 강도:  낮음
  Shard 품질:   기본
  탈출 포인트:  다수, 접근 용이
  PVP 빈도:     낮음

[ 중간 구역 ]  ──────────────────────────────────
  몬스터 강도:  중간
  Shard 품질:   고급
  탈출 포인트:  소수, 경쟁 발생
  PVP 빈도:     중간

[ 핵심부 (Nox Core) ]  ──────────────────────────
  몬스터 강도:  극한
  Shard 품질:   최고급
  탈출 포인트:  1~2개, 극도로 복잡한 루트
  유물(Relic):  1개 스폰
  PVP 빈도:     최고 (모든 플레이어가 수렴)
```

**맵 구조 철학**  
중앙으로 갈수록 탈출 루트가 복잡해지도록 설계됩니다.  
핵심부를 향해 돌진하는 것은 쉽지만, 살아서 나오는 것은 전혀 다른 문제입니다.

<br>

---

## 보상 & 리스크 구조

**모든 플레이어가 실력에 관계없이 의미 있는 플레이를 할 수 있도록 설계되었습니다.**

| 레이어 | 조건 | 보상 | 리스크 |
|--------|------|------|--------|
| **1 — 생존** | 탈출만 성공 | 기본 기여도 + 소량 재화 | 던전 자체의 위험만 |
| **2 — 수집** | Shard 보유 탈출 | 기여도 × Shard 수 + 추가 재화 | 보유량이 많을수록 PVP 표적 가능성 상승 |
| **3 — 쟁탈** | Relic 보유 탈출 | 특별 보상 + 시즌 재화 + 희귀 장비 + 진영 기여 대량 | 몬스터 집중 어그로 + 간접 위치 노출 + 복잡한 탈출 루트 |
| **PVP** | 다른 플레이어 처치 | 상대 Shard 획득 | 전투 시간 소모 → 탈출 시간 단축 |
| **배신** | 협력 중 공격 | Relic/Shard 선취 가능 | **배신자 타이틀 노출** → 던전 내 모든 플레이어의 표적 |

**핵심 설계 원칙**
- 사망해도 **레이어 1 보상(기본 기여도)은 지급** — "내가 기여는 했다"는 느낌 유지
- Relic은 "강해지는 아이템"이 아닌 **"리스크가 집중되는 아이템"**
- PVP 없이도 최고 보상 달성 가능
- 배신은 선택지지만, **배신자 낙인이 생존을 위협**하도록 설계

<br>

---

## 유물(Relic) 쟁탈 시스템

Nox 핵심부에 스폰되는 **유물(Relic)** 은 던전 내 최고 가치 오브젝트이자 **진영 승리의 핵심**입니다.

### 유물 획득 시 발동되는 효과

```
① Nox의 반응
   └─ 유물 소지자 주변 일정 거리의 몬스터가
      소지자 방향으로 이동 시작
   └─ 직접적인 위치 노출 없음
   └─ 몬스터 움직임으로 간접적으로 위치 추리 가능

② 플레이어 선택의 분기
   └─ [유물에 무관심한 플레이어]
      몬스터가 특정 방향으로 이동하는 것을 관찰
      → 유물 소지자 위치 추리 가능 (선택)
      → 무시하고 자신의 PVE 플레이 유지 (선택)

   └─ [유물을 노리는 플레이어]
      몬스터 이동 방향을 단서로 추적
      → 유물 소지자 제거 후 탈취 시도

   └─ [유물 소지자]
      몬스터를 처치하며 위치 노출 최소화
      복잡한 탈출 루트를 빠르게 파악해 이탈
```

### 진영별 Relic 의미

| 진영 | Relic으로 하는 일 |
|------|------------------|
| ⬜ 봉인자 | 봉인 제단에 납부 → 시즌 봉인 수치 대폭 상승 |
| 🔴 각성자 | Nox 에너지 연구에 사용 → 공존 수치 상승, 세계 변화 가속 |
| ⚫ 약탈자 | 세력 강화에 사용 → 혼돈 수치 상승, 다음 시즌 불안정 |

### 설계 의도

유물 위치를 **미니맵에 직접 표시하지 않는 이유:**  
강제 노출이 아닌 환경을 읽는 구조로 설계해  
정보 활용 여부가 플레이어의 선택이 되도록 합니다.  
시스템이 PVP를 강요하지 않으며, 자연스럽게 긴장감이 형성됩니다.

<br>

---

## 세계 붕괴 & 시즌 메타

봉인 기여도가 매 사이클 임계치를 넘지 못하면 **Nox가 확산**됩니다.  
붕괴는 패널티인 동시에 도전 콘텐츠이며, 역전 보상이 존재합니다.

### 붕괴 단계

| 단계 | 조건 | 현상 | 역전 보상 |
|------|------|------|-----------|
| **정상** | 기여도 충족 | 다음 사이클 정상 진행 | — |
| **1단계** | 기여도 미달 | 오염 구역 확산, 몬스터 광폭화 | 오염 구역 클리어 시 추가 Shard |
| **2단계** | 연속 미달 | 탈출 포인트 일부 봉쇄, 안전 구역 축소 | 봉쇄 해제 시 희귀 보상 |
| **3단계** | 위기 상황 | 균열 폭주, 강제 보스 소환 | 클리어 시 최고급 보상 + 특별 칭호 |

### 시즌 엔딩 분기

```
시즌 단위로 진영별 Relic 탈출 수 집계
  └─ 봉인자 우세 → 시즌 엔딩: Nox 봉인 진행, 세계 안정화
  └─ 각성자 우세 → 시즌 엔딩: Nox와의 공존 시대 개막
  └─ 약탈자 우세 → 시즌 엔딩: 권력 공백, 혼돈 상태
  └─ 균형 상태  → 세 세력이 균형을 이루는 불안정한 세계

모든 엔딩은 다음 시즌 세계관에 반영됨
→ 플레이어 집단이 세계의 역사를 만드는 구조
```

<br>

---

## 클래스 시스템

**Gameplay Ability System(GAS)** 기반으로 설계된 클래스 시스템입니다.  
모든 클래스는 공통 `AbilitySystemComponent`를 공유하며,  
데이터 기반 설계로 클래스 확장이 용이하도록 구성됩니다.  
**같은 클래스라도 진영에 따라 외형 색상 계열이 달라집니다.**

### MVP 클래스

| 클래스 | 무기 타입 | 포지션 | 특징 |
|--------|-----------|--------|------|
| **소서리스** | 원거리 마법 | 딜러 | 광역 장판 스킬, 원소 속성 다수 |
| **워리어** | 근거리 검/방패 | 탱커 | 높은 생존력, 팀 보호 |
| **어새신** | 단검/암기 | 딜러 | 높은 기동성, 단일 버스트 |

### GAS 구조

```
UAbilitySystemComponent (PlayerState에 부착)
  ├─ AttributeSet
  │    ├─ Health / MaxHealth
  │    ├─ Mana / MaxMana
  │    ├─ AttackPower
  │    ├─ Defense
  │    └─ MoveSpeed
  ├─ GameplayAbility
  │    ├─ GA_BasicAttack
  │    ├─ GA_Skill_01 (클래스별 상이)
  │    ├─ GA_Skill_02
  │    ├─ GA_Ultimate
  │    └─ GA_Dodge
  ├─ GameplayEffect
  │    ├─ GE_Damage
  │    ├─ GE_Heal
  │    ├─ GE_Buff_AttackUp
  │    └─ GE_Debuff_Slow
  └─ GameplayCue
       ├─ GC_HitEffect
       ├─ GC_SkillVFX
       └─ GC_DeathEffect
```

**설계 원칙**
- Ability는 클래스마다 다르지만 Effect/Cue는 공유 자산으로 관리
- DataAsset 기반으로 클래스 추가 시 코드 수정 최소화
- 네트워크 환경에서 GAS Prediction 적용으로 반응성 확보

<br>

---

## 기술 스택 & 구현 포인트

### 기술 스택

| 분류 | 기술 |
|------|------|
| **엔진** | Unreal Engine 5.4 |
| **언어** | C++ |
| **IDE** | JetBrains Rider 26.1 |
| **AI 코딩** | Claude Code |
| **버전 관리** | Git / GitHub |
| **시점** | 3인칭 TPS (어깨 너머 카메라) |
| **네트워크** | Listen Server (MVP) → Dedicated Server |
| **능력 시스템** | Gameplay Ability System (GAS) |
| **입력** | Enhanced Input System |
| **UI** | UMG + MVVM |
| **물리** | Chaos Physics |

### 핵심 구현 포인트

#### 1. 네트워크 동기화 (최우선)

```
목표: 클라이언트 측 예측(CSP)으로 입력 지연 최소화

구현 내용
  ├─ Actor Replication (캐릭터, 몬스터, 아이템)
  ├─ RPC (Server / Client / Multicast)
  ├─ Client-Side Prediction (무브먼트)
  ├─ GAS Network Prediction (어빌리티 발동)
  ├─ Lag Compensation (전투 판정)
  └─ Network Relevancy (다수 액터 최적화)

어필 포인트
  └─ 네트워크 지연 상황에서도 클라이언트 반응성 유지
  └─ 예측 실패(Correction) 발생 시 보정 로직 구현
  └─ 프로파일링 수치 before/after 문서화
```

#### 2. GAS 기반 어빌리티 시스템

```
목표: 확장 가능한 클래스/스킬 시스템 설계

구현 내용
  ├─ AttributeSet 설계 및 리플리케이션
  ├─ GameplayEffect로 데미지/버프/디버프 처리
  ├─ GameplayCue로 VFX/SFX 분리 관리
  ├─ AbilityTask로 비동기 어빌리티 흐름 제어
  └─ DataAsset 기반 클래스 데이터 관리

어필 포인트
  └─ "왜 이렇게 설계했는가" 구조적 근거 문서화
  └─ 클래스 추가 시 코드 수정 없이 DataAsset만으로 확장
  └─ 멀티플레이 환경에서 GAS Prediction 적용
```

#### 3. 다수 오브젝트 렌더링 최적화

```
목표: 몬스터 100마리 이상 스폰 시 안정적인 프레임 유지

구현 내용
  ├─ Instanced Static Mesh (ISM) 적용
  ├─ Hierarchical LOD (HLOD) 설정
  ├─ Occlusion Culling 최적화
  ├─ Network Relevancy로 원거리 액터 동기화 제한
  └─ Unreal Insights로 병목 구간 프로파일링

어필 포인트
  └─ ISM 적용 전후 Draw Call 수치 비교 (before/after)
  └─ CPU/GPU 병목 구간 식별 및 최적화 과정 문서화
```

#### 4. 유물 어그로 시스템 (Relic Aggro System)

```
목표: 유물 소지자 주변 몬스터가 소지자 방향으로 이동

구현 내용
  ├─ Gameplay Tag 기반 유물 소지 상태 관리
  ├─ EQS(Environment Query System)로 주변 몬스터 탐색
  ├─ AI Perception 시스템 연동
  ├─ 범위 내 몬스터 이동 목표 동적 갱신
  └─ 서버 권위(Server Authority) 기반 처리

어필 포인트
  └─ 게임 디자인 의도를 기술적으로 정확히 구현
  └─ AI와 게임플레이 시스템의 유기적 연동
```

#### 5. 진영 & 협력-배신 시스템

```
목표: 진영 정보 관리 + 일시적 협력 판정 + 배신자 UI 구현

구현 내용
  ├─ PlayerState에 진영 정보 저장 및 리플리케이션
  ├─ Gameplay Tag로 협력 상태 관리 (Tag.State.Ally.Temporary)
  ├─ 배신 감지 시 Tag 제거 + 배신자 타이틀 UI 활성화 (Multicast RPC)
  ├─ 배신자 타이틀 — 해당 플레이어 월드 스페이스 UI로 모든 클라에 표시
  ├─ 진영별 시즌 Relic 탈출 수 서버 집계
  └─ 진영 외형 차별화 — Material Parameter로 색상 계열 분기

어필 포인트
  └─ 게임 긴장감 설계를 UI/네트워크 시스템으로 구현한 사례
  └─ 서버 권위 기반 배신 판정으로 클라 조작 방지
```

#### 6. 3인칭 TPS 카메라 & 긴장감 설계

```
목표: 어둡고 좁은 던전에서 긴장감을 극대화하는 카메라 구조

구현 내용
  ├─ Spring Arm + Camera Component (어깨 너머 시점)
  ├─ 좁은 공간 진입 시 카메라 자동 줌인 (충돌 감지)
  ├─ 전투/비전투 FOV 전환 (부드러운 보간)
  ├─ ADS 모드 전환 (카메라 숄더 스위치 지원)
  └─ 캐릭터 실루엣 표시 — 벽에 가려져도 아웃라인으로 인지 가능

어필 포인트
  └─ 탑다운 대비 시야 제한 → 긴장감 고도화 의도 설계 문서화
  └─ 카메라 전환 보간 수치 조정 과정 기록
```

<br>

---

# NoxSeekers — 프로젝트 폴더 구조 (Data-Driven)

> **목적:** Data-Driven 캐릭터 시스템에 맞춘 폴더 구조 기준 문서  
> **원칙:** 외부 에셋은 External에 원본 보존 / 자체 제작 에셋만 Game에 배치 / DataAsset이 양쪽을 참조  
> **규칙:** 빈 폴더는 UE5가 자동 삭제하므로, 에셋이 생길 때 폴더를 생성할 것

---

## 변경 요약

| 항목 | 기존 | Data-Driven |
|------|------|-------------|
| 캐릭터 폴더 | 직업별 분리 (`Sorceress/`, `Warrior/`) | 타입별 분리 (`Base/`, `Data/`, `Animations/`) |
| 직업 정의 | 각 폴더에 BP/Anim/Mesh 혼재 | `DataAsset` 하나에 참조 통합 |
| 직업 추가 | 폴더 + BP + 에셋 전부 생성 | `DA_Job_XXX` DataAsset 하나만 생성 |
| 외부 에셋 | External에 보관 | 동일 (복제하지 않고 참조) |

---

## Source 구조 (C++)

```
NoxSeekers/
├─ Source/
│   └─ NoxSeekers/
│       ├─ AbilitySystem/
│       │   ├─ Abilities/                  # GA_ 클래스
│       │   ├─ AttributeSets/              # AttributeSet 클래스
│       │   ├─ Effects/                    # GE_ 클래스
│       │   └─ Cues/                       # GC_ 클래스
│       │
│       ├─ Character/
│       │   ├─ NoxCharacterBase.h/cpp      # 모든 캐릭터 공통 베이스
│       │   ├─ Player/
│       │   │   └─ NoxPlayerCharacter.h/cpp # 플레이어 전용 (InitializeJob 포함)
│       │   └─ Enemy/
│       │       └─ NoxEnemyCharacter.h/cpp  # 적 캐릭터
│       │
│       ├─ Data/
│       │   └─ JobDataAsset.h/cpp          # ★ UDataAsset - 직업 정의 클래스
│       │
│       ├─ Game/
│       │   ├─ GameMode/                   # ANoxGameMode
│       │   ├─ GameState/                  # ANoxGameState
│       │   └─ PlayerState/                # ANoxPlayerState (ASC + 진영 정보)
│       │
│       ├─ Player/
│       │   └─ Controller/                 # ANoxPlayerController
│       │
│       ├─ AI/                             # AIController, EQS
│       ├─ Faction/                        # 진영 시스템, 협력-배신 판정
│       ├─ Relic/                          # 유물 시스템
│       ├─ Shard/                          # 조각 수집 시스템
│       ├─ Extraction/                     # 탈출 포인트 시스템
│       │
│       └─ UI/
│           ├─ HUD/
│           └─ WorldSpace/                 # 배신자 타이틀 등 월드 UI
```

---

## Content 구조

```
Content/
│
├─ Game/                                   # ★ 자체 제작 에셋만
│   │
│   ├─ Core/                               # 공통/기반 시스템
│   │   ├─ BlueprintLibrary/
│   │   ├─ Interfaces/
│   │   ├─ GameplayTags/
│   │   └─ Input/                          # InputAction, MappingContext
│   │
│   ├─ Characters/
│   │   │
│   │   ├─ Player/
│   │   │   ├─ Base/                       # ★ 공용 (하나의 BP로 모든 직업 처리)
│   │   │   │   ├─ BP_NoxPlayerCharacter   # 플레이어 캐릭터 BP (1개)
│   │   │   │   └─ ABP_NoxPlayer           # 메인 AnimBP (Linked Anim Layer 허브)
│   │   │   │
│   │   │   ├─ Data/                       # ★ 직업 DataAsset (핵심)
│   │   │   │   ├─ DA_Job_Sorceress        # → External의 메시/애님을 참조
│   │   │   │   ├─ DA_Job_Warrior          # → External의 메시/애님을 참조
│   │   │   │   └─ DA_Job_Assassin         # → External의 메시/애님을 참조
│   │   │   │
│   │   │   ├─ Animations/                 # 직접 제작/수정한 애니메이션만
│   │   │   │   ├─ Shared/                 # 공용 (피격, 사망, 이동 등)
│   │   │   │   └─ AnimLayers/             # Linked Anim Layer 클래스
│   │   │   │       ├─ ABP_Layer_Staff     # 지팡이 전투 레이어
│   │   │   │       ├─ ABP_Layer_Sword     # 검 전투 레이어
│   │   │   │       └─ ABP_Layer_Dagger    # 단검 전투 레이어
│   │   │   │
│   │   │   ├─ Meshes/                     # 직접 제작한 캐릭터 메시만
│   │   │   │                              # (구매 메시는 External에 유지)
│   │   │   │
│   │   │   └─ VFX/                        # 직업별 이펙트
│   │   │       ├─ Sorceress/
│   │   │       ├─ Warrior/
│   │   │       └─ Assassin/
│   │   │
│   │   └─ Enemy/
│   │       ├─ Base/
│   │       │   ├─ BP_NoxEnemy
│   │       │   └─ ABP_NoxEnemy
│   │       ├─ Data/                       # 적 유형별 DataAsset
│   │       │   ├─ DA_Enemy_Common_Goblin
│   │       │   ├─ DA_Enemy_Elite_Knight
│   │       │   └─ DA_Enemy_Boss_Dragon
│   │       └─ BehaviorTree/
│   │
│   ├─ AbilitySystem/                      # GAS 에셋 (Source 구조와 1:1)
│   │   ├─ GA/                             # GameplayAbility BP
│   │   ├─ GE/                             # GameplayEffect
│   │   ├─ GC/                             # GameplayCue
│   │   ├─ Attributes/
│   │   ├─ AbilitySets/                    # 직업별 어빌리티 묶음 DataAsset
│   │   └─ ExecutionCalculations/
│   │
│   ├─ Systems/                            # 게임 핵심 시스템 단위
│   │   ├─ Faction/                        # Data/ UI/ Materials/ (진영 색상)
│   │   ├─ Relic/                          # BP/ VFX/ SFX/ Data/
│   │   ├─ Shard/                          # BP/ VFX/ Data/
│   │   ├─ Extraction/                     # BP/ UI/ VFX/
│   │   └─ Nox/                            # Core/ Environment/ Events/
│   │
│   ├─ AI/
│   │   ├─ Controllers/
│   │   ├─ BehaviorTree/
│   │   ├─ EQS/
│   │   └─ Perception/
│   │
│   ├─ UI/
│   │   ├─ HUD/
│   │   ├─ Menus/
│   │   ├─ WorldSpace/
│   │   └─ MVVM/
│   │
│   ├─ Maps/
│   │   ├─ Lobby/
│   │   ├─ Dungeon/
│   │   │   └─ Nox_Dungeon_01/
│   │   └─ Dev/                            # 테스트용 맵
│   │
│   ├─ Data/                               # 글로벌 DataAsset
│   │   ├─ Factions/
│   │   ├─ Items/
│   │   └─ Balance/
│   │
│   └─ Audio/
│       ├─ SFX/
│       └─ BGM/
│
├─ External/                               # 마켓/외부 에셋 (수정 금지, 참조만)
│   ├─ EssentialAnimation/                 # Magic Staff 애니메이션 팩
│   ├─ ThirdPersonPack/                    # UE5 마네킹
│   ├─ Paragon/
│   ├─ Megascans/
│   └─ etc/
│
└─ Developer/                              # 개인 테스트용 (선택)
```

---

## DataAsset 참조 흐름

```
DA_Job_Sorceress (Game/Characters/Player/Data/)
  │
  ├─ CharacterMesh ──────→ External/xxx/SK_Sorceress  (구매 메시)
  ├─ AnimLayerClass ─────→ Game/Characters/Player/Animations/AnimLayers/ABP_Layer_Staff
  ├─ DefaultAbilities ───→ Game/AbilitySystem/GA/GA_Fireball, GA_Teleport ...
  ├─ BaseHealth ─────────→ 80.0
  └─ BaseMana ───────────→ 200.0
```

- **DataAsset**이 External과 Game 양쪽의 에셋을 자유롭게 참조
- 새 직업 추가 시 **DA_Job_XXX 하나만 생성**하면 즉시 플레이 가능
- 외부 에셋은 절대 복제하지 않음 (경로 참조만)

---

## 폴더 생성 규칙

1. **빈 폴더 금지** — UE5가 자동 삭제하므로, 에셋이 실제로 생길 때 폴더 생성
2. **External 수정 최소화** — 소켓 추가(Skeleton) 정도만 허용, 메시/애님 원본은 건드리지 않음
3. **네이밍 컨벤션**
   - 블루프린트: `BP_` 접두사
   - DataAsset: `DA_` 접두사
   - AnimBP: `ABP_` 접두사
   - Anim Layer: `ABP_Layer_` 접두사
   - GameplayAbility: `GA_` 접두사
   - GameplayEffect: `GE_` 접두사
   - GameplayCue: `GC_` 접두사

<br>

---

## 개발 마일스톤

### MVP (1개월) — 언리얼 숙련도 + 멀티플레이 + 최적화 증명

```
Week 1 — 프로젝트 세팅 & 캐릭터 기초
  ├─ UE5 프로젝트 초기 세팅 (GAS 플러그인, Enhanced Input)
  ├─ 3인칭 TPS 캐릭터 무브먼트 구현 (Spring Arm + Camera)
  ├─ 기초 애니메이션 (Idle / Walk / Run / ADS)
  └─ GitHub 연동 및 브랜치 전략 수립

Week 2 — 네트워크 기초
  ├─ Listen Server 세팅
  ├─ 2인 캐릭터 무브먼트 동기화
  ├─ Actor Replication 기초
  └─ RPC 구조 설계

Week 3 — GAS 기초 + 전투
  ├─ ASC / AttributeSet 구성 (HP / MP)
  ├─ 소서리스 어빌리티 2~3개 구현
  ├─ GE 기반 데미지 처리
  └─ 기초 몬스터 AI (추적 / 공격)

Week 4 — 최적화 + 수치 기록
  ├─ 몬스터 100마리 스폰 테스트
  ├─ ISM 적용 전후 Draw Call 수치 비교
  ├─ 기초 탈출 포인트 구현
  └─ MVP 영상 촬영
```

### Phase 2 (3개월)

```
  ├─ 4인 멀티플레이 확장
  ├─ CSP / Lag Compensation 구현
  ├─ 클래스 2종 추가 (워리어, 어새신)
  ├─ 진영 시스템 구현 (PlayerState + Tag 기반)
  ├─ 일시적 협력 & 배신자 타이틀 UI 시스템
  ├─ 유물(Relic) 어그로 시스템
  ├─ Shard 수집 / 드롭 시스템
  └─ 던전 맵 완성
```

### Phase 3 (6개월)

```
  ├─ HLOD / Occlusion Culling 최적화
  ├─ 클래스 시스템 DataAsset 기반 완성
  ├─ 세계 붕괴 시스템 구현
  ├─ 진영별 시즌 메타 & 엔딩 분기
  ├─ 봉인 기여도 / 시즌 집계 서버 로직
  ├─ Unreal Insights 프로파일링 문서화
  └─ 포트폴리오 영상 제작
```

### 제출용 완성

```
  ├─ 포트폴리오 영상 (3~5분)
  ├─ 기술 블로그 (구현 과정 + 설계 근거)
  ├─ GitHub README 정리
  └─ 어필 포인트 문서화
       ├─ 네트워크 동기화 구조 설명
       ├─ GAS 설계 근거
       ├─ 진영 & 배신 시스템 구현 방식
       ├─ TPS 카메라 긴장감 설계 의도
       └─ 최적화 before/after 수치
```

<br>

---

## 개발 환경

```
Engine   : Unreal Engine 5.7
Language : C++
IDE      : JetBrains Rider 26.1
AI Coding: Claude Code
OS       : Windows 11
VCS      : Git / GitHub
View     : Third-Person Shoulder Camera (TPS)
```

---

> **"Nox의 심장을 향해 돌진하라. 살아 돌아올 수 있다면."**
