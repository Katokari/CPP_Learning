#include <iostream>
#include <string>

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

class clsEmbloyee : public clsPerson {
    private:
    std::string _title;
    float _salary;
    std::string _department;

    public:
    clsEmbloyee(int id, std::string firstName, std::string lastName, std::string email, std::string phone
    , std::string title, std::string department, float salary) : clsPerson (id, firstName, lastName, email, phone)
    {
        _title = title;
        _department = department;
        _salary = salary;
    }

    //title property
    void setTitle(std::string title) {
        _title = title;
    }

    std::string getTitle() {
        return _title;
    }

    //salary property
    void setSalary(float salary) {
        _salary = salary;
    }

    float getSalary() {
        return _salary;
    }

    //department property
    void setDepartment(std::string department) {
        _department = department;
    }

    std::string getDepartment() {
        return _department;
    }

    void print() {
        std::cout << "\nInfo:\n";
        std::cout << "\n______________________\n";
        std::cout << "ID        : " << getId() << "\n";
        std::cout << "First Name: " << getFirstName() << "\n";
        std::cout << "Last Name : " << getLastName() << "\n";
        std::cout << "Full Name : " << getFullName() << "\n";
        std::cout << "Email     : " << getEmail() << "\n";
        std::cout << "Phone     : " << getPhone() << "\n";
        std::cout << "Salary    : " << _salary << "\n";
        std::cout << "Title     : " << _title << "\n";
        std::cout << "Department: " << _department << "\n";
        std::cout << "\n______________________\n";
    }
};

int main() {
    clsEmbloyee Embloyee(1, "Kato", "Meow", "kato@gmail.com", "0949137022", "Developer", "Game Dev", 2000);
    Embloyee.print();
    Embloyee.sendEmail("Hi", "How are you?");
    Embloyee.sendSMS("How are you?");

    return 0;
}