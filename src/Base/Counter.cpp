/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez     
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "Counter.hpp"
#include<ostream>

ClassImp(CAP::Counter);

CAP::Counter::Counter()
:
maxima(),
counters()
{
//  no ops
}

CAP::Counter::Counter(const CAP::Counter & source)
:
maxima(source.maxima),
counters(source.counters)
{
}

CAP::Counter::Counter(std::vector<long> _maxima)
:
maxima(_maxima),
counters()
{
  counters.assign(_maxima.size(),0);
}

CAP::Counter::~Counter()
{
  clear();
}


CAP::Counter & CAP::Counter::operator=(const CAP::Counter & source)
{
  if (this!= &source)
    {
    maxima = source.maxima;
    counters = source.counters;
    }
  return *this;
}


size_t  CAP::Counter::size() const
{
  return maxima.size();
}

long CAP::Counter::operator[](size_t index) const
{
  if (index<counters.size()) return counters[index];
  return -1;
}

void CAP::Counter::increment()
{
  size_t n = counters.size();
  if (n==0) // not initialize yet... So assume 1 bin counter w/ no max
    {
    counters.assign(1,0);
    maxima.assign(1,-1); // -1 means no max -- should only be in  the n-1 position
    }
  else if (n==1)
    {
    counters[0]++;
    }
  else
    {
    size_t k = 0;
    while (k<n)
      {
      counters[k]++;
      if (counters[k]==maxima[k])
        {
        counters[k] = 0;
        k++;
        }
      else
        break;
      }
    }
}

long CAP::Counter::counterValue() const
{
  size_t n = counters.size();
  if (n==0) return 0;
  else if (n==1) return counters[0];
  long value = 0;
  long fac = 1;
  size_t k = 0;
  while (k<n)
    {
    value += counters[k]*fac;
    k++;
    if (maxima[k-1]>0) fac *= maxima[k-1];

    }
  return value;
}

void CAP::Counter::initialize(std::vector<long> _maxima)
{
  maxima = _maxima;
  counters.assign(_maxima.size(),0);
}

void CAP::Counter::printMaxima() const
{
  size_t n = maxima.size();
  if (n<1)
    {
    std::cout << "Null counter" << std::endl;
    return;
    }
  std::cout << "[";
  for (size_t k=0; k<n; k++)
    {
    std::cout << maxima[k];
    if (k<n-1) std::cout << ",";
    }
  std::cout << "]";
}

void CAP::Counter::print() const
{
  size_t n = counters.size();
  if (n<1)
    {
    std::cout << "Null counter" << std::endl;
    return;
    }
  std::cout << "[";
  for (size_t k=0; k<n; k++)
    {
    std::cout << counters[k];
    if (k<n-1) std::cout << ",";
    }
  std::cout << "]";
}

void CAP::Counter::clear()
{
  maxima.clear();
  counters.clear();
}

void CAP::Counter::reset()
{
  size_t n = maxima.size();
  if (n>0)
    counters.assign(maxima.size(),0);
  else
    counters.clear();
}


