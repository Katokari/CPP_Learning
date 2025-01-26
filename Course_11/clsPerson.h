#pragma once
#include <iostream>

class clsPerson {
    private:
    int _id;
    std::string _firstName;
    std::string _lastName;
    std::string _email;
    std::string _phone;

    public:
    clsPerson() {}

    clsPerson(int id, std::string firstName, std::string lastName, std::string email, std::string phone) {
        _id = id;
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }

    int getId() {
        return _id;
    }

    void setFirstName(std::string firstName) {
        _firstName = firstName;
    }

    std::string getFirstName() {
        return _firstName;
    }

    void setLasttName(std::string lastName) {
        _lastName = lastName;
    }

    std::string getLastName() {
        return _lastName;
    }

    void setEmail(std::string email) {
        _email = email;
    }

    std::string getEmail() {
        return _email;
    }

    void setPhone(std::string phone) {
        _phone = phone;
    }

    std::string getPhone() {
        return _phone;
    }

    std::string getFullName() {
        return _firstName + " " + _lastName;
    }

    void print() {
        std::cout << "\nInfo:\n";
        std::cout << "\n______________________\n";
        std::cout << "ID       : " << _id << "\n";
        std::cout << "FirstName: " << _firstName << "\n";
        std::cout << "LastName : " << _lastName << "\n";
        std::cout << "FullName : " << getFullName() << "\n";
        std::cout << "Email    : " << _email << "\n";
        std::cout << "Phone    : " << _phone << "\n";
        std::cout << "\n______________________\n";
    }

    void sendEmail(std::string subject, std::string body) {
        std::cout << "\n";
        std::cout << "The following message sent successfully to email: " << _email << "\n";
        std::cout << "Subject: " << subject << "\n";
        std::cout << "Body: " << body << "\n";
    }
    
    void sendSMS(std::string body) {
        std::cout << "\n";
        std::cout << "The following SMS sent successfully to phone: " << _phone << "\n";
        std::cout << body << "\n";
    }
};