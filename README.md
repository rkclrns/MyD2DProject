# MyD2DProject
2D 게임 엔진 제작

🧩 1. 핵심 구성 요소
GameObject:
게임 세계에 존재하는 모든 객체는 GameObject로 표현됨.
각각은 다음의 컴포넌트를 기본적으로 가짐:

Transform* transform: 위치, 회전, 크기

SpriteRenderer* sprite: 스프라이트 렌더링용 (후에 분리할 필요도 있다)
BoxCollider* boxCollider: 충돌 처리용 (후에 분리할 필요도 있다)

Component:
GameObject가 가질 수 있는 다양한 기능 요소.
예: LineRenderer, SpriteRenderer, Animation, Collider, Transform

🖼️ 2. 렌더링과 리소스 관리
D2DRenderer (싱글톤):
Direct2D 기반으로 실제 화면에 그림을 그리는 역할

ResourceManager (싱글톤):
리소스(Sprite, Font 등)를 로딩하고 관리.
불필요한 중복 로딩을 방지.

🎮 3. 게임 씬과 오브젝트 관리
SceneManager:
현재 활성 씬(Scene)을 관리.
씬은 여러 GameObject들을 포함하고 있음.

Scene:
vector<GameObject*> gameObjects 로 구성됨.
씬 내 모든 오브젝트들의 생명주기(업데이트, 렌더링 등)를 관리.

🧠 4. 시스템과 매니저 (모두 static)
InputSystem:
키보드 등의 입력을 처리
(GetKeyDown, GetKeyPressed 등)

ColliderManager:
충돌 검사 및 상태 전달 담당

TimeSystem:
시간 관련 기능 제공 (DeltaTime)
