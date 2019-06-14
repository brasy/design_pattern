#pragma once

/*
specialsubscriber-->subscribe(msgContainer, msgId)
subscriber-->subscribe(msgContainer, msgId)
msgContainer-->regist(subscriber,msgId)-->m_subscriber<msgId,subscriber>

publisher-->sendMsg(msgContainer,msg)
msgContainer-->receiveMsg(msg)-->notify(msg)-->m_subscriber<msgId,subscriber>
m_subscriber-->handleMsg(msg)
subscriber-->handleMsg(msg)

specialsubscriber-->handleMsg(msg)

*/
