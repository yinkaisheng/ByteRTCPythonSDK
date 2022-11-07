#include "MyRTCVideoEventHandler.h"
#include "spdlog/spdlog.h"
#include "json/json.hpp"
#include "util.h"

using namespace nlohmann;

MyRTCVideoEventHandler::~MyRTCVideoEventHandler()
{

}

void MyRTCVideoEventHandler::setEventCallback(ByteEventCallback callback)
{
	_callback = callback;
}

void MyRTCVideoEventHandler::onWarning(int warn)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["warn"] = warn;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onError(int err)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["err"] = err;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioMixingStateChanged(int mix_id, bytertc::AudioMixingState state, bytertc::AudioMixingError error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["mix_id"] = mix_id;
	js["state"] = state;
	js["error"] = error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioMixingPlayingProgress(int mix_id, int64_t progress)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["mix_id"] = mix_id;
	js["progress"] = progress;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLogReport(const char* log_type, const char* log_content)
{
	//CALLBACK_BLOCK_BEGIN

	//json js;
	//js["log_type"] = log_type;
	//js["log_content"] = log_content;

	//std::string json_str = js.dump(JSON_INDENT);

	//CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioPlaybackDeviceChanged(bytertc::AudioPlaybackDevice device)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["device"] = device;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioRouteChanged(bytertc::AudioRoute route)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["route"] = route;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onConnectionStateChanged(bytertc::ConnectionState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onNetworkTypeChanged(bytertc::NetworkType type)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["type"] = type;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onSimulcastSubscribeFallback(const bytertc::RemoteStreamSwitch& event)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_event;
	js_event["uid"] = event.uid;
	js_event["is_screen"] = event.is_screen;
	js_event["before_video_index"] = event.before_video_index;
	js_event["after_video_index"] = event.after_video_index;
	js_event["before_enable"] = event.before_enable;
	js_event["after_enable"] = event.after_enable;
	js_event["reason"] = event.reason;
	js["event"] = js_event;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onPerformanceAlarms(bytertc::PerformanceAlarmMode mode, const char* room_id,
	bytertc::PerformanceAlarmReason reason, const bytertc::SourceWantedData& data)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["mode"] = mode;
	js["room_id"] = room_id;
	js["reason"] = reason;
	json js_data;
	js_data["frame_rate"] = data.frame_rate;
	js_data["height"] = data.height;
	js_data["width"] = data.width;
	js["data"] = js_data;


	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onMediaDeviceStateChanged(const char* device_id,
	bytertc::MediaDeviceType device_type,
	bytertc::MediaDeviceState device_state,
	bytertc::MediaDeviceError device_error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["device_id"] = device_id;
	js["device_type"] = device_type;
	js["device_state"] = device_state;
	js["device_error"] = device_error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioDeviceStateChanged(const char* device_id, bytertc::RTCAudioDeviceType device_type,
	bytertc::MediaDeviceState device_state, bytertc::MediaDeviceError device_error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["device_id"] = device_id;
	js["device_type"] = device_type;
	js["device_state"] = device_state;
	js["device_error"] = device_error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onVideoDeviceStateChanged(const char* device_id, bytertc::RTCVideoDeviceType device_type,
	bytertc::MediaDeviceState device_state, bytertc::MediaDeviceError device_error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["device_id"] = device_id;
	js["device_type"] = device_type;
	js["device_state"] = device_state;
	js["device_error"] = device_error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onMediaDeviceWarning(const char* device_id, bytertc::MediaDeviceType device_type,
	bytertc::MediaDeviceWarning device_warning)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["device_id"] = device_id;
	js["device_type"] = device_type;
	js["device_warning"] = device_warning;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioDeviceWarning(const char* device_id, bytertc::RTCAudioDeviceType device_type,
	bytertc::MediaDeviceWarning device_warning)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["device_id"] = device_id;
	js["device_type"] = device_type;
	js["device_warning"] = device_warning;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onVideoDeviceWarning(const char* device_id, bytertc::RTCVideoDeviceType device_type,
	bytertc::MediaDeviceWarning device_warning)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["device_id"] = device_id;
	js["device_type"] = device_type;
	js["device_warning"] = device_warning;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onSysStats(const bytertc::SysStats& stats)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stats;
	js_stats["cpu_cores"] = stats.cpu_cores;
	js_stats["cpu_app_usage"] = stats.cpu_app_usage;
	js_stats["cpu_total_usage"] = stats.cpu_total_usage;
	js_stats["full_memory"] = stats.full_memory;
	js_stats["total_memory_usage"] = stats.total_memory_usage;
	js_stats["free_memory"] = stats.free_memory;
	js_stats["total_memory_ratio"] = stats.total_memory_ratio;
	js["stats"] = js_stats;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onCreateRoomStateChanged(const char* room_id, int error_code)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["error_code"] = error_code;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onHttpProxyState(int state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onHttpsProxyState(int state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onSocks5ProxyState(int state, const char* cmd,
	const char* proxy_address, const char* local_address, const char* remote_address)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["state"] = state;
	js["cmd"] = cmd;
	js["proxy_address"] = proxy_address;
	js["local_address"] = local_address;
	js["remote_address"] = remote_address;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onRecordingStateUpdate(bytertc::StreamIndex index, bytertc::RecordingState state,
	bytertc::RecordingErrorCode error_code, bytertc::RecordingInfo info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["index"] = index;
	js["state"] = state;
	js["error_code"] = error_code;
	json js_info;
	js_info["file_path"] = info.file_path;
	js_info["height"] = info.height;
	js_info["video_codec_type"] = info.video_codec_type;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onRecordingProgressUpdate(bytertc::StreamIndex index, bytertc::RecordingProgress process, bytertc::RecordingInfo info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["index"] = index;
	json js_process;
	js_process["duration"] = process.duration;
	js_process["file_size"] = process.file_size;
	js["process"] = js_process;
	json js_info;
	js_info["file_path"] = info.file_path;
	js_info["height"] = info.height;
	js_info["video_codec_type"] = info.video_codec_type;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLoginResult(const char* user_id, int error_code, int elapsed)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["error_code"] = error_code;
	js["elapsed"] = elapsed;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLogout()
{
	CALLBACK_BLOCK_BEGIN

	json js;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onServerParamsSetResult(int error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["error"] = error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onGetPeerOnlineStatus(const char* peer_user_id, int status)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["peer_user_id"] = peer_user_id;
	js["status"] = status;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserMessageReceivedOutsideRoom(const char* user_id, const char* message)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["message"] = message;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserBinaryMessageReceivedOutsideRoom(const char* user_id, int size, const uint8_t* message)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["size"] = size;
	json js_message;
	for (uint32_t n = 0; n < size; ++n)
	{
		js_message.push_back(message[n]);
	}
	js["message"] = js_message;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserMessageSendResultOutsideRoom(int64_t msgid, int error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["msgid"] = msgid;
	js["error"] = error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onServerMessageSendResult(int64_t msgid, int error, const bytertc::ServerACKMsg& msg)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["msgid"] = msgid;
	js["error"] = error;
	json js_msg;
	js["ACKMsg"] = msg.ACKMsg;
	js["length"] = msg.length;
	js["msg"] = js_msg;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onSEIMessageReceived(bytertc::RemoteStreamKey stream_key, const uint8_t* message, int length)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stream_key;
	js_stream_key["room_id"] = stream_key.room_id;
	js_stream_key["stream_index"] = stream_key.stream_index;
	js_stream_key["user_id"] = stream_key.user_id;
	js["stream_key"] = js_stream_key;
	js["length"] = length;
	json js_message;
	for (uint32_t n = 0; n < length; ++n)
	{
		js_message.push_back(message[n]);
	}
	js["message"] = js_message;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onSEIStreamUpdate(const bytertc::RemoteStreamKey& key, bytertc::SEIStreamEventType type)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_key;
	js_key["js_key"] = key.room_id;
	js_key["stream_index"] = key.stream_index;
	js_key["user_id"] = key.user_id;
	js["key"] = js_key;
	js["type"] = type;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onRemoteAudioPropertiesReport(const bytertc::RemoteAudioPropertiesInfo* audio_properties_infos,
	int audio_properties_info_number, int total_remote_volume)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_audio_properties_infos;
	for (int n = 0; n < audio_properties_info_number; ++n)
	{
		const bytertc::RemoteAudioPropertiesInfo& rapi = audio_properties_infos[n];
		json js_rapi;
		json js_api;
		js_api["linear_volume"] = rapi.audio_properties_info.linear_volume;
		js_api["nonlinear_volume"] = rapi.audio_properties_info.nonlinear_volume;
		js_api["linear_volume"] = rapi.audio_properties_info.linear_volume;
		json js_spectrum;
		for (unsigned int n = 0; n < SPECTRUM_SIZE; ++n)
		{
			js_spectrum.push_back(rapi.audio_properties_info.spectrum[n]);
		}
		js_api["spectrum"] = js_spectrum;
		js_api["vad"] = rapi.audio_properties_info.vad;
		js_rapi["audio_properties_infos"] = js_api;
		json js_stream_key;
		js_stream_key["room_id"] = rapi.stream_key.room_id;
		js_stream_key["stream_index"] = rapi.stream_key.stream_index;
		js_stream_key["user_id"] = rapi.stream_key.user_id;
		js_rapi["stream_key"] = js_stream_key;

		js_audio_properties_infos.push_back(js_rapi);
	}

	js["audio_properties_infos"] = js_audio_properties_infos;
	js["audio_properties_info_number"] = audio_properties_info_number;
	js["total_remote_volume"] = total_remote_volume;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLocalAudioPropertiesReport(const bytertc::LocalAudioPropertiesInfo* audio_properties_infos,
	int audio_properties_info_number)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_audio_properties_infos;
	for (int n = 0; n < audio_properties_info_number; ++n)
	{
		const bytertc::LocalAudioPropertiesInfo& lapi = audio_properties_infos[n];
		json js_lapi;
		js_lapi["stream_index"] = lapi.stream_index;
		json js_api;
		js_api["linear_volume"] = lapi.audio_properties_info.linear_volume;
		js_api["nonlinear_volume"] = lapi.audio_properties_info.nonlinear_volume;
		js_api["linear_volume"] = lapi.audio_properties_info.linear_volume;
		json js_spectrum;
		for (unsigned int n = 0; n < SPECTRUM_SIZE; ++n)
		{
			js_spectrum.push_back(lapi.audio_properties_info.spectrum[n]);
		}
		js_api["spectrum"] = js_spectrum;
		js_api["vad"] = lapi.audio_properties_info.vad;
		js_lapi["audio_properties_infos"] = js_api;

		js_audio_properties_infos.push_back(js_lapi);
	}

	js["audio_properties_infos"] = js_audio_properties_infos;
	js["audio_properties_info_number"] = audio_properties_info_number;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioPlaybackDeviceTestVolume(int volume)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["volume"] = volume;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLocalAudioStateChanged(bytertc::LocalAudioStreamState state, bytertc::LocalAudioStreamError error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["state"] = state;
	js["error"] = error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserStartAudioCapture(const char* room_id, const char* user_id)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserStopAudioCapture(const char* room_id, const char* user_id)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onActiveSpeaker(const char* room_id, const char* user_id)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onStreamSyncInfoReceived(bytertc::RemoteStreamKey stream_key, bytertc::SyncInfoStreamType stream_type,
	const uint8_t* data, int32_t length)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stream_key;
	js_stream_key["room_id"] = stream_key.room_id;
	js_stream_key["stream_index"] = stream_key.stream_index;
	js_stream_key["user_id"] = stream_key.user_id;
	js["stream_key"] = js_stream_key;
	js["stream_type"] = stream_type;
	json js_data;
	for (int n = 0; n < length; ++n)
	{
		js_data.push_back(data[n]);
	}
	js["data"] = js_data;
	js["length"] = length;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onNetworkDetectionResult(bytertc::NetworkDetectionLinkType type, bytertc::NetworkQuality quality,
	int rtt, double lost_rate, int bitrate, int jitter)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["type"] = type;
	js["quality"] = quality;
	js["rtt"] = rtt;
	js["lost_rate"] = lost_rate;
	js["bitrate"] = bitrate;
	js["jitter"] = jitter;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onNetworkDetectionStopped(bytertc::NetworkDetectionStopReason reason)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onFirstPublicStreamVideoFrameDecoded(const char* public_stream_id, const bytertc::VideoFrameInfo& info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["public_stream_id"] = public_stream_id;
	json js_info;
	js_info["height"] = info.height;
	js_info["rotation"] = info.rotation;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserStartVideoCapture(const char* room_id, const char* user_id)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserStopVideoCapture(const char* room_id, const char* user_id)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLocalVideoSizeChanged(bytertc::StreamIndex index, const bytertc::VideoFrameInfo& info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["index"] = index;
	json js_info;
	js_info["height"] = info.height;
	js_info["rotation"] = info.rotation;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onRemoteVideoSizeChanged(bytertc::RemoteStreamKey key, const bytertc::VideoFrameInfo& info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_key;
	js_key["room_id"] = key.room_id;
	js_key["stream_index"] = key.stream_index;
	js_key["user_id"] = key.user_id;
	js["key"] = js_key;
	json js_info;
	js_info["height"] = info.height;
	js_info["rotation"] = info.rotation;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onFirstLocalVideoFrameCaptured(bytertc::StreamIndex index, bytertc::VideoFrameInfo info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["index"] = index;
	json js_info;
	js_info["height"] = info.height;
	js_info["rotation"] = info.rotation;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserMuteAudio(const char* room_id, const char* user_id, bytertc::MuteState mute_state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;
	js["mute_state"] = mute_state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onFirstRemoteAudioFrame(const bytertc::RemoteStreamKey& key)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_key;
	js_key["room_id"] = key.room_id;
	js_key["stream_index"] = key.stream_index;
	js_key["user_id"] = key.user_id;
	js["key"] = js_key;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onUserMuteVideo(const char* room_id, const char* user_id, bytertc::MuteState mute)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;
	js["mute"] = mute;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onRemoteAudioStateChanged(const bytertc::RemoteStreamKey& key, bytertc::RemoteAudioState state,
	bytertc::RemoteAudioStateChangeReason reason)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_key;
	js_key["room_id"] = key.room_id;
	js_key["stream_index"] = key.stream_index;
	js_key["user_id"] = key.user_id;
	js["key"] = js_key;
	js["state"] = state;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLocalVideoStateChanged(bytertc::StreamIndex index, bytertc::LocalVideoStreamState state,
	bytertc::LocalVideoStreamError error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["index"] = index;
	js["state"] = state;
	js["error"] = error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onRemoteVideoStateChanged(bytertc::RemoteStreamKey key, bytertc::RemoteVideoState state, bytertc::RemoteVideoStateChangeReason reason)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_key;
	js_key["room_id"] = key.room_id;
	js_key["stream_index"] = key.stream_index;
	js_key["user_id"] = key.user_id;
	js["key"] = js_key;
	js["state"] = state;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioFrameSendStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFrameSendState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	json js_user;
	js_user["meta_data"] = user.meta_data;
	js_user["user_id"] = user.user_id;
	js["user"] = js_user;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onVideoFrameSendStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFrameSendState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	json js_user;
	js_user["meta_data"] = user.meta_data;
	js_user["user_id"] = user.user_id;
	js["user"] = js_user;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onFirstRemoteVideoFrameRendered(const bytertc::RemoteStreamKey key, const bytertc::VideoFrameInfo& info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_key;
	js_key["room_id"] = key.room_id;
	js_key["stream_index"] = key.stream_index;
	js_key["user_id"] = key.user_id;
	js["key"] = js_key;
	json js_info;
	js_info["height"] = info.height;
	js_info["rotation"] = info.rotation;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onFirstRemoteVideoFrameDecoded(const bytertc::RemoteStreamKey key, const bytertc::VideoFrameInfo& info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_key;
	js_key["room_id"] = key.room_id;
	js_key["stream_index"] = key.stream_index;
	js_key["user_id"] = key.user_id;
	js["key"] = js_key;
	json js_info;
	js_info["height"] = info.height;
	js_info["rotation"] = info.rotation;
	js_info["width"] = info.width;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onScreenVideoFrameSendStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFrameSendState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	json js_user;
	js_user["meta_data"] = user.meta_data;
	js_user["user_id"] = user.user_id;
	js["user"] = js_user;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onAudioFramePlayStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFramePlayState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	json js_user;
	js_user["meta_data"] = user.meta_data;
	js_user["user_id"] = user.user_id;
	js["user"] = js_user;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onVideoFramePlayStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFramePlayState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	json js_user;
	js_user["meta_data"] = user.meta_data;
	js_user["user_id"] = user.user_id;
	js["user"] = js_user;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onScreenVideoFramePlayStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFramePlayState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	json js_user;
	js_user["meta_data"] = user.meta_data;
	js_user["user_id"] = user.user_id;
	js["user"] = js_user;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onFirstLocalAudioFrame(bytertc::StreamIndex index)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["index"] = index;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onFirstPublicStreamAudioFrame(const char* public_stream_id)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["public_stream_id"] = public_stream_id;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onCloudProxyConnected(int interval)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["interval"] = interval;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onEchoTestResult(bytertc::EchoTestResult result)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["result"] = result;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onPlayPublicStreamResult(const char* public_stream_id,
#if BYTE_SDK_VERSION >= 346000
	bytertc::PublicStreamErrorCode errorCode
#else
	int errorCode
#endif
)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["public_stream_id"] = public_stream_id;
	js["errorCode"] = errorCode;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onPushPublicStreamResult(const char* room_id, const char* public_streamid,
#if BYTE_SDK_VERSION >= 346000
	bytertc::PublicStreamErrorCode errorCode
#else
	int errorCode
#endif
)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["public_streamid"] = public_streamid;
	js["errorCode"] = errorCode;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onPublicStreamSEIMessageReceived(const char* public_stream_id,
	const uint8_t* message, int message_length
#if BYTE_SDK_VERSION >= 347000
	, bytertc::SEIMessageSourceType source_type
#endif
)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["public_stream_id"] = public_stream_id;
	json js_message;
	for (int n = 0; n < message_length; ++n)
	{
		js_message.push_back(message[n]);
	}
	js["message"] = js_message;
	js["message_length"] = message_length;
#if BYTE_SDK_VERSION >= 347000
	js["source_type"] = source_type;
#endif

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

#if BYTE_SDK_VERSION >= 347000
void MyRTCVideoEventHandler::onAudioDumpStateChanged(bytertc::AudioDumpStatus status)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["status"] = status;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}
#endif

#if BYTE_SDK_VERSION >= 347000
void MyRTCVideoEventHandler::onTakeLocalSnapshotResult(long taskId, bytertc::StreamIndex stream_index, bytertc::IVideoFrame* video_frame, int error_code)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["taskId"] = taskId;
	js["stream_index"] = stream_index;
	js["error_code"] = error_code;
	js["video_frame"] = (size_t)video_frame->shallowCopy();

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onTakeRemoteSnapshotResult(long taskId, bytertc::RemoteStreamKey stream_key, bytertc::IVideoFrame* video_frame, int error_code)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["taskId"] = taskId;
	json js_stream_key;
	js_stream_key["room_id"] = stream_key.room_id;
	js_stream_key["stream_index"] = stream_key.stream_index;
	js_stream_key["user_id"] = stream_key.user_id;
	js["stream_key"] = js_stream_key;
	js["error_code"] = error_code;
	js["video_frame"] = (size_t)video_frame->shallowCopy();

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}
#endif

#if BYTE_SDK_VERSION >= 348000
void MyRTCVideoEventHandler::onNetworkTimeSynchronized()
{
	CALLBACK_BLOCK_BEGIN

	std::string json_str = "{}";

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onLicenseWillExpire(int days)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["days"] = days;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onExternalScreenFrameUpdate(bytertc::FrameUpdateInfo frameUpdateInfo)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_info;
	js_info["framerate"] = frameUpdateInfo.framerate;
	js_info["pixel"] = frameUpdateInfo.pixel;

	js["frame_update_info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCVideoEventHandler::onRemoteVideoSuperResolutionModeChanged(bytertc::RemoteStreamKey stream_key,
	bytertc::VideoSuperResolutionMode mode, bytertc::VideoSuperResolutionModeChangedReason reason)
{
	CALLBACK_BLOCK_BEGIN

		json js;
	json js_stream_key;
	js_stream_key["room_id"] = stream_key.room_id;
	js_stream_key["stream_index"] = stream_key.stream_index;
	js_stream_key["user_id"] = stream_key.user_id;
	js["stream_key"] = js_stream_key;
	js["mode"] = mode;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}
#endif

