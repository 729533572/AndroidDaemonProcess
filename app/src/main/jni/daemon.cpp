#include <jni.h>
#include <android/log.h>
#include <stddef.h>
#include "moki_daemon_PushService.h"
#include "push_process.h"

CPushProcess *pushProcess = NULL;
extern "C" {
    JNIEXPORT void JNICALL Java_moki_daemon_PushService_startDaemonProcess(JNIEnv *env, jclass type) {
        __android_log_print(ANDROID_LOG_FATAL, "Daemon", "Hello");
        pushProcess = new CPushProcess();
        pushProcess -> create_child();

    }
}