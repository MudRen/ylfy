// Room: niushi.c

inherit ROOM;

void create()
{
        set("short", "ţ��");
        set("long", @LONG
СС��ţ����ݵ���ţ�����˵Ĳ�Ӭ������ĺ��磬����
��ˮ�ۣ��Ѷѵ�é�ݣ���һ��һ�У���չ���������ǰ�������
���÷�㶣��ѵ������Ա��˵�ı�ţ���治���������ţ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhang-shi",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/niu" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

