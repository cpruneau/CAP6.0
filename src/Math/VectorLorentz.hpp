#ifndef CAP_VectorLorentz
#define CAP_VectorLorentz
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <cmath>
#include "Aliases.hpp"
#include "Exceptions.hpp"
#include "MathConstants.hpp"
#include "Vector3.hpp"

namespace CAP
{
namespace Math
{

//class Rotation<Q>;

//!
//! Class encapsulates Lorentz vectors
//!
//!  Note 1: Uses the convention that c==1 (speed of light equals unity) so that t,x,y,z  have  units of distance (t is ct) and E, px, py, pz have units of energy (MeV or GeV in most cases)
//!  Note 2: The (+,-,-,-) metric is used throughout.
//!  Note 3: t or e are considered the 0th component as in most modern texts.
//!
//! StorageType for lorentz vectors
//! 0  : t,  x, y, z (cartesian coordinates)
//! 1  : t, phi, theta, r (spherical coordinates)
//! 2  : t, phi, rho, z (cylindrical coordinates)
//! 3  : t, phi, rho, rapidity
//! 4 : mass, phi, pT,  rapidity
//! 5 : mass, phi, pT, pseudorapidity
//!

template <typename T>
class VectorLorentz
{
protected:
  T v0;
  T v1;
  T v2;
  T v3;
  int storageType;

public:

  enum StorageType { TXYZ=0, TPhiThetaR,  TPhiRhoZ, MXYZ, MPhiRhoY, MPhiRhoEta};

  VectorLorentz()
  :
  v0(0),
  v1(0),
  v2(0),
  v3(0)
  { }

  VectorLorentz(const T & _v0, const T & _v1, const T & _v2, const T & _v3, int _storageType=0)
  :
  v0(_v0),
  v1(_v1),
  v2(_v2),
  v3(_v3),
  storageType(_storageType)
  {  }

  VectorLorentz(T * _values, int _storageType=0)
  :
  v0(_values[0]),
  v1(_values[1]),
  v2(_values[2]),
  v3(_values[3]),
  storageType(_storageType)
  {  }

  VectorLorentz(std::vector<T> _values, int _storageType=0)
  :
  v0(_values[0]),
  v1(_values[1]),
  v2(_values[2]),
  v3(_values[3]),
  storageType(_storageType)
  {  }

  VectorLorentz(const VectorLorentz<T> & source)
  :
  v0(source.v0),
  v1(source.v1),
  v2(source.v2),
  v3(source.v3),
  storageType(source.storageType)
  {  }


  virtual ~VectorLorentz() {};

  int storage() const
  {
  return storageType;
  }

  //!
  //! Returns the value stored at the give index.
  //!
  T operator() (unsigned int index) const
  {
  switch (index)
    {
      case 0: return v0;
      case 1: return v1;
      case 2: return v2;
      case 3: return v3;
      default: throw MathException("index>3","VectorLorentz<T>::operator()");
    }
  }

  //!
  //! Returns the components  t, x, y, z of this vector. t corresponds to index==0
  //!
  T operator[] (unsigned int index) const
  {
  switch (storageType)
    {
      case 0: // cartesian coordinates storage and output
      {
      switch (index) // TXYZ
        {
          case 0: return v0; //!> t
          case 1: return v1; //!> x
          case 2: return v2; //!> y
          case 3: return v3; //!> z
          default: throw MathException("index>3","VectorLorentz<T>::operator []");
        }
      break;
      }

      case 1: // TPhiThetaR
      {
      switch (index)
        {
          case 0: return v0;                           //!> t
          case 1: return v3*std::sin(v2)*std::cos(v1); //!> x
          case 2: return v3*std::sin(v2)*std::sin(v1); //!> y
          case 3: return v3*std::cos(v2);              //!> z
          default: throw MathException("index>3","VectorLorentz<T>::operator []");
        }
      break;
      }

      case 2: // TPhiRhoZ
      {
      switch (index)
        {
          case 0: return v0;              //!> t
          case 1: return v2*std::cos(v1); //!> x
          case 2: return v2*std::sin(v1); //!> y
          case 3: return v3;              //!> z
          default: throw MathException("index>3","VectorLorentz<T>::operator []");
        }
      break;
      }

      case 3: // MXYZ
      {
      switch (index)
        {
          case 0: return std::sqrt(v0*v0+v1*v1+v2*v2+v3*v3); //!> t
          case 1: return v1; //!> x
          case 2: return v2; //!> y
          case 3: return v3; //!> z
          default: throw MathException("index>3","VectorLorentz<T>::operator []");
        }
      break;
      }

      case 4: // MPhiRhoY
      {
      T mt = std::sqrt(v0*v0+v2*v2);
      switch (index)
        {
          case 0: return mt * std::cosh(v3); //!> t
          case 1: return v2*std::cos(v1); //!> x
          case 2: return v2*std::sin(v1);; //!> y
          case 3: return mt * std::sinh(v3); //!> z
          default: throw MathException("index>3","VectorLorentz<T>::operator []");
        }
      break;
      }

      case 5: // tPhiRhoEta
      {
      switch (index)
        {
          case 0: return v0; //!> t
          case 1: return v2*std::cos(v1); //!> x
          case 2: return v2*std::sin(v1);; //!> y
          case 3: return v2*std::sinh(v3); //!> z
          default: throw MathException("index>3","VectorLorentz<T>::operator []");
        }
      break;
      }
      default: throw MathException("Internal error","VectorLorentz<T>::operator[]");
    }
  }


