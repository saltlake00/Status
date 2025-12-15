#include "statmanager.h"
#include <iostream>
using namespace std;

StatManager::StatManager() {}

// 스탯 매니저 시작, 스탯입력
void StatManager::InputHM() {
	cout << "HP와 MP를 입력해주세요 :" << endl;

	while (getHP() <= 50 || getMP() <= 50)
	{
		cout << "\nHP : " << endl;
		cin >> getHP();
		cout << "\nMP : " << endl;
		cin >> getMP();

		if (getHP() <= 50 || getMP() <= 50)
		{
			cout << "\nHP나 MP의 값이 너무 작습니다(50이하). 다시 입력해주세요." << endl;
		}

	}
}

void StatManager::InputAD() {
	cout << "공격력과 방어력을 입력해주세요 :" << endl;

	while (getATK() <= 0 || getDEF() <= 0)
	{
		cout << "\n공격력 : " << endl;
		cin >> getATK();
		cout << "\n방어력 : " << endl;
		cin >> getDEF();

		if (getATK() <= 0 || getDEF() <= 0)
		{
			cout << "\n공격력이나 방어력의 값이 너무 작습니다(50이하). 다시 입력해주세요." << endl;
		}

	}

}

void StatManager::setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
	
	cout << "\n* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)" << endl;
}

void StatManager::StartMenu() {
	cout << "\n\n============================================" << endl;
	cout << "\n<스탯 관리 시스템>" << endl;
	cout << " 1. HP UP " << endl;
	cout << " 2. MP UP " << endl;
	cout << " 3. 공격력 UP " << endl;
	cout << " 4. 방어력 UP " << endl;
	cout << " 5. 현재 능력치 " << endl;
	cout << " 6. Level UP " << endl;
	cout << " 0. 나가기 " << endl;
}

void StatManager::StatMenu() {
	while (1)
	{
		StartMenu();
		cout << "\n 번호를 선택해주세요 : " << endl;
		cin >> getMenu();
		cout << endl;

		switch (getMenu())
		{
		// HP UP
		case 1:
			if (HPPotion > 0) {
				getHP() += 20;
				HPPotion--;
				cout << "\n* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 HP: " << getHP() << endl;
				cout << "남은 포션 수: " << HPPotion << endl;
			} else {
				cout << "\nHP 포션이 부족합니다!" << endl;
			}
			break;
		
		// MP UP
		case 2: 
			if (MPPotion > 0) {
				getMP() += 20;
				MPPotion--;
				cout << "\n* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 MP: " << getMP() << endl;
				cout << "남은 포션 수: " << MPPotion << endl;
			} else {
				cout << "\nMP 포션이 부족합니다!" << endl;
			}
			break;
		
		// 공격력 UP
		case 3: 
			getATK() *= 2;
			cout << "* 공격력이 2배로 증가되었습니다." << endl;
			cout << "현재 공격력 : " << getATK() << endl;
			break;

		// 방어력 UP
		case 4: 
			getDEF() *= 2; // 2배 증가
			cout << "\n* 방어력이 2배로 증가되었습니다." << endl;
			cout << "현재 방어력: " << getDEF() << endl;
			break;

		// 현재 능력치 확인
		case 5: 
			cout << "\n* HP : " << getHP();
			cout << "\n  MP : " << getMP();
			cout << "\n  공격력 : " << getATK();
			cout << "\n  방어력 : " << getDEF() << endl;
			break;

		// Level UP
		case 6: 
			cout << "\n* 레벨업! HP/MP 포션이 지급됩니다." << endl;
			HPPotion++;
			MPPotion++;
			cout << "남은 HP/MP 포션 수 : " << HPPotion << "/" << MPPotion << endl;
			break;

		// 종료
		case 0: 
			cout << "\n프로그램을 종료합니다." << endl;
			return; // 함수 종료 (while문 탈출)

		// 입력오류
		default: 
			cout << "\n올바른 번호를 입력해 주세요 (0~6)" << endl;
			break;
		}
	}

}

