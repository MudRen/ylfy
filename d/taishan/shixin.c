// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
    set("short", "����ʯ");
    set("long", @LONG
�������������ķ嶥���������ʯ������һ�𣬾�˵������
�Ĵ���⣬��������ʯʱʯ��㲻�ᶯҡ����֮��ҡ����ֹ��
LONG
    );
    set("exits", ([
        "southdown" : __DIR__"lianhua",
    ]));
    set("outdoors", "taishan");
    setup();
    replace_program(ROOM);
}
