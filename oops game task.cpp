#include <iostream>
using namespace std;

class Hero {
	protected:
	string name , type;
	int health , experience;
	double power;
	
	public:
	Hero (string n ,string t , int h , int e , double p)
	{
		name=n;
		type=t;
		health=h;
		experience=e;
		power=p;
	}
	
	void displayWelcome () {
	cout << "\n=============WELCOME TO FANTASY BATTLE ARENA===============";
	cout << "\n\t\tEACH HERO HAS UNIQUE ATTACK AND DEFENCE\t\t\t\n";
	cout << "======================================================\n";
	}
	
	void displaySameInfo ()
	{
		cout << "\n\n=== Name: " << name << endl;
		cout << "=== Type: " << type << endl;
		cout << "=== Health: " << health << endl;
		cout << "=== Experience: " << experience << endl;
		cout << "=== Power: " << power << endl;
	}
	
	virtual double attack()=0;
	virtual double defence()=0;
		
};

class Warrior : public Hero {
	private:	
	string weaponName;
	double armour;
	int rage;
	
	public:
	Warrior (string n ,string t , int h , int e , double p , string w , double a , int r ) : Hero (n,t,h,e,p) 
	{
		weaponName=w;
		armour=a;
		rage=r;
	}
	
	double attack ()
	{
		return power + rage + experience * 0.5;
	}
	
	double defence ()
	{
		return health + armour * 0.3;
	}
	
	void displayInfo ()
	{
		displaySameInfo();
		cout << "=== Weapon Name: " << weaponName << endl;
		cout << "=== Rage Level: " << rage << endl;
		cout << "=== Armour Strength: " << armour << endl;
	}
	
};

class Mage : public Hero 
{
	private:
	string spell;
	int mana;
	double multiplier;
	
	public:
	Mage (string n ,string t , int h , int e , double p , string s , int m , double m1) : Hero (n,t,h,e,p)
	{
		spell=s;
		mana=m;
		multiplier=m1;
	}
	
	double attack ()
	{
		return power + multiplier + mana + 0.6;
	}
	
	double defence ()
	{
		return mana * 0.5 + experience * 0.3;
	}
	
	void displayInfo ()
	{
		displaySameInfo();
		cout << "=== Spell Name: " << spell << endl;
		cout << "=== Mana Points: " << mana << endl;
		cout << "=== Magic Multiplier: " << multiplier << endl;
	}
};

class Archer : public Hero 
{
	private:
	string bowType;
	int arrows;
	double accuracyRate;
	
	public:
	Archer (string n ,string t , int h , int e , double p , string b , int a , double a1 ) : Hero (n,t,h,e,p)
	{
		bowType=b;
		arrows=a;
		accuracyRate=a1;
	}
	
	double attack ()
	{
		return power + accuracyRate + arrows * 0.2;
	}
	
	double defence ()
	{
		return accuracyRate * 0.5 + health * 0.3;
	}
	
	void displayInfo ()
	{
		displaySameInfo();
		cout << "=== Bow Type: " << bowType << endl;
		cout << "=== Num of Arrows: " << arrows << endl;
		cout << "=== Accuracy Rate: " << accuracyRate << endl;
	}
};

int main ()
{
	Warrior w("Thor","Warrior",90,115,150.3,"Stormbreaker (Axe)",95.5,100);
	Mage m("Doctor Strange","Mage",95,130,135.5,"Time Loop",120,70.5);
	Archer a("Legolas","Archer",75,80,125.4,"Elven Bow",50,99.9);
	
	w.displayWelcome();
	
	cout << "\n\t=========================WARRIOR=====================\t";
	w.displayInfo();
	
	double wAttack = w.attack();
	double wDefence = w.defence();
	
	cout << "=== ATTACK: " << wAttack << endl;
	cout << "=== DEFENCE:" << wDefence << endl;
	
	cout << "\n\t=========================MAGE=======================\t";
	m.displayInfo();
	
	double mAttack = m.attack();
	double mDefence = m.defence();
	
	cout << "=== ATTACK: " << mAttack << endl;
	cout << "=== DEFENCE: " << mDefence << endl;
	cout << "______________________________________________________\n\n";
	
	cout << "\n\t=========================ARCHER=====================\t";
	a.displayInfo();
	
	double aAttack = a.attack();
	double aDefence = a.defence();
	
	cout << "=== ATTACK: " << aAttack << endl;
	cout << "=== DEFENCE: " << aDefence << endl;
	
	cout << "\n\t===================SUMMARY=====================\t\n\n";
		
	if (wAttack > mAttack && wAttack > aAttack)
    cout << "\t\t WARRIOR HAS THE HIGHEST ATTACK";
    	
	else if (mAttack > wAttack && mAttack > aAttack)
    cout << "\t\t MAGE HAS THE HIGHEST ATTACK";
    	
	else
    cout << "\t\t ARCHER HAS THE HIGHEST ATTACK";
	
	return 0;
	
}