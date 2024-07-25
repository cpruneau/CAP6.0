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
#include "NamedObject.hpp"
#include "PrintHelpers.hpp"
#include "Crc32.hpp"

ClassImp(CAP::NamedObject);

namespace CAP
{

NamedObject::NamedObject()
:
name("N"),
title("T"),
version("V"),
hash("H")
{   }

NamedObject::NamedObject(const String & _name,
                         const String & _title,
                         const String & _version,
                         const String & _preHash)
:
name(_name),
title(_title),
version(_version),
hash(_preHash)
{
  //hash = calculateHash(_preHash);
}


NamedObject::NamedObject(const NamedObject & source)
:
name(     source.name ),
title(    source.title ),
version(  source.version ),
hash(     source.hash )
{     }

NamedObject & NamedObject::operator=(const NamedObject & source)
{
  if (this!=&source)
    {
    name         =  source.name;
    title        =  source.title;
    version      =  source.version;
    hash         =  source.hash;
    }
  return *this;
}

String NamedObject::calculateHash(String preHash)
{
  Crc32 hash;
  hash.update(preHash.Data(), preHash.Length());
  hash.finish();
  String value = hash.getValueHex();
  return value;
}

void NamedObject::print(std::ostream & os, int style, int size) const
{
  printCR();
  printLine(os,style,size);
  printValue("Name",name,os,style,size);
  printValue("Title",title,os,style,size);
  printValue("Version",version,os,style,size);
  printValue("Hash",hash,os,style,size);
  printLine(os,style,size);
}

}  //  namespace CAP

//int NamedObject::analyzeCmdLineInput(int nTokens, char **tokens)
//{
//  // result == 0 : exit normally after this call
//  // result == 1 : exit with error status after this call
//  // resutl > 1  : carry normally after this call
//
//  if (nTokens > 1)
//    {
//    String stringToken;
//    for(int i=1; i<nTokens;i++)
//      {
//      stringToken = tokens[i];
//      if ( stringToken.EqualTo("-h") || stringToken.EqualTo("--help") )
//        {
//        printHelp();
//        return 0;
//        }
//      else if ( stringToken.EqualTo("-v") || stringToken.EqualTo("--version") )
//        {
//        printVersion();
//        return 0;
//        }
//      else
//        {
//        printUnknownOption(stringToken);
//        return 1;
//        }
//      }
//    }
//  return 2;
//}
//
//void NamedObject::printVersion(const String & option __attribute__((unused)))  const
//{
//  cout << "Name................:" << getName()<< endl;
//  cout << "Version.............:" << getVersion()<< endl;
//}
//
//void NamedObject::printHelp(const String & option __attribute__((unused))) const
//{
//  cout << "Name................:" << getName()<< endl;
//  cout << "Title...............:" << getTitle()<< endl;
//  cout << "Version.............:" << getVersion()<< endl;
//  cout << "Type................:" << getType()<< endl;
//  cout << "Description.........:" << getDescription()<< endl;
//}
//
//void NamedObject::printUnknownOption(const String & option  __attribute__((unused))) const
//{
//  cout << endl;
//  cout << "Not a valid option..:" << option;
//  cout << endl;
//}
//
