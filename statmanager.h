#pragma once

// 스탯 매니저 헤더
class StatManager
{
public:
	// 스탯 관리 함수 - 스텟업, 포션지급, 레벨업
	StatManager();

	// 스탯 매니저 시작, 스탯입력
	void InputHM();
	void InputAD();

	// 포션 초기 지급
	void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

	// 매니저 메뉴
	void StartMenu();
	void StatMenu();

	// 스탯 주소함수
	int& getHP() { return status[0]; }
	int& getMP() { return status[1]; }
	int& getATK() { return status[2]; }
	int& getDEF() { return status[3]; }
	int& getMenu() { return Menu; }

	//포션 주소함수
	int& getHPPotion() { return HPPotion; }
	int& getMPPotion() { return MPPotion; }

private:
	// 스테이터스 항목, 포션
	int status[4] = { 0 };
	int HPPotion = 0;
	int MPPotion = 0;
	int Menu = 9;
	// [0] HP, [1] MP, [2] ATK, [3] DEF
};
