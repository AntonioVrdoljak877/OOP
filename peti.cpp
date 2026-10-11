#include <iostream>
#include <cmath>


struct Point{
    double x,y;
};


void move_by(Point* p, double dx, double dy){
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b){
    double d1 = a->x - b->x;
    double d2 = a->y - b->y;

    return sqrt(d1*d1 + d2*d2);

}

void move_byR(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double distR(Point& a,  Point& b){
    double d1 = a.x - b.x;
    double d2 = a.y - b.y;

    return sqrt(d1*d1 + d2*d2);
}



int main(){



    Point tocke[5] = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0},
        {7.0, 8.0},
        {9.0, 10.0}
    };

    
    move_by(&tocke[0],2.0,4.0);
    double dis1 = dist(&tocke[0],&tocke[1]);

    std::cout<<"udaljenost 1: "<<dis1;


    move_byR(tocke[0],5.1,4.0);
    double dist2 = distR(tocke[0],tocke[1]);

    std::cout<<"udaljenost 2: "<<dist2;

    int n = 0;
    double min = tocke[0].x*tocke[0].x + tocke[0].y*tocke[0].y;


    for(int i = 0;i<5;i++){
        double trenutna = tocke[i].x*tocke[i].x+tocke[i].y*tocke[i].y;

        if(trenutna<min){
            min = trenutna;
            n=i;
        }
    }

    std::cout<<"Najbliza je:"<<tocke[n].x<<", "<<tocke[n].y;

    return 0;
}
