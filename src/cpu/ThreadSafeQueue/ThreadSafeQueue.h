#ifndef AMD_APPLAG_THREADSAFEQUEUE_H
#define AMD_APPLAG_THREADSAFEQUEUE_H

#include <queue>
#include <mutex>
#include <optional>
#include "Utils.h"

template<typename T>
class ThreadSafeQueue {
public:
    void push(const T& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(value);
    }

    void push(T&& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(std::move(value));
    }

    std::optional<T> pop() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) return std::nullopt;
        T value = std::move(queue_.front());
        queue_.pop();
        return value;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }

private:
    std::queue<T>      queue_;
    mutable std::mutex mutex_;
};

typedef std::shared_ptr<ThreadSafeQueue<std::string>> StringThreadSafeQueuePtr;
typedef std::shared_ptr<ThreadSafeQueue<Message>> MessageThreadSafeQueuePtr;

#endif //AMD_APPLAG_THREADSAFEQUEUE_H