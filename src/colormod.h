#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_MAGENTA  = 35,
        FG_CYAN     = 36,
        RED         = 91,
        GREEN       = 92,
        YELLOW      = 93,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_YELLOW   = 43,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

Color::Modifier one(Color::FG_RED);
Color::Modifier two(Color::FG_GREEN);
Color::Modifier three(Color::FG_YELLOW);
Color::Modifier four(Color::FG_BLUE);
Color::Modifier five(Color::FG_MAGENTA);
Color::Modifier six(Color::FG_CYAN);
Color::Modifier seven(Color::RED);
Color::Modifier eight(Color::GREEN);
Color::Modifier nine(Color::YELLOW);
Color::Modifier ten(Color::FG_RED);
Color::Modifier red(Color::FG_RED);
Color::Modifier deff(Color::FG_DEFAULT);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier defb(Color::BG_DEFAULT);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier magenta(Color::FG_MAGENTA);