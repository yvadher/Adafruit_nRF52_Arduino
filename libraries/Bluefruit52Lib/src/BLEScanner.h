/**************************************************************************/
/*!
    @file     BLEScanner.h
    @author   hathach

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2017, Adafruit Industries (adafruit.com)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#ifndef BLESCANNER_H_
#define BLESCANNER_H_

#include <Arduino.h>
#include "bluefruit_common.h"

class BLEScanner
{
public:
  typedef void (*rx_callback_t) (ble_gap_evt_adv_report_t*);

  BLEScanner(void);

  void setRxCallback(rx_callback_t fp);

  ble_gap_scan_params_t* getParams(void);

  bool isRunning(void);

  void restartOnDisconnect(bool enable);
  bool start(uint16_t timeout = 0);
  bool stop(void);

  /*------------------------------------------------------------------*/
  /* INTERNAL USAGE ONLY
   * Although declare as public, it is meant to be invoked by internal
   * code. User should not call these directly
   *------------------------------------------------------------------*/
  void _eventHandler(ble_evt_t* evt);

private:
  bool          _runnning;
  bool          _start_if_disconnect;
  rx_callback_t _rx_cb;

  ble_gap_scan_params_t _scan_param;
};



#endif /* BLESCANNER_H_ */
