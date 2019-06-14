#include <stdio.h>
#include "Include/runtimechangeshandler.h"
#include "Include/subscriber.h"
#include "msg/dispatcherImpl.h"

/* error1: unknown type name ‘namespace’
 *         error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘{’ token
 * It sounds like trying to compile C++ code with a C compiler.
 * Trying using g++ instead of gcc and giving file a C++ extension such as .cpp (rather than .c).
*/

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    auto dispatcher = std::make_unique<msg::DispatcherImpl>();

    std::shared_ptr<subscribeApi::SharedSubscribeApi> shareDb =
            std::make_shared<subscribeApi::SharedSubscribeApiImp>();
    std::unique_ptr<runtimeView::RuntimeChangesHandler> runtimeMoChangesHandler =
            std::make_unique<runtimeView::RuntimeChangesHandler>(shareDb);

    runtimeMoChangesHandler->subscribe();

    //notify canbe wrapped again by message dispatcher(addReceiver, dispatch)
    dispatcher->addReceiver(
                std::make_unique<subscribeApi::SharedDbNotificationHandlerWrapper>(
                    std::move(shareDb)));
    //std::shared_ptr<subscribeApi::ShareDbNotificationHandler> notify =
    //        std::make_shared<subscribeApi::SharedDbNotificationHandlerWrapper>(shareDb);

    //notify->handle(1);
    //notify->handle(2);
    //notify->handle(3);
    dispatcher->dispatch(Notify_MSG);

    return 0;
}
