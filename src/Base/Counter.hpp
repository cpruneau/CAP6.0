/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#ifndef CAP__Counter
#define CAP__Counter
#include "Aliases.hpp"
namespace CAP
{

/// Definite a multi-field counter
///
class Counter
{

public:
  Counter();
  Counter(const Counter & _Counter);
  Counter(std::vector<long> _maxima);
  virtual ~Counter();
  Counter & operator=(const Counter & _Counter);


  size_t size() const;
  long operator[](size_t index) const;
  void increment();
  long counterValue() const;
  void initialize(std::vector<long> _maxima);
  void printMaxima() const;
  void print() const;

  void clear();
  void reset();



protected:

  std::vector<long> maxima;
  std::vector<long> counters;

  ClassDef(Counter,0)
  
};

} // namespace CAP

#endif /* Counter_hpp */
