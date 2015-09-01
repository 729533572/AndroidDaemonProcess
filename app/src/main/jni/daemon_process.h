//
// Created by Moki on 2015/9/1.
//

#ifndef DAEMON_DAEMON_PROCESS_H
#define DAEMON_DAEMON_PROCESS_H
class CDaemonProcess{
public:

    CDaemonProcess() {
        RTN_MAP.member_rtn = &CDaemonProcess::on_parent_listener;
    }

    virtual ~CDaemonProcess() { }

    void work();

    void *on_parent_listener();

    void restart_parent();

    union
    {
        void* (*thread_rtn)(void*);
        void* (CDaemonProcess::*member_rtn)();
    } RTN_MAP;
};

#endif //DAEMON_DAEMON_PROCESS_H
