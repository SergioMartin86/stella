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
// Copyright (c) 1995-2021 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//
//   Based on code from ScummVM - Scumm Interpreter
//   Copyright (C) 2002-2004 The ScummVM project
//============================================================================

#ifndef ICON_HXX
#define ICON_HXX

#include "bspf.hxx"

namespace GUI {

struct IconDesc
{
  int width;
  int height;

  explicit IconDesc(int _width, int _height)
    : width{_width}, height{_height} {}
};

class Icon
{
  public:
    explicit Icon(IconDesc desc, uIntArray bitmap)
      : myIconDesc{desc}, myBitmap{bitmap} { }
    Icon(int width, int height, uIntArray bitmap)
      : Icon(IconDesc(width, height), bitmap) { }

    const IconDesc& desc() const { return myIconDesc; }
    int height() const { return myIconDesc.height; }
    int width() const { return myIconDesc.width; }
    const uInt32* bitmap() const { return myBitmap.data(); }

  private:
    IconDesc myIconDesc;
    uIntArray myBitmap;

  private:
    // Following constructors and assignment operators not supported
    Icon() = delete;
    Icon(const Icon&) = delete;
    Icon(Icon&&) = delete;
    Icon& operator=(const Icon&) = delete;
    Icon& operator=(Icon&&) = delete;
};

}  // namespace GUI

#endif
