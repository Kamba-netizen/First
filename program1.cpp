#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int x, y;

    public:
    Point(int pos_x, int pos_y);
    int GetX() const {
        return x;
    }

    int GetY() const {
        return y;
    }
     
};

class Geometry {
    private:
    Point* point_array[100];
    int num_points;

    public:
    Geometry() {
        num_points = 0;
    }
    ~Geometry() {
        for (int i=0; i<num_points; i++) 
            delete point_array[i];
    }
    void AddPoint(const Point &point) { 
        point_array[num_points++] = new Point(point.GetX(), point.GetY());
    }

    void PrintDistance();
    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
    void PrintNumMeets();
};

void Geometry::PrintDistance() {
    for (int i=0; i<num_points; i++) {
        int pos1_x = point_array[i]->GetX();
        int pos1_y = point_array[i]->GetY();

        for (int j=i+1; j<num_points; j++) {
            int pos2_x = point_array[j]->GetX();
            int pos2_y = point_array[j]->GetY();
            double distance = sqrt(pow((pos2_x - pos1_x),2)+pow((pos2_y - pos1_y),2));
            cout << "점 " << i+1 << "과 점 " << j+1 << " 사이의 거리는 " << distance << endl;
        }
    }
}

void Geometry::PrintNumMeets() {
    
}
