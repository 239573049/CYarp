#include <stdint.h>

typedef void* PClient;

// �������ö��
enum TransportError
{
	NoError = 0,
	InvalidHandle = 1,
	ParameterError = 2,
	ConnectError = 3,
};

// �ͻ���ѡ��
struct ClientOptions
{
	// CYarp������Uri
	char* ServerUri;
	// Ŀ�������Uri
	char* TargetUri;
	// ���ӵ�CYarp��������Authorization����ͷ��ֵ
	char* Authorization;
	// ��server��target�����ӳ�ʱʱ����Ĭ��Ϊ30s
	int32_t ConnectTimeout;
};

// �����ͻ���
PClient CreateClient();

// �ͷſͻ���
void FreeClient(PClient client);

// ��������
enum TransportError Transport(PClient client, ClientOptions options);