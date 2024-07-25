#ifndef CAP_PrintHelpers
#define CAP_PrintHelpers
#include "Aliases.hpp"
#include <iostream>
#include <iomanip>

namespace CAP
{
char selectFiller(int style);
void printCR(std::ostream & output=std::cout, unsigned int n=1);
void printLine(std::ostream & output=std::cout, int style=4, int size=100);
void printString(const char * keyword, std::ostream & output=std::cout, int style=-1, int size=50);
void printValue(const char * keyword, bool value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, unsigned int value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, size_t value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, int    value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, long   value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, long long value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, double value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, const char * value, std::ostream & output=std::cout, int style=0, int size=50);
void printValue(const char * keyword, const String value, std::ostream & output=std::cout, int style=0, int size=50);
void printRange(const char * keyword, int minimum, int maximum,
                std::ostream & output=std::cout, int style=0, int size=50);
void printRange(const char * keyword, double minimum, double maximum,
                std::ostream & output=std::cout, int style=0, int size=50);
void printRangeOr(const char * keyword,
                  double minimum,  double maximum,
                  double minimum2, double maximum2,
                  std::ostream & output=std::cout, int style=0, int size=0);
void printRangeOr(const char * keyword,
                  int minimum,  int maximum,
                  int minimum2, int maximum2,
                  std::ostream & output=std::cout, int style=0, int size=0);
} // namespace CAP

#endif
