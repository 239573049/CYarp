#include <stdint.h>

typedef void* PClient;

// �������ö��
enum TransportError
{
	// ������ɣ���ʾ��������������Ӻʹ���ͨ�����ѹر�
	Completed = 0,
	// client�����Ч
	InvalidHandle = 1,
	// Options��һЩ��������
	OptionsArgumentError = 2,
	// ���������ӵ��������쳣
	ServerConnectError = 3,
};

// �ͻ���ѡ��
struct ClientOptions
{
	// CYarp������Uri
	// ֧��http��https
	char16_t* ServerUri;
	// Ŀ�������Uri
	// ֧��http��https
	char16_t* TargetUri;
	// Ŀ���������UnixDomainSocket·��[��ѡ]
	char16_t* TargetUnixDomainSocket;
	// ���ӵ�CYarp��������Authorization����ͷ��ֵ
	char16_t* Authorization;
	// ��server��target�����ӳ�ʱʱ��������0Ĭ��Ϊ5s
	int32_t ConnectTimeout;
};

// �����ͻ���
extern "C" PClient CreateClient();

// �ͷſͻ���
extern "C" void FreeClient(
	// �ͻ��˾��
	PClient client);

// ��������
extern "C" enum TransportError Transport(
	// �ͻ��˾��
	PClient client,
	// ѡ��
	ClientOptions * options);