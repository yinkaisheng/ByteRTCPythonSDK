#include "bytertc_video.h"
#include "rtc/bytertc_advance.h"
#include "MyRTCVideoEventHandler.h"
#include "MyRTCRoomEventHandler.h"
#include "json/json.hpp"
#include "spdlog/spdlog.h"

#define LOGPTR spdlog::fmt_lib::ptr

using namespace nlohmann;

BYTERTC_API MyRTCVideoEventHandler* byte_createRTCVideoEventHandler()
{
	return new MyRTCVideoEventHandler();
}

BYTERTC_API void byte_deleteRTCVideoEventHandler(MyRTCVideoEventHandler* handler)
{
	delete handler;
}

BYTERTC_API void byte_RTCVideoEventHandler_setCallback(MyRTCVideoEventHandler* handler, ByteEventCallback callback)
{
	spdlog::info("{} handler {}, callback {}", __FUNCTION__, LOGPTR(handler), LOGPTR(callback));
	handler->setEventCallback(callback);
}

BYTERTC_API MyRTCRoomEventHandler* byte_createRTCRoomEventHandler()
{
	return new MyRTCRoomEventHandler();
}

BYTERTC_API void byte_deleteRTCRoomEventHandler(MyRTCRoomEventHandler* handler)
{
	delete handler;
}

BYTERTC_API void byte_RTCRoomEventHandler_setCallback(MyRTCRoomEventHandler* handler, ByteEventCallback callback)
{
	spdlog::info(__FUNCTION__ " handler {}, callback {}", LOGPTR(handler), LOGPTR(callback));
	handler->setEventCallback(callback);
}

BYTERTC_API bytertc::IRTCVideo* byte_createRTCVideo(const char* app_id, bytertc::IRTCVideoEventHandler* event_handler, const char* parameters)
{
	bytertc::IRTCVideo* rtc_video = bytertc::createRTCVideo(app_id, event_handler, parameters);
	spdlog::info("{} rtc_video {}", __FUNCTION__, LOGPTR(rtc_video));
	return rtc_video;
}

BYTERTC_API void byte_destroyRTCVideo()
{
	spdlog::info(__FUNCTION__);
	bytertc::destroyRTCVideo();
}

BYTERTC_API const char* byte_getErrorDescription(int code)
{
	return bytertc::getErrorDescription(code);
}

BYTERTC_API const char* byte_getSDKVersion()
{
	return bytertc::getSDKVersion();
}

BYTERTC_API bytertc::IVideoFrame* byte_buildVideoFrame(bytertc::VideoFrameBuilder* builder)
{
	return bytertc::buildVideoFrame(*builder);
}

BYTERTC_API void byte_IVideoFrame_release(bytertc::IVideoFrame* frame)
{
	frame->release();
}

BYTERTC_API int byte_RTCVideo_setLocalVideoCanvas(bytertc::IRTCVideo* rtc_video, bytertc::StreamIndex index,
	bytertc::VideoCanvas* canvas)
{
	return rtc_video->setLocalVideoCanvas(index, *canvas);
}

BYTERTC_API int byte_RTCVideo_setVideoCaptureConfig(bytertc::IRTCVideo* rtc_video, bytertc::VideoCaptureConfig* capture_config)
{
	return rtc_video->setVideoCaptureConfig(*capture_config);
}

BYTERTC_API int byte_RTCVideo_setVideoEncoderConfig(bytertc::IRTCVideo* rtc_video, bytertc::VideoEncoderConfig* max_solution)
{
	return rtc_video->setVideoEncoderConfig(*max_solution);
}

BYTERTC_API int byte_RTCVideo_setVideoEncoderConfigList(bytertc::IRTCVideo* rtc_video, 
	bytertc::VideoEncoderConfig* channel_solutions, int solution_num)
{
	return rtc_video->setVideoEncoderConfig(channel_solutions, solution_num);
}

BYTERTC_API int byte_RTCVideo_setVideoEncoderConfigSolutions(bytertc::IRTCVideo* rtc_video, bytertc::StreamIndex index,
		const bytertc::VideoSolution* solutions, int solutions_num)
{
	return rtc_video->setVideoEncoderConfig(index, solutions, solutions_num);
}

BYTERTC_API void byte_RTCVideo_setRemoteStreamVideoCanvas(bytertc::IRTCVideo* rtc_video,
		bytertc::RemoteStreamKey* stream_key, const bytertc::VideoCanvas* canvas)
{
	rtc_video->setRemoteStreamVideoCanvas(*stream_key, *canvas);
}

BYTERTC_API bytertc::IVideoDeviceManager* byte_RTCVideo_getVideoDeviceManager(bytertc::IRTCVideo* rtc_video)
{
	return rtc_video->getVideoDeviceManager();
}

BYTERTC_API int byte_IVideoDeviceManager_getVideoCaptureDevice(bytertc::IVideoDeviceManager* vdm, char device_id[bytertc::MAX_DEVICE_ID_LENGTH])
{
	return vdm->getVideoCaptureDevice(device_id);
}

BYTERTC_API int byte_IVideoDeviceManager_setVideoCaptureDevice(bytertc::IVideoDeviceManager* vdm, const char device_id[bytertc::MAX_DEVICE_ID_LENGTH])
{
	return vdm->setVideoCaptureDevice(device_id);
}

BYTERTC_API bytertc::IVideoDeviceCollection* byte_IVideoDeviceManager_enumerateVideoCaptureDevices(bytertc::IVideoDeviceManager* vdm)
{
	return vdm->enumerateVideoCaptureDevices();
}

