#include <iostream>
#include <string.h>
using namespace std;

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char* name);
    ~Marine();

    int attack();                       //공격
    void be_attacked(int damage_earn);  //입는 대미지
    void move(int x, int y);            //새로운 위치
    
    void show_state();
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y) {
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage =5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, const char* marname) {
    name = new char[strlen(marname) + 1];
    strcpy(name, marname);
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage =5;
    is_dead = false;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() {
    return damage;
}
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0)
        is_dead = true;
}
void Marine::show_state() {
    cout << "*** Marine: "<< name << " ***" << endl;
    cout << "Location : (" << coord_x << ", " << coord_y << ")" << endl;
    cout << "HP : " << hp << endl;
    cout << endl;
}
Marine::~Marine() {
    cout << name << "의 소멸자 호출 ! " << endl;
    if (name != NULL)
        delete[] name;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2,3, "M1");
    marines[1] = new Marine(2,5, "M2");

    marines[0]->show_state();
    marines[1]->show_state();

    cout << "마린 1이 마린 2를 공격! " << endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_state();
    marines[1]->show_state();

    for (int i=0; i<2; i++)
        delete marines[i]; 

    return 0;
}