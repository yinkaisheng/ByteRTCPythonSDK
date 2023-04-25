#include "bytertc_video.h"
#include "rtc/bytertc_advance.h"
#include "MyRTCVideoEventHandler.h"
#include "MyRTCRoomEventHandler.h"
#include "MyVideoFrameObserver.h"
#include "json/json.hpp"
#include "spdlog/spdlog.h"

#pragma warning(disable:4996)

#define LOGPTR spdlog::fmt_lib::ptr

using namespace nlohmann;

BYTERTC_API int byte_setEnv(bytertc::Env env)
{
	return bytertc::setEnv(env);
}

BYTERTC_API MyRTCVideoEventHandler* byte_createRTCVideoEventHandler()
{
	return new MyRTCVideoEventHandler();
}

BYTERTC_API void byte_deleteRTCVideoEventHandler(MyRTCVideoEventHandler* handler)
{
	delete handler;
}


BYTERTC_API MyVideoFrameObserver* byte_createVideoFrameObserver()
{
	return new MyVideoFrameObserver();
}

BYTERTC_API void byte_deleteVideoFrameObserver(MyVideoFrameObserver* videoOb)
{
	delete videoOb;
}

BYTERTC_API void byte_VideoFrameObserver_saveFrame(MyVideoFrameObserver* videoOb,
	SaveFrameType type, int save, unsigned int fileCount, unsigned int frameCount)
{
	videoOb->saveFrame(type, (bool)save, fileCount, frameCount);
}


BYTERTC_API MyLocalEncodedVideoFrameObserver* byte_createLocalEncodedVideoFrameObserver()
{
	return new MyLocalEncodedVideoFrameObserver();
}

BYTERTC_API void byte_deleteLocalEncodedVideoFrameObserver(MyLocalEncodedVideoFrameObserver* videoOb)
{
	delete videoOb;
}

BYTERTC_API void byte_LocalEncodedVideoFrameObserver_saveFrame(MyLocalEncodedVideoFrameObserver* videoOb, int save)
{
	videoOb->saveFrame((bool)save);
}


BYTERTC_API MyRemoteEncodedVideoFrameObserver* byte_createRemoteEncodedVideoFrameObserver()
{
	return new MyRemoteEncodedVideoFrameObserver();
}

BYTERTC_API void byte_deleteRemoteEncodedVideoFrameObserver(MyRemoteEncodedVideoFrameObserver* videoOb)
{
	delete videoOb;
}

