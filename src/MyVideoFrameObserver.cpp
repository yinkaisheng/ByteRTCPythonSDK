#include "MyVideoFrameObserver.h"
#include <memory>

MyVideoFrameObserver::MyVideoFrameObserver()
{
	memset(&m_frameInfo[0], 0, sizeof(m_frameInfo));
}

MyVideoFrameObserver::~MyVideoFrameObserver()
{

}

void MyVideoFrameObserver::saveFrame(SaveFrameType frameType, bool save, unsigned int fileCount, unsigned int frameCount)
{
	SaveFrameInfo& info = m_frameInfo[frameType];
	info.save = save;
	info.fileCount = fileCount;
	info.fileFrameCount = frameCount;
	info.currentFileNo = 0;
	info.curFrameCount = 0;
}

void MyVideoFrameObserver::saveVideoFrame(const char* fileName, const char* mode, bytertc::IVideoFrame* videoFrame)
{
	FILE* pFile = fopen(fileName, mode);
	std::unique_ptr<FILE, decltype(&fclose)> file{ pFile, fclose };
	auto fmt = videoFrame->pixelFormat();
	if (!(fmt == bytertc::kVideoPixelFormatI420
		|| fmt == bytertc::kVideoPixelFormatNV12
		|| fmt == bytertc::kVideoPixelFormatNV21
		|| fmt == bytertc::kVideoPixelFormatARGB
		|| fmt == bytertc::kVideoPixelFormatRGBA
		|| fmt == bytertc::kVideoPixelFormatBGRA))
	{
		return;
	}

	if (pFile)
	{
		int width = videoFrame->width();
		int height = videoFrame->height();
		uint8_t* pY = videoFrame->getPlaneData(0);
		uint8_t* pU = videoFrame->getPlaneData(1);
		uint8_t* pV = videoFrame->getPlaneData(2);
		int ystride = videoFrame->getPlaneStride(0);
		int ustride = videoFrame->getPlaneStride(1);
		int vstride = videoFrame->getPlaneStride(2);

		if (ystride == width || ystride == width*4)
		{
			if (fmt == bytertc::kVideoPixelFormatI420)
			{
				fwrite(pY, ystride * height, 1, pFile);
				fwrite(pU, ystride * height / 4, 1, pFile);
				fwrite(pV, ystride * height / 4, 1, pFile);
			}
			else if (fmt == bytertc::kVideoPixelFormatNV12 || fmt == bytertc::kVideoPixelFormatNV21)
			{
				fwrite(pY, ystride * height, 1, pFile);
				fwrite(pU, ystride * height / 2, 1, pFile);
			}
			else // rgb32
			{
				fwrite(pY, ystride * height, 1, pFile);
			}
		}
		else
		{
			unsigned int frameSize = width * height * 3 / 2;
			std::unique_ptr<uint8_t> yuv{ new uint8_t[frameSize] };
			uint8_t* pDstY = yuv.get();
			uint8_t* pDstU = pDstY + width*height;
			uint8_t* pDstV = pDstU + width*height/4;
			int halfW = width / 2;
			if (fmt == bytertc::kVideoPixelFormatI420)
			{
				for (int h = 0; h < height; ++h)
				{
					memcpy(pDstY + width * h, pY + ystride * h, width);
					if (h % 2 == 0)
					{
						memcpy(pDstU + halfW * (h >> 1), pU + ustride * (h >> 1), halfW);
						memcpy(pDstV + halfW * (h >> 1), pV + vstride * (h >> 1), halfW);
					}
				}
			}
			else if (fmt == bytertc::kVideoPixelFormatNV12 || fmt == bytertc::kVideoPixelFormatNV21)
			{
				for (int h = 0; h < height; ++h)
				{
					memcpy(pDstY + width * h, pY + ystride * h, width);
					if (h % 2 == 0)
					{
						memcpy(pDstU + width * (h >> 1), pU + ustride * (h >> 1), width);
					}
				}
			}
			else // rgb32
			{
				for (int h = 0; h < height; ++h)
				{
					memcpy(pDstY + width * h * 4, pY + ystride * h, width*4);
				}
			}
			fwrite(pDstY, frameSize, 1, pFile);
		}
	}
}

