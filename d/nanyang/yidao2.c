// Room: /d/shaolin/yidao2.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "�����");
    set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵������Ͼ��Ͽ��������������������ǳ����֡�
��ʱ������������������߷ɳ۶���������һ·���������ϵ���
�������ž�װ���¼��������еĻ���������ŵ�������������Щ
Щϰ��Ľ����ˡ���·��������������������֡�
LONG
    );
    set("exits", ([
        "south" : __DIR__"yidao1",
        "north" : __DIR__"hanshui1",
    ]));
    set("outdoors", "shaolin");
    setup();
    replace_program(ROOM);
}