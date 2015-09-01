//
// Created by Moki on 2015/9/1.
//

#ifndef DAEMON_PUSH_PROCESS_H
#define DAEMON_PUSH_PROCESS_H

class CPushProcess{
public:

    CPushProcess() { }

    virtual ~CPushProcess() { }

    int create_child();

    void on_child_dead();

    void catch_child_dead_signal();
};


#endif //DAEMON_PUSH_PROCESS_H