void MyVideoFrameObserver::saveVideoFrame(const char* funcName, const char* uid, SaveFrameInfo& info, bytertc::IVideoFrame* videoFrame)
{
	if (!info.save)
	{
		return;
	}

	const char* name = strstr(funcName, "::");
	if (name)
	{
		funcName = name + 2;
	}

	int width = videoFrame->width();
	int height = videoFrame->height();
	bytertc::VideoPixelFormat format = videoFrame->pixelFormat();
	std::string ext = "raw";
	if (format == bytertc::kVideoPixelFormatARGB)
	{
		ext = "argb";
	}
	if (format == bytertc::kVideoPixelFormatRGBA)
	{
		ext = "rgba";
	}
	else if (format == bytertc::kVideoPixelFormatBGRA)
	{
		ext = "bgra";
	}
	else if (format == bytertc::kVideoPixelFormatI420)
	{
		ext = "i420";
	}
	else if (format == bytertc::kVideoPixelFormatNV12)
	{
		ext = "nv12";
	}
	else if (format == bytertc::kVideoPixelFormatNV21)
	{
		ext = "nv21";
	}

	char szName[128]{};
	if (uid)
	{
		std::snprintf(szName, sizeof(szName), "%s_uid_%s_%u_%dx%d.%s", funcName, uid, info.currentFileNo, width, height, ext.c_str());
	}
	else
	{
		std::snprintf(szName, sizeof(szName), "%s_%u_%dx%d.%s", funcName, info.currentFileNo, width, height, ext.c_str());
	}

	saveVideoFrame(szName, info.curFrameCount == 0 ? "wb" : "ab+", videoFrame);
	++info.curFrameCount;
	if (info.curFrameCount >= info.fileFrameCount)
	{
		info.currentFileNo = (info.currentFileNo + 1) % info.fileCount;
		info.curFrameCount = 0;
	}
}

bool MyVideoFrameObserver::onLocalScreenFrame(bytertc::IVideoFrame* videoFrame)
{
	SaveFrameType type = kSaveLocalScreenFrame;
	SaveFrameInfo& info = m_frameInfo[type];
	saveVideoFrame(__FUNCTION__, nullptr, info, videoFrame);
	return true;
}

bool MyVideoFrameObserver::onLocalVideoFrame(bytertc::IVideoFrame* videoFrame)
{
	SaveFrameType type = kSaveLocalVideoFrame;
	SaveFrameInfo& info = m_frameInfo[type];
	saveVideoFrame(__FUNCTION__, nullptr, info, videoFrame);
	return true;
}

bool MyVideoFrameObserver::onRemoteScreenFrame(const char* roomid, const char* uid, bytertc::IVideoFrame* videoFrame)
{
	SaveFrameType type = kSaveRemoteScreenFrame;
	SaveFrameInfo& info = m_frameInfo[type];
	saveVideoFrame(__FUNCTION__, uid, info, videoFrame);
	return true;
}

bool MyVideoFrameObserver::onRemoteVideoFrame(const char* roomid, const char* uid, bytertc::IVideoFrame* videoFrame)
{
	SaveFrameType type = kSaveRemoteVideoFrame;
	SaveFrameInfo& info = m_frameInfo[type];
	saveVideoFrame(__FUNCTION__, uid, info, videoFrame);
	return true;
}

bool MyVideoFrameObserver::onMergeFrame(const char* roomid, const char* uid, bytertc::IVideoFrame* videoFrame)
{
	SaveFrameType type = kSaveMergeFrame;
	SaveFrameInfo& info = m_frameInfo[type];
	saveVideoFrame(__FUNCTION__, uid, info, videoFrame);
	return true;
}
