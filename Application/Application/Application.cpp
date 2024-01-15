#include <iostream>

using namespace std;

class Robot {
    unsigned short health;
    unsigned short energy;
    unsigned short attack;
    unsigned short protection;
    string strategy;

public:
    Robot(unsigned short health=100, unsigned short energy=100, unsigned short attack=20, unsigned short protection=50){
        this->health = health;
        this->energy = energy;
        this->attack = attack;
        this->protection = protection;
    }
    unsigned short gethealth() {return health;}
    unsigned short getenergy() { return health; }
    unsigned short getprotection() { return health; }
    unsigned short getattack() { return health; }
    void takedamage(unsigned int damage) {
        this->health -= damage;
    }
    void protectdamage(unsigned int damage) {
        this->protection -= damage;
    }

    void attack(Robot enemy) {
        if (enemy.getprotection() > attack) {
            enemy.protectdamage(attack);
        }
        else if (enemy.getprotection() > 0 && enemy.getprotection() <= attack) {
            enemy.takedamage(attack - enemy.getprotection());
        }
        else {
            enemy.takedamage(attack);
        }
        energy--;
    }

    void protect() {
        energy -= 5;
        protection += 5;
    }

    void stats(){
        cout << "Hp: " << health << endl
            << "Protection: " << protection << endl
            << "Attack: " << attack << endl
            << "Energy: " << energy << endl;
    }

    void pickstrategy(char a) {
        switch (a) {
        case('a'):
            strategy = "aggresive";
            break;
        case('b'):
            strategy = "balance";
            break;
        case('p'):
            strategy = "protective";
            break;
        default:
            strategy = "balance";
        }
    }
};

int main()
{
    
}


/*
Для 2х студентів Ваша група має створити симулятор битви між роботами. 
Кожен член групи відповідає за свою частину проекту: 

Перший учасник: Реалізувати клас "Робот" із основними характеристиками: здоров'я, енергія, атака, захист. 
Методи для атаки та захисту, що враховують поточні характеристики робота.  Done*
Можливість вибору стратегії бою (наприклад, агресивна, оборонна, баланс). 

Другий учасник: Реалізувати клас "Арена" щодо битви між роботами. 
Методи для початку та закінчення бою, відстеження стану кожного робота. 
Логіка визначення переможця та виведення результатів битви. 
Надайте приклади використання вашого симулятора, де роботи з різними характеристиками борються один з одним. 

Використовуйте вказівники для обміну даними між класами.
*/