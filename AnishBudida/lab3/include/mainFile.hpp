class mainServer {
    public:
        mainServer();
        bool send(const std::String& message, u_16int port);
        void receive(std::string& message);
        void close();
}
