// std::shared_ptr
// https://www.cplusplus.com/reference/memory/shared_ptr/?kw=shared_ptr

#include <utility>

class Count {
public:
	void incr() noexcept { ++count_; }
	long decr() noexcept { return --count_; }
	long count() const noexcept { return count_; }

private:
	long count_ = 1;
};

template <typename T>
class SharedPtr {
public:
	explicit SharedPtr(T* ptr = nullptr) : ptr_(ptr) {
		if (ptr_) count_ = new Count;
	}

	~SharedPtr() noexcept {
		if (ptr_ && !count_->decr()) {
			delete ptr_;
			delete count_;
		}
	}

	SharedPtr(const SharedPtr& rhs) noexcept : ptr_(rhs.ptr_) {
		if (ptr_) {
			rhs.count_->incr();
			count_ = rhs.count_;
		}
	}

	SharedPtr(SharedPtr&& rhs) noexcept : ptr_(rhs.ptr_) {
		if (ptr_) {
			count_ = rhs.count_;
			rhs.ptr = nullptr;
		}
	}

	SharedPtr& operator=(SharedPtr rhs) noexcept {
		rhs.swap(*this);
		return *this;
	}

	void swap(SharedPtr& rhs) noexcept {
		using std::swap;
		swap(ptr_, rhs.ptr_);
		swap(count_, rhs.count_);
	}

	T& operator*() const noexcept { return *ptr_; }
	T* operator->() const noexcept { return ptr_; }
	T* get() const noexcept { return ptr_; }
	operator bool() const noexcept { return static_cast<bool>(ptr_); }

	void reset(T* ptr = nullptr) {
		SharedPtr(ptr).swap(*this);
	}

	bool unique() const noexcept {
		return !ptr_ || count_->count() == 1;
	}

	long count() const noexcept {
		return ptr_ ? count_->count() : 0;
	}

private:
	T* ptr_;
	Count* count_;
};
