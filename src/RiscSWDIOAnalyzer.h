#ifndef RISCSWDIO_ANALYZER_H
#define RISCSWDIO_ANALYZER_H

#include <Analyzer.h>

#include "RiscSWDIOAnalyzerSettings.h"
#include "RiscSWDIOAnalyzerResults.h"
#include "RiscSWDIOSimulationDataGenerator.h"

#include "RiscSWDIOTypes.h"

class RiscSWDIOAnalyzer : public Analyzer2
{
  public:
    RiscSWDIOAnalyzer();
    virtual ~RiscSWDIOAnalyzer();
    virtual void SetupResults();
    virtual void WorkerThread();

    virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
    virtual U32 GetMinimumSampleRateHz();

    virtual const char* GetAnalyzerName() const;
    virtual bool NeedsRerun();

  protected: // vars
    RiscSWDIOAnalyzerSettings mSettings;
    std::auto_ptr<RiscSWDIOAnalyzerResults> mResults;

    AnalyzerChannelData* mPDT;
    AnalyzerChannelData* mPCK;

    AnalyzerChannelData* mSWDIO;
    AnalyzerChannelData* mSWCLK;

    RiscSWDIOSimulationDataGenerator mSimulationDataGenerator;

    SWDParser mSWDParser;

    bool mSimulationInitilized;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer();
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif // RISCSWDIO_ANALYZER_H