﻿//0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//+-+-+-+-+-------+-+-------------+-------------------------------+
//|F|R|R|R| opcode|M| Payload len |    Extended payload length    |
//|I|S|S|S|  (4)  |A|     (7)     |             (16/64)           |
//|N|V|V|V|       |S|             |   (if payload len==126/127)   |
//| |1|2|3|       |K|             |                               |
//+-+-+-+-+-------+-+-------------+ - - - - - - - - - - - - - - - +
//|     Extended payload length continued, if payload len == 127  |
//+ - - - - - - - - - - - - - - - +-------------------------------+
//|                               |Masking-key, if MASK set to 1  |
//+-------------------------------+-------------------------------+
//| Masking-key (continued)       |          Payload Data         |
//+-------------------------------- - - - - - - - - - - - - - - - +
//:                     Payload Data continued ...                :
//+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
//|                     Payload Data continued ...                |
//+---------------------------------------------------------------+

#include <iostream>
#include <string.h>
#include <vector>
#include "WebSocketServer.h"

//
//std::string get_key(const char* buffer)
//{
//	std::string locBuffer(buffer);
//	size_t end_pos = locBuffer.find("==");
//	size_t pos = locBuffer.rfind(":", end_pos);
//	std::string b64Hash = locBuffer.substr(pos + 2, end_pos - pos);
//	return b64Hash;
//}

int main()
{
	ws::WebSocketServer server(8091);




	std::getchar();

	return 0;
}

