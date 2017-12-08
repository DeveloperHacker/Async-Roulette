#pragma once

#include "../tcp/TransferServer.h"
#include "Session.h"

class SessionServer : public TransferServer {
public:
    enum State {
        INIT,
        READY
    };

private:
    std::unordered_map<id_t, std::pair<std::shared_ptr<Session>, State>> clients;

public:
    SessionServer(std::shared_ptr<Socket> socket);

    void broadcast(const char *message) override;

    void broadcast(const std::string &message) override;

    void send(id_t id, const char *message) override;

    void send(id_t id, const std::string &message) override;

    void send(const std::vector<id_t> &ids, const char *message) override;

    void send(const std::vector<id_t> &ids, const std::string &message) override;

    void raw_broadcast(const char *message);

    void raw_broadcast(const std::string &message);

    void raw_send(id_t id, const char *message);

    void raw_send(id_t id, const std::string &message);

    void raw_send(const std::vector<id_t> &ids, const char *message);

    void raw_send(const std::vector<id_t> &ids, const std::string &message);

protected:
    bool handle(id_t id, const std::string &message) override;

    void connect_handle(id_t id) override;

    void disconnect_handle(id_t id) override;

    virtual bool crypto_handle(id_t id, const std::string &message) = 0;
};