  T t()  const
  {
  switch (storageType)
    {
      case 0: return v0; //!> x
      case 1: return v0;
      case 2: return v0;
      case 3: return std::sqrt(v0*v0+v1*v1+v2*v2+v3*v3);
      case 4: return std::sqrt(v0*v0+v2*v2) * std::sinh(v3);
      case 5: return v0;
      default: throw MathException("Internal error","VectorLorentz<T>::x()");
    }
  }

  T x()  const
  {
  switch (storageType)
    {
      case 0: return v1;
      case 1: return v3*std::sin(v2)*std::cos(v1);
      case 2: return v2*std::cos(v1);
      case 3: return v1;
      case 4: return v2*std::cos(v1);
      case 5: return v2*std::cos(v1);

      default: throw MathException("Internal error","VectorLorentz<T>::x()");
    }
  }

  T y()  const
  {
  switch (storageType)
    {
      case 0: return v2;
      case 1: return v3*std::sin(v2)*std::sin(v1);
      case 2: return v2*std::sin(v1);
      case 3: return v2;
      case 4: return v2*std::sin(v1);
      case 5: return v2*std::sin(v1);
      default: throw MathException("Internal error","VectorLorentz<T>::y()");
    }
  }


  T z()  const
  {
  switch (storageType)
    {
      case 0: return v3;
      case 1: return v3*std::cos(v2);
      case 2: return v3;
      case 3: return v3;
      case 4: return std::sqrt(v0*v0+v2*v2)*std::sinh(v3);
      case 5: return v2*std::sinh(v3);
      default: throw MathException("Internal error","VectorLorentz<T>::z()");
    }
  }



  void setTXYZ(const T * values)
  {
  v0 = values[0];
  v1 = values[1];
  v2 = values[2];
  v3 = values[3];
  storageType = 0;
  }

  void setTXYZ(const std::vector<T> & values)
  {
  v0 = values[0];
  v1 = values[1];
  v2 = values[2];
  v3 = values[3];
  storageType = 0;
  }

  void setTXYZ(const VectorLorentz<T> & otherVector)
  {
  v0 = otherVector.t();
  v1 = otherVector.x();
  v2 = otherVector.y();
  v3 = otherVector.z();
  storageType = 0;
  }

  void setTXYZ(const T & t, const T & x, const T & y, const T & z)
  {
  v0 = t;
  v1 = x;
  v2 = y;
  v3 = z;
  storageType = 0;
  }

  void setFromTXYZ(const T & t, const T & x, const T & y, const T & z)
  {
  switch (storageType)
    {
      default: throw MathException("Internal error","VectorLorentz<T>::setFromXYZ()");
      break;

      case 0:
      v0 = t;
      v1 = x;
      v2 = y;
      v3 = z;
      break;

      case 1:
      {
      T rhoSq = x*x + y*y;
      v0 = t;
      v1 = std::atan2(y,x);
      v2 = std::atan2(std::sqrt(rhoSq),z);
      v3 = std::sqrt(rhoSq + z*z);
      break;
      }

      case 2:
      {
      v0 = t;
      v1 = std::atan2(y,x);
      v2 = std::sqrt(x*x + y*y);
      v3 = z;
      break;
      }

      case 3:
      {
      T mSq = t*t-x*x-y*y-z*z;
      if (mSq<0) throw MathException("t*t-x*x-y*y-z*z < 0 case 3","setFromTXYZ");
      v0 = std::sqrt(mSq);
      v1 = x;
      v2 = y;
      v3 = z;
      break;
      }
      case 4:
      {
      T mSq = t*t-x*x-y*y-z*z;
      if (mSq<0) throw MathException("t*t-x*x-y*y-z*z < 0 case 4","setFromTXYZ");
      v0 = std::sqrt(mSq);
      v1 = std::atan2(y,x);
      v2 = std::sqrt(x*x + y*y);
      v3 = 0.5*std::log((t+z)/(t-z));
      break;
      }

      case 5:
      {
      v0 = t;
      v1 = std::atan2(y,x);
      v2 = std::sqrt(x*x + y*y);
      T theta = std::atan2(std::sqrt(v2), z);
      T ct = std::cos(theta);
      if (ct*ct < 1)
        v3 = -0.5* std::log( (1.0-ct)/(1.0+ct) );
      else
        v3 = (z == 0) ? 0 : ((z>0) ? 1E10 : -1E10);
      break;
      }
    }
  }


