class mainServer {
    public:
        mainServer();
        bool send(std::string& message, u_16int port);
        void receive(std::string& message);
        void close();
}
