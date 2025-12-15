// 상태창 구현

#include <iostream>
#include <string>
#include "statmanager.h"

using namespace std;

int main()
{
	StatManager s;

	// 초기 세팅 입력
	s.InputHM();
	s.InputAD();

	// 포션 지급
	s.setPotion(5, &s.getHPPotion(), &s.getMPPotion());

	// 상태창 시작
	s.StatMenu();

	
}