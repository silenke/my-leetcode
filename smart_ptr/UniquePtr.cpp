// std::unique_ptr
// https://www.cplusplus.com/reference/memory/unique_ptr/

#include <utility>

template <typename T>
class UniquePtr {
public:
	explicit UniquePtr(T* ptr = nullptr) noexcept : ptr_(ptr) {}

	UniquePtr(UniquePtr&& rhs) noexcept : ptr_(rhs.release()) {}

	UniquePtr& operator=(UniquePtr&& rhs) noexcept {
		if (this != &rhs) reset(rhs.release());
		return *this;
	}

	void swap(UniquePtr& rhs) noexcept {
		std::swap(ptr_, rhs.ptr_);
	}

	~UniquePtr() noexcept {
		if (ptr_) delete ptr_;
	}

	T& operator*() const noexcept { return *ptr_; }
	T* operator->() const noexcept { return ptr_; }
	T* get() const noexcept { return ptr_; }
	operator bool() const noexcept { return static_cast<bool>(ptr_); }

	T* release() noexcept {
		return std::exchange(ptr_, nullptr);
	}

	void reset(T* ptr = nullptr) noexcept {
		T* old = std::exchange(ptr_, ptr);
		if (old) delete old;
	}

	UniquePtr(const UniquePtr& rhs) = delete;
	UniquePtr& operator=(const UniquePtr& rhs) = delete;

private:
	T* ptr_;
};
