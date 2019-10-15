
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include <stdexcept>

namespace sdds {
	template<typename T>
	class Collection {
		std::string name_;
		T* items_ = nullptr;
		size_t size_ = 0;
		void(*onItemAdded)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(std::string name) {
			name_ = name;
		}
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() {
			delete[] items_;
			items_ = nullptr;
		}
		void setObserver(void(*observer)(const Collection<T>&, const T&)) {
			onItemAdded = observer;
		}
		const std::string& name() const { return name_; }
		size_t size() const { return size_; }
		Collection& operator+=(const T& item) {
			for (auto i = 0u;i < size_;++i) {
				if (items_[i].title() == item.title()) {
					return *this;
				}
			}
			T* temp = new T[size_ + 1];
			for (auto i = 0u;i < size_;++i) {
				temp[i] = items_[i];
			}
			temp[size_] = item;
			delete[] items_;
			items_ = temp;
			size_++;

			if (onItemAdded != nullptr) {
				onItemAdded(*this, items_[size_ - 1]);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= size_) {
				std::string err = "Bad index [";
				err += std::to_string(idx);
				err += "]. Collection has [";
				err += std::to_string(size_);
				err += "] items.";
				throw std::out_of_range(err);
			}
			return items_[idx];
		}
		T* operator[](std::string title) const {
			T* check = nullptr;
			for (size_t i = 0; i < size_; ++i) {
				if (items_[i].title() == title) { 
					check = &(items_[i]);
				}
			}
			return check;
		}
		friend std::ostream& operator<<(std::ostream& os, const Collection& obj) {
			for (size_t i = 0u; i < obj.size(); i++) {
				os << obj.items_[i];
			}
			return os;
		}

	};
}

#endif
