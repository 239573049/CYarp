#include <stdint.h>

typedef void* CYarpClient;

typedef void (*CYarpTunnelErrorCallback)(
	// ��������
	char16_t* type,
	// ������Ϣ
	char16_t* message);

// �������ö��
enum CYarpTransportError
{
	// client�����Ч
	InvalidHandle = -1,

	// �������
	Completed = 0,

	// ���ӵ�������ʧ��
	ConnectFailure = 1,

	// ���ӵ��������ѳ�ʱ
	ConnectTimedout = 2,

	// ���ӵ����������֤��ͨ��
	ConnectUnauthorized = 3
};

// �ͻ���ѡ��
struct CYarpClientOptions
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
	CYarpTunnelErrorCallback TunnelErrorCallback;
};

// �����ͻ���
// ��������ȷʱ����NULL
extern "C" CYarpClient CYarpClientCreate(CYarpClientOptions * options);

// �ͷſͻ���
extern "C" void CYarpClientFree(CYarpClient client);

// ��������
extern "C" enum CYarpTransportError CYarpClientTransport(CYarpClient client);