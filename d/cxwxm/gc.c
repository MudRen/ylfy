// Room: /d/cxwxm/gc.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long",
"�����ǳ��������ŵĹ㳡�������㳡�ɴ��Ĵ���ʯ�̳ɣ���\n"
"Ϊ��������������㳡���ƺ�Ī���İ�����������һ�����ӣ�ȴ��\n"
"�ǳ��ĸɾ����㳡�Ķ�����һ�����ȣ����ڹ㳡���ϱ��������һ\n"
"��С�ݡ�\n\n"
);
        set("outdoors", "cxwxm");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nanwu",
  "east" : __DIR__"changlang",
  "north" : __DIR__"beiwu",
  "west" : __DIR__"damen",
]));

        setup();
        replace_program(ROOM);
}
