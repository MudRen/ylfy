// cruise.h

#ifndef _CRUISE_H_
#define _CRUISE_H_

#define CRUISE_USER_DATA        0               // ���DBASE����

// ��֤��Ϣ
#define USER_ID                 0
#define USER_SITE               1
#define USER_MAGIC_NUMBER       2

// CRUISE-FTP�Ĵ����
#define RESULT_OK               "1 "            // �������
#define RESULT_CRUISE           "2 "            // ���ذ汾
#define RESULT_FILE             "10 "           // �����ļ�
#define RESULT_NO_CRUISE        "90 "           // û�а汾
#define RESULT_FINISH           "91 "           // ͬ�����
#define RESULT_ERR              "99 "           // δ֪����

// CRUISE-FTP�������˵�״̬
#define STATUS_LOGIN            1               // �ոյ�¼
#define STATUS_WAIT_COMMAND     2               // �ȴ�����
#define STATUS_SENDING          3               // �����ļ�

// CRUISE-FTP�ͻ��˵�״̬
#define STATUS_CONNECTING       101             // ������
#define STATUS_GET_ITEM         102             // ��ð汾
#define STATUS_GET_ITEM_ID      103             // ��ð汾����
#define STATUS_GET_FILE         104             // ��ȡ�ļ�
#define STATUS_SYN              105             // ������
#define STATUS_FINISHED         106             // ���ν���

// CRUISE-FTP��Ϣ�ṹ�е���Ŀ
#define STATUS                  0               // ״̬
#define FILE_NAME               1               // �ļ�����
#define FILE_POS                2               // �ļ�λ��
#define FILE_SIZE               3               // �ļ���С
#define CMD_QUEUE               4               // �����������
#define PENDING_WRITE           5               // �ȴ����͵���Ϣ
#define CMD_BUFFER              6               // (��������)������
#define RESULT_BUFFER           6               // (�ͻ���)������
#define SUB_SITES               7               // վ������

// ÿ��ͨ��Ӧ�𷵻صĳ���
#define NORMAL_RESULT_LEN       80              // 80���ֽ�

// ÿ�η��͵��ļ����С
#define FILE_BLOCK              1460            // ÿ�η���1460

#endif
