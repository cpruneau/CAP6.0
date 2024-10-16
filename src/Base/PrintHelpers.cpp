#include "PrintHelpers.hpp"

namespace CAP
{

char selectFiller(int style)
{
  char filler;
  switch (style)
    {
      default:
      case 0: filler = '.'; break;
      case 1: filler = ' '; break;
      case 2: filler = '_'; break;
      case 3: filler = '-'; break;
      case 4: filler = '='; break;
    }
  return filler;
}

//!
//! Print n carriage returns.
//!
void printCR(std::ostream & output, unsigned int n)
{
  for (unsigned int k=0; k<n; k++) output << std::endl;
}

//!
//! Print a line on output according to the properties size and style.
//!
void printLine(std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< filler << std::endl;
}


//!
//! Print a line on output according to the properties size and style.
//!
void printString(const char * keyword, std::ostream & output, int style, int size)
{
  if (style<0)
    output << keyword <<  std::endl;
  else
    {
    char filler = selectFiller(style);
    output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " <<  std::endl;
    }
}

void printValue(const char * keyword, bool   value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value << std::endl;
}

void printValue(const char * keyword, size_t value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value <<  std::endl;
}

void printValue(const char * keyword, unsigned int value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value <<  std::endl;
}

void printValue(const char * keyword, int    value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value <<  std::endl;
}

void printValue(const char * keyword, long   value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value << std::endl;
}

void printValue(const char * keyword, long long value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value << std::endl;
}


void printValue(const char * keyword, double value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value << std::endl;
}

void printValue(const char * keyword, const char * value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value << std::endl;
}

void printValue(const char * keyword, const String value, std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output <<  std::left << std::setw(size) << std::setfill(filler)<< keyword << " : " << value << std::endl;
}

void printRange(const char * keyword, double minimum, double maximum,
                std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output << std::left << std::setw(size) << std::setfill(filler)<< keyword 
  << " Minimum=" << minimum << "  Maximum=" << maximum << std::endl;
}

void printRange(const char * keyword, int minimum, int maximum,
                std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output << std::left << std::setw(size) << std::setfill(filler)<< keyword
  << " Minimum=" << minimum << "  Maximum=" << maximum << std::endl;
}

void printDualRange(const char * keyword, 
                  double minimum,  double maximum,
                  double minimum2, double maximum2,
                  std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output << std::left << std::setw(size) << std::setfill(filler)<< keyword
  << " Minimum=" << minimum << "  Maximum=" << maximum
  << " Mimumum2=" << minimum2 << "  Maximum2=" << maximum2
  << std::endl;
}

void printDualRange(const char * keyword,
                  int minimum,  int maximum,
                  int minimum2, int maximum2,
                  std::ostream & output, int style, int size)
{
  char filler = selectFiller(style);
  output << std::left << std::setw(size) << std::setfill(filler)<< keyword
  << " Minimum=" << minimum << "  Maximum=" << maximum
  << " Mimumum2=" << minimum2 << "  Maximum2=" << maximum2
  << std::endl;
}



} // namespace CAP

