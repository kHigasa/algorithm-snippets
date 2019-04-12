template<typename T>
class my_vector {
    private:
        T* data;
        size_t size;
        size_t capacity;

    public:
        my_vector() : data(nullptr), size(0), capacity(0) {}
        ~my_vector() { delete[] data; }

        size_t size() const { return size; }
        size_t capacity() const { return capacity; }
        void clear() { size = 0; }

        void reserve(size_t n) {
            if (n > capacity) {
                capacity = n;
                T* new_data = new T[capacity];
                T* old_data = data;
                for (size_t i = 0; i < size; ++i) {
                    new_data[i] = old_data[i];
                }
                data = new_data;
                delete[] old_data;
            }
        }

        void push_back(const T& item) {
            if (size == capacity) {
                reserve(capacity == 0 ? 1 : capacity * 2);
            }
            data[size++] = item;
        }
}

