#ifndef RISCSWDIO_ANALYZER_RESULTS_H
#define RISCSWDIO_ANALYZER_RESULTS_H

#include <AnalyzerResults.h>

class RiscSWDIOAnalyzer;
class RiscSWDIOAnalyzerSettings;

class RiscSWDIOAnalyzerResults : public AnalyzerResults
{
  public:
    RiscSWDIOAnalyzerResults( RiscSWDIOAnalyzer* analyzer, RiscSWDIOAnalyzerSettings* settings );
    virtual ~RiscSWDIOAnalyzerResults();

    virtual void GenerateBubbleText( U64 frame_index, Channel& channel, DisplayBase display_base );
    virtual void GenerateExportFile( const char* file, DisplayBase display_base, U32 export_type_user_id );

    virtual void GenerateFrameTabularText( U64 frame_index, DisplayBase display_base );
    virtual void GeneratePacketTabularText( U64 packet_id, DisplayBase display_base );
    virtual void GenerateTransactionTabularText( U64 transaction_id, DisplayBase display_base );

    double GetSampleTime( S64 sample ) const;
    std::string GetSampleTimeStr( S64 sample ) const;

    RiscSWDIOAnalyzerSettings* GetSettings()
    {
        return mSettings;
    }

  protected: // functions
    void GetBubbleText( const Frame& f, DisplayBase display_base, std::vector<std::string>& results );

  protected: // vars
    RiscSWDIOAnalyzerSettings* mSettings;
    RiscSWDIOAnalyzer* mAnalyzer;
};

#endif // RISCSWDIO_ANALYZER_RESULTS_H