//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2017 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef VARIANT_HXX
#define VARIANT_HXX

#include "Rect.hxx"
#include "bspf.hxx"

/**
  This class implements a very simple variant type, which is convertible
  to several other types.  It stores the actual data as a string, and
  converts to other types as required.  Eventually, this class may be
  extended to use templates and become a more full-featured variant type.

  @author  Stephen Anthony
*/
class Variant
{
  private:
    // Underlying data store is (currently) always a string
    string data;

    // Use singleton so we use only one ostringstream object
    inline ostringstream& buf() {
      static ostringstream buf;
      return buf;
    }

  public:
    Variant() { }

    Variant(const string& s) : data(s) { }
    Variant(const char* s) : data(s) { }

    Variant(Int32 i)  { buf().str(""); buf() << i; data = buf().str(); }
    Variant(uInt32 i) { buf().str(""); buf() << i; data = buf().str(); }
    Variant(float f)  { buf().str(""); buf() << f; data = buf().str(); }
    Variant(double d) { buf().str(""); buf() << d; data = buf().str(); }
    Variant(bool b)   { buf().str(""); buf() << b; data = buf().str(); }
    Variant(const GUI::Size& s) { buf().str(""); buf() << s; data = buf().str(); }

    // Conversion methods
    const string& toString() const { return data;                          }
    const char* const toCString() const { return data.c_str();             }
    const Int32 toInt() const      { return atoi(data.c_str());            }
    const float toFloat() const    { return float(atof(data.c_str()));     }
    const bool toBool() const      { return data == "1" || data == "true"; }
    const GUI::Size toSize() const { return GUI::Size(data);               }

    // Comparison
    bool operator==(const Variant& v) const { return data == v.data; }
    bool operator!=(const Variant& v) const { return data != v.data; }

    friend ostream& operator<<(ostream& os, const Variant& v) {
      return os << v.data;
    }
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static const Variant EmptyVariant;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
using VariantList = vector<std::pair<string,Variant>>;

namespace VarList {
  inline void push_back(VariantList& list, const Variant& name,
                        const Variant& tag = EmptyVariant)
  {
    list.emplace_back(name.toString(), tag);
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static const VariantList EmptyVarList;

#endif
