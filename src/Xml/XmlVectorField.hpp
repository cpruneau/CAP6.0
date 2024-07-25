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
#ifndef CAP__XmlVectorField
#define CAP__XmlVectorField
#include "XmlDocument.hpp"
#include "VectorField.hpp"

namespace CAP
{

class XmlVectorField : public XmlDocument
{
public:

  friend XmlParser;

  XmlVectorField();
  XmlVectorField(const String  & _inputPath,
                 const String  & _inputFileName);
  XmlVectorField(const String  & _inputFile);
  virtual ~XmlVectorField() {}
  VectorField* getXmlVectorField();

  ClassDef(XmlVectorField,0)

};



} // namespace CAP

#endif /* XmlDocument */
