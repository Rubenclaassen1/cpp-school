#include <iostream>
#include "Course.h"

Course::Course(const std::string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new std::string[capacity];
}

Course::Course(const Course& course) {
	numberOfStudents = course.getNumberOfStudents();
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	//this->students = course.students;
	this->students = new std::string[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {
	if (numberOfStudents < capacity) {
		students[numberOfStudents] = name;
		numberOfStudents++;
	}
	else {

		capacity++;

		previousStudents = students;
		students = new std::string[capacity];
		for (int i = 0; i < numberOfStudents; i++) {
			students[i] = previousStudents[i];
		}
		students[numberOfStudents] = name;
		std::cout << "capacity increased" << std::endl;
		numberOfStudents++;
		delete[] previousStudents;
	}

}

void Course::dropStudent(const std::string& name) {
	int index = -1;

	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i] == name) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		std::string* newStudents = new std::string[capacity];
		for (int i = 0; i < index; i++) {
			newStudents[i] = students[i];
		}

		for (int i = index + 1; i < numberOfStudents; i++) {
			newStudents[i - 1] = students[i];
		}
		delete[] students;

		students = newStudents;
		numberOfStudents--;


		std::cout << "Student " << name << " has been removed" << std::endl;

	}
	else {
		std::cout << "Student " << name << " is not in this course" << std::endl;
	}


}

void Course::clear() {
	delete[] students;
	students = new std::string[capacity];
	numberOfStudents = 0;
	std::cout << "course has been cleared" << std::endl;
}

std::string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}