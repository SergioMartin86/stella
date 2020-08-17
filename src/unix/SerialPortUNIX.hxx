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
// Copyright (c) 1995-2020 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef SERIALPORT_UNIX_HXX
#define SERIALPORT_UNIX_HXX

#include "SerialPort.hxx"

/**
  Implement reading and writing from a serial port under UNIX.  For now,
  it seems to be Linux-only, and reading isn't actually supported at all.

  @author  Stephen Anthony
*/
class SerialPortUNIX : public SerialPort
{
  public:
    SerialPortUNIX();
    ~SerialPortUNIX() override;

    /**
      Open the given serial port with the specified attributes.

      @param device  The name of the port
      @return  False on any errors, else true
    */
    bool openPort(const string& device) override;

    /**
      Write a byte to the serial port.

      @param data  The byte to write to the port
      @return  True if a byte was written, else false
    */
    bool writeByte(uInt8 data) override;

    /**
      Test for 'Clear To Send' enabled.

      @return  True if CTS signal enabled, else false
    */
    bool isCTS() override;

  private:
    // File descriptor for serial connection
    int myHandle{0};

  private:
    // Following constructors and assignment operators not supported
    SerialPortUNIX(const SerialPortUNIX&) = delete;
    SerialPortUNIX(SerialPortUNIX&&) = delete;
    SerialPortUNIX& operator=(const SerialPortUNIX&) = delete;
    SerialPortUNIX& operator=(SerialPortUNIX&&) = delete;
};

#endif