BYTERTC_API void byte_RemoteEncodedVideoFrameObserver_saveFrame(MyRemoteEncodedVideoFrameObserver* videoOb, int save)
{
	videoOb->saveFrame((bool)save);
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

BYTERTC_API bytertc::IRTCVideo* byte_createRTCVideo(const char* app_id, MyRTCVideoEventHandler* event_handler, const char* parameters)
{
	bytertc::IRTCVideo* rtc_video = bytertc::createRTCVideo(app_id, event_handler, parameters);
	spdlog::info("{} rtc_video {}, IRTCVideoEventHandler {}", __FUNCTION__, LOGPTR(rtc_video), LOGPTR(event_handler));
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

BYTERTC_API int byte_IVideoFrame_width(bytertc::IVideoFrame* frame)
{
	return frame->width();
}

BYTERTC_API int byte_IVideoFrame_height(bytertc::IVideoFrame* frame)
{
	return frame->height();
}

BYTERTC_API bytertc::VideoFrameType byte_IVideoFrame_frameType(bytertc::IVideoFrame* frame)
{
	return frame->frameType();
}

BYTERTC_API bytertc::VideoPixelFormat byte_IVideoFrame_pixelFormat(bytertc::IVideoFrame* frame)
{
	return frame->pixelFormat();
}

BYTERTC_API int byte_IVideoFrame_numberOfPlanes(bytertc::IVideoFrame* frame)
{
	return frame->numberOfPlanes();
}

BYTERTC_API uint8_t* byte_IVideoFrame_getPlaneData(bytertc::IVideoFrame* frame, int plane_index)
{
	return frame->getPlaneData(plane_index);
}

BYTERTC_API int byte_IVideoFrame_getPlaneStride(bytertc::IVideoFrame* frame, int plane_index)
{
	return frame->getPlaneStride(plane_index);
}

BYTERTC_API void byte_RTCVideo_registerVideoFrameObserver(bytertc::IRTCVideo* rtc_video, MyVideoFrameObserver* videoOb)
{
	rtc_video->registerVideoFrameObserver(videoOb);
}

BYTERTC_API void byte_RTCVideo_registerLocalEncodedVideoFrameObserver(bytertc::IRTCVideo* rtc_video, MyLocalEncodedVideoFrameObserver* videoOb)
{
	rtc_video->registerLocalEncodedVideoFrameObserver(videoOb);
}

BYTERTC_API void byte_RTCVideo_registerRemoteEncodedVideoFrameObserver(bytertc::IRTCVideo* rtc_video, MyRemoteEncodedVideoFrameObserver* videoOb)
{
	rtc_video->registerRemoteEncodedVideoFrameObserver(videoOb);
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

#if BYTE_SDK_VERSION >= 351000
BYTERTC_API void byte_RTCVideo_setVideoCaptureRotation(bytertc::IRTCVideo* rtc_video, bytertc::VideoRotation rotation)
{
	rtc_video->setVideoCaptureRotation(rotation);
}
#endif

BYTERTC_API int byte_RTCVideo_setVideoEncoderConfig(bytertc::IRTCVideo* rtc_video, bytertc::VideoEncoderConfig* encode_config)
{
	return rtc_video->setVideoEncoderConfig(*encode_config);
}

BYTERTC_API int byte_RTCVideo_setVideoEncoderConfig2(bytertc::IRTCVideo* rtc_video, 
	bytertc::VideoEncoderConfig* encode_config, int config_num)
{
	return rtc_video->setVideoEncoderConfig(encode_config, config_num);
}

BYTERTC_API int byte_RTCVideo_setVideoEncoderConfigDeprecated(bytertc::IRTCVideo* rtc_video, bytertc::StreamIndex index,
		const bytertc::VideoSolution* solutions, int config_num)
{
	return rtc_video->setVideoEncoderConfig(index, solutions, config_num);
}

//IVideoEffect
BYTERTC_API bytertc::IVideoEffect* byte_RTCVideo_getVideoEffectInterface(bytertc::IRTCVideo* rtc_video)
{
	return rtc_video->getVideoEffectInterface();
}

#if BYTE_SDK_VERSION >= 347000
BYTERTC_API int byte_IVideoEffect_initCVResource(bytertc::IVideoEffect* effect, const char* license_file_path, const char* algo_model_dir)
{
	return effect->initCVResource(license_file_path, algo_model_dir);
}
#endif

BYTERTC_API int byte_IVideoEffect_setAlgoModelResourceFinder(bytertc::IVideoEffect* effect, uintptr_t finder, uintptr_t deleter)
{
	return effect->setAlgoModelResourceFinder(finder, deleter);
}

BYTERTC_API void byte_IVideoEffect_setAlgoModelPath(bytertc::IVideoEffect* effect, const char* model_path)
{
	effect->setAlgoModelPath(model_path);
}

BYTERTC_API int byte_IVideoEffect_checkLicense(bytertc::IVideoEffect* effect, void* android_context, void* jni_env, const char* license_path)
{
	return effect->checkLicense(android_context, jni_env, license_path);
}

BYTERTC_API int byte_IVideoEffect_getAuthMessage(bytertc::IVideoEffect* effect, char* auth_msg, int* len)
{
	char* pmsg = nullptr;
	int ret = effect->getAuthMessage(&pmsg, len);
	if (ret == 0)
	{
		//std::string strMsg;
		//strMsg += std::to_string((size_t)pmsg);
		//strMsg += " ";
		//strMsg += pmsg;
		//std::strncpy(auth_msg, strMsg.c_str(), (size_t)len);
		std::strncpy(auth_msg, pmsg, (size_t)len);
		effect->freeAuthMessage(pmsg);
	}
	return ret;
}

BYTERTC_API int byte_IVideoEffect_freeAuthMessage(bytertc::IVideoEffect* effect, char* pmsg)
{
	return effect->freeAuthMessage(pmsg);
}

#if BYTE_SDK_VERSION >= 347000
BYTERTC_API int byte_IVideoEffect_enableVideoEffect(bytertc::IVideoEffect* effect)
{
	return effect->enableVideoEffect();
}

BYTERTC_API int byte_IVideoEffect_disableVideoEffect(bytertc::IVideoEffect* effect)
{
	return effect->disableVideoEffect();
}

BYTERTC_API int byte_IVideoEffect_enableVirtualBackground(bytertc::IVideoEffect* effect,
	const char* bg_sticker_path, bytertc::VirtualBackgroundSource* source)
{
	return effect->enableVirtualBackground(bg_sticker_path, *source);
}
#endif

BYTERTC_API int byte_IVideoEffect_enableEffect(bytertc::IVideoEffect* effect, int enabled)
{
	return effect->enableEffect((bool)enabled);
}

#if BYTE_SDK_VERSION >= 346000
BYTERTC_API int byte_IVideoEffect_setBackgroundSticker(bytertc::IVideoEffect* effect,
	const char* model_path, bytertc::VirtualBackgroundSource* source)
{
	return effect->setBackgroundSticker(model_path, *source);
}
#endif

BYTERTC_API int byte_IVideoEffect_disableVirtualBackground(bytertc::IVideoEffect* effect)
{
	return effect->disableVirtualBackground();
}

//IAudioDeviceManager
BYTERTC_API bytertc::IAudioDeviceManager* byte_RTCVideo_getAudioDeviceManager(bytertc::IRTCVideo* rtc_video)
{
	return rtc_video->getAudioDeviceManager();
}

BYTERTC_API int byte_IAudioDeviceManager_getAudioCaptureDevice(bytertc::IAudioDeviceManager* adm, char device_id[bytertc::MAX_DEVICE_ID_LENGTH])
{
	return adm->getAudioCaptureDevice(device_id);
}

BYTERTC_API int byte_IAudioDeviceManager_getAudioPlaybackDevice(bytertc::IAudioDeviceManager* adm, char device_id[bytertc::MAX_DEVICE_ID_LENGTH])
{
	return adm->getAudioPlaybackDevice(device_id);
}

BYTERTC_API int byte_IAudioDeviceManager_setAudioCaptureDevice(bytertc::IAudioDeviceManager* adm, const char* device_id)
{
	return adm->setAudioCaptureDevice(device_id);
}

BYTERTC_API int byte_IAudioDeviceManager_setAudioPlaybackDevice(bytertc::IAudioDeviceManager* adm, const char* device_id)
{
	return adm->setAudioPlaybackDevice(device_id);
}

BYTERTC_API bytertc::IAudioDeviceCollection* byte_IAudioDeviceManager_enumerateAudioCaptureDevices(bytertc::IAudioDeviceManager* adm)
{
	return adm->enumerateAudioCaptureDevices();
}

BYTERTC_API bytertc::IAudioDeviceCollection* byte_IAudioDeviceManager_enumerateAudioPlaybackDevices(bytertc::IAudioDeviceManager* adm)
{
	return adm->enumerateAudioPlaybackDevices();
}

BYTERTC_API int byte_IAudioDeviceCollection_getCount(bytertc::IAudioDeviceCollection* adc)
{
	return adc->getCount();
}

BYTERTC_API int byte_IAudioDeviceCollection_getDevice(bytertc::IAudioDeviceCollection* adc, int index,
	char device_name[bytertc::MAX_DEVICE_ID_LENGTH], char device_id[bytertc::MAX_DEVICE_ID_LENGTH])
{
	return adc->getDevice(index, device_name, device_id);
}

BYTERTC_API int byte_IAudioDeviceCollection_getDeviceInfo(bytertc::IAudioDeviceCollection* adc, int index,
	bytertc::AudioDeviceInfo* adi)
{
	return adc->getDevice(index, adi);
}

BYTERTC_API void byte_IAudioDeviceCollection_release(bytertc::IAudioDeviceCollection* adc)
{
	adc->release();
}

//IVideoDeviceManager
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

BYTERTC_API void byte_RTCVideo_setVideoWatermark(bytertc::IRTCVideo* rtc_video,
	bytertc::StreamIndex stream_index, const char* image_path, bytertc::RTCWatermarkConfig* config)
{
	rtc_video->setVideoWatermark(stream_index, image_path, *config);
}

BYTERTC_API void byte_RTCVideo_clearVideoWatermark(bytertc::IRTCVideo* rtc_video, bytertc::StreamIndex stream_index)
{
	rtc_video->clearVideoWatermark(stream_index);
}

#if BYTE_SDK_VERSION >= 346000
BYTERTC_API int byte_RTCVideo_setDummyCaptureImagePath(bytertc::IRTCVideo* rtc_video, const char* file_path)
{
	return rtc_video->setDummyCaptureImagePath(file_path);
}
#endif

BYTERTC_API void byte_RTCVideo_setLocalVideoMirrorType(bytertc::IRTCVideo* rtc_video, bytertc::MirrorType mirror_type)
{
	rtc_video->setLocalVideoMirrorType(mirror_type);
}

#if BYTE_SDK_VERSION >= 344000
BYTERTC_API void byte_RTCVideo_setVideoOrientation(bytertc::IRTCVideo* rtc_video, bytertc::VideoOrientation orientation)
{
	rtc_video->setVideoOrientation(orientation);
}
#endif

BYTERTC_API int byte_RTCVideo_enableEffectBeauty(bytertc::IRTCVideo* rtc_video, int enable)
{
	return rtc_video->enableEffectBeauty((bool)enable);
}

BYTERTC_API int byte_RTCVideo_setBeautyIntensity(bytertc::IRTCVideo* rtc_video, bytertc::EffectBeautyMode beauty_mode, float intensity)
{
	return rtc_video->setBeautyIntensity(beauty_mode, intensity);
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

BYTERTC_API bytertc::IVideoFrame* byte_RTCVideo_getThumbnail(bytertc::IRTCVideo* rtc_video, bytertc::ScreenCaptureSourceType type,
	void* source_id, int max_width, int max_height)
{
	return rtc_video->getThumbnail(type, source_id, max_width, max_height);
}

BYTERTC_API bytertc::IVideoFrame* byte_RTCVideo_getWindowAppIcon(bytertc::IRTCVideo* rtc_video,
	void* source_id, int max_width, int max_height)
{
	return rtc_video->getWindowAppIcon(source_id, max_width, max_height);
}

BYTERTC_API void byte_RTCVideo_setScreenAudioSourceType(bytertc::IRTCVideo* rtc_video, bytertc::AudioSourceType source_type)
{
	rtc_video->setScreenAudioSourceType(source_type);
}

BYTERTC_API void byte_RTCVideo_setScreenAudioStreamIndex(bytertc::IRTCVideo* rtc_video, bytertc::StreamIndex stream_index)
{
	rtc_video->setScreenAudioStreamIndex(stream_index);
}

BYTERTC_API void byte_RTCVideo_startScreenAudioCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->startScreenAudioCapture();
}

BYTERTC_API void byte_RTCVideo_startScreenAudioCapture2(bytertc::IRTCVideo* rtc_video, const char* device_id)
{
	rtc_video->startScreenAudioCapture(device_id);
}

BYTERTC_API void byte_RTCVideo_stopScreenAudioCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->stopScreenAudioCapture();
}

BYTERTC_API void byte_RTCVideo_updateScreenCapture(bytertc::IRTCVideo* rtc_video, bytertc::ScreenMediaType media_type)
{
	rtc_video->updateScreenCapture(media_type);
}

BYTERTC_API void byte_RTCVideo_startAudioCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->startAudioCapture();
}

BYTERTC_API void byte_RTCVideo_stopAudioCapture(bytertc::IRTCVideo* rtc_video)
{
	rtc_video->stopAudioCapture();
}

BYTERTC_API void byte_RTCVideo_enableAudioPropertiesReport(bytertc::IRTCVideo* rtc_video, bytertc::AudioPropertiesConfig* config)
{
	rtc_video->enableAudioPropertiesReport(*config);
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

BYTERTC_API void byte_RTCVideo_setPublishFallbackOption(bytertc::IRTCVideo* rtc_video, bytertc::PublishFallbackOption option)
{
	rtc_video->setPublishFallbackOption(option);
}

BYTERTC_API void byte_RTCVideo_setSubscribeFallbackOption(bytertc::IRTCVideo* rtc_video, bytertc::SubscribeFallbackOption option)
{
	rtc_video->setSubscribeFallbackOption(option);
}

BYTERTC_API int byte_RTCVideo_setRemoteUserPriority(bytertc::IRTCVideo* rtc_video, const char* room_id, const char* user_id, bytertc::RemoteUserPriority priority)
{
	return rtc_video->setRemoteUserPriority(room_id, user_id, priority);
}

#if BYTE_SDK_VERSION >= 347000
BYTERTC_API void byte_RTCVideo_setRemoteVideoCanvas(bytertc::IRTCVideo* rtc_video,
	bytertc::RemoteStreamKey* stream_key, const bytertc::VideoCanvas* canvas)
{
	rtc_video->setRemoteVideoCanvas(*stream_key, *canvas);
}
#else
BYTERTC_API void byte_RTCVideo_setRemoteStreamVideoCanvas(bytertc::IRTCVideo* rtc_video,
	bytertc::RemoteStreamKey* stream_key, const bytertc::VideoCanvas* canvas)
{
	rtc_video->setRemoteStreamVideoCanvas(*stream_key, *canvas);
}
#endif

#if BYTE_SDK_VERSION >= 347000
BYTERTC_API void byte_RTCVideo_enableSimulcastMode(bytertc::IRTCVideo* rtc_video, int enabled) {
	rtc_video->enableSimulcastMode((bool)enabled);
}
#else
BYTERTC_API int byte_RTCVideo_enableSimulcastMode(bytertc::IRTCVideo* rtc_video, int enabled) {
	return rtc_video->enableSimulcastMode((bool)enabled);
}
#endif

#if BYTE_SDK_VERSION >= 347000 || (BYTE_SDK_VERSION >= 345701 && BYTE_SDK_VERSION < 346000)
BYTERTC_API long byte_RTCVideo_takeLocalSnapshot(bytertc::IRTCVideo* rtc_video, bytertc::StreamIndex stream_index, MyRTCVideoEventHandler* callback) {
	return rtc_video->takeLocalSnapshot(stream_index, callback);
}

BYTERTC_API long byte_RTCVideo_takeRemoteSnapshot(bytertc::IRTCVideo* rtc_video, bytertc::RemoteStreamKey* stream_key, MyRTCVideoEventHandler* callback) {
	return rtc_video->takeRemoteSnapshot(*stream_key, callback);
}
#endif

#if BYTE_SDK_VERSION >= 348000
BYTERTC_API int byte_RTCVideo_setScreenVideoEncoderConfig(bytertc::IRTCVideo* rtc_video, bytertc::ScreenVideoEncoderConfig* encoder_config)
{
	return rtc_video->setScreenVideoEncoderConfig(*encoder_config);
}
#else
BYTERTC_API int byte_RTCVideo_setScreenVideoEncoderConfig(bytertc::IRTCVideo* rtc_video, bytertc::VideoEncoderConfig* encoder_config)
{
	return rtc_video->setScreenVideoEncoderConfig(*encoder_config);
}
#endif

#if BYTE_SDK_VERSION >= 348000
BYTERTC_API int byte_RTCVideo_setRemoteVideoSuperResolution(bytertc::IRTCVideo* rtc_video, bytertc::RemoteStreamKey* stream_key, bytertc::VideoSuperResolutionMode mode)
{
	return rtc_video->setRemoteVideoSuperResolution(*stream_key, mode);
}
#endif

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

BYTERTC_API void byte_RTCRoom_subscribeStream(bytertc::IRTCRoom* rtc_room, const char* user_id, bytertc::MediaStreamType type)
{
	rtc_room->subscribeStream(user_id, type);
}

BYTERTC_API void byte_RTCRoom_unsubscribeStream(bytertc::IRTCRoom* rtc_room, const char* user_id, bytertc::MediaStreamType type)
{
	rtc_room->unsubscribeStream(user_id, type);
}

BYTERTC_API void byte_RTCRoom_subscribeScreen(bytertc::IRTCRoom* rtc_room, const char* user_id, bytertc::MediaStreamType type)
{
	rtc_room->subscribeScreen(user_id, type);
}

BYTERTC_API void byte_RTCRoom_unsubscribeScreen(bytertc::IRTCRoom* rtc_room, const char* user_id, bytertc::MediaStreamType type)
{
	rtc_room->unsubscribeScreen(user_id, type);
}

#if BYTE_SDK_VERSION >= 347000
BYTERTC_API int byte_RTCRoom_setRemoteVideoConfig(bytertc::IRTCRoom* rtc_room, const char* user_id, bytertc::RemoteVideoConfig* config)
{
	return rtc_room->setRemoteVideoConfig(user_id, *config);
}
#else
BYTERTC_API void byte_RTCRoom_setRemoteVideoConfig(bytertc::IRTCRoom* rtc_room, const char* user_id, bytertc::RemoteVideoConfig* config)
{
	rtc_room->setRemoteVideoConfig(user_id, *config);
}
#endif

BYTERTC_API int byte_RTCRoom_startForwardStreamToRooms(bytertc::IRTCRoom* rtc_room, bytertc::ForwardStreamConfiguration* config)
{
	return rtc_room->startForwardStreamToRooms(*config);
}

BYTERTC_API int byte_RTCRoom_updateForwardStreamToRooms(bytertc::IRTCRoom* rtc_room, bytertc::ForwardStreamConfiguration* config)
{
	return rtc_room->updateForwardStreamToRooms(*config);
}

BYTERTC_API void byte_RTCRoom_stopForwardStreamToRooms(bytertc::IRTCRoom* rtc_room)
{
	rtc_room->stopForwardStreamToRooms();
}

BYTERTC_API int64_t byte_RTCRoom_sendRoomMessage(bytertc::IRTCRoom* rtc_room, const char* message)
{
	return rtc_room->sendRoomMessage(message);
}

BYTERTC_API int64_t byte_RTCRoom_sendRoomBinaryMessage(bytertc::IRTCRoom* rtc_room, const uint8_t* message, int size)
{
	return rtc_room->sendRoomBinaryMessage(size, message);
}

BYTERTC_API int64_t byte_RTCRoom_sendUserMessage(bytertc::IRTCRoom* rtc_room, const char* user_id,
	const char* message, bytertc::MessageConfig config)
{
	return rtc_room->sendUserMessage(user_id, message, config);
}

BYTERTC_API int64_t byte_RTCRoom_sendUserBinaryMessage(bytertc::IRTCRoom* rtc_room, const char* user_id,
	const uint8_t* message, int size, bytertc::MessageConfig config)
{
	return rtc_room->sendUserBinaryMessage(user_id, size, message, config);
}

