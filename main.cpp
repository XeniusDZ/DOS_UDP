#include <iostream>
#include "GUI.h"
#include "udp.cpp"

/**
 * compiling project
 *
 */
int main() {
    DOSATTACKER app(0); /** Creating GUI object **/
    app.show(); /** Showing the GUI **/

    app.Attack.events().click([&app]{  /** event when clicking on button**/

        auto IP = app.textbox1.text();

        if(isIPv4(IP)){
            udp_attack(IP); /** calling function **/
            app.textbox1.select(true);
            app.textbox1.del();
            app.textbox1.append("Attack done successfully", true);
        }else{
            app.textbox1.select(true);
            app.textbox1.del();
            app.textbox1.append("Failed", true);}

    });
    nana::exec(); /** executing GUI **/
    return 0;
}
