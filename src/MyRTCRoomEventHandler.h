#pragma once
#include "bytertc_room_event_handler.h"
#include "common.h"

class MyRTCRoomEventHandler : public bytertc::IRTCRoomEventHandler
{
public:
	virtual ~MyRTCRoomEventHandler();

	void setEventCallback(ByteEventCallback callback);

	void onRoomStateChanged(const char* room_id, const char* uid, int state, const char* extra_info) override;
	void onStreamStateChanged(const char* room_id, const char* uid, int state, const char* extra_info) override;
	void onLeaveRoom(const bytertc::RtcRoomStats& stats) override;
	void onRoomWarning(int warn) override;
	void onRoomError(int err) override;
	void onTokenWillExpire() override;
	void onRoomStats(const bytertc::RtcRoomStats& stats) override;
	void onLocalStreamStats(const bytertc::LocalStreamStats& stats) override;
	void onRemoteStreamStats(const bytertc::RemoteStreamStats& stats) override;
	void onUserJoined(const bytertc::UserInfo& user_info, int elapsed) override;
	void onUserLeave(const char* uid, bytertc::UserOfflineReason reason) override;
	void onMuteAllRemoteAudio(const char* user_id, bytertc::MuteState mute_state) override;
	void onMuteAllRemoteVideo(const char* uid, bytertc::MuteState mute) override;
	void onStreamRemove(const bytertc::MediaStreamInfo& stream, bytertc::StreamRemoveReason reason) override;
	void onStreamAdd(const bytertc::MediaStreamInfo& stream) override;
	void onUserPublishStream(const char* uid, bytertc::MediaStreamType type) override;
	void onUserUnpublishStream(const char* uid, bytertc::MediaStreamType type, bytertc::StreamRemoveReason reason) override;
	void onUserPublishScreen(const char* uid, bytertc::MediaStreamType type) override;
	void onUserUnpublishScreen(const char* uid, bytertc::MediaStreamType type, bytertc::StreamRemoveReason reason) override;
	void onStreamSubscribed(bytertc::SubscribeState state_code, const char* user_id, const bytertc::SubscribeConfig& info) override;
	void onStreamPublishSuccess(const char* user_id, bool is_screen) override;
	void onRoomMessageReceived(const char* uid, const char* message) override;
	void onRoomBinaryMessageReceived(const char* uid, int size, const uint8_t* message) override;
	void onUserMessageReceived(const char* uid, const char* message) override;
	void onUserBinaryMessageReceived(const char* uid, int size, const uint8_t* message) override;
	void onUserMessageSendResult(int64_t msgid, int error) override;
	void onRoomMessageSendResult(int64_t msgid, int error) override;
	void onRoomModeChanged(bytertc::RtcRoomMode mode) override;
	void onSubscribe(const char* user_id, bool is_reconnect) override;
	void onUnSubscribe(const char* user_id, bool is_reconnect) override;
	void onMaximumScreenShareFpsUpdated(int fps) override;
	void onMaximumScreenSharePixelsUpdated(int screenPixels) override;
	void onNeedAvatar(const char* uid) override;
	void onVideoStreamBanned(const char* uid, bool banned) override;
	void onAVSyncStateChange(bytertc::AVSyncState state) override;
	void onAudioStreamBanned(const char* uid, bool banned) override;
	void onForwardStreamStateChanged(bytertc::ForwardStreamStateInfo* infos, int info_count) override;
	void onForwardStreamEvent(bytertc::ForwardStreamEventInfo* infos, int info_count) override;
	void onNetworkQuality(const bytertc::NetworkQualityStats& local_quality,
		const bytertc::NetworkQualityStats* remote_qualities, int remote_qualities_num) override;

private:
	ByteEventCallback _callback{};
};
