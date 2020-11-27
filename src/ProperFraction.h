//
// Created by Owner on 31.10.2020.
//

#pragma once

class ProperFraction
{
private:
    int numerator = 0;
    int denominator = 0;
    int reduction();
    ProperFraction();

public:
    int GetNNumerator();
    int GetDenominator();
    ProperFraction (int numerator_par, int denominator_par);
    ProperFraction (const ProperFraction& a);
    void Multiply(const ProperFraction &a);
    void Add(const ProperFraction &a);
    void Divide(const ProperFraction &a);
    double print();
};