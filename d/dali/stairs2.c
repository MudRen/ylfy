inherit ROOM;
void create()
{
        set("short", "�ν����");
        set("long", @LONG
���ݿ�һ�ɣ�����̺�̿������ҷ�������������������ϡ�ϸ�����ݺ�̺����
˿�ݺᣬ��Լ����һ�����꽻��ͼ������Ц֮����¥�ϴ�������ʱ��������һ����
����Ѫ�����ŵ��������㲻�������ļӿ��˲���������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"stairs",
  "westup" : __DIR__"secfloor",
]));

        setup();
}
