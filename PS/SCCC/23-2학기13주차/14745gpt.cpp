#include <iostream>
#include <set>
#include <utility>

struct Point {
    int x, y;

    // 생성자
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// ccw 계산
int ccw(const Point& a, const Point& b, const Point& c) {
    int res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (res > 0) return 1; // 반시계 방향
    if (res < 0) return -1; // 시계 방향
    return 0; // 일직선
}

// 볼록 껍질을 관리하는 함수
void manageConvexHull(std::set<Point>& convexHull, const Point& newPoint) {
    auto it = convexHull.lower_bound(newPoint);

    // lower_bound를 이용하여 새로운 점을 삽입하거나 이미 존재하는 점의 위치를 찾음
    convexHull.insert(it, newPoint);

    // 삽입한 점의 이전 점을 찾음
    auto prev = it;
    if (prev != convexHull.begin()) --prev;

    // 삽입한 점의 다음 점을 찾음
    auto next = it;
    ++next;

    // 삽입한 점의 인접한 점들을 while 문을 이용하여 볼록 껍질에 포함시키거나 제외시킴
    while (prev != convexHull.begin() && ccw(*prev, newPoint, *next) < 0) {
        convexHull.erase(prev);
        prev = convexHull.lower_bound(newPoint);
        if (prev != convexHull.begin()) --prev;
    }

    while (next != convexHull.end() && ccw(newPoint, *next, *prev) < 0) {
        convexHull.erase(next);
        next = convexHull.lower_bound(newPoint);
        ++next;
    }
}

int main() {
    std::set<Point> convexHull;

    // 점 추가 (임의의 점들)
    convexHull.insert(Point(0, 3));
    convexHull.insert(Point(1, 1));
    convexHull.insert(Point(2, 2));

    // 새로운 점 추가
    Point newPoint(4, 4);
    manageConvexHull(convexHull, newPoint);

    // 업데이트된 볼록 껍질 출력
    for (const auto& point : convexHull) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    return 0;
}
