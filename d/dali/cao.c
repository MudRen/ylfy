inherit ROOM;
void create()
{
        set("short", "���ϲ�");
        set("long", @LONG
���ϲݣ��̴���ͨ��
�޴���Ϊ���軺��Ũ�̿��������������������
��������ɫһ���¡�
���Ӳ��������أ�����Զ�����ഺ����ӽ�����졣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lastbridge",
  "northwest" : __DIR__"hua",
]));

        setup();
}
