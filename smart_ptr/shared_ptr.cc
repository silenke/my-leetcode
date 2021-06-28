#include "..\..\leetcode.h"

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class SharedPtr {
public:
	SharedPtr() : pT_(nullptr), pC_(nullptr) {
	
		print();
	}

	SharedPtr(T* pT) : pT_(pT), pC_(pT_ ? new int(1): nullptr) {
	
		print();
	}

	SharedPtr(const SharedPtr& rhs) {
	
		if (this == &rhs) return;

		pT_ = rhs.pT_;
		pC_ = rhs.pC_;
		if (pC_) (*pC_)++;

		print();
	}

	SharedPtr& operator=(const SharedPtr& rhs) {
		
		if (this == &rhs) return *this;

		release();
		pT_ = rhs.pT_;
		pC_ = rhs.pC_;
		if (pC_) (*pC_)++;

		print();
		return *this;
	}

	~SharedPtr() {
		
		release();
		print();
	}

	T* get() {

		return pT_;
	}

	int count() {

		return pC_ ? *pC_ : 0;
	}

private:
	T* pT_;
	int* pC_;

	void release() {

		if (!pT_) return;

		if (--(*pC_) == 0) {
			delete pT_;
			pT_ = nullptr;
			delete pC_;
			pC_ = nullptr;
		}
	}

	void print() {

		cout << get() << " " << count() << endl;
	}
};

template<typename T>
void test(T* pT) {

	SharedPtr<int> sp1(pT);
	SharedPtr<int> sp2(sp1);
	SharedPtr<int> sp3;
	sp3 = sp2;
}

int main() {

    test<int>(nullptr);
    cout << endl;
	test<int>(new int(1024));

	return 0;
}
