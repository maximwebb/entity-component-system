class TestEvent {
    const std::string& msg;

    explicit TestEvent(const std::string s) : msg(std::move(s)) {};
};