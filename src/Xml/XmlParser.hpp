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
#ifndef CAP__XmlParser
#define CAP__XmlParser
#include <list>
#include "Parser.hpp"

namespace CAP
{

struct XmlAttribute
{
  String name;
  String value;
};

struct XmlTag
{
  String  name;
  std::list<XmlAttribute> attributes;
  long int begin;
  long int end;
  XmlTag*  father;
  XmlTag*  child;
  XmlTag*  prev;
  XmlTag*  next;
};

class XmlDocument;

class XmlParser : public Parser
{
public:

  XmlParser();
  XmlParser(const XmlParser & parser);
  virtual ~XmlParser() {}
  XmlParser & operator=(const XmlParser & parser);

  virtual void read(XmlDocument   & _xmlDocument,
                    const String & _inputPath,
                    const String & _inputFileName)  ;
  XmlTag* createTag(String& aBuff);

  ClassDef(XmlParser,0)

};



} // namespace CAP

#endif /* XmlParser_hpp */
