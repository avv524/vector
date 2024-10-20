#include <iostream>
#include <string>


template<typename T>
class vector{
private:
    T* data;
    int size_;
public:
    vector() : data(nullptr), size_(0) {}
    ~vector() {delete[] data;}

    int size() const {return size_;}

    void push_back(const T& inputData){
        T* data2 = new T[size_ + 1];
        for (int i = 0; i<size_;++i)
            data2[i] = data[i];
        data2[size_] = inputData;
        delete[] data;
        data = data2;
        ++size_;
    }

    void pop_back(){
        --size_;
        T* data2 = new T[size_];
        for (int i = 0; i<size_;++i)
            data2[i] = data[i];
        delete data;
        data = data2;
    }

    T& operator[](int index){
        if(index >= size_ || index < 0){
            throw std::out_of_range("out of range");
        }
        return data[index];
    }
};
int main(){
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(100);
    std::cout << "vector after some push_backs: ";
    for(int i = 0; i< arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout <<"vector size is: "<< arr.size()<< std::endl;
    arr.pop_back();
    std::cout<<"vector after pop_back: ";
    for(int i = 0; i< arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout<<std::endl;
    std::cout <<"vector size is: "<< arr.size()<<std::endl;
    vector<std::string> arr2;
    arr2.push_back("HSE");
    arr2.push_back("university");
    std::cout << "string vector is: ";
    for(int i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    std::cout<<std::endl;
    std::cout <<"vector size is: "<< arr2.size()<<std::endl;
    return 0;
}
