// shaluo.c
inherit ROOM;
void create()
{
    set("short", "ɯ��ƺ");
    set("long", @LONG
������Ȫ��̤������ʯ������ɽ�����ζ��ϣ���������ɯ��ƺ������
��ɽ·��ʼ���ͣ�����һ���ػ�������ɽ����������ʮ���̡���ͨ��ɽ�ϡ�
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"path1",
        "southup" : __DIR__"qingke",
        "southeast" : __DIR__"pubu",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "huashan" );
    set("objects", ([ 
        __DIR__"npc/haoke" : 2,
    ]));
 
    setup();
    replace_program(ROOM);
}
