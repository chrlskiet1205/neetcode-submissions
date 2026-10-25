class DynamicArray {
public:

    // member functions
    int capacity = 0;
    int size = 0;
    int* data;

    DynamicArray(int capacity) {
        if (capacity > 0){
            data = new int[capacity];
            this->capacity = capacity;
        }
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        if (i < capacity){
            data[i] = n;
        }
    }

    void pushback(int n) {
        // resize if needed
        if (this->capacity == this->size){
            resize();
        }

        this->data[size] = n;
        (this->size)++;
    }

    int popback() {
        int deleted = this->data[(this->size)-1];
        // delete this->data[(this->size)-1];
        (this->size)--;
        return deleted;
    }

    void resize() {
        int* temp = new int[(this->capacity)*2];
        for (int i = 0; i < this->size; i++){
            temp[i] = data[i];
        }
        delete[] this->data;
        this->data = temp;
        
        this->capacity *= 2;
    }

    int getSize() {
        return (this->size);
    }

    int getCapacity() {
        return this->capacity;
    }
};
