#include "WebSocketServer.h"

#ifdef _WIN32
#include <wincrypt.h>
#else

#endif

#include "SHA1.hpp"

namespace ws
{
	constexpr char* http_request = "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Accept: ";
	constexpr char* magic_string = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

	
	WebSocketServer::WebSocketServer(const char* ip_and_port)
	{
	}

	WebSocketServer::~WebSocketServer()
	{
	}

	const char* WebSocketServer::CreateAcceptKey(const char* request_key)
	{
		uint8_t* binary = HashSha1(request_key);
		return EncodeBase64(binary);
	}

	const char* WebSocketServer::EncodeBase64(uint8_t* byte)
	{
#ifdef _WIN32
		DWORD length = 0;
		CryptBinaryToStringA(byte, 20, CRYPT_STRING_BASE64, nullptr, &length);
		char* str = nullptr;
		CryptBinaryToStringA(byte, 20, CRYPT_STRING_BASE64, str, &length);
#endif
		return str;
	}


	uint8_t* WebSocketServer::HashSha1(const char* request_key)
	{
		std::string key(request_key);
		key += magic_string;
		SHA1 checksum;
		checksum.update(key);
		std::string result = checksum.final();
		uint8_t* byte_list = checksum.get_bytelist();
		uint32_t* digest = checksum.get_digest();

		FlipByteOrder(byte_list, digest);
	}

	void WebSocketServer::FlipByteOrder(uint8_t* byte, uint32_t* digest)
	{
		for (int i = 0; i < 5; i++)
		{
			byte[(i * 4) + 3] = digest[i] & 0x000000ff;
			byte[(i * 4) + 2] = (digest[i] & 0x0000ff00) >> 8;
			byte[(i * 4) + 1] = (digest[i] & 0x00ff0000) >> 16;
			byte[(i * 4) + 0] = (digest[i] & 0xff000000) >> 24;
		}
	}

};