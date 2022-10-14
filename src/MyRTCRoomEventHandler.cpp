#include "MyRTCRoomEventHandler.h"
#include "spdlog/spdlog.h"
#include "json/json.hpp"
#include "util.h"

using namespace nlohmann;

MyRTCRoomEventHandler::~MyRTCRoomEventHandler()
{

}

void MyRTCRoomEventHandler::setEventCallback(ByteEventCallback callback)
{
	_callback = callback;
}

void MyRTCRoomEventHandler::onRoomStateChanged(const char* room_id, const char* user_id, int state, const char* extra_info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;
	js["state"] = state;
	js["extra_info"] = extra_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onStreamStateChanged(const char* room_id, const char* user_id, int state, const char* extra_info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["room_id"] = room_id;
	js["user_id"] = user_id;
	js["state"] = state;
	js["extra_info"] = extra_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onLeaveRoom(const bytertc::RtcRoomStats& stats)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stats;
	js_stats["room_id"] = stats.cpu_app_usage;
	js_stats["cpu_total_usage"] = stats.cpu_total_usage;
	js_stats["duration"] = stats.duration;
	js_stats["rtt"] = stats.rtt;
	js_stats["rx_audio_kbitrate"] = stats.rx_audio_kbitrate;
	js_stats["rx_bytes"] = stats.rx_bytes;
	js_stats["rx_cellular_kbitrate"] = stats.rx_cellular_kbitrate;
	js_stats["rx_jitter"] = stats.rx_jitter;
	js_stats["rx_kbitrate"] = stats.rx_kbitrate;
	js_stats["rx_jitrx_screen_kbitrateter"] = stats.rx_screen_kbitrate;
	js_stats["rx_video_kbitrate"] = stats.rx_video_kbitrate;
	js_stats["rxLostrate"] = stats.rxLostrate;
	js["stats"] = js_stats;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRoomWarning(int warn)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["warn"] = warn;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRoomError(int err)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["err"] = err;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onTokenWillExpire()
{
	CALLBACK_BLOCK_BEGIN

	json js;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRoomStats(const bytertc::RtcRoomStats& stats)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stats;
	js_stats["cpu_app_usage"] = stats.cpu_app_usage;
	js_stats["cpu_total_usage"] = stats.cpu_total_usage;
	js_stats["duration"] = stats.duration;
	js_stats["rtt"] = stats.rtt;
	js_stats["rx_audio_kbitrate"] = stats.rx_audio_kbitrate;
	js_stats["rx_bytes"] = stats.rx_bytes;
	js_stats["rx_cellular_kbitrate"] = stats.rx_cellular_kbitrate;
	js_stats["rx_jitter"] = stats.rx_jitter;
	js_stats["rx_kbitrate"] = stats.rx_kbitrate;
	js_stats["rx_jitrx_screen_kbitrateter"] = stats.rx_screen_kbitrate;
	js_stats["rx_video_kbitrate"] = stats.rx_video_kbitrate;
	js_stats["rxLostrate"] = stats.rxLostrate;
	js["stats"] = js_stats;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onLocalStreamStats(const bytertc::LocalStreamStats& stats)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stats;
	json js_audio_stats;
	js_audio_stats["audio_loss_rate"] = stats.audio_stats.audio_loss_rate;
	js_audio_stats["jitter"] = stats.audio_stats.jitter;
	js_audio_stats["num_channels"] = stats.audio_stats.num_channels;
	js_audio_stats["record_sample_rate"] = stats.audio_stats.record_sample_rate;
	js_audio_stats["rtt"] = stats.audio_stats.rtt;
	js_audio_stats["send_kbitrate"] = stats.audio_stats.send_kbitrate;
	js_audio_stats["sent_sample_rate"] = stats.audio_stats.sent_sample_rate;
	js_audio_stats["stats_interval"] = stats.audio_stats.stats_interval;
	js_stats["audio_stats"] = js_audio_stats;
	js_stats["is_screen"] = stats.is_screen;
	js_stats["local_rx_quality"] = stats.local_rx_quality;
	js_stats["local_tx_quality"] = stats.local_tx_quality;
	json js_video_stats;
	js_video_stats["codec_type"] = stats.video_stats.codec_type;
	js_video_stats["encoded_bitrate"] = stats.video_stats.encoded_bitrate;
	js_video_stats["encoded_frame_count"] = stats.video_stats.encoded_frame_count;
	js_video_stats["encoded_frame_height"] = stats.video_stats.encoded_frame_height;
	js_video_stats["encoded_frame_width"] = stats.video_stats.encoded_frame_width;
	js_video_stats["encoder_output_frame_rate"] = stats.video_stats.encoder_output_frame_rate;
	js_video_stats["input_frame_rate"] = stats.video_stats.input_frame_rate;
	js_video_stats["is_screen"] = stats.video_stats.is_screen;
	js_video_stats["jitter"] = stats.video_stats.jitter;
	js_video_stats["renderer_output_frame_rate"] = stats.video_stats.renderer_output_frame_rate;
	js_video_stats["rtt"] = stats.video_stats.rtt;
	js_video_stats["sent_frame_rate"] = stats.video_stats.sent_frame_rate;
	js_video_stats["sent_kbitrate"] = stats.video_stats.sent_kbitrate;
	js_video_stats["stats_interval"] = stats.video_stats.stats_interval;
	js_video_stats["video_loss_rate"] = stats.video_stats.video_loss_rate;
	js_stats["video_stats"] = js_video_stats;
	js["stats"] = js_stats;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRemoteStreamStats(const bytertc::RemoteStreamStats& stats)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stats;
	json js_audio_stats;
	js_audio_stats["audio_loss_rate"] = stats.audio_stats.audio_loss_rate;
	js_audio_stats["concealed_samples"] = stats.audio_stats.concealed_samples;
	js_audio_stats["concealment_event"] = stats.audio_stats.concealment_event;
	js_audio_stats["dec_duration"] = stats.audio_stats.dec_duration;
	js_audio_stats["dec_sample_rate"] = stats.audio_stats.dec_sample_rate;
	js_audio_stats["e2e_delay"] = stats.audio_stats.e2e_delay;
	js_audio_stats["frozen_rate"] = stats.audio_stats.frozen_rate;
	js_audio_stats["jitter"] = stats.audio_stats.jitter;
	js_audio_stats["jitter_buffer_delay"] = stats.audio_stats.jitter_buffer_delay;
	js_audio_stats["num_channels"] = stats.audio_stats.num_channels;
	js_audio_stats["playout_sample_rate"] = stats.audio_stats.playout_sample_rate;
	js_audio_stats["quality"] = stats.audio_stats.quality;
	js_audio_stats["received_kbitrate"] = stats.audio_stats.received_kbitrate;
	js_audio_stats["received_sample_rate"] = stats.audio_stats.received_sample_rate;
	js_audio_stats["rtt"] = stats.audio_stats.rtt;
	js_audio_stats["stall_count"] = stats.audio_stats.stall_count;
	js_audio_stats["stall_duration"] = stats.audio_stats.stall_duration;
	js_audio_stats["stats_interval"] = stats.audio_stats.stats_interval;
	js_audio_stats["total_rtt"] = stats.audio_stats.total_rtt;
	js_stats["audio_stats"] = js_audio_stats;
	js_stats["is_screen"] = stats.is_screen;
	js_stats["remote_rx_quality"] = stats.remote_rx_quality;
	js_stats["remote_tx_quality"] = stats.remote_tx_quality;
	js_stats["uid"] = stats.uid;
	json js_video_stats;
#if BYTE_SDK_VERSION >= 344000
	js_video_stats["codec_type"] = stats.video_stats.codec_type;
#endif
	js_video_stats["decoder_output_frame_rate"] = stats.video_stats.decoder_output_frame_rate;
	js_video_stats["e2e_delay"] = stats.video_stats.e2e_delay;
	js_video_stats["frozen_rate"] = stats.video_stats.frozen_rate;
	js_video_stats["height"] = stats.video_stats.height;
	js_video_stats["is_screen"] = stats.video_stats.is_screen;
	js_video_stats["jitter"] = stats.video_stats.jitter;
	js_video_stats["received_kbitrate"] = stats.video_stats.received_kbitrate;
	js_video_stats["renderer_output_frame_rate"] = stats.video_stats.renderer_output_frame_rate;
	js_video_stats["rtt"] = stats.video_stats.rtt;
	js_video_stats["stall_count"] = stats.video_stats.stall_count;
	js_video_stats["stall_duration"] = stats.video_stats.stall_duration;
	js_video_stats["stats_interval"] = stats.video_stats.stats_interval;
#if BYTE_SDK_VERSION == 348102
	js_video_stats["super_resolution_mode"] = stats.video_stats.super_resolution_mode;
#endif
	js_video_stats["video_index"] = stats.video_stats.video_index;
	js_video_stats["video_loss_rate"] = stats.video_stats.video_loss_rate;
	js_video_stats["width"] = stats.video_stats.width;
	js_stats["video_stats"] = js_video_stats;
	js["stats"] = js_stats;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserJoined(const bytertc::UserInfo& user_info, int elapsed)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_user_info;
	js_user_info["uid"] = user_info.uid;
	js_user_info["extra_info"] = user_info.extra_info;
	js["user_info"] = js_user_info;
	js["elapsed"] = elapsed;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserLeave(const char* user_id, bytertc::UserOfflineReason reason)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onStreamRemove(const bytertc::MediaStreamInfo& stream, bytertc::StreamRemoveReason reason)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stream_info;
	js_stream_info["has_audio"] = stream.has_audio;
	js_stream_info["has_video"] = stream.has_video;
	js_stream_info["is_screen"] = stream.is_screen;
	json js_vsd;
	js_vsd["codec_mode"] = stream.max_profile.codec_mode;
	js_vsd["codec_name"] = stream.max_profile.codec_name;
	js_vsd["encode_preference"] = stream.max_profile.encode_preference;
	js_vsd["fps"] = stream.max_profile.fps;
	js_vsd["height"] = stream.max_profile.height;
	js_vsd["max_send_kbps"] = stream.max_profile.max_send_kbps;
	js_vsd["scale_mode"] = stream.max_profile.scale_mode;
	js_vsd["width"] = stream.max_profile.width;
	js_stream_info["max_profile"] = js_vsd;
	js_stream_info["user_id"] = stream.user_id;
	js_stream_info["profile_count"] = stream.profile_count;
	json js_profiles;
	for (int n = 0; n < stream.profile_count; ++n)
	{
		const bytertc::VideoSolutionDescription& vsd = stream.profiles[n];
		json js_vsd_n;
		js_vsd_n["codec_mode"] = vsd.codec_mode;
		js_vsd_n["codec_name"] = vsd.codec_name;
		js_vsd_n["encode_preference"] = vsd.encode_preference;
		js_vsd_n["fps"] = vsd.fps;
		js_vsd_n["height"] = vsd.height;
		js_vsd_n["max_send_kbps"] = vsd.max_send_kbps;
		js_vsd_n["scale_mode"] = vsd.scale_mode;
		js_vsd_n["width"] = vsd.width;
		js_profiles.push_back(js_vsd_n);
	}
	js_stream_info["profiles"] = js_profiles;
	js["stream"] = js_stream_info;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onStreamAdd(const bytertc::MediaStreamInfo& stream)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_stream_info;
	js_stream_info["has_audio"] = stream.has_audio;
	js_stream_info["has_video"] = stream.has_video;
	js_stream_info["is_screen"] = stream.is_screen;
	json js_vsd;
	js_vsd["codec_mode"] = stream.max_profile.codec_mode;
	js_vsd["codec_name"] = stream.max_profile.codec_name;
	js_vsd["encode_preference"] = stream.max_profile.encode_preference;
	js_vsd["fps"] = stream.max_profile.fps;
	js_vsd["height"] = stream.max_profile.height;
	js_vsd["max_send_kbps"] = stream.max_profile.max_send_kbps;
	js_vsd["scale_mode"] = stream.max_profile.scale_mode;
	js_vsd["width"] = stream.max_profile.width;
	js_stream_info["max_profile"] = js_vsd;
	js_stream_info["user_id"] = stream.user_id;
	js_stream_info["profile_count"] = stream.profile_count;
	json js_profiles;
	for (int n = 0; n < stream.profile_count; ++n)
	{
		const bytertc::VideoSolutionDescription& vsd = stream.profiles[n];
		json js_vsd_n;
		js_vsd_n["codec_mode"] = vsd.codec_mode;
		js_vsd_n["codec_name"] = vsd.codec_name;
		js_vsd_n["encode_preference"] = vsd.encode_preference;
		js_vsd_n["fps"] = vsd.fps;
		js_vsd_n["height"] = vsd.height;
		js_vsd_n["max_send_kbps"] = vsd.max_send_kbps;
		js_vsd_n["scale_mode"] = vsd.scale_mode;
		js_vsd_n["width"] = vsd.width;
		js_profiles.push_back(js_vsd_n);
	}
	js_stream_info["profiles"] = js_profiles;
	js["stream"] = js_stream_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserPublishStream(const char* user_id, bytertc::MediaStreamType type)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["type"] = type;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserUnpublishStream(const char* user_id, bytertc::MediaStreamType type, bytertc::StreamRemoveReason reason)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["type"] = type;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserPublishScreen(const char* user_id, bytertc::MediaStreamType type)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["type"] = type;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserUnpublishScreen(const char* user_id, bytertc::MediaStreamType type, bytertc::StreamRemoveReason reason)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["type"] = type;
	js["reason"] = reason;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onStreamSubscribed(bytertc::SubscribeState state_code, const char* user_id, const bytertc::SubscribeConfig& info)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["state_code"] = state_code;
	json js_info;
	js_info["framerate"] = info.framerate;
	js_info["is_screen"] = info.is_screen;
	js_info["priority"] = info.priority;
	js_info["sub_audio"] = info.sub_audio;
	js_info["sub_height"] = info.sub_height;
	js_info["sub_video"] = info.sub_video;
	js_info["sub_video_index"] = info.sub_video_index;
	js_info["sub_width"] = info.sub_width;
	js_info["svc_layer"] = info.svc_layer;
	js_info["video_index"] = info.video_index;
	js["info"] = js_info;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onStreamPublishSuccess(const char* user_id, bool is_screen)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["is_screen"] = is_screen;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRoomMessageReceived(const char* user_id, const char* message)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["message"] = message;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRoomBinaryMessageReceived(const char* user_id, int size, const uint8_t* message)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["size"] = size;
	json js_message;
	for (int n = 0; n < size; ++n)
	{
		js_message.push_back(message[n]);
	}
	js["message"] = js_message;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserMessageReceived(const char* user_id, const char* message)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["message"] = message;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserBinaryMessageReceived(const char* user_id, int size, const uint8_t* message)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["size"] = size;
	json js_message;
	for (int n = 0; n < size; ++n)
	{
		js_message.push_back(message[n]);
	}
	js["message"] = js_message;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUserMessageSendResult(int64_t msgid, int error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["msgid"] = msgid;
	js["error"] = error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRoomMessageSendResult(int64_t msgid, int error)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["msgid"] = msgid;
	js["error"] = error;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onRoomModeChanged(bytertc::RtcRoomMode mode)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["mode"] = mode;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onMaximumScreenShareFpsUpdated(int fps)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["fps"] = fps;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onMaximumScreenSharePixelsUpdated(int screen_pixels)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["screen_pixels"] = screen_pixels;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onVideoStreamBanned(const char* user_id, bool banned)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["banned"] = banned;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onAVSyncStateChange(bytertc::AVSyncState state)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["state"] = state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onAudioStreamBanned(const char* user_id, bool banned)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["user_id"] = user_id;
	js["banned"] = banned;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onForwardStreamStateChanged(bytertc::ForwardStreamStateInfo* infos, int info_count)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["info_count"] = info_count;
	json js_infos;
	for (int n = 0; n < info_count; ++n)
	{
		const bytertc::ForwardStreamStateInfo& info = infos[n];
		json js_info;
		js_info["error"] = info.error;
		js_info["room_id"] = info.room_id;
		js_info["state"] = info.state;
		js_infos.push_back(js_info);
	}
	js["infos"] = js_infos;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}


void MyRTCRoomEventHandler::onForwardStreamEvent(bytertc::ForwardStreamEventInfo* infos, int info_count)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	js["info_count"] = info_count;
	json js_infos;
	for (int n = 0; n < info_count; ++n)
	{
		const bytertc::ForwardStreamEventInfo& info = infos[n];
		json js_info;
		js_info["event"] = info.event;
		js_info["room_id"] = info.room_id;
		js_infos.push_back(js_info);
	}
	js["infos"] = js_infos;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onNetworkQuality(const bytertc::NetworkQualityStats& local_quality,
	const bytertc::NetworkQualityStats* remote_qualities, int remote_qualities_num)
{
	CALLBACK_BLOCK_BEGIN

	json js;
	json js_nqs;
	js_nqs["fraction_lost"] = local_quality.fraction_lost;
	js_nqs["rtt"] = local_quality.rtt;
	js_nqs["rx_quality"] = local_quality.rx_quality;
	js_nqs["total_bandwidth"] = local_quality.total_bandwidth;
	js_nqs["tx_quality"] = local_quality.tx_quality;
	js_nqs["uid"] = local_quality.uid;
	js["local_quality"] = js_nqs;
	js["remote_qualities_num"] = remote_qualities_num;
	json js_rq;
	for (int n = 0; n < remote_qualities_num; ++n)
	{
		const bytertc::NetworkQualityStats& nqs = remote_qualities[n];
		json js_nqs_n;
		js_nqs_n["fraction_lost"] = nqs.fraction_lost;
		js_nqs_n["rtt"] = nqs.rtt;
		js_nqs_n["rx_quality"] = nqs.rx_quality;
		js_nqs_n["total_bandwidth"] = nqs.total_bandwidth;
		js_nqs_n["tx_quality"] = nqs.tx_quality;
		js_nqs_n["uid"] = nqs.uid;
		js_rq.push_back(js_nqs_n);
	}
	js["remote_qualities"] = js_rq;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}


#if BYTE_SDK_VERSION < 347000
void MyRTCRoomEventHandler::onMuteAllRemoteAudio(const char* user_id, bytertc::MuteState mute_state)
{
	CALLBACK_BLOCK_BEGIN

		json js;
	js["user_id"] = user_id;
	js["mute_state"] = mute_state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onMuteAllRemoteVideo(const char* user_id, bytertc::MuteState mute_state)
{
	CALLBACK_BLOCK_BEGIN

		json js;
	js["user_id"] = user_id;
	js["mute_state"] = mute_state;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}


void MyRTCRoomEventHandler::onSubscribe(const char* user_id, bool is_reconnect)
{
	CALLBACK_BLOCK_BEGIN

		json js;
	js["user_id"] = user_id;
	js["is_reconnect"] = is_reconnect;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onUnSubscribe(const char* user_id, bool is_reconnect)
{
	CALLBACK_BLOCK_BEGIN

		json js;
	js["user_id"] = user_id;
	js["is_reconnect"] = is_reconnect;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

void MyRTCRoomEventHandler::onNeedAvatar(const char* user_id)
{
	CALLBACK_BLOCK_BEGIN

		json js;
	js["user_id"] = user_id;

	std::string json_str = js.dump(JSON_INDENT);

	CALLBACK_BLOCK_END
}

#endif

