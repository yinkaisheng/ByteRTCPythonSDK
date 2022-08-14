#pragma once
#include "bytertc_video_event_handler.h"
#include "common.h"

class MyRTCVideoEventHandler : public bytertc::IRTCVideoEventHandler
{
public:
	virtual ~MyRTCVideoEventHandler();

	void setEventCallback(ByteEventCallback callback);
	void onWarning(int warn) override;
	void onError(int err) override;
	void onAudioMixingStateChanged(int mix_id, bytertc::AudioMixingState state, bytertc::AudioMixingError error) override;
	void onAudioMixingPlayingProgress(int mix_id, int64_t progress) override;
	void onLogReport(const char* log_type, const char* log_content) override;
	void onAudioPlaybackDeviceChanged(bytertc::AudioPlaybackDevice device) override;
	void onAudioRouteChanged(bytertc::AudioRoute route) override;
	void onConnectionStateChanged(bytertc::ConnectionState state) override;
	void onNetworkTypeChanged(bytertc::NetworkType type) override;
	void onSimulcastSubscribeFallback(const bytertc::RemoteStreamSwitch& event) override;
	void onPerformanceAlarms(bytertc::PerformanceAlarmMode mode, const char* room_id,
		bytertc::PerformanceAlarmReason reason, const bytertc::SourceWantedData& data) override;
	void onMediaDeviceStateChanged(const char* device_id, bytertc::MediaDeviceType device_type,
		bytertc::MediaDeviceState device_state, bytertc::MediaDeviceError device_error) override;
	void onAudioDeviceStateChanged(const char* device_id, bytertc::RTCAudioDeviceType device_type,
		bytertc::MediaDeviceState device_state, bytertc::MediaDeviceError device_error) override;
	void onVideoDeviceStateChanged(const char* device_id, bytertc::RTCVideoDeviceType device_type,
		bytertc::MediaDeviceState device_state, bytertc::MediaDeviceError device_error) override;
	void onMediaDeviceWarning(const char* device_id, bytertc::MediaDeviceType device_type,
		bytertc::MediaDeviceWarning device_warning) override;
	void onAudioDeviceWarning(const char* device_id, bytertc::RTCAudioDeviceType device_type,
		bytertc::MediaDeviceWarning device_warning) override;
	void onVideoDeviceWarning(const char* device_id, bytertc::RTCVideoDeviceType device_type,
		bytertc::MediaDeviceWarning device_warning) override;
	void onSysStats(const bytertc::SysStats& stats) override;
	void onCreateRoomStateChanged(const char* room_id, int error_code) override;
	void onHttpProxyState(int state) override;
	void onHttpsProxyState(int state) override;
	void onSocks5ProxyState(int state, const char* cmd,
		const char* proxy_address, const char* local_address, const char* remote_address) override;
	void onRecordingStateUpdate(bytertc::StreamIndex type, bytertc::RecordingState state,
		bytertc::RecordingErrorCode error_code, bytertc::RecordingInfo info) override;
	void onRecordingProgressUpdate(bytertc::StreamIndex type, bytertc::RecordingProgress process,
		bytertc::RecordingInfo info) override;
	void onLoginResult(const char* user_id, int error_code, int elapsed) override;
	void onLogout() override;
	void onServerParamsSetResult(int error) override;
	void onGetPeerOnlineStatus(const char* peer_user_id, int status) override;
	void onUserMessageReceivedOutsideRoom(const char* user_id, const char* message) override;
	void onUserBinaryMessageReceivedOutsideRoom(const char* user_id, int size, const uint8_t* message) override;
	void onUserMessageSendResultOutsideRoom(int64_t msgid, int error) override;
	void onServerMessageSendResult(int64_t msgid, int error, const bytertc::ServerACKMsg& msg) override;
	void onSEIMessageReceived(bytertc::RemoteStreamKey stream_key, const uint8_t* message, int length) override;
	void onSEIStreamUpdate(const  bytertc::RemoteStreamKey& key, bytertc::SEIStreamEventType type) override;
	void onRemoteAudioPropertiesReport(const  bytertc::RemoteAudioPropertiesInfo* audio_properties_infos,
		int audio_properties_info_number, int total_remote_volume) override;
	void onLocalAudioPropertiesReport(const  bytertc::LocalAudioPropertiesInfo* audio_properties_infos, int audio_properties_info_number) override;
	void onAudioPlaybackDeviceTestVolume(int volume) override;
	void onLocalAudioStateChanged(bytertc::LocalAudioStreamState state, bytertc::LocalAudioStreamError error) override;
	void onUserStartAudioCapture(const char* room_id, const char* user_id) override;
	void onUserStopAudioCapture(const char* room_id, const char* user_id) override;
	void onActiveSpeaker(const char* room_id, const char* F) override;
	void onStreamSyncInfoReceived(bytertc::RemoteStreamKey stream_key, bytertc::SyncInfoStreamType stream_type,
		const uint8_t* data, int32_t length) override;
	void onNetworkDetectionResult(bytertc::NetworkDetectionLinkType type, bytertc::NetworkQuality quality, int rtt, double lost_rate,
		int bitrate, int jitter) override;
	void onNetworkDetectionStopped(bytertc::NetworkDetectionStopReason reason) override;
	void onPlayPublicStreamResult(const char* public_stream_id, int errorCode) override;
	void onPublicStreamSEIMessageReceived(const char* public_stream_id, const uint8_t* message, int message_length) override;
	void onFirstPublicStreamVideoFrameDecoded(const char* public_stream_id, const  bytertc::VideoFrameInfo& info) override;
	void onUserStartVideoCapture(const char* room_id, const char* user_id) override;
	void onUserStopVideoCapture(const char* room_id, const char* user_id) override;
	void onLocalVideoSizeChanged(bytertc::StreamIndex index, const  bytertc::VideoFrameInfo& info) override;
	void onRemoteVideoSizeChanged(bytertc::RemoteStreamKey key, const  bytertc::VideoFrameInfo& info) override;
	void onFirstLocalVideoFrameCaptured(bytertc::StreamIndex index, bytertc::VideoFrameInfo info) override;
	void onUserMuteAudio(const char* room_id, const char* user_id, bytertc::MuteState mute_state) override;
	void onFirstRemoteAudioFrame(const  bytertc::RemoteStreamKey& key) override;
	void onUserMuteVideo(const char* room_id, const char* user_id, bytertc::MuteState mute) override;
	void onRemoteAudioStateChanged(const  bytertc::RemoteStreamKey& key, bytertc::RemoteAudioState state,
		bytertc::RemoteAudioStateChangeReason reason) override;
	void onLocalVideoStateChanged(bytertc::StreamIndex index, bytertc::LocalVideoStreamState state,
		bytertc::LocalVideoStreamError error) override;
	void onRemoteVideoStateChanged(bytertc::RemoteStreamKey key, bytertc::RemoteVideoState state, bytertc::RemoteVideoStateChangeReason reason) override;
	void onAudioFrameSendStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFrameSendState state) override;
	void onVideoFrameSendStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFrameSendState state) override;
	void onFirstRemoteVideoFrameRendered(const bytertc::RemoteStreamKey key, const bytertc::VideoFrameInfo& info) override;
	void onFirstRemoteVideoFrameDecoded(const bytertc::RemoteStreamKey key, const bytertc::VideoFrameInfo& info) override;
	void onScreenVideoFrameSendStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFrameSendState state) override;
	void onAudioFramePlayStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFramePlayState state) override;
	void onVideoFramePlayStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFramePlayState state) override;
	void onScreenVideoFramePlayStateChanged(const char* room_id, const bytertc::RtcUser& user, bytertc::FirstFramePlayState state) override;
	void onFirstLocalAudioFrame(bytertc::StreamIndex index) override;
	void onPushPublicStreamResult(const char* room_id, const char* public_streamid, int errorCode) override;
	void onFirstPublicStreamAudioFrame(const char* public_stream_id) override;
	void onCloudProxyConnected(int interval) override;
	void onEchoTestResult(bytertc::EchoTestResult result) override;
private:
	ByteEventCallback _callback{};
};
