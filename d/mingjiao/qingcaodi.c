// Room: qingcaodi.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�ò���Ĺ�������׳�����ɷ����ĸ��˲��ܺϱ������º�
��ػ���һ��Ʈ�����Ҷ��һ���ˡ�����ķ�ţСͯ����֪����ؽ�
�����ֵ�һ�ζϵ�������������Զ����ɽ�﷢����

LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mutong2" : 1,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"caodi1",
"north" : __DIR__"tohsq1",	
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

