#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

struct Vector2D{
    int X{0};
    int Y{0};

    const Vector2D operator+(const Vector2D& other) const{
        return Vector2D{X+other.X, Y+other.Y};
    }

    const Vector2D operator-(const Vector2D& other) const{
        return Vector2D{X-other.X, Y-other.Y};
    }

};


#endif // DATASTRUCTURES_H
