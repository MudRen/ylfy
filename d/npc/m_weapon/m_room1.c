// Room: /d/npc/m_weapon/m_room1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ɳĮ����");
    set("long", @LONG
������ɳĮ�в����һ�����ޣ����ϲ�Զ��Լ���Կ���һ��
�ںڵ�ɽ������紫��һЩ���������Ĵ�����������Ҳ��֪��˭
�ڴ���ʲô��������Ⱥɽ���֣�����Ʈ�졣
LONG
    );
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xuanbing",
  "east" : "/d/xingxiu/nanjiang2",
//  "northwest" : "/d/sunlight/tohsq1",
]));
    setup();
    replace_program(ROOM);
}
