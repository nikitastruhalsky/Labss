//
// Created by Owner on 31.10.2020.
//

#include <iostream>
#include "ProperFraction.h"


    void ProperFraction::reduction()
    {
        int n = 1;
        for (int i = 1; i < fabs(numerator) + 1; ++i)
        {
            if ((numerator % i == 0) && (denominator % i == 0))
            {
                n = i;
            }
        }
        numerator = numerator / n;
        denominator = denominator / n;
    }

    ProperFraction::ProperFraction()
    {

    }


    int ProperFraction::GetNNumerator()
    {
        return numerator;
    }

    int ProperFraction::GetDenominator()
    {
        return denominator;
    }

    ProperFraction::ProperFraction (int numerator_par, int denominator_par)
    {
        numerator = numerator_par;
        if (denominator_par != 0)
        {
            denominator = denominator_par;
        }
    }

    ProperFraction::ProperFraction (const ProperFraction& a)
    {
        numerator = a.numerator;
        if (a.denominator != 0)
        {
            denominator = a.denominator;
        }
    }


    void ProperFraction::ProperFraction::Multiply(const ProperFraction &a)
    {

        numerator = a.numerator * numerator;
        denominator = a.denominator * denominator;
        reduction();
    }

    void ProperFraction::ProperFraction::Add(const ProperFraction &a)
    {

        numerator = (a.denominator * numerator) + (a.numerator * denominator);
        denominator = a.denominator * denominator;
        reduction();
    }

    void ProperFraction::ProperFraction::Divide(const ProperFraction &a)
    {

        numerator = a.denominator * numerator;
        denominator = a.numerator * denominator;
        reduction();
    }

    void ProperFraction::print()
    {
        if (denominator == 0)
        {
            std::cout << "Mistake. Zero can't be in denominator." << std::endl;
            return;
        }
        if (fabs(numerator) > fabs(denominator))
        {
            std::cout << "Mistake. A modulus of denominator should be bigger than a numerator's one." << std::endl;
            return;
        }
        if (numerator == 0)
        {
            std::cout << "Mistake. Zero can't be in a numerator." << std::endl;
            return;
        }
        reduction();
        if ((numerator > 0) && (denominator > 0))
        {
            std::cout << numerator << "/" << denominator << std::endl;
        }
        if ((numerator < 0) && (denominator < 0))
        {
            std::cout << fabs(numerator) << "/" << fabs(denominator) << std::endl;
        }
        if ((numerator > 0) && (denominator < 0))
        {
            std::cout << "-" << numerator << "/" << fabs(denominator) << std::endl;
        }
        if ((numerator < 0) && (denominator > 0))
        {
            std::cout << "-" << fabs(numerator) << "/" << denominator << std::endl;
        }
    }