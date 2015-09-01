//
// Created by Moki on 2015/9/1.
//

#include "push_process.h"
#include "daemon_process.h"
#include <sys/types.h>
#include <unistd.h>
#include <android/log.h>
#include <sys/wait.h>

extern CPushProcess *pushProcess;
int CPushProcess::create_child() {
    pid_t pid = fork();
    if (pid < 0){
        return -1;
    } else if (pid == 0){
        CDaemonProcess *daemonProcess = new CDaemonProcess();
        daemonProcess -> work();
        __android_log_print(ANDROID_LOG_FATAL, "Daemon", "child do");
        return pid;
    } else if (pid > 0){
        __android_log_print(ANDROID_LOG_FATAL, "Daemon", "parent do:%d", pid);
        pushProcess -> catch_child_dead_signal();
        return pid;
    }
    return -1;
}

void CPushProcess::on_child_dead() {
    create_child();
}

void handle_signal(int sig_no){
    __android_log_print(ANDROID_LOG_FATAL, "Daemon", "handle");
    pid_t pid;
    int status;
    pid = wait(&status);

    if (pushProcess != NULL){
        pushProcess -> on_child_dead();
    }
}

void CPushProcess::catch_child_dead_signal() {
    __android_log_print(ANDROID_LOG_FATAL, "daemon", "catch");
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handle_signal;
    sigaction(SIGCHLD, &sa, NULL);
}

