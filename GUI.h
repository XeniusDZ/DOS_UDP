#ifndef DOSATTACKER_H
#define DOSATTACKER_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/button.hpp>

class DOSATTACKER
        : public nana::form
{
public:
    nana::place place_;
    nana::label DOS;
    nana::textbox textbox1;
    nana::button Attack;
    DOSATTACKER(nana::window wd, const ::nana::size& sz = {480, 480}, const nana::appearance& apr = {true, true, false, false, false, false, false})
            : nana::form(wd, sz, apr)
    {
        init_();

        //<*ctor

        //*>
    }

    ~DOSATTACKER()
    {
        //<*dtor

        //*>
    }


private:
    void init_()
    {
        place_.bind(*this);
        place_.div("vert margin=[100,100,100,100] gap=100 _field_");
        caption("Form");
        // DOS ATTACKER
        DOS.create(*this);
        place_["_field_"] << DOS;
        DOS.typeface(nana::paint::font("", 9, {10000, false, false, false}));
        DOS.caption("DOS ATTACKER");
        DOS.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(0));
        // textbox1
        textbox1.create(*this);
        place_["_field_"] << textbox1;
        textbox1.typeface(nana::paint::font("", 10, {400, false, false, false}));
        textbox1.tip_string("Input IP Address");
        // Attack
        Attack.create(*this);
        place_["_field_"] << Attack;
        Attack.caption("Attack");

        place_.collocate();
    }




    //<*declarations

    //*>
};

#endif //DOSATTACKER_H