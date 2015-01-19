#ifndef TASK_WORKER_THREAD_H
#define TASK_WORKER_THREAD_H

#include "task.h"
#include "task_queue.h"

#include <thread>
#include <future>
#include <mutex>

class TaskWorker
{
public:
    typedef std::shared_ptr<TaskWorker> Ptr;

    TaskWorker(TaskQueue &task_queue);
    virtual ~TaskWorker();

    void      done();
    void      interrupt();

private:
    std::mutex  task_mutex_;
    Task::Ptr   task_;
    TaskQueue  &task_queue_;

    std::mutex  interruption_mutex_;
    bool        interruption_request_;
    std::thread thread_;

    void run();

};

#endif // TASK_WORKER_THREAD_H