BYTERTC_API int byte_IVideoDeviceCollection_getCount(bytertc::IVideoDeviceCollection* vdc)
{
	return vdc->getCount();
}

BYTERTC_API int byte_IVideoDeviceCollection_getDevice(bytertc::IVideoDeviceCollection* vdc, int index,
	char device_name[bytertc::MAX_DEVICE_ID_LENGTH], char device_id[bytertc::MAX_DEVICE_ID_LENGTH])
{
	return vdc->getDevice(index, device_name, device_id);
}

BYTERTC_API int byte_IVideoDeviceCollection_getDeviceInfo(bytertc::IVideoDeviceCollection* vdc, int index,
	bytertc::VideoDeviceInfo* vdi)
{
	return vdc->getDevice(index, vdi);
}

BYTERTC_API void byte_IVideoDeviceCollection_release(bytertc::IVideoDeviceCollection* vdc)
{
	vdc->release();
}

BYTERTC_API void byte_RTCVideo_startVideoCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->startVideoCapture();
}

BYTERTC_API void byte_RTCVideo_stopVideoCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->stopVideoCapture();
}

BYTERTC_API void* byte_RTCVideo_getScreenCaptureSourceList(bytertc::IRTCVideo* rtc_video)
{
	return rtc_video->getScreenCaptureSourceList();
}

BYTERTC_API void byte_IScreenCaptureSourceList_release(bytertc::IScreenCaptureSourceList* source_list)
{
	source_list->release();
}

BYTERTC_API int32_t byte_IScreenCaptureSourceList_getCount(bytertc::IScreenCaptureSourceList* source_list)
{
	return source_list->getCount();
}

BYTERTC_API void byte_IScreenCaptureSourceList_getSourceInfo(bytertc::IScreenCaptureSourceList* source_list,
		bytertc::ScreenCaptureSourceInfo* source_info, int32_t index)
{
	*source_info = source_list->getSourceInfo(index);
}

BYTERTC_API void byte_RTCVideo_startScreenVideoCapture(bytertc::IRTCVideo* rtc_video,
		bytertc::ScreenCaptureSourceInfo* source_info, bytertc::ScreenCaptureParameters* capture_params)
{
	rtc_video->startScreenVideoCapture(*source_info, *capture_params);
}

BYTERTC_API void byte_RTCVideo_stopScreenVideoCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->stopScreenVideoCapture();
}

BYTERTC_API void byte_RTCVideo_startAudioCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->startAudioCapture();
}

BYTERTC_API void byte_RTCVideo_stopAudioCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->stopAudioCapture();
}

BYTERTC_API void byte_RTCVideo_setVideoSourceType(bytertc::IRTCVideo* rtc_video, bytertc::StreamIndex stream_index, bytertc::VideoSourceType type)
{
	rtc_video->setVideoSourceType(stream_index, type);
}

BYTERTC_API void byte_RTCVideo_pushExternalVideoFrame(bytertc::IRTCVideo* rtc_video, bytertc::IVideoFrame* frame)
{
	rtc_video->pushExternalVideoFrame(frame);
}

BYTERTC_API void byte_RTCVideo_startCloudProxy(bytertc::IRTCVideo* rtc_video, bytertc::CloudProxyConfiguration* configuration)
{
	rtc_video->startCloudProxy(*configuration);
}

BYTERTC_API void byte_RTCVideo_stopCloudProxy(bytertc::IRTCVideo* rtc_video, bytertc::CloudProxyConfiguration* configuration)
{
	rtc_video->stopCloudProxy();
}

BYTERTC_API bytertc::IRTCRoom* byte_RTCVideo_createRTCRoom(bytertc::IRTCVideo* rtc_video, const char* room_id)
{
	return rtc_video->createRTCRoom(room_id);
}

BYTERTC_API void byte_RTCRoom_destroy(bytertc::IRTCRoom* rtc_room)
{
	rtc_room->destroy();
}

BYTERTC_API void byte_RTCRoom_setRTCRoomEventHandler(bytertc::IRTCRoom* rtc_room, MyRTCRoomEventHandler* handler)
{
	spdlog::info("{} room {}, handler {}", __FUNCTION__, LOGPTR(rtc_room), LOGPTR(handler));
	rtc_room->setRTCRoomEventHandler(handler);
}

BYTERTC_API int byte_RTCRoom_joinRoom(bytertc::IRTCRoom* rtc_room, const char* token,
	bytertc::UserInfo* user_info, bytertc::RTCRoomConfig* config)
{
	return rtc_room->joinRoom(token, *user_info, *config);
}

BYTERTC_API void byte_RTCRoom_leaveRoom(bytertc::IRTCRoom* rtc_room)
{
	rtc_room->leaveRoom();
}

BYTERTC_API void byte_RTCRoom_publishStream(bytertc::IRTCRoom* rtc_room, bytertc::MediaStreamType type)
{
	rtc_room->publishStream(type);
}

BYTERTC_API void byte_RTCRoom_unpublishStream(bytertc::IRTCRoom* rtc_room, bytertc::MediaStreamType type)
{
	rtc_room->unpublishStream(type);
}

BYTERTC_API void byte_RTCRoom_publishScreen(bytertc::IRTCRoom* rtc_room, bytertc::MediaStreamType type)
{
	rtc_room->publishScreen(type);
}

BYTERTC_API void byte_RTCRoom_unpublishScreen(bytertc::IRTCRoom* rtc_room, bytertc::MediaStreamType type)
{
	rtc_room->unpublishScreen(type);
}

