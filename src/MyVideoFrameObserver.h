#pragma once
#include "bytertc_video.h"
#include <map>
#include <mutex>

enum SaveFrameType
{
    kSaveLocalVideoFrame,
    kSaveLocalScreenFrame,
    kSaveRemoteVideoFrame,
    kSaveRemoteScreenFrame,
    kSaveMergeFrame,
    kSaveFrameTypeCount,
};

struct SaveFrameInfo
{
    unsigned int fileCount;
    unsigned int currentFileNo;
    unsigned int fileFrameCount;
    unsigned int curFrameCount;
    bool save;
};

class MyVideoFrameObserver : public bytertc::IVideoFrameObserver {
public:
    MyVideoFrameObserver();
    virtual ~MyVideoFrameObserver();

    void saveFrame(SaveFrameType frameType, bool save, unsigned int fileCount, unsigned int frameCount);

    void saveVideoFrame(const char* fileName, const char* mode, bytertc::IVideoFrame* videoFrame);

    void saveVideoFrame(const char* funcName, SaveFrameInfo& info, bytertc::IVideoFrame* videoFrame);

    bool onLocalScreenFrame(bytertc::IVideoFrame* videoFrame) override;

    bool onLocalVideoFrame(bytertc::IVideoFrame* videoFrame) override;

    bool onRemoteScreenFrame(const char* roomid, const char* uid, bytertc::IVideoFrame* videoFrame) override;

    bool onRemoteVideoFrame(const char* roomid, const char* uid, bytertc::IVideoFrame* videoFrame) override;

    bool onMergeFrame(const char* roomid, const char* uid, bytertc::IVideoFrame* videoFrame) override;
private:
    SaveFrameInfo m_frameInfo[kSaveFrameTypeCount];
};
