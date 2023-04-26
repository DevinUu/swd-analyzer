#include <AnalyzerHelpers.h>

#include "RiscSWDIOAnalyzerSettings.h"
#include "RiscSWDIOAnalyzerResults.h"
#include "RiscSWDIOTypes.h"

RiscSWDIOAnalyzerSettings::RiscSWDIOAnalyzerSettings() : mVDD( UNDEFINED_CHANNEL ), mPDT( UNDEFINED_CHANNEL ), mPCK( UNDEFINED_CHANNEL ), mSWDIO( UNDEFINED_CHANNEL ), mSWCLK( UNDEFINED_CHANNEL )
{
    // init the interface
    mVDDInterface.SetTitleAndTooltip( "VDD", "VDD" );
    mVDDInterface.SetChannel( mVDD );
    mVDDInterface.SetSelectionOfNoneIsAllowed(true);//可选择none选项关闭

    mPDTInterface.SetTitleAndTooltip( "PDT", "PDT" );
    mPDTInterface.SetChannel( mPDT );

    mPCKInterface.SetTitleAndTooltip( "PCK", "PCK" );
    mPCKInterface.SetChannel( mPCK );

    mSWDIOInterface.SetTitleAndTooltip( "SWDIO", "SWDIO" );
    mSWDIOInterface.SetChannel( mSWDIO );

    mSWCLKInterface.SetTitleAndTooltip( "SWCLK", "SWCLK" );
    mSWCLKInterface.SetChannel( mSWCLK );

    // add the interface
    AddInterface( &mVDDInterface );
    AddInterface( &mPDTInterface );
    AddInterface( &mPCKInterface );
    AddInterface( &mSWDIOInterface );
    AddInterface( &mSWCLKInterface );

    // describe export
    AddExportOption( 0, "Export as text file" );
    AddExportExtension( 0, "text", "txt" );

    ClearChannels();

    AddChannel( mVDD, "VDD", false );
    AddChannel( mPDT, "PDT", false );
    AddChannel( mPCK, "PCK", false );
    AddChannel( mSWDIO, "SWDIO", false );
    AddChannel( mSWCLK, "SWCLK", false );
}

RiscSWDIOAnalyzerSettings::~RiscSWDIOAnalyzerSettings()
{
}

bool RiscSWDIOAnalyzerSettings::SetSettingsFromInterfaces()
{
    if( mPDTInterface.GetChannel() == UNDEFINED_CHANNEL )
    {
        SetErrorText( "Please select an input for the channel PDT." );
        return false;
    }
    if( mPCKInterface.GetChannel() == UNDEFINED_CHANNEL )
    {
        SetErrorText( "Please select an input for the channel PCK." );
        return false;
    }
    if( mSWDIOInterface.GetChannel() == UNDEFINED_CHANNEL )
    {
        SetErrorText( "Please select an input for the channel SWDIO." );
        return false;
    }

    if( mSWCLKInterface.GetChannel() == UNDEFINED_CHANNEL )
    {
        SetErrorText( "Please select an input for the channel SWCLK." );
        return false;
    }

    mVDD = mVDDInterface.GetChannel();
    mPDT = mPDTInterface.GetChannel();
    mPCK = mPCKInterface.GetChannel();
    mSWDIO = mSWDIOInterface.GetChannel();
    mSWCLK = mSWCLKInterface.GetChannel();

    if( 
        ( mVDD == mPDT )
        ||( mVDD == mPCK )
        ||( mVDD == mSWDIO )
        ||( mVDD == mSWCLK )
        ||( mPDT == mPCK )
        ||( mPDT == mSWDIO )
        ||( mPDT == mSWCLK )
        ||( mPCK== mSWDIO )
        ||( mPCK == mSWCLK )
        ||(mSWDIO == mSWCLK ))
    {
        SetErrorText( "Please select different inputs for the channels." );
        return false;
    }

    ClearChannels();

    AddChannel( mVDD, "VDD", true );
    AddChannel( mPDT, "PDT", true );
    AddChannel( mPCK, "PCK", true );
    AddChannel( mSWDIO, "SWDIO", true );
    AddChannel( mSWCLK, "SWCLK", true );

    return true;
}

void RiscSWDIOAnalyzerSettings::UpdateInterfacesFromSettings()
{
    mVDDInterface.SetChannel( mVDD );
    mPDTInterface.SetChannel( mPDT );
    mPCKInterface.SetChannel( mPCK );
    mSWDIOInterface.SetChannel( mSWDIO );
    mSWCLKInterface.SetChannel( mSWCLK );
}

void RiscSWDIOAnalyzerSettings::LoadSettings( const char* settings )
{
    SimpleArchive text_archive;
    text_archive.SetString( settings );

    text_archive >> mVDD;
    text_archive >> mPDT;
    text_archive >> mPCK;
    text_archive >> mSWDIO;
    text_archive >> mSWCLK;

    ClearChannels();
    AddChannel( mVDD, "VDD", true );
    AddChannel( mPDT, "PDT", true );
    AddChannel( mPCK, "PCK", true );
    AddChannel( mSWDIO, "SWDIO", true );
    AddChannel( mSWCLK, "SWCLK", true );

    UpdateInterfacesFromSettings();
}

const char* RiscSWDIOAnalyzerSettings::SaveSettings()
{
    SimpleArchive text_archive;
    text_archive << mVDD;
    text_archive << mPDT;
    text_archive << mPCK;
    text_archive << mSWDIO;
    text_archive << mSWCLK;

    return SetReturnString( text_archive.GetString() );
}