  void setTPhiThetaR(const T & t, const T & phi, const T & theta, const T & r)
  {
  v0 = t;
  v1 = phi;
  v2 = theta;
  v3 = r;
  storageType = 1;
  }


  void setTPhiRhoZ(const T & t, const T & phi, const T & rho, const T & z)
  {
  v0 = t;
  v1 = phi;
  v2 = rho;
  v3 = z;
  storageType = 2;
  }

  void setMXYZ(const T & m, const T & x, const T & y, const T & z)
  {
  v0 = m;
  v1 = x;
  v2 = y;
  v3 = z;
  storageType = 3;
  }

  void setMPhiRhoY(const T & m, const T & phi, const T & rho, const T & y)
  {
  v0 = m;
  v1 = phi;
  v2 = rho;
  v3 = y;
  storageType = 4;
  }

  void setTPhiRhoEta(const T & t, const T & phi, const T & rho, const T & eta)
  {
  v0 = t;
  v1 = phi;
  v2 = rho;
  v3 = eta;
  storageType = 5;
  }


  T  phi() const
  {
  switch (storageType)
    {
      case 0: return std::atan2(v2,v1);
      case 1: return v1;
      case 2: return v1;
      case 3: return std::atan2(v2,v1);
      case 4: return v1;
      case 5: return v1;
      default: throw MathException("Internal error","VectorLorentz<T>::phi()");
    }
  }

  T  cosPhi() const
  {
  switch (storageType)
    {
      case 0: return v1/std::sqrt(v1*v1+v2*v2);
      case 1: return std::cos(v1);
      case 2: return std::cos(v1);
      case 3: return v1/std::sqrt(v1*v1+v2*v2);
      case 4: return std::cos(v1);
      case 5: return std::cos(v1);
      default: throw MathException("Internal error","VectorLorentz<T>::cosPhi()");
    }
  }

  T  sinPhi() const
  {
  switch (storageType)
    {
      case 0: return v2/std::sqrt(v1*v1+v2*v2);
      case 1: return std::sin(v1);
      case 2: return std::sin(v1);
      case 3: return v2/std::sqrt(v1*v1+v2*v2);
      case 4: return std::sin(v1);
      case 5: return std::sin(v1);
      default: throw MathException("Internal error","VectorLorentz<T>::sinPhi()");
    }
  }

  //!
  //! Return the azimuthal angle between this and the other vector
  //!  TXYZ=0, TPhiThetaR,  TPhiRhoZ, MXYZ, MPhiRhoY, MPhiRhoEta};
  template <typename Q>
  T  deltaPhi(const VectorLorentz<Q> & other) const
  {
  switch (storageType)
    {
      case 0:
      case 3:
      {
      switch (other.storageType)
        {
          case 0:
          case 3:
          {
          T dPhi = std::atan2(v2,v1) - std::atan2(other.v2,other.v1);
          while (dPhi>twoPi()) dPhi -= twoPi();
          while (dPhi<0) dPhi += twoPi();
          return dPhi;
          }

          case 1:
          case 2:
          case 4:
          case 5:
          {
          T dPhi = std::atan2(v2,v1) - other.v1;
          while (dPhi>twoPi()) dPhi -= twoPi();
          while (dPhi<0) dPhi += twoPi();
          return dPhi;
          }

          default:
          throw MathException("Unknown storageType","deltaPhi(const VectorLorentz<Q> & other) const");
        }
      }

      case 1:
      case 2:
      case 4:
      case 5:
      {
      switch (other.storageType)
        {
          case 0:
          case 3:
          {
          T dPhi = v1 - std::atan2(other.v2,other.v1);
          while (dPhi>twoPi()) dPhi -= twoPi();
          while (dPhi<0) dPhi += twoPi();
          return dPhi;
          }

          case 1:
          case 2:
          case 4:
          case 5:
          {
          T dPhi = v1 - other.v1;
          while (dPhi>twoPi()) dPhi -= twoPi();
          while (dPhi<0) dPhi += twoPi();
          return dPhi;
          }

          default:
          throw MathException("Unknown storageType","deltaPhi(const VectorLorentz<Q> & other) const");
        }
      }

      default: throw MathException("Unknown storageType","VectorLorentz<T>::phi()");
    }
  }

