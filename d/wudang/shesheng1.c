// Room: shiliang.c ʯ��
// arnzh 97/1/24
inherit ROOM;
void create()
{
    set("short", "�µ�");
    set("long", @LONG
�����������µף������վ�����û�뵽�Լ���Ȼ������������
LONG
    );
    set("exits", ([
        "up" : __DIR__"shijie62",
    ]));
    
    
    setup();
    replace_program(ROOM);
}
