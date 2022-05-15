// MyAnimalGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Critten {
public:
	Critten(int hungred = 0, int boredom = 0);
	void Play();
	void Eat();
	void Talk();
private:
	int m_Hugred;
	int m_Boredom;
	inline int GetMood() {
		return (m_Hugred + m_Boredom);
	}
	void PassTime(int time = 1);
};

Critten::Critten(int hungred, int boredom)
{
	Critten::m_Hugred = hungred;
	Critten::m_Boredom = boredom;
}

void Critten::Play()
{
	m_Boredom -= 4;
	if (m_Boredom < 0) {
		m_Boredom = 0;
	}

	cout << "Playing" << "\n";

	PassTime();
}

void Critten::Eat()
{
	m_Hugred -= 4;
	if (m_Hugred < 0) {
		m_Hugred = 0;
	}

	cout << "Eating" << "\n";

	PassTime();
}

void Critten::Talk()
{
	int mood = GetMood();

	cout << "Hi! ";

	if (mood > 15) {
		cout << "Very bed!" << "\n";
	}
	else if (mood > 10) {
		cout << "Bad..." << "\n";
	}
	else if (mood > 5) {
		cout << "Not bad" << "\n";
	}
	else {
		cout << "I'm happy!" << "\n";
	}

	PassTime();
}

void Critten::PassTime(int time)
{
	m_Hugred += time;
	m_Boredom += time;
}

int main()
{
	Critten crit(0, 0);
	int choise;
	crit.Talk();
	do {
		cout << "Choise your action:" << "\n";
		cout << "0 - Quit" << "\n";
		cout << "1 - Talk with your animal" << "\n";
		cout << "2 - Eat him" << "\n";
		cout << "3 - Go play?" << "\n";
		cin >> choise;

		switch (choise) {
		case 0:
			cout << "Goodbye!" << "\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		default:
			cout << "This action is'nt finded" << "\n";
			break;
		}
	} while (choise != 0);
	return 0;
}
