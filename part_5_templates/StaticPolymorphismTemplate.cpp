//
// Created by shiqing on 18-12-10.
//

#include <random>
#include "UsefullFwd.h"

/**
 * chapter14:模板的多态威力
 *
 */

namespace ch14 {
    /**
     * 在c++中，动多态是通过继承和虚函数来实现的，继承和虚函数都是（至少一部分）在运行期进行处理的，
     * 因此我们称为dynamic polymorphism.
     * 模板也允许我们使用单一的泛型标记，来关联不同的特定行为，关联在编译期进行处理的，因此我们把这种借助模板多态称为静多态。
     */
    struct Coord {
        Coord(double x = 0.0, double y = 0.0, double z = 0.0) : x_(x), y_(y), z_(z) {}
        Coord abs();
        double x_, y_, z_;
    };

    Coord Coord::abs() {
        return Coord(x_ < 0 ? -x_ : x_, y_ < 0 ? -y_ : y_, z_ < 0 ? -z_ : z_);
    }

    Coord operator-(const Coord &lhs, const Coord &rhs) {
        return Coord(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_, lhs.z_ - rhs.z_);
    }

    inline Coord randomRealCoords() {
        std::default_random_engine e;
        std::uniform_real_distribution<> u(0, 10);
        return Coord(u(e), u(e), u(e));
    }


    namespace DynamicObj {
        class GeoObj {
        public:
            virtual void draw() const = 0;
            virtual Coord centerOfGravity() const = 0;
        };

        class Circle : public GeoObj {
        public:
            void draw() const override;

            Coord centerOfGravity() const override;
        };
        class Line : public GeoObj {
        public:
            void draw() const override;

            Coord centerOfGravity() const override;
        };
        class Rectangle : public GeoObj {
        public:
            void draw() const override;

            Coord centerOfGravity() const override;
        };


        void Line::draw() const {
            cout << "Line::draw()\n";
        }

        Coord Line::centerOfGravity() const {
            cout << "Line::centerOfGravity()\n";
            return randomRealCoords();
        }

        void Circle::draw() const {
            cout << "Circle::draw()\n";
        }

        Coord Circle::centerOfGravity() const {
            cout << "Circle::centerOfGravity()\n";
            return randomRealCoords();
        }

        void Rectangle::draw() const {
            cout << "Rectangle::draw()\n";
        }

        Coord Rectangle::centerOfGravity() const {
            cout << "Rectangle::centerOfGravity()\n";
            return randomRealCoords();
        }

        void myDraw(const GeoObj &obj) {
            obj.draw();
        }

        Coord distance(const GeoObj &lhs, const GeoObj &rhs) {
            auto c = lhs.centerOfGravity() - rhs.centerOfGravity();
            return c.abs();
        }

        void drawElems(const vector<GeoObj*> &elems) {
            for (const auto &elem : elems) {
                elem->draw();
            }
        }

    }


    /*
     * cuiriously recurring template pattern, CRTP ---
     * 奇异递归模板模式
     *
     */




}


int main() {
    using namespace ch14;
    DynamicObj::Circle c, c1, c2;
    DynamicObj::Line l1, l2, l3;
    DynamicObj::myDraw(l1);
    DynamicObj::myDraw(c);
    DynamicObj::distance(c1, c2);
    DynamicObj::distance(c, l3);

    vector<DynamicObj::GeoObj *> coll;
    coll.push_back(&l1);
    coll.push_back(&c);
    DynamicObj::drawElems(coll);

}



