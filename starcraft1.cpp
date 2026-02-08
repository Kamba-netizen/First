#include <iostream>
#include <string.h>
using namespace std;

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;
    int coord_x, coord_y;
    const int default_damage;
    bool is_dead;

    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);
    ~Marine();

    int attack() const;                    //공격
    Marine& be_attacked(int damage_earn);  //입는 대미지
    void move(int x, int y);            //새로운 위치
    
    void show_state();
    static void show_total_marine();
};
int Marine::total_marine_num = 0;

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
        total_marine_num++;
    }
Marine::Marine(int x, int y)
    : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
        total_marine_num++;

    }
Marine::Marine(int x, int y, int default_damage)
    : hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false) {
        total_marine_num++;
    }
Marine::~Marine() { total_marine_num--; }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() const {
    return default_damage;
}
Marine& Marine::be_attacked(int dabage_earn) {
    hp -= dabage_earn;
    if (hp <= 0 ) 
        is_dead = true;
    return* this;
}
void Marine::show_state() {
    cout << "*** Marine ***" << endl;
    cout << "Location : (" << coord_x << ", " << coord_y << ")" << endl;
    cout << "HP : " << hp << endl;
    cout << "현재 총 마린 수: " << total_marine_num << endl;
    cout << endl;
}
void Marine::show_total_marine() {
    cout << "전체 마린 수: " << total_marine_num << endl;
}
void create_marine() {
    Marine marine3(10,10,4);
    Marine::show_total_marine();
}
int main() {
    Marine marine1(2, 3, 10);
    marine1.show_state();

    Marine marine2(3, 5, 10);
    marine2.show_state();

    std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_state();
    marine2.show_state();
}