  T theta() const
  {
  switch (storageType)
    {
      case 0: return std::atan2(std::sqrt(v1*v1+v2*v2),v3);
      case 1: return v2;
      case 2: return std::atan2(v2,v3);
      case 3: return std::atan2(std::sqrt(v1*v1+v2*v2),v3);
      case 4:
      {
      T mt = std::sqrt(v0*v0+v2*v2);
      T z  = mt * std::sinh(v3);
      return std::atan2(v2,z);
      }
      case 5:
      {
      T z = v2 * std::sinh(v3);
      return std::atan2(v2,z);
      }
      default: throw MathException("Internal error","VectorLorentz<T>::theta()");
    }
  }

  T  cosTheta() const
  {
  switch (storageType)
    {
      case 0: return v3/std::sqrt(v1*v1+v2*v2+v3*v3);
      case 1: return std::cos(v2);
      case 2: return v3/std::sqrt(v2*v2+v3*v3);
      case 3: return v3/std::sqrt(v1*v1+v2*v2+v3*v3);
      case 4:
      {
      T mt = std::sqrt(v0*v0+v2*v2);
      T z  = mt * std::sinh(v3);
      return z/std::sqrt(v2*v2+z*z);
      }
      case 5:
      {
      T z = v2 * std::sinh(v3);
      return z/std::sqrt(v2*v2+z*z);
      }
      default: throw MathException("Internal error","VectorLorentz<T>::cosTheta()");
    }
  }

  T sinTheta() const
  {
  switch (storageType)
    {
      case 0:
      {
      T ptSq = v1*v1+v2*v2;
      return sqrt(ptSq)/std::sqrt(ptSq+v3*v3);
      }
      case 1:
      {
      return std::cos(v2);
      }

      case 2:
      {
      return v2/std::sqrt(v2*v2+v3*v3);
      }
      case 3:
      {
      return v3/std::sqrt(v1*v1+v2*v2+v3*v3);
      }
      case 4:
      {
      T mt = std::sqrt(v0*v0+v2*v2);
      T z  = mt * std::sinh(v3);
      return v2/std::sqrt(v2*v2+z*z);
      }
      case 5:
      {
      T z = v2 * std::sinh(v3);
      return v2/std::sqrt(v2*v2+z*z);
      }

      default:
      {
      throw MathException("Internal error","VectorLorentz<T>::sinTheta()");
      }

    }
  }

  T modulus3() const
  {
  switch (storageType)
    {
      case 0: return std::sqrt(v1*v1+v2*v2+v3*v3);
      case 1: return v3;
      case 2: return std::sqrt(v2*v2+v3*v3);
      case 3: return std::sqrt(v1*v1+v2*v2+v3*v3);
      case 4:
      {
      T mt = std::sqrt(v0*v0+v2*v2);
      T z  = mt * std::sinh(v3);
      return std::sqrt(v2*v2+z*z);
      }
      case 5:
      {
      T z = v2 * std::sinh(v3);
      return std::sqrt(v2*v2+z*z);
      }
      default: throw MathException("Internal error","VectorLorentz<T>::modulus()");
    }
  }

  T  modulus3Square() const
  {
  switch (storageType)
    {
      case 0: return v1*v1+v2*v2+v3*v3;
      case 1: return v3*v3;
      case 2: return v2*v2+v3*v3;
      case 3: return v1*v1+v2*v2+v3*v3;
      case 4:
      {
      T mt = std::sqrt(v0*v0+v2*v2);
      T z  = mt * std::sinh(v3);
      return v2*v2+z*z;
      }
      case 5:
      {
      T z = v2 * std::sinh(v3);
      return v2*v2+z*z;
      }
      default: throw MathException("Internal error","VectorLorentz<T>::modulusSquare()");
    }
  }

  T modulus() const
  {
  switch (storageType)
    {
      case 0:
      {
      T s = v0*v0 - (v1*v1+v2*v2+v3*v3);
      if (s<0) throw MathException("v0*v0 - (v1*v1+v2*v2+v3*v3) case 0","modulus()");
      return std::sqrt(s);
      }

      case 1:
      {
      T s = v0*v0 - v3*v3;
      if (s<0) throw MathException("v0*v0 - v3*v3 case 1","modulus()");
      return std::sqrt(s);
      }

      case 2:
      {
      T s = v0*v0 - (v2*v2+v3*v3);
      if (s<0) throw MathException("v0*v0 - v3*v3 case 1","modulus()");
      return std::sqrt(s);
      }

      case 3: return v0;
      case 4: return v0;
      case 5:
      {
      T z = v2 * std::sinh(v3);
      T s = v0*v0 - (v2*v2+z*z);
      if (s<0) throw MathException("v0*v0 - (v1*v1+v2*v2+v3*v3) case 0","modulus()");
      return std::sqrt(s);
      }

      default: throw MathException("Internal error","VectorLorentz<T>::modulus()");
    }
  }

