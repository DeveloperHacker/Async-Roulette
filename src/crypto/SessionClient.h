#pragma once

#include "../tcp/TransferClient.h"
#include "Session.h"

class CryptoClient : public TransferClient {
public:
    enum State {
        INIT,
        WAIT,
        READY
    };

private:
    Session session;
    State state;

public:
    CryptoClient(std::shared_ptr<Socket> socket);

    void send(const char *message) override;

    void send(const std::string &message) override;

    void raw_send(const char *message);

    void raw_send(const std::string &message);

protected:
    virtual void crypto_output() = 0;

    virtual void crypto_input(const std::string &message) = 0;

    void output() override;

    void input(const std::string &message) override;
};
