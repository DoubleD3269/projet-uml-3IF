#ifndef USER_H
#define USER_H
#include <stdlib.h>
#include <string>

// Class representing a user with authentication capabilities
class User{

    public:
        // Authenticates the user by verifying email and password
        bool authenticateUser();

        // Constructor - initializes a new User object
        User();

        // Destructor - cleans up User object resources
        ~User();

    private:
        // User's email address
        std::string email;
        // User's password for authentication
        std::string password;
};

#endif