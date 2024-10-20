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

    vector(const vector& other){
        size_ = other.size_;
        data = new T[size_];
        for(int i = 0;i < size_;++i){
            data[i] = other.data[i];
        }
    }

    vector(vector&& other){
        size_ = other.size_;
        data = other.data;
        other.data = nullptr;
        other.size_ = 0;
    }

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
        delete[] data;
        data = data2;
    }

    T& operator[](int index){
        if(index >= size_ || index < 0){
            throw std::out_of_range("out of range");
        }
        return data[index];
    }

    vector& operator = (const vector& other){
        if(this == &other){return *this;}
        delete[] data;
        size_ = other.size_;
        data = new T(size_);
        for(int i = 0;i < size_; ++i){
            data[i] = other.data[i];
        }
        return *this;
    }

    vector& operator = (vector&& other){
        if(this == &other){return *this;}
        delete[] data;
        size_ = other.size_;
        data = other.data;
        other.data = nullptr;
        other.size_ = 0;
        return *this;
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

    vector<int> copy = arr;
    std::cout<< "copied vector is: ";
    for(int i = 0; i< copy.size(); ++i)
        std::cout << copy[i] << " ";
    std::cout<<std::endl;
    
    vector<int> copy2;
    copy2.push_back(90909);
    copy2 = arr;
    std::cout<< "copied assignment vector is: ";
    for(int i = 0; i< copy2.size(); ++i)
        std::cout << copy2[i] << " ";
    std::cout<<std::endl;

    vector<int> move = std::move(arr);
    std::cout<< "moved vector is: ";
    for(int i = 0; i< move.size(); ++i)
        std::cout << move[i] << " ";
    std::cout<<std::endl;
    std::cout<< "size of move: "<< move.size() << std::endl;
    std::cout<< "size of arr now: "<< arr.size() << std::endl;
    
    vector<int> move2;
    move2.push_back(90909);
    move2 = std::move(move);
    std::cout<< "moved assignment vector is: ";
    for(int i = 0; i< move2.size(); ++i)
        std::cout << move2[i] << " ";
    std::cout<<std::endl;
    std::cout<< "size of move2: "<< move2.size() << std::endl;
    std::cout<< "size of move now: "<< move.size() << std::endl;
    return 0;
}
