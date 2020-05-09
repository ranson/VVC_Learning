/* The copyright in this software is being made available under the BSD
* License, included below. This software may be subject to other third party
* and contributor rights, including patent rights, and no such rights are
* granted under this license.
*
* Copyright (c) 2010-2020, ITU/ISO/IEC
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  * Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef __HRD__
#define __HRD__

#include "Common.h"
#include "SEI.h"
#if !JVET_P0118_HRD_ASPECTS
class TimingInfo
{
protected:
  bool     m_timingInfoPresentFlag;
  uint32_t m_numUnitsInTick;
  uint32_t m_timeScale;
  int      m_numTicksPocDiffOneMinus1;

public:
  TimingInfo()
    : m_timingInfoPresentFlag      (false)
    , m_numUnitsInTick             (1001)
    , m_timeScale                  (60000)
    , m_numTicksPocDiffOneMinus1   (0)
  {}

  void     setTimingInfoPresentFlag( bool flag )   { m_timingInfoPresentFlag = flag;       }
  bool     getTimingInfoPresentFlag( ) const       { return m_timingInfoPresentFlag;       }

  void     setNumUnitsInTick( uint32_t value )     { m_numUnitsInTick = value;             }
  uint32_t getNumUnitsInTick( ) const              { return m_numUnitsInTick;              }
  void     setTimeScale( uint32_t value )          { m_timeScale = value;                  }
  uint32_t getTimeScale( ) const                   { return m_timeScale;                   }

  void     setNumTicksPocDiffOneMinus1(int x)      { m_numTicksPocDiffOneMinus1 = x;       }
  int      getNumTicksPocDiffOneMinus1( ) const    { return m_numTicksPocDiffOneMinus1;    }
};

struct HrdSubLayerInfo
{
  bool     fixedPicRateFlag;
  bool     fixedPicRateWithinCvsFlag;
  uint32_t picDurationInTcMinus1;
  bool     lowDelayHrdFlag;
  uint32_t cpbCntMinus1;
  uint32_t bitRateValueMinus1[MAX_CPB_CNT][2];
  uint32_t cpbSizeValue      [MAX_CPB_CNT][2];
  uint32_t ducpbSizeValue    [MAX_CPB_CNT][2];
  bool     cbrFlag           [MAX_CPB_CNT][2];
  uint32_t duBitRateValue    [MAX_CPB_CNT][2];
};
#endif
#if JVET_P0118_HRD_ASPECTS
class OlsHrdParams
{
private:
  bool     m_fixedPicRateGeneralFlag;
  bool     m_fixedPicRateWithinCvsFlag;
  uint32_t m_elementDurationInTcMinus1;
  bool     m_lowDelayHrdFlag;

  uint32_t m_bitRateValueMinus1[MAX_CPB_CNT][2];
  uint32_t m_cpbSizeValueMinus1[MAX_CPB_CNT][2];
  uint32_t m_ducpbSizeValueMinus1[MAX_CPB_CNT][2];
  uint32_t m_duBitRateValueMinus1[MAX_CPB_CNT][2];
  bool     m_cbrFlag[MAX_CPB_CNT][2];
public:
  OlsHrdParams();
  virtual ~OlsHrdParams();

  void      setFixedPicRateGeneralFlag(bool flag) { m_fixedPicRateGeneralFlag = flag; }
  bool      getFixedPicRateGeneralFlag() const { return m_fixedPicRateGeneralFlag; }
  void      setFixedPicRateWithinCvsFlag(bool flag) { m_fixedPicRateWithinCvsFlag = flag; }
  bool      getFixedPicRateWithinCvsFlag() const { return m_fixedPicRateWithinCvsFlag; }
  void      setElementDurationInTcMinus1(uint32_t value) { m_elementDurationInTcMinus1 = value; }
  uint32_t  getElementDurationInTcMinus1() const { return m_elementDurationInTcMinus1; }
  void      setLowDelayHrdFlag(bool flag) { m_lowDelayHrdFlag = flag; }
  bool      getLowDelayHrdFlag() const { return m_lowDelayHrdFlag; }
  void      setBitRateValueMinus1(int cpbcnt, int nalOrVcl, uint32_t value) { m_bitRateValueMinus1[cpbcnt][nalOrVcl] = value; }
  uint32_t  getBitRateValueMinus1(int cpbcnt, int nalOrVcl) const { return m_bitRateValueMinus1[cpbcnt][nalOrVcl]; }

  void      setCpbSizeValueMinus1(int cpbcnt, int nalOrVcl, uint32_t value) { m_cpbSizeValueMinus1[cpbcnt][nalOrVcl] = value; }
  uint32_t  getCpbSizeValueMinus1(int cpbcnt, int nalOrVcl) const { return m_cpbSizeValueMinus1[cpbcnt][nalOrVcl]; }
  void      setDuCpbSizeValueMinus1(int cpbcnt, int nalOrVcl, uint32_t value) { m_ducpbSizeValueMinus1[cpbcnt][nalOrVcl] = value; }
  uint32_t  getDuCpbSizeValueMinus1(int cpbcnt, int nalOrVcl) const { return m_ducpbSizeValueMinus1[cpbcnt][nalOrVcl]; }
  void      setDuBitRateValueMinus1(int cpbcnt, int nalOrVcl, uint32_t value) { m_duBitRateValueMinus1[cpbcnt][nalOrVcl] = value; }
  uint32_t  getDuBitRateValueMinus1(int cpbcnt, int nalOrVcl) const { return m_duBitRateValueMinus1[cpbcnt][nalOrVcl]; }
  void      setCbrFlag(int cpbcnt, int nalOrVcl, bool value) { m_cbrFlag[cpbcnt][nalOrVcl] = value; }
  bool      getCbrFlag(int cpbcnt, int nalOrVcl) const { return m_cbrFlag[cpbcnt][nalOrVcl]; }
};
#endif

#if JVET_P0118_HRD_ASPECTS
class GeneralHrdParams
#else
class HRDParameters
#endif
{
private:
#if JVET_P0118_HRD_ASPECTS
  uint32_t m_numUnitsInTick;
  uint32_t m_timeScale;
  bool     m_generalNalHrdParamsPresentFlag;
  bool     m_generalVclHrdParamsPresentFlag;
  bool     m_generalSamPicTimingInAllOlsFlag;
#else
  bool     m_nalHrdParametersPresentFlag;
  bool     m_vclHrdParametersPresentFlag;
#endif
  uint32_t m_tickDivisorMinus2;
  bool     m_generalDecodingUnitHrdParamsPresentFlag;
  uint32_t m_bitRateScale;
  uint32_t m_cpbSizeScale;
  uint32_t m_cpbSizeDuScale;
#if JVET_P0118_HRD_ASPECTS
  uint32_t m_hrdCpbCntMinus1;
#endif
#if !JVET_P0118_HRD_ASPECTS
  HrdSubLayerInfo m_HRD[MAX_TLAYER];
#endif

public:
#if JVET_P0118_HRD_ASPECTS
  GeneralHrdParams()
#else
  HRDParameters()
#endif
#if JVET_P0118_HRD_ASPECTS
    :m_generalNalHrdParamsPresentFlag(false)
    ,m_generalVclHrdParamsPresentFlag(false)
    ,m_generalSamPicTimingInAllOlsFlag(true)
#else
    :m_nalHrdParametersPresentFlag       (false)
    ,m_vclHrdParametersPresentFlag       (false)
#endif
    ,m_tickDivisorMinus2                 (0)
    ,m_generalDecodingUnitHrdParamsPresentFlag  (false)
    ,m_bitRateScale                      (0)
    ,m_cpbSizeScale                      (0)
    ,m_cpbSizeDuScale                    (0)
#if JVET_P0118_HRD_ASPECTS
    ,m_hrdCpbCntMinus1(0)
#endif
  {}
#if JVET_P0118_HRD_ASPECTS
  bool operator==(const GeneralHrdParams& other) const
  {
    return (m_numUnitsInTick == other.m_numUnitsInTick
      && m_timeScale == other.m_timeScale
      && m_generalNalHrdParamsPresentFlag == other.m_generalNalHrdParamsPresentFlag
      && m_generalVclHrdParamsPresentFlag == other.m_generalVclHrdParamsPresentFlag
      && m_generalSamPicTimingInAllOlsFlag == other.m_generalSamPicTimingInAllOlsFlag
      && m_generalDecodingUnitHrdParamsPresentFlag == other.m_generalDecodingUnitHrdParamsPresentFlag
      && (m_generalDecodingUnitHrdParamsPresentFlag ? (m_tickDivisorMinus2 == other.m_tickDivisorMinus2): 1)
      && m_bitRateScale == other.m_bitRateScale
      && m_cpbSizeScale == other.m_cpbSizeScale
      && (m_generalDecodingUnitHrdParamsPresentFlag ? (m_cpbSizeDuScale == other.m_cpbSizeDuScale) : 1)
      && m_hrdCpbCntMinus1 == other.m_hrdCpbCntMinus1
      );
  }

  GeneralHrdParams& operator=(const GeneralHrdParams& input)
  {
    m_numUnitsInTick = input.m_numUnitsInTick;
    m_timeScale = input.m_timeScale;
    m_generalNalHrdParamsPresentFlag = input.m_generalNalHrdParamsPresentFlag;
    m_generalVclHrdParamsPresentFlag = input.m_generalVclHrdParamsPresentFlag;
    m_generalSamPicTimingInAllOlsFlag = input.m_generalSamPicTimingInAllOlsFlag;
    m_generalDecodingUnitHrdParamsPresentFlag = input.m_generalDecodingUnitHrdParamsPresentFlag;
    if (input.m_generalDecodingUnitHrdParamsPresentFlag)
    {
      m_tickDivisorMinus2 = input.m_tickDivisorMinus2;
    }
    m_bitRateScale = input.m_bitRateScale;
    m_cpbSizeScale = input.m_cpbSizeScale;
    if (input.m_generalDecodingUnitHrdParamsPresentFlag)
    {
      m_cpbSizeDuScale = input.m_cpbSizeDuScale;
    }
    m_hrdCpbCntMinus1 = input.m_hrdCpbCntMinus1;
    return *this;
  }
#endif
#if JVET_P0118_HRD_ASPECTS
  virtual ~GeneralHrdParams() {}
#else
  virtual ~HRDParameters() {}
#endif
#if JVET_P0118_HRD_ASPECTS
  void      setNumUnitsInTick(uint32_t value) { m_numUnitsInTick = value; }
  uint32_t  getNumUnitsInTick() const { return m_numUnitsInTick; }

  void      setTimeScale(uint32_t value) { m_timeScale = value; }
  uint32_t  getTimeScale() const { return m_timeScale; }

  void      setGeneralNalHrdParametersPresentFlag(bool flag) { m_generalNalHrdParamsPresentFlag = flag; }
  bool      getGeneralNalHrdParametersPresentFlag() const { return m_generalNalHrdParamsPresentFlag; }

  void      setGeneralVclHrdParametersPresentFlag(bool flag) { m_generalVclHrdParamsPresentFlag = flag; }
  bool      getGeneralVclHrdParametersPresentFlag() const { return m_generalVclHrdParamsPresentFlag; }

  void      setGeneralSamPicTimingInAllOlsFlag(bool flag) { m_generalSamPicTimingInAllOlsFlag = flag; }
  bool      getGeneralSamPicTimingInAllOlsFlag() const { return m_generalSamPicTimingInAllOlsFlag; }
#else
  void      setNalHrdParametersPresentFlag( bool flag )                                { m_nalHrdParametersPresentFlag = flag;                      }
  bool      getNalHrdParametersPresentFlag( ) const                                    { return m_nalHrdParametersPresentFlag;                      }

  void      setVclHrdParametersPresentFlag( bool flag )                                { m_vclHrdParametersPresentFlag = flag;                      }
  bool      getVclHrdParametersPresentFlag( ) const                                    { return m_vclHrdParametersPresentFlag;                      }
#endif


  void      setTickDivisorMinus2( uint32_t value )                                     { m_tickDivisorMinus2 = value;                               }
  uint32_t  getTickDivisorMinus2( ) const                                              { return m_tickDivisorMinus2;                                }


  void      setGeneralDecodingUnitHrdParamsPresentFlag( bool flag)                     { m_generalDecodingUnitHrdParamsPresentFlag = flag;                 }
  bool      getGeneralDecodingUnitHrdParamsPresentFlag( ) const                        { return m_generalDecodingUnitHrdParamsPresentFlag;                 }

  void      setBitRateScale( uint32_t value )                                          { m_bitRateScale = value;                                    }
  uint32_t  getBitRateScale( ) const                                                   { return m_bitRateScale;                                     }

  void      setCpbSizeScale( uint32_t value )                                          { m_cpbSizeScale = value;                                    }
  uint32_t  getCpbSizeScale( ) const                                                   { return m_cpbSizeScale;                                     }
  void      setCpbSizeDuScale( uint32_t value )                                        { m_cpbSizeDuScale = value;                                  }
  uint32_t  getCpbSizeDuScale( ) const                                                 { return m_cpbSizeDuScale;                                   }

#if JVET_P0118_HRD_ASPECTS
  void      setHrdCpbCntMinus1(uint32_t value) { m_hrdCpbCntMinus1 = value; }
  uint32_t  getHrdCpbCntMinus1() const { return m_hrdCpbCntMinus1; }
#endif

#if !JVET_P0118_HRD_ASPECTS
  void      setFixedPicRateFlag( int layer, bool flag )                                { m_HRD[layer].fixedPicRateFlag = flag;                      }
  bool      getFixedPicRateFlag( int layer ) const                                     { return m_HRD[layer].fixedPicRateFlag;                      }

  void      setFixedPicRateWithinCvsFlag( int layer, bool flag )                       { m_HRD[layer].fixedPicRateWithinCvsFlag = flag;             }
  bool      getFixedPicRateWithinCvsFlag( int layer ) const                            { return m_HRD[layer].fixedPicRateWithinCvsFlag;             }

  void      setPicDurationInTcMinus1( int layer, uint32_t value )                      { m_HRD[layer].picDurationInTcMinus1 = value;                }
  uint32_t  getPicDurationInTcMinus1( int layer ) const                                { return m_HRD[layer].picDurationInTcMinus1;                 }

  void      setLowDelayHrdFlag( int layer, bool flag )                                 { m_HRD[layer].lowDelayHrdFlag = flag;                       }
  bool      getLowDelayHrdFlag( int layer ) const                                      { return m_HRD[layer].lowDelayHrdFlag;                       }

  void      setCpbCntMinus1( int layer, uint32_t value )                               { m_HRD[layer].cpbCntMinus1 = value;                         }
  uint32_t  getCpbCntMinus1( int layer ) const                                         { return m_HRD[layer].cpbCntMinus1;                          }

  void      setBitRateValueMinus1( int layer, int cpbcnt, int nalOrVcl, uint32_t value )   { m_HRD[layer].bitRateValueMinus1[cpbcnt][nalOrVcl] = value; }
  uint32_t  getBitRateValueMinus1( int layer, int cpbcnt, int nalOrVcl ) const             { return m_HRD[layer].bitRateValueMinus1[cpbcnt][nalOrVcl];  }

  void      setCpbSizeValueMinus1( int layer, int cpbcnt, int nalOrVcl, uint32_t value )   { m_HRD[layer].cpbSizeValue[cpbcnt][nalOrVcl] = value;       }
  uint32_t  getCpbSizeValueMinus1( int layer, int cpbcnt, int nalOrVcl ) const             { return m_HRD[layer].cpbSizeValue[cpbcnt][nalOrVcl];        }
  void      setDuCpbSizeValueMinus1( int layer, int cpbcnt, int nalOrVcl, uint32_t value ) { m_HRD[layer].ducpbSizeValue[cpbcnt][nalOrVcl] = value;     }
  uint32_t  getDuCpbSizeValueMinus1( int layer, int cpbcnt, int nalOrVcl ) const           { return m_HRD[layer].ducpbSizeValue[cpbcnt][nalOrVcl];      }
  void      setDuBitRateValueMinus1( int layer, int cpbcnt, int nalOrVcl, uint32_t value ) { m_HRD[layer].duBitRateValue[cpbcnt][nalOrVcl] = value;     }
  uint32_t  getDuBitRateValueMinus1(int layer, int cpbcnt, int nalOrVcl ) const            { return m_HRD[layer].duBitRateValue[cpbcnt][nalOrVcl];      }
  void      setCbrFlag( int layer, int cpbcnt, int nalOrVcl, bool value )                  { m_HRD[layer].cbrFlag[cpbcnt][nalOrVcl] = value;            }
  bool      getCbrFlag( int layer, int cpbcnt, int nalOrVcl ) const                        { return m_HRD[layer].cbrFlag[cpbcnt][nalOrVcl];             }

  bool      getCpbDpbDelaysPresentFlag( ) const                                            { return getNalHrdParametersPresentFlag() || getVclHrdParametersPresentFlag(); }
#endif
};

class HRD
{
public:
  HRD()
  :m_bufferingPeriodInitialized (false)
#if JVET_Q0818_PT_SEI
  , m_pictureTimingAvailable    (false)	
#endif
  {};

  virtual ~HRD()
  {};
#if JVET_P0118_HRD_ASPECTS
  void                 setGeneralHrdParameters(GeneralHrdParams &generalHrdParam) { m_generalHrdParams = generalHrdParam; }
  GeneralHrdParams        getGeneralHrdParameters() const { return m_generalHrdParams; }
  const GeneralHrdParams& getGeneralHrdParameters() { return m_generalHrdParams; }

  void                 setOlsHrdParameters(int tLayter, OlsHrdParams &olsHrdParam) { m_olsHrdParams[tLayter] = olsHrdParam; }
  OlsHrdParams          getOlsHrdParameters() { return m_olsHrdParams[0]; }
  OlsHrdParams*          getOlsHrdParametersAddr() { return &m_olsHrdParams[0]; }
  const OlsHrdParams&    getOlsHrdParameters() const { return m_olsHrdParams[0]; }

#else
  void                 setHRDParameters(HRDParameters &hrdParam)    { m_hrdParams=hrdParam; }
  HRDParameters        getHRDParameters() const                     { return m_hrdParams; }
  const HRDParameters& getHRDParameters()                           { return m_hrdParams; }

  void                 setTimingInfo(TimingInfo &timingInfo)        { m_timingInfo=timingInfo; }
  TimingInfo           getTimingInfo() const                        { return m_timingInfo; }
  const TimingInfo&    getTimingInfo()                              { return m_timingInfo; }
#endif

  void                       setBufferingPeriodSEI(const SEIBufferingPeriod* bp)  { bp->copyTo(m_bufferingPeriodSEI); m_bufferingPeriodInitialized = true; }
  const SEIBufferingPeriod*  getBufferingPeriodSEI() const                        { return m_bufferingPeriodInitialized ? &m_bufferingPeriodSEI : nullptr; }

#if JVET_Q0818_PT_SEI
  void                       setPictureTimingSEI(const SEIPictureTiming* pt)  { pt->copyTo(m_pictureTimingSEI); m_pictureTimingAvailable = true; }
  const SEIPictureTiming*    getPictureTimingSEI() const                      { return m_pictureTimingAvailable ? &m_pictureTimingSEI : nullptr; }
#endif

protected:
#if JVET_P0118_HRD_ASPECTS
  GeneralHrdParams      m_generalHrdParams;
  OlsHrdParams          m_olsHrdParams[MAX_TLAYER];
#else
  HRDParameters m_hrdParams;
  TimingInfo    m_timingInfo;
#endif
  bool               m_bufferingPeriodInitialized;
  SEIBufferingPeriod m_bufferingPeriodSEI;
#if JVET_Q0818_PT_SEI
  bool               m_pictureTimingAvailable;
  SEIPictureTiming   m_pictureTimingSEI;
#endif
};

#endif //__HRD__
