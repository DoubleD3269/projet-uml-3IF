#ifndef GOVAGENT_H
#define GOVAGENT_H
#include "User.h"
#include <stdlib.h>
#include <string>

// Class representing a GovAgent inheriting from User
class GovAgent : public User{

    public:
        // Constructor - initializes a new GovAgent object
        GovAgent();

        // Destructor - cleans up GovAgent object resources
        ~GovAgent();

    private:
        // ID of the Governement Agency
        std::string agencyId;
};

#endif