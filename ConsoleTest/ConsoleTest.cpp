// ConsoleTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "bytertc_video.h"
#include "bytertc_room_event_handler.h"
#include "bytertc_video_event_handler.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

std::string readLine(const std::string& tip = "") {
    std::cout << tip << std::endl;
	std::string line;
	std::getline(std::cin, line);
    return line;
}

class Demo : public bytertc::IRTCVideoEventHandler
    , public bytertc::IRTCRoomEventHandler
{
public:
    void onConnectionStateChanged(bytertc::ConnectionState state) override {
        printf(__FUNCTION__ " state:%d\n", state);
    }

	void onLocalVideoStateChanged(bytertc::StreamIndex index, bytertc::LocalVideoStreamState state, bytertc::LocalVideoStreamError error) override {
		printf(__FUNCTION__ " index:%d, state:%d, error:%d\n", index, state, error);
    }

    void onRoomError(int error) override {
		printf(__FUNCTION__ " error:%d\n", error);
    }

	void onRoomWarning(int warn) override {
		printf(__FUNCTION__ " warn:%d\n", warn);
	}

    void onRoomStats(const bytertc::RtcRoomStats& stats) override {
		printf(__FUNCTION__ " \n");
    }

	void onUserJoined(const bytertc::UserInfo& user_info, int elapsed) override {
		printf(__FUNCTION__ " user_id:%s\n", user_info.uid);
	}

	void onUserLeave(const char* user_id, bytertc::UserOfflineReason reason) override {
		printf(__FUNCTION__ " user_id:%s\n", user_id);
	}

    void test() {
        const char* appId = "62e52104c0700a038dd110cc";
        const char* roomId = "sdktest";
        const char* userId = "yks1";
        const char* token = "00162e52104c0700a038dd110ccQQCeaqwFI9f0YqMR/mIHAHNka3Rlc3QEAHlrczEGAAAAoxH+YgEAoxH+YgIAoxH+YgMAoxH+YgQAoxH+YgUAoxH+YiAAQUQ/j0j81ufAWBUS6DlR5u5Nn1kkIlbXtURq12s3rgI=";

        bytertc::IRTCVideo* pRtcVideo = createRTCVideo(appId, this, nullptr);
		std::this_thread::sleep_for(std::chrono::seconds(1));
        pRtcVideo->startAudioCapture();
        bytertc::IVideoDeviceManager* pVdm = pRtcVideo->getVideoDeviceManager();
        if (pVdm) {
			bytertc::IVideoDeviceCollection* pVdc = pVdm->enumerateVideoCaptureDevices();
            if (pVdc) {
                int count = pVdc->getCount();
                if (count > 1) {
                    bytertc::VideoDeviceInfo vdi;
                    int ret = pVdc->getDevice(1, &vdi);
                    if (ret == 0) {
                        ret = pVdm->setVideoCaptureDevice(vdi.device_id);
                        printf("setVideoCaptureDevice %s, returns %d \n", vdi.device_id, ret);
                    }
                }
                pVdc->release();
            }
        }
        pRtcVideo->startVideoCapture();
        bytertc::IRTCRoom* pRtcRoom  = pRtcVideo->createRTCRoom(roomId);
        pRtcRoom->setRTCRoomEventHandler(this);
        bytertc::UserInfo userInfo;
        userInfo.uid = userId;
        userInfo.extra_info = nullptr;
        bytertc::RTCRoomConfig roomConfig;
        roomConfig.is_auto_publish = true;
        roomConfig.is_auto_subscribe_audio = true;
        roomConfig.is_auto_subscribe_video = true;
        roomConfig.room_profile_type = bytertc::kRoomProfileTypeCommunication;
        int ret = pRtcRoom->joinRoom(token, userInfo, roomConfig);
        printf("joinRoom returns %d \n", ret);

        readLine("paused");
        pRtcRoom->leaveRoom();
		readLine("paused");
        pRtcRoom->destroy();
        pRtcRoom = nullptr;
        bytertc::destroyRTCVideo();
        pRtcVideo = nullptr;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Demo demo;
    demo.test();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
