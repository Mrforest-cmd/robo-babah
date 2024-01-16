#include <iostream>
#include <string>

using namespace std;

class Robot {
    unsigned short health;
    unsigned short energy;
    unsigned short attack;
    unsigned short protection;
    string strategy;

public:
    Robot(unsigned short health = 100, unsigned short energy = 100, unsigned short attack = 20, unsigned short protection = 50, string strategy = "balance") {
        this->health = health;
        this->energy = energy;
        this->attack = attack;
        this->protection = protection;
        this->strategy = strategy;
    }
    unsigned short gethealth() { return health; }
    unsigned short getenergy() { return energy; }
    unsigned short getprotection() { return protection; }
    unsigned short getattack() { return attack; }
    string getstrategy() { return strategy; }
    void takedamage(unsigned int damage) {
        this->health -= damage;
    }
    void protectdamage(unsigned int damage) {
        this->protection -= damage;
    }

    void attacking(Robot& enemy) {
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
        protection += 25;
        attack -= 5;
    }

    void aggressive() {
        energy -= 5;
        protection -= 5;
        attack += 10;
    }

    void balance() {
        energy -= 10;
        protection += 5;
        attack += 5;
    }

    void stats() {
        cout << "Hp: " << health << endl
            << "Protection: " << protection << endl
            << "Attack: " << attack << endl
            << "Energy: " << energy << endl << endl;
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

class Arena {
public:

    void Battle(Robot& robot1, Robot& robot2) {
        cout << "Battle started!\n";

        while (robot1.gethealth() > 0 && robot2.gethealth() > 0) {

            cout << "Robot 1's turn:\n";

            char strategyChoice;
            cout << "Robot 1, choose a strategy (a: aggressive, b: balance, d: defensive): ";
            cin >> strategyChoice;
            robot1.pickstrategy(strategyChoice);

            if (robot1.getstrategy() == "aggressive") {
                robot1.aggressive();
                robot1.attacking(robot2);
                cout << "Attacking!\n\n";
            }
            else if (robot1.getstrategy() == "defensive") {
                robot1.protect();
                cout << "Defending!\n\n";
            }
            else if (robot1.getstrategy() == "balance") {
                robot1.balance();
                robot1.attacking(robot2);
                cout << "Attack + Defence... Balance!\n\n";
            }
            else {
                robot1.attacking(robot2);
                cout << "Attacking!\n\n";
            }

            cout << "Robot 1: \n";
            robot1.stats();
            cout << "\nRobot 2: \n";
            robot2.stats();

            if (robot2.gethealth() <= 0) {
                break;
            }

            cout << "Robot 2's turn:\n";

            cout << "Robot 2, choose a strategy (a: aggressive, b: balance, d: defensive): ";
            cin >> strategyChoice;
            robot2.pickstrategy(strategyChoice);

            if (robot2.getstrategy() == "aggressive") {
                robot2.aggressive();
                robot2.attacking(robot1);
                cout << "Attacking!\n\n";
            }
            else if (robot2.getstrategy() == "defensive") {
                robot2.protect();
                cout << "Defending!\n\n";
            }
            else if (robot2.getstrategy() == "balance") {
                robot2.balance();
                robot2.attacking(robot2);
                cout << "Attack + Defence... Balance!\n\n";
            }
            else {
                robot2.attacking(robot1);
                cout << "Attacking!\n\n";
            }
            cout << "Robot 1: \n";
            robot1.stats();
            cout << "\nRobot 2: \n";
            robot2.stats();
        }

        if (robot1.gethealth() <= 0) {
            cout << "\nRobot 2 wins the battle!\n";
        }
        else {
            cout << "\nRobot 1 wins the battle!\n";
        }
    }
};

int main()
{
    Robot robot1 = Robot(100, 100, 20, 50);
    Robot robot2 = Robot(100, 100, 20, 50);
    Arena arena;
    arena.Battle(robot1, robot2);
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