  T  modulusSquare() const
  {
  switch (storageType)
    {
      case 0:
      return v0*v0 - (v1*v1+v2*v2+v3*v3);

      case 1:
      return v0*v0 - v3*v3;

      case 2:
      return v0*v0 - (v2*v2+v3*v3);

      case 3: return v0*v0;
      case 4: return v0*v0;
      case 5:
      {
      T z = v2 * std::sinh(v3);
      return v0*v0 - (v2*v2+z*z);
      }

      default:
      {
      throw MathException("Internal error","VectorLorentz<T>::modulus()");
      }

    }
  }

  T  perp() const
  {
  switch (storageType)
    {
      case 0: return std::sqrt(v1*v1+v2*v2);
      case 1: return v3*std::sin(v2);
      case 2: return v2;
      case 3: return std::sqrt(v2*v2+v3*v3);
      case 4: return v2;
      case 5: return v2;
      default: throw MathException("Internal error","VectorLorentz<T>::perp()");
    }
  }

  T perpSquare() const
  {
  switch (storageType)
    {
      default:
      throw MathException("Internal error","VectorLorentz<T>::perpSquare()");
      break;

      case 0: return v1*v1+v2*v2;
      case 1:
      {
      T rho = v3*std::sin(v2);
      return rho*rho;
      }
      case 2: return v2*v2;
      case 3: return v1*v1+v2*v2;
      case 4: return v2*v2;
      case 5: return v2*v2;
    }
  }

  Vector3<T> xyz() const
  {
  return  Vector3<T>( x(), y(), z(),0);
  }

  T massSquare() const
  {
  return modulusSquare();
  }


  T mass() const
  {
  T mSq = modulusSquare();
  if (mSq<0) throw MathException("modulusSquare()<0","mass()");
  return std::sqrt(mSq);
  }

  T betaX() const
  {
  T tt = t();
  if (tt<=0) throw MathException("t<=0","betaX()");
  return x()/tt;
  }

  T betaY() const
  {
  T tt = t();
  if (tt<=0) throw MathException("t<=0","betaY()");
  return y()/tt;
  }

  T betaZ() const
  {
  T tt = t();
  if (tt<=0) throw MathException("t<=0","betaZ()");
  return z()/tt;
  }

  T beta() const
  {
  T tt = t();
  if (tt<=0) throw MathException("t<=0","beta()");
  return std::sqrt(x()*x()+y()*y()+z()*z())/tt;
  }

  T betaSquare() const
  {
  T tt = t();
  if (tt<=0) throw MathException("t<=0","beta()");
  return (x()*x()+y()*y()+z()*z())/(tt*tt);
  }


  Vector3<T> betaVector() const
  {
  T tt = t();
  if (tt<=0) throw MathException("t<=0","betaVector()");
  return Vector3<T>(x()/tt,y()/tt,z()/tt,0);
  }

  T gammaSquare() const
  {
  T bSq = betaSquare();
  if (bSq>=1) throw MathException("betaSq()>=1","gamma()");
  return 1.0/(1-bSq);
  }


  T gamma() const
  {
  T bSq = betaSquare();
  if (bSq>=1) throw MathException("betaSq()>=1","gamma()");
  return 1.0/std::sqrt(1-bSq);
  }

  T pseudorapidity() const
  {
  T ct = cosTheta();
  if (ct*ct < 1) return -0.5* std::log( (1.0-ct)/(1.0+ct) );
  T zz = z();
  return (zz == 0) ? 0 : ((zz>0) ? 1E10 : -1E10);
  }

  //!
  //!Transverse mass square
  //!
  T transverseMassSquare() const
  {
  T mSq = modulusSquare();
  switch (storageType)
    {
      default:
      throw MathException("Internal error","VectorLorentz<T>::perpSquare()");
      break;

      case 0:  return mSq + v1*v1+v2*v2;
      case 1:
      {
      T rho = v3*std::sin(v2);
      return mSq + rho*rho;
      }
      case 2: return mSq + v2*v2;
      case 3: return mSq + v1*v1+v2*v2;
      case 4: return mSq + v2*v2;
      case 5: return mSq + v2*v2;
    }
  }

  //!
  //!Transverse mass
  //!
  T transverseMass() const
  {
  return std::sqrt(transverseMassSquare());
  }

  template <typename Q>
  VectorLorentz & operator= (const VectorLorentz<Q> & otherVector)
  {
  if (this!=&otherVector)
    {
    v0 = otherVector.v0;
    v1 = otherVector.v1;
    v2 = otherVector.v2;
    v3 = otherVector.v3;
    storageType = otherVector.storageType;
    }
  return *this;
  }

