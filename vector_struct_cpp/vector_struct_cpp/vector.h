#pragma once

#include <iostream>

struct TVector
{
    int n;
    double* x;

    TVector();
    TVector(int n);
    TVector(const TVector&);
    ~TVector();

    TVector operator+(const TVector&);
    TVector operator-(const TVector&);
    double operator*(const TVector&);
    const TVector& operator=(const TVector&);
};

std::istream& operator>>(std::istream& in, TVector& v);
std::ostream& operator<<(std::ostream& out, const TVector& v);
