#include <stdint.h>

typedef void* PClient;
typedef void (*TunnelErrorCallback)(
	// ��������
	char16_t* type,
	// ������Ϣ
	char16_t* message);

// �������ö��
enum TransportError
{
	// client�����Ч
	InvalidHandle = -1,

	// ������ɣ���ʾ��������������Ӻʹ���ͨ�����ѹر�
	Completed = 0,

	// Optionsֵ��Ч
	InvalidOptions = 1,

	// ���ӵ����������֤��ͨ��
	ConnectUnauthorized = 2,

	// ���ӵ��������ѳ�ʱ
	ConnectTimedout = 3,

	// ���ӵ�������ʧ��
	ConnectFailure = 4
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
	// ����������ص�
	TunnelErrorCallback TunnelErrorCallback;
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