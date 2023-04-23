#ifndef RISCSWDIO_ANALYZER_SETTINGS_H
#define RISCSWDIO_ANALYZER_SETTINGS_H

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>

#include "RiscSWDIOTypes.h"

class RiscSWDIOAnalyzerSettings : public AnalyzerSettings
{
  public:
    RiscSWDIOAnalyzerSettings();
    virtual ~RiscSWDIOAnalyzerSettings();

    virtual bool SetSettingsFromInterfaces();
    virtual void LoadSettings( const char* settings );
    virtual const char* SaveSettings();

    void UpdateInterfacesFromSettings();

    Channel mVDD;
    Channel mPDT;
    Channel mPCK;
    Channel mSWDIO;
    Channel mSWCLK;

  protected:
    AnalyzerSettingInterfaceChannel mVDDInterface;
    AnalyzerSettingInterfaceChannel mPDTInterface;
    AnalyzerSettingInterfaceChannel mPCKInterface;
    AnalyzerSettingInterfaceChannel mSWDIOInterface;
    AnalyzerSettingInterfaceChannel mSWCLKInterface;
};

#endif // RISCSWDIO_ANALYZER_SETTINGS_H