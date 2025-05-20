// Copyright 2023, Bradley Peterson, Weber State University, All rights reserved.

#include <iostream>
#include <map>
#include <algorithm>
#include <list>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include <cctype>

template <typename T> class DoublyLinkedList;

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::stringstream;
using std::iter_swap;
using std::vector;

//******************
// The Node class
//******************
template <typename T>
class Node {
public:
    T data{};
    Node<T>* prev{
        nullptr
    };
    Node<T>* next{
        nullptr
    };
};

//******************
// The Iterator class
//******************
template <typename T>
class Iterator {
    friend class DoublyLinkedList<T>;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using pointer = T*;
    using reference = T&;

    T& operator*() {
        return curr->data;
    }

    Iterator& operator++() {
        if (!pastTheEnd) {
            if (curr->next == nullptr) {
                pastTheEnd = true;
            } else {
                curr = curr->next;
            }
        }
        return *this;
    }

    Iterator operator++(int) {
        auto temp = *this;
        ++(*this);
        return temp;
    }

    Iterator& operator--() {
        if (pastTheEnd) {
            pastTheEnd = false;
        } else if (curr->prev != nullptr) {
            curr = curr->prev;
        }
        return *this;
    }

    Iterator operator--(int) {
        auto temp = *this;
        --(*this);
        return temp;
    }

    bool operator!=(const Iterator& other) const {
        return curr != other.curr || pastTheEnd != other.pastTheEnd;
    }

    bool operator==(const Iterator& other) const {
        return curr == other.curr && pastTheEnd == other.pastTheEnd;
    }
private:
    Node<T>* curr{ nullptr };
    bool pastTheEnd{ false };
};
//****************************
// The DoublyLinkedList class
//****************************
template <typename T>
class DoublyLinkedList {

public:

    //public members of the DoublyLinkedList class
    DoublyLinkedList() {}
    ~DoublyLinkedList();

    void pushFront(const T&);
    void pushBack(const T&);

    Iterator<T> begin() {
        Iterator<T> it;
        it.curr = first;
        it.pastTheEnd = (first == nullptr);
        return it;
    }

    Iterator<T> end() {
        Iterator<T> it;
        it.curr = last;
        it.pastTheEnd = true;
        return it;
    }

protected:

    Node<T>* first{ nullptr };
    Node<T>* last{ nullptr };

};

template <typename T>// destructor
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* temp = this->first;

    while (first) {
        first = first->next;
        delete temp;
        temp = first;
    }
}

template <typename T>
void DoublyLinkedList<T>::pushFront(const T& item) {
    Node<T>* temp = new Node<T>();

    temp->data = item;
    if (!first) {
        // Scenario: List is empty
        last = temp;
    }
    else {
        first->prev = temp;
        temp->next = first;
    }
    first = temp;
}

template <typename T>
void DoublyLinkedList<T>::pushBack(const T& item) {
    Node<T>* temp = new Node<T>();

    temp->data = item;
    if (!first) {
        // Scenario: List is empty
        first = temp;
    }
    else {
        last->next = temp;
        temp->prev = last;
    }
    last = temp;
}

//***********************************
template <typename T>
void assignmentReverse(T begin, T end) {
    if (begin == end) return;
    --end;  // Get the container off its past-the-end state so its "pointing" at the last value in the container.

    while (begin != end) {
        iter_swap(begin, end);
        ++begin;
        if (begin == end) {
            break;
        }
        --end;
    }
}

void loadOnlyPalindromes(DoublyLinkedList<string>& wordsToFilter, vector<string>& output) {
    auto newEndIter = std::copy_if(wordsToFilter.begin(),
                                   wordsToFilter.end(),
                                   output.begin(),
                                   [](const string& str) {
                                       string temp = str;
                                       temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c) {
                                           return std::isspace(c) || std::ispunct(c);
                                       }), temp.end());
                                       std::transform(temp.begin(), temp.end(), temp.begin(), [](char c) {
                                           return std::tolower(c);
                                       });
                                       string reversed = temp;
                                       std::reverse(reversed.begin(), reversed.end());
                                       return temp == reversed;
                                   });

    output.resize(std::distance(output.begin(), newEndIter));  // Shrink output to new size
}

