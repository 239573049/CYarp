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
	char* ServerUri;
	// Ŀ�������Uri
	// ֧��http��https
	char* TargetUri;
	// Ŀ���������UnixDomainSocket·��[��ѡ]
	char* TargetUnixDomainSocket;
	// ���ӵ�CYarp��������Authorization����ͷ��ֵ
	char* Authorization;
	// ��server��target�����ӳ�ʱʱ��������0Ĭ��Ϊ30s
	int32_t ConnectTimeout;
};

// �����ͻ���
extern "C" PClient CreateClient();

// �ͷſͻ���
extern "C" void FreeClient(PClient client);

// ��������
extern "C" enum TransportError Transport(PClient client, ClientOptions* options);