  template <typename Q>
  bool  operator== (const VectorLorentz<Q> & otherVector) const
  {
  return (t()==otherVector.t())  &&
    (x()==otherVector.x()) &&
    (y()==otherVector.y()) &&
    (z()==otherVector.z());
  }

  template <typename Q>
  bool  operator!= (const VectorLorentz<Q> & otherVector) const
  {
  return (t()!=otherVector.t()) ||
    (x()!=otherVector.x()) ||
    (y()!=otherVector.y()) ||
    (z()!=otherVector.z());
  }

  template <typename Q>
  VectorLorentz & operator+= (const VectorLorentz<Q> & otherVector)
  {
  T tt = t() + otherVector.t();
  T xx = x() + otherVector.x();
  T yy = y() + otherVector.y();
  T zz = z() + otherVector.z();
  setFromTXYZ(tt,xx,yy,zz);
  return *this;
  }

  template <typename Q>
  VectorLorentz & operator-= (const VectorLorentz<Q> & otherVector)
  {
  T tt = t() - otherVector.t();
  T xx = x() - otherVector.x();
  T yy = y() - otherVector.y();
  T zz = z() - otherVector.z();
  setFromTXYZ(tt,xx,yy,zz);
  return *this;
  }

  //! Unary minus.
  VectorLorentz operator- () const
  {
  VectorLorentz v(0,0,0,storageType);
  switch (storageType)
    {
      default: throw MathException("Internal error","VectorLorentz<T>::operator- ()");

      case 0:
      case 3:
      v.v0 =  v0;
      v.v1 = -v1;
      v.v2 = -v2;
      v.v3 = -v3;
      break;

      case 1:
      {
      v.v0  =  v0;
      T phi = pi()+v1;
      v.v1  = phi>twoPi() ?  phi -= twoPi() : phi;
      v.v2  = pi()-v2;
      v.v3  = v3;
      break;
      }

      case 2:
      {
      v.v0  =  v0;
      T phi = pi()+v1;
      v.v1 = phi>twoPi() ?  phi += twoPi() : phi;
      v.v2 = v2;
      v.v3 = -v3;
      break;
      }

      case 4:
      {
      v.v0  =  v0;
      T phi = pi()+v1;
      v.v1 = phi>twoPi() ?  phi += twoPi() : phi;
      v.v2 = v2;
      v.v3 = -v3;
      break;
      }

      case 4:
      {
      v.v0  =  v0;
      T phi = pi()+v1;
      v.v1 = phi>twoPi() ?  phi += twoPi() : phi;
      v.v2 = v2;
      v.v3 = -v3;
      break;
      }
    }
  return v;
  }


  // 3D Scalar product.
  template <typename Q>
  T  scalarProduct3D(const VectorLorentz<Q> & otherVector) const
  {
  return (x()*otherVector.x() + y()*otherVector.y() + z()*otherVector.z());
  }

  // 4D Scalar product.
  template <typename Q>
  T  scalarProduct(const VectorLorentz<Q> & otherVector) const
  {
  return t()*otherVector.t() - (x()*otherVector.x() + y()*otherVector.y() + z()*otherVector.z());
  }


  //! Normalize this vector to be a unitvector
  VectorLorentz & normalize()
  {
  switch (storageType)
    {
      case 0:
      {
      T r = std::sqrt(v1*v1+v2*v2+v3*v3);
      if (r==0) throw MathException("Cannot produced unit vector from null vector","VectorLorentz<T>::unit()");
      v1 /= r;
      v2 /= r;
      v3 /= r;
      break;
      }
      case 1:
      if (v3==0) throw MathException("Cannot produced unit vector from null vector","VectorLorentz<T>::unit()");
      v3 = 1;
      break;

      case 2:
      {
      T r = std::sqrt(v2*v2+v3*v3);
      if (r==0) throw MathException("Cannot produced unit vector from null vector","VectorLorentz<T>::unit()");
      v2 /= r;
      v3 /= r;
      break;
      }
      default:
      throw MathException("Internal error","VectorLorentz<T>::normalize()");
    }
  return *this;
  }

  //! unit VectorLorentz parallel to this vecotr.
//  VectorLorentz unit() const
//  {
//  switch (storageType)
//    {
//      default:
//      throw MathException("Internal error","VectorLorentz<T>::unit()");
//
//      case 0:
//      {
//      T r = std::sqrt(v1*v1+v2*v2+v3*v3);
//      if (r==0) throw MathException("Cannot produced unit vector from null vector","VectorLorentz<T>::unit()");
//      VectorLorentz<T> vxyz(v1/r,v2/r,v3/r,storageType);
//      return vxyz;
//      break;
//      }
//
//      case 1:
//      {
//      if (v3==0) throw MathException("Cannot produced unit vector from null vector","VectorLorentz<T>::unit()");
//      VectorLorentz<T> vr(v1,v2,1.0,storageType);
//      return vr;
//      break;
//      }
//
//      case 2:
//      {
//      T r = std::sqrt(v2*v2+v3*v3);
//      if (r==0) throw MathException("Cannot produced unit vector from null vector","VectorLorentz<T>::unit()");
//      VectorLorentz<T> vrho(v1,v2/r,v3/r,storageType);
//      return vrho;
//      }
//    }
//  }

