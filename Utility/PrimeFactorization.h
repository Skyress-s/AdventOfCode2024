//
// Created by mathm on 04/01/2025.
//


#pragma once
#include <vector>


template<typename T>
std::vector<T> BasicPrimeFactorization(T N)
{
          std::vector<T> Factorization;
          for (long long D = 2; D * D <= N; D++)
          {
                    while (N % D == 0)
                    {
                              Factorization.push_back(D);
                              N /= D;
                    }
          }
          if (N > 1)
                    Factorization.push_back(N);
          return Factorization;
}
