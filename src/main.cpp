#include <iostream>
#include <zmq.h>

int main(int argc, char** argv)
{
    void* context = zmq_ctx_new();
    void* responder = zmq_socket(context, ZMQ_REP);
    zmq_bind(responder, "tcp://*:5557");
    int ret = 0;
    while (1)
    {
        try
        {
            char szBuffer[1024] {0};
            ret = zmq_recv(responder, szBuffer, 1023, 0);
            szBuffer[ret] = '\0';
            zmq_send(responder, const_cast<char*>("reply"), 5, 0);
            printf("recv msg %s\n",szBuffer);
        }
        catch(const std::exception&)
        {

        }
    }
    return 0;
}
