#ifndef CHANGE_THIS_H
#define CHANGE_THIS_H

#include <string>

struct Course;
struct Student;

template <typename type>
struct Node{
    type val;
    Node* next;
};

template <typename type>
struct List{
    Node<type>* head = nullptr;
    Node<type>* tail = nullptr;
};

struct Course{
    std::string name;
    List<Student> students;
};

struct Student{
    std::string name;
    List<Course> courses;
};

#endif