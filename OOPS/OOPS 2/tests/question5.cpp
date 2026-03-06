
class Player {
    public:
        int score = 0;
};

Player& bad() {
    Player p;
    p.score = 50;
    return p;
}

int main() {
    // Why is this undefined behaviour even though it compiles?
    // In mordern compilers it will throw an error, because you are returning an object that you created in a function
    // which will get destoried after the function is over
}