  //! Active rotation of this VectorLorentz by the given angle relative to the x-axis
  void rotateX(const T & angle)
  {
  T s    = std::sin(angle);
  T c    = std::cos(angle);
  T yy  = y();
  T zz  = z();
  setFromTXYZ(t(),x(), c*yy - s*zz, s*yy + c*zz);
  }

  //! Active rotation of this VectorLorentz by the given angle relative to the y-axis
  void rotateY(const T & angle)
  {
  T s    = std::sin(angle);
  T c    = std::cos(angle);
  T xx   = x();
  T zz   = z();
  setFromTXYZ(t(), s*zz+c*xx, y(), c*zz-s*xx);
  }

  //! Active rotation of this VectorLorentz by the given angle relative to the z-axis
  void rotateZ(const T & angle)
  {
  T s    = std::sin(angle);
  T c    = std::cos(angle);
  T xx   = x();
  T yy   = y();
  setFromTXYZ(t(), c*xx - s*yy, s*xx + c*yy, z());
  }

  void boostX(const T & beta)
  {
  T tt  = t();
  T xx  = x();
  T gamma = 1.0/std::sqrt(1 - beta*beta);
  setFromTXYZ(gamma*(tt+beta*xx), gamma*(xx+beta*tt), y(), z());
  }

  void boostY(const T & beta)
  {
  T tt  = t();
  T yy  = y();
  T gamma = 1.0/std::sqrt(1 - beta*beta);
  setFromTXYZ(gamma*(tt+beta*yy), x(), gamma*(yy+beta*tt), z());
  }

  void boostZ(const T & beta)
  {
  T tt  = t();
  T zz  = z();
  T gamma = 1.0/std::sqrt(1 - beta*beta);
  setFromTXYZ(gamma*(tt+beta*zz), x(), y(), gamma*(zz+beta*tt));
  }

  //!
  //!Boost this Lorentz vector alnog the given velocity vector
  //!
  void boost(const T & betaX,const T & betaY,const T & betaZ)
  {
  T  betaSq = betaX*betaX + betaY*betaY + betaZ*betaZ;
  T  gamma = 1.0 / std::sqrt(1.0 - betaSq);
  T  bp = betaX*x() + betaY*y() + betaZ*z();
  T  gamma2 = betaSq > 0 ? (gamma - 1.0)/betaSq : 0.0;
  setFromTXYZ(gamma*(t()+bp),  x()+gamma2*bp*betaX+gamma*betaX*t(), y() + gamma2*bp*betaY + gamma*betaY*t(), z() + gamma2*bp*betaZ + gamma*betaZ*t());
  }

  void boost(const Vector3<T> & v)
  {
  T  betaX = v[0];
  T  betaY = v[1];
  T  betaZ = v[2];
  T  betaSq = betaX*betaX + betaY*betaY + betaZ*betaZ;
  T  gamma = 1.0 / std::sqrt(1.0 - betaSq);
  T  bp = betaX*x() + betaY*y() + betaZ*z();
  T  gamma2 = betaSq > 0 ? (gamma - 1.0)/betaSq : 0.0;
  setFromTXYZ(gamma*(t()+bp),  x()+gamma2*bp*betaX+gamma*betaX*t(), y() + gamma2*bp*betaY + gamma*betaY*t(), z() + gamma2*bp*betaZ + gamma*betaZ*t());
  }

  //!
  //!Compute and return the rapidity of this vector
  //!
  T rapidity() const
  {
  T arg = (t()+z()) / (t()-z());
  if (arg<=0) throw MathException("arg<=0","VectorLorentz<T>::rapidity()");
  return 0.5*std::log(arg);
  }

  //!
  //! Return the rapidity difference between this and the other vector
  //!  TXYZ=0, TPhiThetaR,  TPhiRhoZ, MXYZ, MPhiRhoY, MPhiRhoEta};
  template <typename Q>
  T  deltaRapidity(const VectorLorentz<Q> & other) const
  {
  switch (storageType)
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 5:
      {
      switch (other.storageType)
        {
          case 0:
          case 1:
          case 2:
          case 3:
          case 5:
          {
          return rapidity() - other.rapidity();
          }

          case 4:
          {
          return rapidity() - other.v3;
          }

          default:
          throw MathException("Unknown storageType","deltaPhi(const VectorLorentz<Q> & other) const");
        }
      }

      case 4:
      {
      switch (other.storageType)
        {
          case 0:
          case 1:
          case 2:
          case 3:
          case 5:
          {
          return v3 - other.rapidity() ;
          }

          case 4:
          {
          return v3 - other.v3 ;
          }

          default:
          throw MathException("Unknown storageType","deltaPhi(const VectorLorentz<Q> & other) const");
        }
      }

      default: throw MathException("Unknown storageType","VectorLorentz<T>::phi()");
    }
  }

