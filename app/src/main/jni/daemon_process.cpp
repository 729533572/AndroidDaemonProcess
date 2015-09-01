//
// Created by Moki on 2015/9/1.
//

#include <android/log.h>
#include "daemon_process.h"
#include <pthread.h>
#include <unistd.h>

void CDaemonProcess::work() {
    __android_log_print(ANDROID_LOG_FATAL, "daemon", "child work");
    pthread_t thread;
    int res;
    res = pthread_create(&thread, NULL, RTN_MAP.thread_rtn, this);
    __android_log_print(ANDROID_LOG_FATAL, "daemon", "%d", res);
}

void *CDaemonProcess::on_parent_listener() {
    while (getppid() != 1){
        usleep(50);
    }
    restart_parent();
    return NULL;
}

void CDaemonProcess::restart_parent() {
    __android_log_print(ANDROID_LOG_FATAL, "daemon", "restart");
    //在这里使用execp启动android service，稍后完善。
}