  //!
  //! Return the rapidity difference between this and the other vector
  //!  TXYZ=0, TPhiThetaR,  TPhiRhoZ, MXYZ, MPhiRhoY, MPhiRhoEta};
  template <typename Q>
  T  deltaPseudoRapidity(const VectorLorentz<Q> & other) const
  {
  switch (storageType)
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      {
      switch (other.storageType)
        {
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          {
          return pseudorapidity() - other.pseudorapidity();
          }

          case 5:
          {
          return pseudorapidity() - other.v3;
          }

          default:
          throw MathException("Unknown storageType","deltaPhi(const VectorLorentz<Q> & other) const");
        }
      }

      case 5:
      {
      switch (other.storageType)
        {
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          {
          return v3 - other.rapidity() ;
          }

          case 5:
          {
          return v3 - other.v3 ;
          }

          default:
          throw MathException("Unknown storageType","deltaPhi(const VectorLorentz<Q> & other) const");
        }
      }

      default: throw MathException("Unknown storageType","VectorLorentz<T>::phi()");
    }
  }


  virtual void print() const
  {
  switch (storageType)
    {
      case 0:
      std::cout << "(t:" << v0 << " x:" << v1 << ", y:" << v2 << ", z:" << v3 << ") " << std::endl; break;
      case 1:
      std::cout << "(t:" << v0 << " phi:" << v1 << ", theta:" << v2 << ", r:" << v3 << ") " << std::endl; break;
      case 2:
      std::cout << "(t:" << v0 << " phi:" << v1 << ", rho:" << v2 << ", z:" << v3 << ") " << std::endl; break;
      default: throw MathException("Internal error","VectorLorentz<T>::print()");
    }
  }

  ClassDef(VectorLorentz,1)

 // friend class CAP::Math::LorentzVector;
};


//!
//! Add the two vectors and return a new vector
//!
template <typename T, typename Q>
VectorLorentz<T> operator+ (const VectorLorentz<T> & left, const VectorLorentz<Q> & right)
{
  T tt = left.t() + right.t();
  T xx = left.x() + right.x();
  T yy = left.y() + right.y();
  T zz = left.z() + right.z();
  return VectorLorentz<T>(tt,xx,yy,zz,left.storage());
}

//!
//! Subtract  the two vectors and return a new vector
//!
template <typename T, typename Q>
VectorLorentz<T> operator- (const VectorLorentz<T> & left, const VectorLorentz<Q> & right)
{
  T tt = left.t() + right.t();
  T xx = left.x() - right.x();
  T yy = left.y() - right.y();
  T zz = left.z() - right.z();
  return VectorLorentz<T>(tt,xx,yy,zz,left.storage());
}

//!
//! SR (4D) scalar product of two left and right vectors
//!
template <typename T, typename Q>
T operator * (const VectorLorentz<T> & left, const VectorLorentz<Q> & right)
  {
  return left.t()*right.t() + left.x()*right.x() + left.y()*right.y() + left.z()*right.z();
  }


//!
//! Scaling of the left vector by a scalar value from the right
//!
template <typename T, typename Q>
VectorLorentz<T> operator* (const VectorLorentz<T> & left, Q  a)
  {
  VectorLorentz<T> v(0,0,0,left.storage());
  v.setFromTXYZ(a*left.t(), a*left.x(), a*left.y(), a*left.z());
  return v;
  }

//!
//! Scaling of the right vector by a scalar value from the left
//!
template <typename T, typename Q>
VectorLorentz<T> operator* (const Q & a, const VectorLorentz<T> & right)
  {
  VectorLorentz<T> v(0,0,0,right.storageType);
  v.setFromTXYZ(a*right.t(), a*right.x(), a*right.y(), a*right.z());
  return v;
  }

//!
//! Print out the given vector to the given ostream.
//!
template <typename T>
std::ostream& operator<<(std::ostream& out, const CAP::Math::VectorLorentz<T>& v)
{
  out << "(" << v.x()  << "," << v.y() << "," << v.z() << ")" ;
  return out;
}

typedef  VectorLorentz<float>  VectorLorentzF;
typedef  VectorLorentz<double> VectorLorentzD;
typedef  VectorLorentz<long double> VectorLorentzLD;

} // namespace Math
} // namespace CAP

#endif
